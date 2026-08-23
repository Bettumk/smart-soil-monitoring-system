#define BLYNK_TEMPLATE_NAME "<Given-Template-Name>"
#define BLYNK_TEMPLATE_ID "<Given-Template-ID>"
#define BLYNK_AUTH_TOKEN "<Given-Auth-Token>"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// WiFi credentials
char ssid[] = "YourWifiName";
char pass[] = "YourWifiPassword";

// DS18B20 data wire
#define ONE_WIRE_BUS D4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

BlynkTimer timer;

// Soil moisture sensor pin
#define SOIL_MOISTURE_PIN A0

// Relay control pin
#define RELAY_PIN D2

// Moisture threshold
int moistureThreshold = 30;

bool moistureAlertSent = false;
bool manualControl = false;

void setup() {
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  sensors.begin();

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Relay off initially

  timer.setInterval(1000L, sendSensor);

  Serial.println("Setup complete.");
}

// Blynk manual control button on V2
BLYNK_WRITE(V2) {
  int buttonState = param.asInt();

  if (buttonState == 1) {
    manualControl = true;
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Manual control: Relay turned on.");
  } else {
    manualControl = false;
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Manual control: Relay turned off.");
  }
}

void sendSensor() {
  int soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);

  float soilMoisturePercent =
      map(soilMoistureValue, 1023, 0, 0, 100);

  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);

  Serial.print("Soil Moisture: ");
  Serial.print(soilMoisturePercent);
  Serial.print("% | Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  Blynk.virtualWrite(V0, soilMoisturePercent);
  Blynk.virtualWrite(V1, temperatureC);

  if (soilMoisturePercent < moistureThreshold && !moistureAlertSent) {
    Blynk.logEvent(
      "low_soil_moisture",
      "Soil moisture is low! Please water your plants."
    );

    Serial.println("Alert: Soil moisture is low. Notification sent.");
    moistureAlertSent = true;
  } else if (soilMoisturePercent >= moistureThreshold) {
    moistureAlertSent = false;
  }

  if (soilMoisturePercent < moistureThreshold && !manualControl) {
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Automatic control: Relay turned on.");
  } else if (!manualControl) {
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Automatic control: Relay turned off.");
  }
}

void loop() {
  Blynk.run();
  timer.run();
}

/*
Uploading:
1. Connect NodeMCU to the laptop via USB.
2. Select the appropriate board and port in Arduino IDE.
3. Upload the code to the NodeMCU.
4. Open Serial Monitor to check readings and debug information.

Testing:
- Check soil moisture and temperature readings.
- Verify readings are sent to Blynk.
- Test automatic water-pump operation.
- Test manual pump control using the Blynk app.

The system provides real-time soil data for efficient irrigation
control for small-scale farmers.
*/
