#define TRIGGER_PIN 12 // o pino de trig é 12
#define ECHO_PIN 10 // o pino de echo é 10
#define LINE_THRESHOLD 500 // Define o limite para detectar a linha
#define IN1 11
#define IN2 9
#define IN3 5
#define IN4 3
// 1 => Verdadeiro preto menor que 500
// 0 => Falso branco maior que 500

#include "MotorController.h"


MotorController motor(IN1, IN2, IN3, IN4);


void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}


void loop() {
  
}

long getUDistance() { // em centímetros
  // Limpa o pino de disparo
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  int counts = 100;
  long distancias = 0;
  long duracao;
  for (int i = 0; i < counts; i++) {
    // Emite pulso ultrassônico
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    // Lê o pulso de eco
    duracao = pulseIn(ECHO_PIN, HIGH);

    // Calcula a distância
    distancias += duracao / 29 / 2; // O som se move a 29 microssegundos por centímetro
  }
  return distancias/counts;
}