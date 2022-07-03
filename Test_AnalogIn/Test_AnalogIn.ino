#define LOW_PASS_FILTER(x0, x1) ((double)(x0)*0.85+(double)(x1)*0.15)
#define ANALOG_INPUT 13

int buff = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int s1 = analogRead(ANALOG_INPUT);
  buff = LOW_PASS_FILTER(buff,s1);
  //Serial.printf("S1: %4d, Vin: %6.4f\n\r", s1, (double)s1 * 3.3 / 4092.0, 3);
  Serial.println(buff);//LPFを通したADコンバータの値
  //Serial.println((double)s1 * 3.3 / 4092.0);//電圧
  //Serial.println(s1);//ADコンバータの値
  delay(100);
}
