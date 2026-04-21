#define DELAY 20
#define MIN_RAW 0
#define MAX_RAW 1023
#define MIN_CMD 0
#define MAX_CMD 200

const int sensorPin = A0;
const int ledPin = 12;

int sensorVal;
int cmd;

void setup() {
  Serial.begin(9600);       // Inicializa a comunicação serial
  pinMode(ledPin, OUTPUT);  // Define o pino do LED como saída
}

void loop() {
  sensorVal = analogRead(sensorPin);        // Lê o valor analógico do sensor
  cmd = sensorToLed(sensorVal);            // Mapeia o valor lido para o comando do LED
  analogWrite(ledPin, cmd);                // Aplica o valor de PWM ao LED
  delay(DELAY);                            // Aguarda o intervalo de 20 ms

  // Exibe os valores no monitor serial
  Serial.print("Sensor: ");
  Serial.println(sensorVal);
  Serial.print("Command: ");
  Serial.println(cmd);
}

// Função que mapeia o valor do sensor para o comando PWM
int sensorToLed(int raw) {
  int val = map(raw, MIN_RAW, MAX_RAW, MIN_CMD, MAX_CMD);  // Mapeia o valor
  val = max(val, MIN_CMD);                                // Garante o mínimo
  val = min(val, MAX_CMD);                                // Garante o máximo
  return val;
}
