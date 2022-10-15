#define LOW_PASS_FILTER(x0, x1) ((double)(x0)*0.85+(double)(x1)*0.15)
#define ARRAY_LEN(x) (sizeof((x))/sizeof((x)[0]))

int pins[]={13};
int buff[ARRAY_LEN(pins)] = {0};

void setup() {
  Serial.begin(115200);
}

void loop() {
  for(int i=0; i<ARRAY_LEN(pins); i++){
    int s = analogRead(pins[i]);
    buff[i] = LOW_PASS_FILTER(buff[i],s);
    Serial.println(buff[i]);//LPFを通したADコンバータの値
  }
  delay(100);
}
