#include <Wire.h>
#include <Adafruit_VL53L0X.h>
#include <WiFi.h>

// Wi-Fi credentials for optional notification
const char* ssid     = "Your_SSID";
const char* password = "Your_PASSWORD";

// Sensor and buzzer
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
const int buzzerPin = 25;  // PWM pin for buzzer

// Motion detection
int thresholdDistance = 100; // Distance in mm
bool alarmTriggered = false;
unsigned long alarmDuration = 5000; // ms
unsigned long alarmStart = 0;

void setup() {
  Serial.begin(115200);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);

  // Start I2C for VL53L0X
  Wire.begin();
  if (!lox.begin()) {
    Serial.println("VL53L0X not detected!");
    while (1);
  }

  // Optional: connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 10) {
    delay(1000);
    Serial.print(".");
    attempts++;
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWi-Fi connected!");
  } else {
    Serial.println("\nWi-Fi connection failed.");
  }
}

void loop() {
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);

  if (measure.RangeStatus != 4) {
    Serial.print("Distance: ");
    Serial.print(measure.RangeMilliMeter);
    Serial.println(" mm");

    if (measure.RangeMilliMeter < thresholdDistance && !alarmTriggered) {
      triggerAlarm();
    }
  } else {
    Serial.println("Out of range");
  }

  if (alarmTriggered && (millis() - alarmStart >= alarmDuration)) {
    stopAlarm();
  }

  delay(100);
}

void triggerAlarm() {
  Serial.println("🔔 Theft Detected! Triggering Alarm.");
  digitalWrite(buzzerPin, HIGH);
  alarmStart = millis();
  alarmTriggered = true;

  if (WiFi.status() == WL_CONNECTED) {
    sendWiFiAlert();
  }
}

void stopAlarm() {
  digitalWrite(buzzerPin, LOW);
  alarmTriggered = false;
  Serial.println("Alarm deactivated.");
}

void sendWiFiAlert() {
  
  WiFiClient client;
  const char* host = "your-server.com"; // e.g., IFTTT webhook or Node-RED
  const int port = 80;

  if (!client.connect(host, port)) {
    Serial.println("Failed to connect to server.");
    return;
  }

  String url = "/alert-endpoint?event=theft_detected";
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  Serial.println("Wi-Fi alert sent.");
}
