// importando as bibliotecas do código
#include <MPU6050_tockn.h>
#include <Wire.h>
// Vamos agora criar as váriaveis dos pinos
#define pinLedX 2
#define pinLedY 4
#define pinLedZ 7
// criando o acelerometro
#define MPU6050_ADDR         0x68
//#define MPU6050_ADDR         0x69
// Vamos criar o acelerometro usando a lib
#define DEBUG
MPU6050 mpu6050(Wire);
// váriaveis para salvar o angulo
float anguloX;
float anguloY;
float anguloZ;
// salvar o tempo do projeto
unsigned long controleTempo;

void setup() {
	// iniciando a comunicação
  Serial.begin(9600);
	//   iniciando o aceletrometro
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(false);
// Dizendo que os 3 pinos dos leds são saida de energia
  pinMode(pinLedX,OUTPUT);
  pinMode(pinLedY,OUTPUT);
  pinMode(pinLedZ,OUTPUT);
//   ascendendo os leds
  digitalWrite(pinLedX,HIGH);
  digitalWrite(pinLedY,HIGH);
  digitalWrite(pinLedZ,HIGH);
  delay(500);
//   Apagando os leds
  digitalWrite(pinLedX,LOW);
  digitalWrite(pinLedY,LOW);
  digitalWrite(pinLedZ,LOW);

//   Terminando o Setup
  #ifdef DEBUG
  Serial.println("Fim Setup");
  #endif  
}

void loop() {
	// Sempre atualizando o acelerometro no começo de tudo
  mpu6050.update();
// pegando os angulos
  anguloX = mpu6050.getAngleX();
  anguloY = mpu6050.getAngleY();
  anguloZ = mpu6050.getAngleZ();
// Se cada um dos angulos subir mais que 25 graus 
// irá acender o led
  if (anguloX >= 25){
    Serial.println("subindo");
    digitalWrite(pinLedX,HIGH);
  } else if (anguloX <= -25){
    Serial.println("descendo");
    digitalWrite(pinLedX,HIGH);
  }else {
    digitalWrite(pinLedX,LOW);
  }

  if (anguloY >= 25){
    Serial.println("esquerda");
    digitalWrite(pinLedY,HIGH);
  } else if (anguloY <= -25){
    Serial.println("direita");
    digitalWrite(pinLedY,HIGH);
  }else {
    digitalWrite(pinLedY,LOW);
  }

  if (anguloZ >= 50 || anguloZ <= -70){
    digitalWrite(pinLedZ,HIGH);
  } else {
    digitalWrite(pinLedZ,LOW);
  }

	// printando sempre a cada 1 segundo
  if( millis() - controleTempo > 1000){
    Serial.print("Angulo de giro: ");
    Serial.println(anguloZ);

    controleTempo = millis();
  }
}