// Definição dos pinos do sensor
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

// Variáveis para armazenar a frequência de cada cor
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

void setup() {
  // Configurando os pinos de controle como saída
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  // Pino de saída do sensor como entrada
  pinMode(sensorOut, INPUT);

  // Configurando a escala de frequência do sensor (20%)
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  // Iniciando comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Lê vermelho
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  redFrequency = pulseIn(sensorOut, LOW);
  delay(100);

  // Lê verde
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);
  delay(100);

  // Lê azul
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blueFrequency = pulseIn(sensorOut, LOW);
  delay(100);

  // Mostra os valores
  Serial.print("R = ");
  Serial.print(redFrequency);
  Serial.print(" G = ");
  Serial.print(greenFrequency);
  Serial.print(" B = ");
  Serial.print(blueFrequency);

  // Identifica e exibe a cor
  String corDetectada = detectColor(redFrequency, greenFrequency, blueFrequency);
  Serial.print(" => Cor detectada: ");
  Serial.println(corDetectada);

  delay(500); // Pequeno delay antes da próxima leitura
}

// Função para detectar a cor predominante
String detectColor(int r, int g, int b) {
  if (r < g && r < b) {
    return "Vermelho";
  } else if (g < r && g < b) {
    return "Verde";
  } else if (b < r && b < g) {
    return "Azul";
  } else {
    return "Indefinido";
  }
}
