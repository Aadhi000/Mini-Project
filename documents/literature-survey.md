# 📚 Literature Survey – Smart Disaster Detection and Alerting System

## 1. Introduction

Natural disasters like landslides, earthquakes, and floods pose significant risks to both human life and infrastructure. Traditional disaster detection systems are either manual, costly, or lack real-time capabilities. In recent years, the integration of IoT (Internet of Things) has enabled smarter, faster, and more scalable solutions.

This project surveys similar works and highlights the innovations brought by our proposed system.

---

## 2. Related Works

### [1] Kumar & Ramesh (2022) – IoT-Based Slope Instability Detection  
An IoT system using geophones for early landslide detection in Sikkim.  
✅ Real-time alerts  
✅ Edge-based processing  
❌ Expensive sensors and complex setup

---

### [2] Teja et al. (2024) – Earthquake Detection Using IoT  
Used ADXL335 accelerometers + Arduino to detect seismic activity.  
✅ Cost-effective  
✅ SMS and buzzer alerts  
❌ Limited sensor fusion

---

### [3] Indukala et al. (2024) – Microseismic Landslide Alerting  
Real-time vibration monitoring using wireless nodes in Himalayas.  
✅ Wireless deployment  
❌ Only detects landslides, no moisture/tilt detection

---

### [4] Jadhav et al. (2024) – Multi-Sensor Disaster System  
Used flame, water, and rain sensors with NodeMCU.  
✅ Multi-hazard coverage  
❌ Limited accuracy, lacks soil and seismic features

---

### [5] Joshi et al. (2023) – SMARTMODE WSN System  
Wireless smart landslide monitoring using MEMS and solar.  
✅ Power efficient  
✅ Adaptive sampling  
❌ High deployment complexity

---

## 3. Gap Analysis

| Feature               | Existing Systems | Our System |
|----------------------|------------------|------------|
| Real-Time Alerts      | ✔️               | ✔️         |
| Soil Moisture         | ❌/Limited        | ✔️         |
| Tilt Detection        | ❌               | ✔️         |
| Vibration Monitoring  | ✔️               | ✔️         |
| Mobile Notification   | ❌/Limited        | ✔️ (Blynk) |
| Low-Cost              | ❌               | ✔️         |
| Multi-Sensor Fusion   | Partial          | ✔️         |

---

## 4. Uniqueness of Our Project

- Combines 3 key environmental parameters: vibration, tilt, and moisture.
- Uses low-cost components like ESP32, MPU6050, SW-420, YL69.
- Provides real-time alerts using Blynk IoT on mobile.
- Easy to install and scale.
- Runs on Wi-Fi and supports future GSM/ML add-ons.

---

## 5. Conclusion

Compared to existing systems, our Smart Disaster Detection and Alerting System achieves:
- Higher sensor fusion
- Better real-time alerting
- Low hardware cost
- Greater adaptability for smart cities and remote areas

It closes the gap between traditional warning systems and next-gen IoT-based disaster safety technologies.

---
