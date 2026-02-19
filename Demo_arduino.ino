const int PULSANTE = 4;
const int LEDR = 9;
const int LEDG = 10;
const int LEDV = 11;

bool statoPrecedente = HIGH;
bool iniziato = false;
String colore = "";

void setup() {
  Serial.begin(9600);
  pinMode(PULSANTE, INPUT_PULLUP);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDV, OUTPUT);
}

void loop() {
  bool r = digitalRead(PULSANTE);
  if(iniziato == false && digitalRead(LEDR) == 0 && digitalRead(LEDG) == 0 && digitalRead(LEDV) == 0){
    digitalWrite(LEDR, HIGH);
    colore = "Rosso";
    Serial.println(colore);
  }
  if(statoPrecedente == 1 && r == 0 && digitalRead(LEDR) == 1 && digitalRead(LEDG) == 0 && digitalRead(LEDV) == 0){
    digitalWrite(LEDV, HIGH);
    iniziato = true;
    colore = "Verde";
    Serial.println(colore);
    delay(10);
    digitalWrite(LEDR, LOW);
    delay(100);
  } else if(statoPrecedente == 1 && r == 0 && digitalRead(LEDR) == 0 && digitalRead(LEDG) == 0 && digitalRead(LEDV) == 1){
    digitalWrite(LEDG, HIGH);
    colore = "Giallo";
    Serial.println(colore);
    delay(10);
    digitalWrite(LEDV, LOW);
    delay(100);
  } else if(statoPrecedente == 1 && r == 0 && digitalRead(LEDR) == 0 && digitalRead(LEDG) == 1 && digitalRead(LEDV) == 0){
    digitalWrite(LEDR, HIGH);
    colore = "Rosso";
    Serial.println(colore);
    delay(10);
    digitalWrite(LEDG, LOW);
    delay(100);
  }
  Serial.println(r);
  statoPrecedente = r;
}
