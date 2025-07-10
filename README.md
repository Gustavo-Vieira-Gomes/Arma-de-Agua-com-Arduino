# Arma de Água com Arduino e Sensor de Presença

# Objetivo do projeto

O objetivo do trabalho era utilizar um sensor ultrassônico para detectar a presença de um alvo. A partir disso, realizar o disparo utilizando uma Bomba de Água imersa dentro do recipiente.

# Circuito do Projeto no tinkercad.
Para representação, foram necessárias algumas adaptações no tinkercad:
- Motor DC no lugar da bomba de água
- Relé utilizado com formato diferente do que usamos (No projeto utilizamos o relé de 5 pinos.)
- Bateria adaptada. No projeto, utilizamos nossa fonte de tensão ajustável configurada servindo 5V. No tinkercad, usamos 3 baterias de 1,5V

![Alt text](<./circuito arduino.jpg>)

# Componentes utilizados

| Componentes | Quantidade | Valor unitário (R$) |
|:-----|:--------:|------:|
| Fonte de Tensão Ajustável | 1 | Valor Descrito Acima |
| Resistor 2,2K | 1 | 0,07 |
| Transistor NPN | 1 | 2,60 |
| Relé 5V | 1 | 5,70 |
| Diodo | 2 | 0,70 |
| Placa Arduino Uno | 1 | 52,40 |
| Sensor Ultrassom | 1 | 16,00 |
| Bomba de Água 3 a 6V | 1 | 20,00 |

# Imagem do Projeto
![Alt text](./arma-de-agua-com-arduino.jpg)
<br>

# Vídeo do Projeto
https://youtube.com/shorts/WPJaGv6oAQE?feature=share

# Vídeo da explicação do Projeto
https://youtu.be/nrvvnMfkwuk

# Código do arduíno utilizado

```ino
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
```

# Alunos:

Guilherme Pego dos Santos - 15575570
<br>
Gustavo Vieira Gomes - 16907251
<br>
Mateus Juares Felipe - 16891602
<br>
André Luiz Sousa Paião - 16854281
