#include "soil_model.h"
#define SOIL_PIN 34// your .h file
#define PUMP_PIN 21
#define BUZZER_PIN 19
#define LED_PIN 18

Eloquent::ML::Port::DecisionTree model;

void setup() {
  Serial.begin(115200);

  pinMode(PUMP_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(PUMP_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
     float features[1];
     features[0] = analogRead(SOIL_PIN);

     int prediction = model.predict(features);
     
    // Output result
    Serial.print("Moisture: ");
    Serial.print(features[0]);
    Serial.println(" -> ");

    if (prediction == 1) {
      Serial.println("DRY");

      digitalWrite(PUMP_PIN, HIGH);
      digitalWrite(BUZZER_PIN, HIGH);
      digitalWrite(LED_PIN, HIGH);

    } else{
      Serial.println("WET");

      digitalWrite(PUMP_PIN, LOW);
      digitalWrite(BUZZER_PIN, LOW);
      digitalWrite(LED_PIN, LOW);
    }
    
    delay(2000);

}
