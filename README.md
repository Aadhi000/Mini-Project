# 🌪️ Smart Disaster Detection and Alerting System

An IoT-based disaster detection and alerting solution that monitors soil moisture, ground vibration, and tilt angle to predict and alert about earthquakes or landslides. Built using ESP32, Blynk, and multiple sensors, it provides real-time alerts via buzzer and mobile dashboard.

## 🚀 Features

- Real-time monitoring of moisture, vibration, and tilt
- Blynk IoT cloud integration for remote alerts
- Immediate buzzer alarm on disaster risk detection
- Automatic alerts when thresholds are breached
- Low-cost, scalable, and energy-efficient design

## 🧰 Hardware Used

| Component              | Description                     |
|------------------------|---------------------------------|
| ESP32                  | Main microcontroller with WiFi  |
| YL-69 Moisture Sensor  | Measures soil water content     |
| SW-420 Vibration Sensor| Detects seismic vibrations      |
| MPU6050                | Detects tilt and motion         |
| Buzzer                 | Audible local alert             |

## 🖼️ System Architecture

![System Architecture](images/BLOCKDIAGRAM.png)

## 🔧 Circuit Diagram

![Circuit Diagram](images/CIRCUITDIAGRAM.png)

## 🛠️ How It Works

1. Moisture sensor detects soil saturation.
2. MPU6050 measures tilts.
3. Vibration sensor detects seismic activity.
4. ESP32 processes and triggers buzzer + Blynk alert.

## 💻 Software Stack

- Arduino IDE
- Blynk IoT platform
- EasyEDA (for circuit design)

## 📂 Repository Structure

| Folder / File                | Description                                                                 |
|------------------------------|-----------------------------------------------------------------------------|
| `Discussions/`               | Contains markdowns related to system analysis:                              |
|                              | → `advantages.md` – Benefits of the system                                  |
|                              | → `disadvantages.md` – Challenges or drawbacks                              |
|                              | → `applications.md` – Real-world use cases                                  |
|                              | → `future-scope.md` – Future enhancements                                   |
|                                                                                                           |
| `Estimation/`                | Project budgeting and effort analysis                                       |
| └── `estimation.md`          | Total cost, time, and resource estimation                                   |
|                                                                                                           |
| `Output/`                    | Visual outputs and final demonstrations                                     |
| ├── `images/`                | Image snapshots of the working system                                       |
| └── `video/`                 | Demo video of the project                                                   |
|                                                                                                           |
| `Web_Dashboard/`             | Dashboard setup details (layout, widget mapping)                           |
| └── `dashboard-description.md` | Markdown file describing dashboard configuration                        |
|                                                                                                           |
| `blynk_credentials/`         | Blynk configuration                                                         |
| └── `blynk-config.txt`       | Auth token, template ID, event names                                       |
|                                                                                                           |
| `docs/`                      | Project documentation and technical content                                |
| ├── `architecture.md`        | Hardware + software architecture                                            |
| ├── `working.md`             | Explanation of system operation                                             |
| └── `literature-survey.md`   | Review of related systems and improvements                                 |
|                                                                                                           |
| `extras/`                    | Additional project material                                                 |
| └── `REPORT.pdf`             | Full project report in PDF format                                           |
|                                                                                                           |
| `firmware/`                  | Arduino/ESP32 source code                                                   |
| └── `esp32_alert_system.ino` | Firmware for ESP32 microcontroller                                         |
|                                                                                                           |
| `flowchart/`                 | System logic representation                                                 |
| └── `flowchart.png`          | Visual flowchart of the system process                                      |
|                                                                                                           |
| `images/`                    | Diagrams for documentation                                                  |
| ├── `block-diagram.png`      | Logical system block diagram                                                |
| └── `circuit-diagram.png`    | Electrical circuit schematic                                                |
|                                                                                                           |
| `README.md`                  | You’re reading it — project overview and index                              |

## 👨‍💻 Team

- Aadil Muhammed  
- Beval Philip Mathew  
- Rahul B  
- Sibi B John  


