const int ledIR = 3;
const int pinRecepteur = 2;

// Pins des 4 LEDs
const int led1 = 5;
const int led2 = 6;
const int led3 = 7;
const int led4 = 8;

void setup() {
  pinMode(ledIR, OUTPUT);
  pinMode(pinRecepteur, INPUT);

  // Configuration des LEDs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  envoyerSignal38kHz(); // envoie un signal IR modulé
  int etat = digitalRead(pinRecepteur);

  if (etat == LOW) {
    Serial.println("🔔 Présence détectée !");
    allumerLEDs();
  } else {
    Serial.println("Aucune présence.");
    eteindreLEDs();
  } delay(200);  // Pause pour éviter les rebonds
}// Fonction pour simuler un signal 38kHz pendant un court moment
void envoyerSignal38kHz() {
  for (int i = 0; i < 100; i++) {
    digitalWrite(ledIR, HIGH);
    delayMicroseconds(18);  // Fréquence réduite (~27kHz)
    digitalWrite(ledIR, LOW);
    delayMicroseconds(18);
  }}// Allumer les 4 LEDs
void allumerLEDs() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
}// Éteindre les 4 LEDs
void eteindreLEDs() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}
