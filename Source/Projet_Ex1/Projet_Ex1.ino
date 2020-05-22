const int ButtonStart = 2;
const int ButtonStop = 3;

const int a = 4;
const int b = 5;
const int c = 6;
const int d = 7;
const int e = 8;
const int f = 9;
const int g = 10;
const int h = 11;
const int i = 12;
const int j = 13;

int ButtonStartState = 0;
int ButtonStopState = 0;

int cpt = 0;

void setup() {
pinMode(a, OUTPUT);
pinMode(b, OUTPUT);
pinMode(c, OUTPUT);
pinMode(d, OUTPUT);
pinMode(e, OUTPUT);
pinMode(f, OUTPUT);
pinMode(g, OUTPUT);
pinMode(h, OUTPUT);
pinMode(i, OUTPUT);
pinMode(j, OUTPUT);

pinMode(ButtonStart, INPUT);
pinMode(ButtonStop, INPUT);
}

void loop() {

 int ButtonStartState;
 int ButtonStopState;

 if( ButtonStartState = digitalRead(ButtonStart) == LOW)
 {
  cpt = 1;
 }
 
 if(cpt==1)
 {
    for(int coucou = 4 ; coucou<=13 ; coucou++)
    { 
      if(ButtonStopState = digitalRead(ButtonStop) == LOW)
      {
        int a = 0;
        digitalWrite(coucou,HIGH);
        while(a=digitalRead(ButtonStart) != LOW);
        digitalWrite(coucou, LOW);
      }
      
      digitalWrite(coucou, HIGH);
      delay(100);
      digitalWrite(coucou, LOW);
      
    }

   
    for(int coucou = 13; coucou>=4 ; coucou--)
    {
      if(ButtonStopState = digitalRead(ButtonStop) == LOW)
      {
        int a = 0;
        digitalWrite(coucou,HIGH);
        while(a=digitalRead(ButtonStart) != LOW);
        digitalWrite(coucou, LOW);
      }
      
      digitalWrite(coucou, HIGH);
      delay(100);
      digitalWrite(coucou, LOW);
    }  
}
}
