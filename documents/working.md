# ⚙️ WORKING

The **Smart Disaster Detection and Alerting System** is an IoT-based monitoring solution designed to detect environmental hazards such as **landslides** and **earthquakes**. It uses an **ESP-WROOM-32 (ESP32)** microcontroller to gather real-time data from various sensors and issue alerts via a **buzzer** and the **Blynk cloud platform** for remote monitoring.

---

### 🌐 Initialization

- The system begins with **Wi-Fi connection initialization**, retrying until successful.
- Once connected:
  - It logs sensor data.
  - Sends real-time alerts.
- If the connection drops, it attempts to **automatically reconnect**.

---

### 🔍 Sensor Monitoring

The system continuously reads data from **three key sensors**:

---

#### 1. 💧 YL-69 Moisture Sensor

Monitors **soil moisture levels** to evaluate potential landslide risks:

| Moisture Range      | Status                      |
|---------------------|-----------------------------|
| ≥ 3000              | ✅ Normal (Safe)             |
| 2500 – 3000         | ⚠️ Water Increasing          |
| 2000 – 2500         | 🛑 High Water (Critical)     |
| ≤ 2000              | 🚨 Landslide Risk (Alert)    |

---

#### 2. 🌍 SW-420 Vibration Sensor

Detects **ground vibrations** typically caused by:
- Earthquakes
- Soil movement during landslides

If significant movement is detected, the system **correlates it with other sensor data** for disaster classification.

---

#### 3. 📐 MPU-6050 Accelerometer + Gyroscope

Measures **tilt and orientation** to detect land shifts:
- An **abnormal tilt angle** indicates potential soil displacement.
- Triggers early warnings for landslides when combined with other sensors.

---

### 🚨 Alert System

If any sensor exceeds predefined thresholds:
- **Buzzer** is triggered locally for instant alerting.
- **Notifications** are pushed to the **Blynk app** in real time.

This IoT solution serves as an **early warning system** for disaster-prone regions, significantly improving **risk mitigation** and **public safety**.

---

✅ *Compact, real-time, and smart — it brings technology to the frontline of disaster detection.*
