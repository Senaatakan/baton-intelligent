int trig = 2;
int echo = 3;
int buzzer = 11;
float sure;
float uzaklik;

void setup() {
  pinMode(trig, OUTPUT); //arduinodan sensöre
  pinMode(echo, INPUT);   //sensörden arduinoya
  pinMode(buzzer, OUTPUT);  //arduinodan sinyal çıkışı sağlar 
  Serial.begin(9600);
  Serial.println("Uzaklık");
}

void loop() {
  digitalWrite(trig,HIGH); //tetikleme pininden okuma yapabilmek için
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  sure = pulseIn(echo, HIGH); //echo pininden ölçülen değer 5V olduğunda bunu algılayıp süreye çevirir
  uzaklik = sure /58.2;   // süre değerini uzaklık değerine çevirmek için ses hızından yararlanılarak bulunan formül
  Serial.println(uzaklik);

  if (uzaklik <= 10) {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(90);
  }
  else if (uzaklik <= 20) {
    digitalWrite(buzzer, HIGH);
    delay(150);
    digitalWrite(buzzer, LOW);
    delay(100);
  }
  else if (uzaklik <= 30) {
    digitalWrite(buzzer, HIGH);
    delay(350);
    digitalWrite(buzzer, LOW);
    delay(250);
  }
  else if (uzaklik <= 40) {
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(450);
  }
 else if (uzaklik <= 50) {
    digitalWrite(buzzer, HIGH);
    delay(750);
    digitalWrite(buzzer, LOW);
    delay(650);
  }
  else {
  }
}
