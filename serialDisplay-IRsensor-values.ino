int l, c1, c2, c3, r;
void setup()
{
  Serial.begin(115200);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  l = digitalRead(6);
  c1 = digitalRead(7);
  c2 = digitalRead(8);
  c3 = digitalRead(10);
  r = digitalRead(11); // put your setup code here, to run once:

}

void loop()
{
 { l = digitalRead(6);
  c1 = digitalRead(7);
  c2 = digitalRead(8);
  c3 = digitalRead(10);
  r = digitalRead(11);
  // put your main code here, to run repeatedly:
  Serial.print(l);
  Serial.print("-");
  Serial.print(c1);
  Serial.print("-");
  Serial.print(c2);
  Serial.print("-");
  Serial.print(c3);
  Serial.print("-");
  Serial.println(r);}
  delay(500);
}
