const int a = 2;
const int b = 3;

const int AND = 13;
const int OR = 12;
const int NOR = 11;
const int NAND = 10;
const int XOR = 9;
const int NXOR = 8;

void setup() 
{
pinMode(a, INPUT);
pinMode(b, INPUT);

pinMode(AND, OUTPUT);
pinMode(OR, OUTPUT);
pinMode(NOR, OUTPUT);
pinMode(NAND, OUTPUT);
pinMode(XOR, OUTPUT);
pinMode(NXOR, OUTPUT);
}

void loop()
{
  int read_a, read_b;
  
  if((read_a = digitalRead(a) == LOW) && (read_b = digitalRead(b) == LOW))
  {
    digitalWrite(AND, HIGH);
  }
  else
  {
    digitalWrite(AND, LOW);
  }

  if(((read_a = digitalRead(a) == LOW) && (read_b = digitalRead(b) == HIGH)) 
  || ((read_a = digitalRead(a) == HIGH) && (read_b = digitalRead(b) == LOW)) 
  || ((read_a = digitalRead(a) == LOW) && (read_b = digitalRead(b) == LOW)))
  {
    digitalWrite(OR, HIGH);
  }
  else
  {
    digitalWrite(OR, LOW);
  }

  if((read_a = digitalRead(a) == HIGH) && (read_b = digitalRead(b) == HIGH))
  {
    digitalWrite(NOR, HIGH);
  }
  else
  {
    digitalWrite(NOR, LOW);
  }
 

  if(((read_a = digitalRead(a) == HIGH) && (read_b = digitalRead(b) == HIGH)) 
  || ((read_a = digitalRead(a) == HIGH) && (read_b = digitalRead(b) == LOW)) 
  || ((read_a = digitalRead(a) == LOW) && (read_b = digitalRead(b) == HIGH)))
  {
    digitalWrite(NAND, HIGH);
  }
  else
  {
    digitalWrite(NAND, LOW);
  }

  if(((read_a = digitalRead(a) == LOW) && (read_b = digitalRead(b) == HIGH)) 
  || ((read_a = digitalRead(a) == HIGH )&& (read_b = digitalRead(b) == LOW)))
  {
    digitalWrite(XOR, HIGH);
  }
  else
  {
    digitalWrite(XOR, LOW);
  }

  if(((read_a = digitalRead(a) == HIGH) && (read_b = digitalRead(b) == HIGH)) 
  || ((read_a = digitalRead(a) == LOW) && (read_b = digitalRead(b) == LOW)))
  {
    digitalWrite(NXOR, HIGH);
  }
  else
  {
    digitalWrite(NXOR, LOW);
  }
}
