#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <MPU6050_tockn.h>
#include <Wire.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "wifi ssid";
char pass[] = "wifi password";
#define VS_PIN 35   // Vibration Sensor (Analog)
#define MOISTURE_PIN 32 // Moisture Sensor
#define BUZZER_PIN 25 // Buzzer
MPU6050 mpu6050(Wire);
float initialAngleX, initialAngleY, initialAngleZ;
long mpuTimer = 0;
BlynkTimer timer;
bool waterLevelAlertSent = false;
bool landslideRiskAlertSent = false;
bool highWaterAlertSent = false;
bool tiltAlertSent = false;
bool vibrationAlertSent = false;
bool buzzerActive = false;
const float alpha = 0.05;
const int NOISE_THRESHOLD = 10;
const int VIBRATION_THRESHOLD = 100;
float smoothedVibration = 0;
void activateBuzzer() {
if (!buzzerActive) {
digitalWrite(BUZZER_PIN, HIGH);
buzzerActive = true;
}
}
void deactivateBuzzer() {
if (buzzerActive) {
digitalWrite(BUZZER_PIN, LOW);
buzzerActive = false;
}
}
void sendVibrationData() {
int rawVibration = analogRead(VS_PIN);
if (abs(smoothedVibration - rawVibration) > NOISE_THRESHOLD) {
smoothedVibration = (alpha * rawVibration) + ((1 - alpha) * smoothedVibration);
}
Blynk.virtualWrite(V6, smoothedVibration);
if (smoothedVibration > VIBRATION_THRESHOLD) {
if (!vibrationAlertSent) {
Blynk.logEvent("vibration_alert", "High Vibration Detected!");
vibrationAlertSent = true;
}
activateBuzzer();
} else {
vibrationAlertSent = false;
}
}
void sendMoistureData() {
int sensor_data = analogRead(MOISTURE_PIN);
Blynk.virtualWrite(V1, sensor_data);
if (sensor_data >= 3000) {
Blynk.virtualWrite(V2, "NORMAL STATE");
waterLevelAlertSent = landslideRiskAlertSent = highWaterAlertSent = false;
} else if (sensor_data < 3000 && sensor_data >= 2500) {
if (!waterLevelAlertSent) {
Blynk.virtualWrite(V2, "⭕ WATER LEVEL INCREASING!");
Blynk.logEvent("water_level_increasing", "❕ Water Level Increasing!");
waterLevelAlertSent = true;
}
} else if (sensor_data < 2500 && sensor_data >= 2000) {
if (!landslideRiskAlertSent) {
Blynk.virtualWrite(V2, "HIGH WATER LEVEL!");
Blynk.logEvent("high_water_level", "Immediate Action Required!");
landslideRiskAlertSent = true;
}
} else if (sensor_data < 2000) {
if (!highWaterAlertSent) {
Blynk.virtualWrite(V2, "LANDSLIDE RISK!");
Blynk.logEvent("landslide_risk", "Possible Landslide Risk!");
highWaterAlertSent = true;
}
activateBuzzer();
}
}
void sendTiltData() {
mpu6050.update();
if (millis() - mpuTimer > 50) {
float relativeAngleX = mpu6050.getAngleX() - initialAngleX;
float relativeAngleY = mpu6050.getAngleY() - initialAngleY;
float relativeAngleZ = mpu6050.getAngleZ() - initialAngleZ;
Blynk.virtualWrite(V3, relativeAngleX);
Blynk.virtualWrite(V4, relativeAngleY);
Blynk.virtualWrite(V5, relativeAngleZ);
if ((abs(relativeAngleX) > 30 || abs(relativeAngleY) > 30 || abs(relativeAngleZ) > 30)) {
if (!tiltAlertSent) {
Blynk.logEvent("tilt_event", "Tilt Detected!");
tiltAlertSent = true;
}
activateBuzzer();
} else {
tiltAlertSent = false;
}
mpuTimer = millis();
}
}
void checkToDeactivateBuzzer() {
if (!vibrationAlertSent && !highWaterAlertSent && !landslideRiskAlertSent && !tiltAlertSent) {
deactivateBuzzer();
}
}
void setup() {
pinMode(VS_PIN, INPUT);
pinMode(MOISTURE_PIN, INPUT);
pinMode(BUZZER_PIN, OUTPUT);
digitalWrite(BUZZER_PIN, LOW);
WiFi.begin(ssid, pass);
int retry = 0;
while (WiFi.status() != WL_CONNECTED && retry < 20) {
delay(500);
retry++;
}
Blynk.begin(auth, ssid, pass);
Blynk.virtualWrite(V0, "CALIBRATING SENSORS...");
Wire.begin(21, 22);
mpu6050.begin();
mpu6050.calcGyroOffsets(true);
delay(1000);
mpu6050.update();
initialAngleX = mpu6050.getAngleX();
initialAngleY = mpu6050.getAngleY();
initialAngleZ = mpu6050.getAngleZ();
Blynk.virtualWrite(V0, "SYSTEM READY");
timer.setInterval(50L, sendMoistureData);
timer.setInterval(50L, sendTiltData);
timer.setInterval(50L, sendVibrationData);
}
void loop() {
if (!Blynk.connected()) {
Blynk.connect();
}
Blynk.run();
timer.run();
checkToDeactivateBuzzer();
}
