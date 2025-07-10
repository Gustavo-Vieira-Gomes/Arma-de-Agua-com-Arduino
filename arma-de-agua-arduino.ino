#include <NewPing.h>

// Define os pinos do sensor
#define TRIGGER_PIN  4
#define ECHO_PIN     7
#define MAX_DISTANCE 200  // Distância máxima em cm (pode ajustar conforme necessário)

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  delay(50); // Espera entre medições (evita sobrecarga no sensor)
  
  int distancia = sonar.ping_cm();  // Mede a distância em cm

  if (distancia > 0) {
    if (distancia < 15){
      digitalWrite(2, HIGH);
      Serial.print("Ativado");
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(2, LOW);
      digitalWrite(13, LOW);
    }
    Serial.print("Distância: ");
    Serial.print(distancia);
    Serial.println(" cm");
  } else if (distancia == 0) {
    Serial.println("Distancia 0");
    digitalWrite(2, LOW);
    digitalWrite(13, LOW);
  } else {
    Serial.println("Sem leitura");
    digitalWrite(2, LOW);
    digitalWrite(13, LOW);
  }
  
}