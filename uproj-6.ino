#define POTPIN A0
#define CWPIN 3
#define CCWPIN 4

short newRead, lastRead, difference;

void setup() {
  // put your setup code here, to run once:
  pinMode(POTPIN, INPUT);
  pinMode(CWPIN, OUTPUT);
  pinMode(CCWPIN, OUTPUT);
  Serial.begin(9600);
  lastRead = analogRead(POTPIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  newRead = analogRead(POTPIN);
  Serial.println(newRead);
  difference = newRead - lastRead;
  if (difference > 5) {
    Serial.println("Turn Counter-Clockwise");
    digitalWrite(CCWPIN, HIGH);
  } else if (difference < -5) {
    Serial.println("Turn Clockwise");
    digitalWrite(CWPIN, HIGH);
  }
  delay(500);
  digitalWrite(CCWPIN, LOW);
  digitalWrite(CWPIN, LOW);
  lastRead = newRead;
}
