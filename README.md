#Smart Home Automation System using ESP32 (IoT)

Overview
This project is an IoT-based Smart Home Automation System built using ESP32, IR sensors, a rain sensor, and servo motors. The system automates home functionalities like garage control, door access, and cloth protection during rain, while also allowing secure manual control via the Blynk mobile app.


Features
- Automatic Garage Door System (Vehicle Detection)
- Smart Parking Detection (Auto Close Garage)
- Smart Door System (Person Detection)
- Rain Detection System (Cloth Protection)
- Remote Control via Blynk App
- Security Layer (Manual Override Required)
- Real-time Email & App Notifications

Components Used
- ESP32 Development Board
- IR Sensors (x3)
- Rain Sensor (x1)
- Servo Motors (x3)
- Breadboard
- 9V Battery / External Power Supply
- Jumper Wires

System Working

Garage Automation
- IR Sensor detects incoming vehicle
- Garage door opens using servo motor
- When car is parked (second IR sensor), garage door closes automatically

Door Automation
- IR sensor detects person at door
- Door opens using servo motor

Rain Protection System
- Rain sensor detects water
- Clothes are automatically pulled inside using servo motor

Security Feature
Even if sensors trigger actions automatically, the system sends notifications and allows the user to manually control everything using the Blynk app to prevent unauthorized access.

Blynk App Control
- Button V0 → Garage Door
- Button V1 → Main Door
- Button V2 → Clothes System

Notification System
- Vehicle detected
- Car parked
- Person detected
- Rain detected

Notifications are sent via:
- Email
- Blynk Push Notifications

Circuit Diagram
![Circuit Diagram](your_image.png)

Code
Full ESP32 Arduino Code available in this repository.

Limitations
- Servo motors require external power for stability
- No camera-based verification system
- Basic sensor-based detection only

Future Improvements
- Mobile App Dashboard (Custom UI)
- AI-based Face Recognition for Door Access
- Integration with Google Assistant / Alexa
- Cloud database (Firebase)
- CCTV monitoring system

Conclusion
This project demonstrates how IoT can be used to automate and secure a smart home. It combines sensor-based automation with cloud-based control, making it both intelligent and safe.

👨‍💻 Author
Abu Sayed Muhammed Hanif

---

## ⭐ If you like this project, give it a star!
