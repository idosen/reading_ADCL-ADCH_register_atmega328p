int test;
int test1;

void setup() {
  Serial.begin(9600);
  ADCSRA |= (1<<ADPS2) |  (1<<ADPS1) |  (1<<ADPS0);
  ADMUX  |= (1<<REFS0);
  ADMUX  |= (1<<ADLAR);
  ADCSRA |= (1<<ADEN);
}

void loop() {
  ADCSRA |=(1<<ADSC); //wait for conversion to finish
  delay(50);
  test= ADCL;
  test1= ADCH; 
  Serial.print("ADCL=");
  Serial.print(test);
  Serial.println();
  Serial.print("ADCH=");
  Serial.print(test1);
  Serial.println();
  delay(500);
}
