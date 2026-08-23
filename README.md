# 🌱 Smart Soil Monitoring System

An IoT-based smart soil monitoring and automated irrigation system designed for real-time soil condition monitoring and efficient water management.

The system uses a NodeMCU ESP8266 to collect soil moisture and temperature data and sends the information to the Blynk platform through Wi-Fi. When the soil moisture level falls below a predefined threshold, the system can automatically activate the water pump through a relay.

---

## 📌 Project Overview

The Smart Soil Monitoring System is designed to help monitor soil conditions and support automated irrigation.

The system measures:

- Soil moisture
- Soil temperature
- Irrigation status

The collected data is displayed through the Blynk platform, allowing remote monitoring.

When the soil moisture becomes too low, the system:

1. Detects the low moisture condition.
2. Sends a notification through Blynk.
3. Automatically activates the water pump.
4. Allows the user to manually control the pump through the Blynk application.

---

## 🎯 Objectives

- Monitor soil moisture in real time.
- Monitor soil temperature.
- Provide remote monitoring through Blynk.
- Automatically control irrigation based on soil moisture.
- Send an alert when soil moisture becomes low.
- Provide manual control of the water pump.
- Reduce unnecessary water usage.
- Support efficient irrigation for small-scale farming.

---

## 🧰 Hardware Components

- NodeMCU ESP8266
- Soil Moisture Sensor
- DS18B20 Temperature Sensor
- Relay Module
- Water Pump
- Battery
- Connecting Wires
- Breadboard
- Supporting electronic components

---

## 💻 Software & Technologies

- Arduino IDE
- Arduino / C++
- ESP8266
- Blynk
- Wi-Fi
- IoT

---

## 🏗️ System Architecture

```text
+-----------------------+
| Soil Moisture Sensor  |
+-----------+-----------+
            |
            v
+-----------------------+
|   NodeMCU ESP8266     |
|   Data Processing     |
+-----------+-----------+
            |
            +--------------------+
            |                    |
            v                    v
+-------------------+    +-------------------+
| DS18B20 Temperature|    | Relay + Water     |
| Sensor             |    | Pump              |
+-------------------+    +-------------------+
            |
            v
+-----------------------+
|       Wi-Fi           |
+-----------+-----------+
            |
            v
+-----------------------+
|       Blynk           |
| Monitoring & Control  |
+-----------------------+

⚙️ Working Principle

The system continuously reads the soil moisture value using the soil moisture sensor.

The NodeMCU ESP8266 processes the sensor reading and sends the data to the Blynk platform through Wi-Fi.

The DS18B20 sensor measures temperature and sends the temperature value along with the soil moisture information.

A predefined moisture threshold is used to determine whether irrigation is required.

Automatic Operation

If the soil moisture level falls below the configured threshold:

The system identifies the soil as dry.
A low-moisture notification is sent through Blynk.
The relay is activated.
The water pump starts automatically.

When the soil moisture reaches an acceptable level, the automatic irrigation control turns the pump off.

Manual Operation

The user can also control the water pump manually using the Blynk application.

📱 Blynk Features

The Blynk application is used for:

Real-time soil moisture monitoring
Temperature monitoring
Water pump control
Low-moisture notifications
Remote monitoring
Manual irrigation control
📸 Project Gallery
🔌 Circuit Setup

The circuit integrates the NodeMCU ESP8266, soil moisture sensor, relay module, water pump and supporting components.

💻 Arduino IDE / ESP8266 Development

Arduino IDE was used for developing and uploading the ESP8266-based system code.

🌱 Wet Soil Testing

The system was tested under wet-soil conditions to observe soil moisture measurements.

🪴 Dry Soil Testing

The system was tested under dry-soil conditions to verify moisture detection and irrigation behavior.

📱 Blynk Dashboard and Low-Moisture Alert

The Blynk interface provides remote monitoring and displays a low-soil-moisture notification when the configured threshold is reached.

💻 Source Code

The complete Arduino/ESP8266 source code is available in this repository.

👉 View Smart Soil Monitoring Code

🧪 Testing

The prototype was tested under different soil conditions.

Tests Performed
Wet-soil measurement
Dry-soil measurement
Soil moisture monitoring
Temperature monitoring
Blynk monitoring
Low-moisture notification
Automatic water-pump operation
Manual water-pump control
Overall system integration
📊 Results

The prototype demonstrated:

Real-time soil moisture monitoring
Temperature monitoring
Wi-Fi-based IoT communication
Remote monitoring through Blynk
Low-moisture notification
Automatic irrigation control
Manual pump control

The testing demonstrated that the system can monitor soil conditions and respond to low soil moisture conditions through automated irrigation.

🏆 Project Highlights
Area	Implementation
Microcontroller	NodeMCU ESP8266
Programming	Arduino / C++
Soil Monitoring	Soil Moisture Sensor
Temperature	DS18B20
IoT Platform	Blynk
Communication	Wi-Fi
Automation	Relay + Water Pump
Alerts	Low Soil Moisture Notification
Control	Automatic + Manual
👨‍💻 Project Role

End-to-End Project Development – Team Member

Contributed to project development including problem identification, system design, hardware assembly, programming, sensor integration, Blynk setup, irrigation automation, testing, debugging and project documentation.

🎓 Project Information

Project Type: Academic Group Project

Institution: Dayananda Sagar Academy of Technology and Management

📚 Documentation

The project documentation and academic materials can be added to this repository as required.

🔮 Future Improvements

Possible future improvements include:

Weather-based irrigation
Mobile application improvements
Cloud-based data storage
Historical sensor-data visualization
Multiple soil monitoring nodes
Improved sensor calibration
More advanced irrigation scheduling
Solar-powered operation
⭐ Conclusion

The Smart Soil Monitoring System demonstrates the use of IoT, sensors, wireless communication and automated control for smart irrigation.

By combining the NodeMCU ESP8266, soil moisture sensor, temperature sensor, relay, water pump and Blynk platform, the system provides real-time monitoring and automated irrigation support.

👥 Project Team

Academic Group Project

Dayananda Sagar Academy of Technology and Management
