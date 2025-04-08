#define velociade 100


// váriaveis do carrinho e sensores
int trigPin = 9;
int echoPin = 10;
int revright = 3;
int fwdright= 5;     
int fwdleft = 11;      
int revleft= 6;       
int c = 0;

void setup() {
  // Agora vamos setar os pinos do carrinho e do sensor 
  Serial.begin(9600); 
  pinMode(fwdright, OUTPUT);
  pinMode(revleft, OUTPUT);
  pinMode(revright, OUTPUT);
  pinMode(fwdleft, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  // Vamos calcular a distância que o carrinho está enchergando
  // Váriaveis de distancia e duração
  long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  // pegando a distância
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);  
  // Se a distancia for maior que 20cm ela vai andar reto
  // se não ele irá virar
  if(distance>20)
    {
      analogWrite(5,velociade);                               
      digitalWrite(3,LOW);                             
      digitalWrite(6,LOW);                              
      analogWrite(11,velociade);                            
    }
  else if(distance<20)  
    {
      analogWrite(5,velociade);
      digitalWrite(3,LOW);
      analogWrite(6,velociade);                                  
      digitalWrite(11,LOW);                                           
  }
}