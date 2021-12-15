#define LedPin 13 // Пин светодиода
#define ButtPin 14 //Прин кнопки

bool flag1 = false; //Флаг нажатия кнопки 1

void setup() {
  pinMode(LedPin, OUTPUT);
  digitalWrite(LedPin, LOW);
  Serial.begin(115200);
}

void loop() {
  bool btn1State = digitalRead(ButtPin);

  //Если нажали кнопку
  if (btn1State && !flag1)
  {
    Serial.println("Butt press");
    flag1 = true;
    digitalWrite(LedPin, HIGH);
  }
  
  //Если отпустили кнопку
  if (!btn1State && flag1)
  {
    Serial.println("Butt realise");
    flag1 = false;
    digitalWrite(LedPin, LOW);
  }
}
