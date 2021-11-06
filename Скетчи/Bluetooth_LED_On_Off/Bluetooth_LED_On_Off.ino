#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

//Обработка ошибки, в случае отключенного Bluetooth
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

char receivedChar;// Полученное значение (символ)

const char turnON = '1'; //Символ для включения светодиода
const char turnOFF = '0'; //Символ для отключения светодиода
#define LEDpin 23 //Пин светодиода 

void setup() {
  SerialBT.begin("ESP32"); //Имя устройства Bluetooth
  pinMode(LEDpin, OUTPUT);
}

void loop() {
  receivedChar = (char)SerialBT.read();

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    SerialBT.print("Received:");// Пишем "Received:" в приложении
    SerialBT.println(receivedChar);// Пишем полученное значение (для приложения)

    //Отправили "1"
    if (receivedChar == turnON)
    {
      SerialBT.println("LED ON:");// Пишем "LED ON:" в приложении
      digitalWrite(LEDpin, HIGH);// Включаем светодиод
    }
    
    //Отправили "0"
    if (receivedChar == turnOFF)
    {
      SerialBT.println("LED OFF:"); //Пишем "LED OFF:" в приложении
      digitalWrite(LEDpin, LOW); //Выключаем светодиод
    }
  }
  delay(20);
}
