// ainda falta acertar um tom mas a melodia esta certa.


int buzzerPin = 8; // Pino do buzzer

// Definições das notas musicais em Hz
int notas[] = {
  415,  // G#
  493,  // B
  415,  // G#
  493,  // B
  493,  // B
  370,  // F#
  466,  // A#
  370,  // F#
  415,  // G#
  329, // E
  415,   // G#
  415,   // G#
  329, // E
  415   // G#
};

int duracoes[] = {
  300,  // G#
  200,  // B
  250,  // G#
  200,  // B
  200,  // B
  300,  // F#
  250,  // A#
  250,  // F#
  250,   // G#
  250,  // E
  250,   // G#
  200,   // G#
  250,   // E
  250   // G#
};

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Tocar cada nota
  for (int i = 0; i < 15; i++) {
    tone(buzzerPin, notas[i]);  // Toca a nota
    delay(duracoes[i]);         // Espera a duração da nota
    noTone(buzzerPin);          // Para o som
    delay(50);                  // Pequena pausa entre as notas
  }
  
  delay(300);
}
