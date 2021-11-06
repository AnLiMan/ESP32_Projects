#define LED 1 //Пин встроенного светодиода

void setup() {
  pinMode(1, OUTPUT);
}

void loop() {
  digitalWrite(LED, !digitalRead(LED));   // Ключаем светодиод на на противоположное значение
  delay(1500);                       // ждём секунду
}
