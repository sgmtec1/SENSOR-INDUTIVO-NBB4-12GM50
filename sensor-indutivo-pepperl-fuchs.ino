// Open Source
// ligação do display SDA = A4 , SLC= A5, GND, VCC;
// ligação do Sensor pino 13 sinal (Preto) VCC= + (Marrom) GND= - (Azul)

#include <Wire.h> //INCLUSÃO DE BIBLIOTECA
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE); //ENDEREÇO DO I2C E DEMAIS INFORMAÇÕES

int sinal=6;
const int LedVermelho = 8;
const int LedVerde = 7;
int sensor;
int i = 0;
int conta=0;

void setup() {

lcd.begin(16, 2);
pinMode (sinal,INPUT);
pinMode (LedVermelho,OUTPUT);
pinMode (LedVerde,OUTPUT);
}

void loop() {
  
lcd.setCursor(0,0);
lcd.print("POSICAO DA PECA");
lcd.setCursor(0, 1);
lcd.print("PECA ");


sensor = digitalRead(sinal);  

while (sensor == LOW)
{
sensor = digitalRead(sinal);
digitalWrite(LedVermelho, HIGH);
digitalWrite(LedVerde, LOW);
lcd.setCursor(6, 1);
lcd.print("NAO ENCONTRADA");
}
 

while (sensor == HIGH)
{
sensor = digitalRead(sinal);
digitalWrite(LedVermelho, LOW);
digitalWrite(LedVerde, HIGH);
lcd.setCursor(6, 1);
lcd.print("ENCONTRADA");
}

}
