#include <Wire.h>                   // Memanggil library wire.h
#include <LiquidCrystal_I2C.h>      // Memanggil library LCD dengan I2C
LiquidCrystal_I2C lcd(0x27, 16, 2); // Alamat I2C(0x27) LCD dan Jenis LCD (20x4)
 
#define echoPin D5 //Deklarasi echo terhubung pada pin D5 HC-SR04
#define trigPin D6 //Deklarasi trig terhubung pada pin D6 HC-SR04
#define led D7     //Deklarasi LED terhubung pada pin D7
 
// defines variables
long durasi; // variabel durasi suara
int jarak;   // variabel untuk mengukur jarak
 
void setup() {
  lcd.init();               // instruksi untuk memulai LCD
  lcd.begin(16,2);          // instruksi untuk menggunakan lcd 20x4
  lcd.backlight();          // instruksi untuk mengaktifkan lampu latar LCD
  pinMode(trigPin, OUTPUT); // deklarasi pin trig sebagai output
  pinMode(echoPin, INPUT);  // deklarasi pin echo sebagai input
  pinMode(led, OUTPUT);     // deklarasi LED sebagai output
  Serial.begin(115200);       // komunikasi serial menggunakan baudrate 9600
}
 
void loop() { 
  digitalWrite(trigPin, LOW);  // Trig tidak aktif
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Trig aktif
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Membaca sinyal masuk pada echo
  durasi = pulseIn(echoPin, HIGH);
  // Menghitung Jarak
  jarak = durasi * 0.034 / 2;     // Rumus menghitung jarak ultrasonik
  lcd.setCursor(2, 0);            // karakter dimulai dari kolom 2 baris 1
  lcd.setCursor(4, 1);            // karakter dimulai dari kolom 4 baris 2
  lcd.print("NodeMcu");           // Karakter yang akan ditampilkan pada LCD
  lcd.setCursor(0,2);             // karakter dimulai dari kolom 1 baris 3
  lcd.print("Distance:");         // Karakter yang akan ditampilkan pada LCD
  lcd.print(jarak);               // Menampilkan data jarak pada LCD
  lcd.print("   cm");
  delay(10);
 
  if (jarak < 5){                 // instruksi untuk mengaktifkan LED jika jarak benda kurang dari 5 cm
    digitalWrite(led, HIGH);
    lcd.setCursor(0,3);
    lcd.print("LED ON ");
  }
  else {
    digitalWrite(led, LOW);      // instruksi untuk mematikan LED jika jarak benda lebih dari 5 cm
    lcd.setCursor(0,3);
    lcd.print("LED OFF");
  }
    delay(500);
}
