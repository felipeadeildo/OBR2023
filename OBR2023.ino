#include "MotorController.h"

#define TRIGGER_PIN 12
#define ECHO_PIN 10
#define LINE_THRESHOLD 500
#define IN1 11
#define IN2 9
#define IN3 5
#define IN4 3
#define L1 A0
#define L2 A1
#define R2 A2
#define R1 A3

MotorController motor(IN1, IN2, IN3, IN4);

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(L1, INPUT);
  pinMode(L2, INPUT);
  pinMode(R1, INPUT);
  pinMode(R2, INPUT);
}

void loop() {
  int distance = getUDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  while (distance > 20) {
    int r1 = isBlack(R1);
    int r2 = isBlack(R2);
    int l1 = isBlack(L1);
    int l2 = isBlack(L2);

    int speedA = 255;
    int speedB = 255;

    if      ( l1 &&  l2 &&  r2 &&  r1) { motor.move(speedA, speedB);   Serial.println("Movendo-se para frente"); }
    else if ( l1 &&  l2 &&  r2 && !r1) { motor.move(speedA, speedB/2); Serial.println("Virando levemente à direita"); }
    else if ( l1 &&  l2 && !r2 &&  r1) { motor.move(speedA/2, speedB); Serial.println("Virando levemente à esquerda"); }
    else if ( l1 &&  l2 && !r2 && !r1) { motor.move(-speedA, speedB);  Serial.println("Virando à direita"); }
    else if ( l1 && !l2 &&  r2 &&  r1) { motor.move(speedA, -speedB);  Serial.println("Virando à esquerda"); }
    else if ( l1 && !l2 &&  r2 && !r1) { motor.move(-speedA/2, speedB/2); Serial.println("Virando à direita lentamente"); }
    else if ( l1 && !l2 && !r2 &&  r1) { motor.move(speedA/2, -speedB/2); Serial.println("Virando à esquerda lentamente"); }
    else if ( l1 && !l2 && !r2 && !r1) { motor.move(-speedA/2, speedB); Serial.println("Procurando a linha à direita"); }
    else if (!l1 &&  l2 &&  r2 &&  r1) { motor.move(speedA/2, -speedB); Serial.println("Procurando a linha à esquerda"); }
    else if (!l1 &&  l2 &&  r2 && !r1) { motor.move(-speedA, speedB/2); Serial.println("Fazendo curva à direita"); }
    else if (!l1 &&  l2 && !r2 &&  r1) { motor.move(speedA, speedB/2); Serial.println("Fazendo curva à esquerda"); }
    else if (!l1 &&  l2 && !r2 && !r1) { motor.move(speedA/2, speedB/2); Serial.println("Movendo-se para frente lentamente"); }
    else if (!l1 && !l2 &&  r2 &&  r1) { motor.move(speedA/2, speedB); Serial.println("Ajustando à esquerda"); }
    else if (!l1 && !l2 &&  r2 && !r1) { motor.move(-speedA/2, -speedB); Serial.println("Ajustando à direita"); }
    else if (!l1 && !l2 && !r2 &&  r1) { motor.move(speedA, -speedB/2); Serial.println("Corrigindo para a esquerda"); }
    else if (!l1 && !l2 && !r2 && !r1) { motor.move(speedA/2, -speedB/2); Serial.println("Corrigindo para a direita"); }

    delay(30);
    motor.stop();
    delay(30);
    distance = getUDistance();
  }
}



long getUDistance() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  int counts = 10; // Reduzido o número de leituras
  long distances = 0;

  for (int i = 0; i < counts; i++) {
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);
    long duration = pulseIn(ECHO_PIN, HIGH);
    distances += duration / 29 / 2; // O som se move a 29 microssegundos por centímetro
  }

  return distances / counts;
}

bool isBlack(uint8_t pin) {
  int value = analogRead(pin);
  return value < LINE_THRESHOLD;
}
