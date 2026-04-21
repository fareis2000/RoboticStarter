int sensorPin = 7; // Pino digital do sensor FC-51

void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int leitura = digitalRead(sensorPin);

  if (leitura == 0) {
    Serial.println("Branco");
  } else {
    Serial.println("Preto");
  }

  delay(600); // Pausa para evitar mensagens rápidas demais
}
