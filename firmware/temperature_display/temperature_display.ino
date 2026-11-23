#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 5        // sensor DATA on PD5 = Arduino pin 5
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);   // address may be 0x3F

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  lcd.clear();
  if (isnan(t) || isnan(h)) {
    lcd.print("Sensor error");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(t, 1);
    lcd.print(" C");
    lcd.setCursor(0, 1);
    lcd.print("Hum:  ");
    lcd.print(h, 0);
    lcd.print(" %");
  }
  delay(2000);
}