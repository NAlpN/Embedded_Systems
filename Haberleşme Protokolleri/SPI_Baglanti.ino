// SPI, yüksek hızlı veri aktarımı sağlar ve genellikle SD kartlar, LCD’ler ile kullanılır.
// Senkron, yüksek hızlı haberleşme. Master-Slave yapısı, çok hızlıdır ama daha fazla kablo gerektirir.

#include <SPI.h>

void setup(){
    SPI.begin();
}

void loop()(){
    digitalWrite(SS, LOW);
    SPI.transfer(0xFF);
    digitalWrite(SS, HIGH);
    delay(1000);
}