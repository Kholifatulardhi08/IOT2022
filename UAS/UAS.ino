#define BLYNK_TEMPLATE_ID "TMPL-6Ktt_cJ"
#define BLYNK_DEVICE_NAME "UAS"
#define BLYNK_AUTH_TOKEN "r0r0m1UTmnw7DVR_5SJKTvSQhU5R3buj"
#define BLYNK_PRINT Serial
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 16, 2);

#define echoPin D5 //Deklarasi echo terhubung pada pin D5 HC-SR04
#define trigPin D6 //Deklarasi trig terhubung pada pin D6 HC-SR04
#define led 0     //Deklarasi LED terhubung pada pin D3

// defines variables
long durasi; // variabel durasi suara
int jarak;   // variabel untuk mengukur jarak
WidgetLCD LCD(V1);

char auth[] = BLYNK_AUTH_TOKEN;
char id[] = "ARDLITIRTA";
char pass[] = "budisuriah123";

void setup() {
  lcd.init();               // instruksi untuk memulai LCD        // instruksi untuk menggunakan lcd 20x4
  lcd.backlight();
  Blynk.begin(auth, id, pass); // instruksi untuk mengaktifkan lampu latar LCD
  pinMode(trigPin, OUTPUT); // deklarasi pin trig sebagai output
  pinMode(echoPin, INPUT);  // deklarasi pin echo sebagai input
  pinMode(led, OUTPUT);     // deklarasi LED sebagai output
  Serial.begin(9600);       // komunikasi serial menggunakan baudrate 9600
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
  lcd.setCursor(0, 0);            // karakter dimulai dari kolom 2 baris
  lcd.print("Distance: ");
  lcd.setCursor(0, 1);                               // Karakter yang akan ditampilkan pada LCD
  lcd.print(jarak);               // Menampilkan data jarak pada LCD
  lcd.print("   cm");
  delay(1000);
  if (jarak < 5) {                // instruksi untuk mengaktifkan LED jika jarak benda kurang dari 5 cm
    digitalWrite(led, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("LED ON ");
    LCD.print (0, 1, "BAHAYA");
  }
  else {
    digitalWrite(led, LOW);      // instruksi untuk mematikan LED jika jarak benda lebih dari 5 cm
    lcd.setCursor(0, 1);
    lcd.print("LED OFF");
    LCD.print (0, 0, " Jarak Aman");
    LCD.print (0, 1, "AMAN");
  }
  Blynk.run();
  delay(1000);
}
