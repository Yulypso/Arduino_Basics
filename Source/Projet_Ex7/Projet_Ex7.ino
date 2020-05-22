int motorPin1 = 2;  
int motorPin2 = 3;    
int enablePin1 = 0;   

int motorPin3 = 4;   
int motorPin4 = 5;  
int enablePin2 = 1;  

int Echo1 = A0;
int Trig1 = A1;
int Echo2 = A2;
int Trig2 = A3;

int distance = 0;


int Distance_test1() {
  //Lancement de l'impulsion
  digitalWrite(Trig1, HIGH);  
  delayMicroseconds(10);
  digitalWrite(Trig1, LOW);   
  float Fdistance1 = pulseIn(Echo1, HIGH); //permet de mesurer la pulsation
  Fdistance1= Fdistance1 / 58;       //permet de calculer la distance en cm
  return (int)Fdistance1;
}  

int Distance_test2() {
  //Lancement de l'impulsion
  digitalWrite(Trig2, HIGH);  
  delayMicroseconds(10);
  digitalWrite(Trig2, LOW);   
  float Fdistance2 = pulseIn(Echo2, HIGH);  
  Fdistance2= Fdistance2 / 58;       
  return (int)Fdistance2;
}  

void stop() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  Serial.println("Stop!");
} 

void right() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  Serial.println("Right");
}

void left() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  Serial.println("Left");
}

void forward() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  Serial.println("Forward");
}

void backward() {
  digitalWrite(motorPin1, LOW);   
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW); 
  digitalWrite(motorPin4, HIGH);
  Serial.println("Backward");
}

void setup() {
  //set all the other pins you're using as outputs:
  pinMode(Echo1, INPUT);
  pinMode(Echo2, INPUT);
  pinMode(Trig1, OUTPUT);  
  pinMode(Trig2, OUTPUT);  
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enablePin1, OUTPUT);
  
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(enablePin2, OUTPUT);

  //Mettre la broche Enable a high comme ca le moteur tourne
  digitalWrite(enablePin1, HIGH);
  digitalWrite(enablePin2, HIGH);
}

void loop() {

distance = Distance_test1();

if(distance <= 20) {
  stop();
  delay(500);
  backward();
  delay(250);
  right();
  delay(100);
}
else
{
  forward();
  delay(500);
}

distance = Distance_test2();

if(distance <= 20) {
  stop();
  delay(500);
  backward();
  delay(250);
  left();
  delay(100);
}
else{
  forward();
  delay(500);
}
}
