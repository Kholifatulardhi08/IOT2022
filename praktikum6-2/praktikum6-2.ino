int led = 16; //pin D0
#define triggerPin D1
#define echoPin D2

void setup() {
   Serial.begin (115200);
   pinMode(triggerPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(BUILTIN_LED, OUTPUT);
   pinMode(led, OUTPUT);
}

void loop() {
   long duration, jarak;
   digitalWrite(triggerPin, LOW);
   delayMicroseconds(2);
   digitalWrite(triggerPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(triggerPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   jarak = duration * 0.034 / 2;
   Serial.print(jarak);
   Serial.println(" cm");
   
}
