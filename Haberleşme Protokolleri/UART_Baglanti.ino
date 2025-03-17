// UART, seri haberleşme sağlayan bir protokoldür. Her iki cihazın aynı baud hızında ayarlanması gerekir.
// Asenkron, düşük hızlı seri haberleşme. Başlangıç ve durdurma bitleri kullanır, tek bir cihazla iletişim için uygundur.

//UART ile mesaj göndermek için.
void setup(){
    Serial.begin(9600);
}

void loop(){
    Serial.println("1. Cihazın mesajı!");
    delay(1000);
}

//UART ile bir mesaj almak için.
void setup(){
    Serial.begin(9600);
}

void loop(){
    if(Serial.available()){
        String mesaj = Serial.readString();
        Serial.print("Gelen Mesaj:");
        Serial.print(mesaj);
    }
}