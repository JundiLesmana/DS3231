#include<Wire.h>
//#include <LiquidCrystal_I2C.h> // libray lcd
//LiquidCrystal_I2C lcd(0x27, 16, 2);

#include "RTClib.h" //library DS3231
RTC_DS3231 rtc;
 // Pin relay 1 terhubung ke pin 5
/*const int relay2Pin = D4;  // Pin relay 2 terhubung ke pin 6
const int relay3Pin = D5;  // Pin relay 3 terhubung ke pin 7
const int relay4Pin = D6;  // Pin relay 4 terhubung ke pin 8
*/
char dataHari[7][12] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
String hari;
int tanggal, bulan, tahun, jam, menit, detik;
float suhu;
const int relay1Pin = D3; 
const int relay2Pin = D4;
const int relay3Pin = D5;
const int relay4Pin = D6;


void setup () {
  Serial.begin(9600);
  //lcd.begin();
  //untuk set waktu
  /*if (! rtc.begin()) {
    Serial.println("RTC Tidak Ditemukan");
    Serial.flush();
    abort();
   */
   //utk perintah
   rtc.begin();
    pinMode(relay1Pin,OUTPUT);
    pinMode(relay2Pin,OUTPUT);
    pinMode(relay3Pin,OUTPUT);
    pinMode(relay4Pin,OUTPUT);
    digitalWrite(relay1Pin,HIGH);
    digitalWrite(relay2Pin,HIGH);
    digitalWrite(relay3Pin,HIGH);
    digitalWrite(relay4Pin,HIGH);
  }

  //Atur Waktu, upload untuk set waktu, kemudian beri komentar lalu upload kembali
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //rtc.adjust(DateTime(2023,6,24,0,39,0));
//}

void loop () {
  DateTime now = rtc.now();
  hari    = dataHari[now.dayOfTheWeek()];
  tanggal = now.day();
  bulan   = now.month();
  tahun   = now.year();
  jam     = now.hour();
  menit   = now.minute();
  detik   = now.second();
  suhu    = rtc.getTemperature();
  //lcd.setCursor(0,0);
  //lcd.print(String() +hari+"," +tanggal+"-"+bulan+"-"+tahun);
  //lcd.setCursor(0,1);
  //lcd.print(String() +jam+":" +menit+":"+detik+" " +suhu+".C ");

if((jam==18)&&(jam<=6)){
  digitalWrite(relay1Pin, LOW); 
  digitalWrite(relay2Pin, LOW);
  digitalWrite(relay3Pin, LOW);
  digitalWrite(relay4Pin, LOW);
  Serial.println("nyala");
}
else
{ 
digitalWrite(relay1Pin, HIGH);
digitalWrite(relay2Pin, HIGH);
digitalWrite(relay3Pin, HIGH);
digitalWrite(relay4Pin, HIGH);
Serial.println(now.minute()) ;
Serial.println(now.hour()) ;
}
delay(1000);

/*if((jam==18)&&(jam<=6)){
  digitalWrite(relay1Pin, LOW); 
  digitalWrite(relay2Pin, LOW);
  digitalWrite(relay3Pin, LOW);
  digitalWrite(relay4Pin, LOW);
  Serial.println("nyala");
}
else
{ 
digitalWrite(relay1Pin, HIGH);
digitalWrite(relay2Pin, HIGH);
digitalWrite(relay3Pin, HIGH);
digitalWrite(relay4Pin, HIGH);
Serial.println(now.minute()) ;
Serial.println(now.hour()) ;
}
delay(1000);
/*
if(jam == 0 & menit == 15 ){
digitalWrite(relay1Pin, LOW);}
else digitalWrite(relay1Pin, HIGH);
Serial.println(now.minute()) ;
Serial.println(now.hour()) ;
*/
}
