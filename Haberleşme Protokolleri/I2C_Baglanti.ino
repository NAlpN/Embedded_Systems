// I2C, aynı veri hattı üzerinde birden fazla cihazın haberleşmesini sağlar.
// Çoklu cihaz desteği, 7-bit adresleme. Tek veri hattı (SDA & SCL) ile çok sayıda cihaz bağlanabilir.

// Örneğin. I2C protokolü kullanılarak 0x3C adresine sahip bir cihazla iletişim kurmak için
#include <Wire.h>

void setup(){
    wire.begin();
    Serial.begin(9600);
}

void loop(){
    Wire.beginTransmission(0x3C);
    Wire.write("Hello!");
    Wire.endTransmission();
    delay(1000);
}