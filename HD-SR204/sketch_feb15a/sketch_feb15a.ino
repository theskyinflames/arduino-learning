int TRIG=10;
int ECHO=9;
int LED=3;
int BUZZ=2;
int DURATION;
int DISTANCE;


void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZ, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURATION = pulseIn(ECHO, HIGH);
  DISTANCE = DURATION / 58.2; // DISTANCE IN SECONDS FOR HC-SR04 SENSOR
  
  Serial.println(DISTANCE);
  delay(200);
  if (DISTANCE<=20 && DISTANCE>=0){
    digitalWrite(LED, HIGH);
    tone(BUZZ, 1000);
    delay(DISTANCE * 50);
    digitalWrite(LED, LOW);
    noTone(BUZZ);
  }
}
