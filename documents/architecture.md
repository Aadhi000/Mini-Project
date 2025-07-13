# 🧠 System Architecture – Smart Disaster Detection and Alerting System

## 1. Overview

The Smart Disaster Detection and Alerting System is an IoT-based safety and alert mechanism designed to identify early signs of environmental hazards such as landslides and earthquakes. It integrates multiple sensors with a Wi-Fi-enabled ESP32 microcontroller and uses cloud-based notification via the Blynk platform.

---

## 2. Functional Modules

### 🔌 Sensor Module
This module includes:
- **YL-69 Soil Moisture Sensor**: Detects moisture content in the soil.
- **SW-420 Vibration Sensor**: Detects tremors and vibrations in the ground.
- **MPU6050 Accelerometer + Gyroscope**: Detects tilting and land movement.

### 🧠 Processing Module
- **ESP32 Microcontroller**:
  - Processes incoming sensor values.
  - Compares values to predefined thresholds.
  - Triggers alerts via buzzer and Blynk IoT if limits are crossed.

### 📶 Communication Module
- **Wi-Fi Module (Built-in ESP32)**:
  - Sends real-time data to Blynk Cloud.
  - Receives control signals and enables remote access.

### 🔔 Alerting Module
- **Buzzer**: Provides an audible local alarm.
- **Mobile Notification**: Push notification via Blynk events.

---

## 3. System Block Diagram

<pre>  
Soil Moisture Sensor ─┐ 
Vibration Sensor ─────┼──> ESP32 ───> Buzzer 
Tilt Sensor (MPU6050) ┘ └──> Blynk Cloud ───> Mobile Notification </pre>


---

## 4. Data Flow

1. Sensors collect data continuously.
2. ESP32 reads and compares data to safety thresholds.
3. If danger is detected:
   - A buzzer is activated immediately.
   - A log event is sent to the Blynk app (e.g., `tilt_event`, `vibration_alert`).
4. Users receive real-time alerts and can monitor live readings.

---

## 5. Power Supply

- 5V regulated power supply required.
- The system can also operate on battery backup or solar with a regulator circuit.

---

## 6. Cloud Integration

- **Blynk Cloud**
  - Sensor data visualization using gauges, charts.
  - Real-time events using `logEvent()` API.
  - Mobile notifications and live status.

---

## 7. Advantages

- Remote monitoring of remote or high-risk areas.
- Real-time early warning system.
- Compact, low-cost design with easy scalability.

---

## 8. Future Enhancements

- GSM-based SMS alerts.
- Google Maps integration for live geolocation.
- AI-based pattern recognition and forecasting.

---
