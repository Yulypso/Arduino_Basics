void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}
 
void loop()
{
  for(int i=2; i<=4; i=(i+1)%3+3)
  {
    for(int lum = 0; lum < 255; lum++)
    {
      analogWrite(i, lum);
      delay(10);
    }

    for(int lum = 255; lum >= 0; lum--)
    {
      analogWrite(i, lum);
      delay(10);
    }

    delay(100);
  }
}
