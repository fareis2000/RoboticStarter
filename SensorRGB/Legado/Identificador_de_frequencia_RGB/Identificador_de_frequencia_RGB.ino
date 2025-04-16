// Criando as variáveis do sensor
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

// Aos finais da variável da concentração de led
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

void setup() {
  // Dizendo que todas as variáveis são saida
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  // Dizendo que o sensor tem uma saida
  pinMode(sensorOut, INPUT);
  
  // Frequência  em 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
   // Iniciando comunicação 
  Serial.begin(9600);
}
void loop() {
  // Setando para ler o vermelho
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  // Lendo a frequência
  redFrequency = pulseIn(sensorOut, LOW);
  
   // Mostrando o valor de R
  Serial.print("R = ");
  Serial.print(redFrequency);
  delay(100);
  
  // Setando o verde para poder ser lido
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // lendo a frequência verde
  greenFrequency = pulseIn(sensorOut, LOW);
  
  // Printando o verde  
  Serial.print(" G = ");
  Serial.print(greenFrequency);
  delay(100);
  // Setando o azul
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Lendo os valores
  blueFrequency = pulseIn(sensorOut, LOW);
  // Mostrando os valores 
  Serial.print(" B = ");
  Serial.println(blueFrequency);
  delay(100);
}