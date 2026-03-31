#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

char auth[] = "YOUR_BLYNK_AUTH_TOKEN";
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

#define VEHICLE_IR 34
#define PARK_IR    35
#define DOOR_IR    32
#define RAIN_PIN   33

#define SERVO_GARAGE  13
#define SERVO_DOOR    12
#define SERVO_CLOTH   14

Servo garageServo;
Servo doorServo;
Servo clothServo;

#define VPIN_GARAGE V0
#define VPIN_DOOR   V1
#define VPIN_CLOTH  V2

bool garageState = false;
bool doorState = false;
bool clothState = false;

void setup() {
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);

  pinMode(VEHICLE_IR, INPUT);
  pinMode(PARK_IR, INPUT);
  pinMode(DOOR_IR, INPUT);
  pinMode(RAIN_PIN, INPUT);

  garageServo.attach(SERVO_GARAGE);
  doorServo.attach(SERVO_DOOR);
  clothServo.attach(SERVO_CLOTH);

  garageServo.write(0);
  doorServo.write(0);
  clothServo.write(0);

BLYNK_WRITE(VPIN_GARAGE) {
  garageState = param.asInt();
  if (garageState) {
    garageServo.write(90);
  } else {
    garageServo.write(0); 
  }
}

BLYNK_WRITE(VPIN_DOOR) {
  doorState = param.asInt();
  if (doorState) {
    doorServo.write(90);
  } else {
    doorServo.write(0);
  }
}

BLYNK_WRITE(VPIN_CLOTH) {
  clothState = param.asInt();
  if (clothState) {
    clothServo.write(90);
  } else {
    clothServo.write(0);
  }
}

void loop() {
  Blynk.run();

  if (digitalRead(VEHICLE_IR) == LOW) {
    Serial.println("Vehicle detected!");
    Blynk.logEvent("vehicle_detected", "Vehicle arrived at garage");

    garageServo.write(90); 
    delay(3000);
  }

  if (digitalRead(PARK_IR) == LOW) {
    Serial.println("Car parked!");
    Blynk.logEvent("car_parked", "Garage closing");

    garageServo.write(0);  // Close
    delay(3000);
  }

  if (digitalRead(DOOR_IR) == LOW) {
    Serial.println("Person detected at door!");
    Blynk.logEvent("person_detected", "Someone at the door");

    doorServo.write(90);
    delay(3000);
  }

  if (digitalRead(RAIN_PIN) == LOW) {
    Serial.println("Rain detected!");
    Blynk.logEvent("rain_detected", "Rain started! Taking clothes in");

    clothServo.write(90);
    delay(3000);
  }

  delay(200);
}