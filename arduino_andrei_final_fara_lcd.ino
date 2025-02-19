#include <SimpleDHT.h> // Include biblioteca pentru senzorul DHT11

// Pinul la care este conectat senzorul DHT11
int pinDHT11 = A0;
SimpleDHT11 dht11(pinDHT11);

// Pinii la care sunt conectate LED-urile
int ledVerde = A1;
int ledGalben = A2;
int ledRosu = A3;

void setup() {
  pinMode(ledVerde, OUTPUT); // Setează LED-ul verde ca ieșire
  pinMode(ledGalben, OUTPUT); // Setează LED-ul galben ca ieșire
  pinMode(ledRosu, OUTPUT); // Setează LED-ul roșu ca ieșire
  Serial.begin(9600); // Inițializează comunicația serială pentru afișarea datelor în consolă
}

void loop() {
  byte temperatura = 0;
  byte umiditate = 0;
  if (dht11.read(&temperatura, &umiditate, NULL)) {
    return;
  }

  // Afișează umiditatea și temperatura în consolă
  Serial.print("Umiditate: ");
  Serial.println(umiditate);
  Serial.print("Temperatura: ");
  Serial.println(temperatura);

  static byte lastUmiditate = 0;

  if (umiditate != lastUmiditate) {
    lastUmiditate = umiditate;

    if (umiditate >= 20 && umiditate <= 55) {
      digitalWrite(ledVerde, HIGH); // Aprinde LED-ul verde
      digitalWrite(ledGalben, LOW); // Stinge LED-ul galben
      digitalWrite(ledRosu, LOW); // Stinge LED-ul roșu
    } else if (umiditate > 55 && umiditate <= 60) {
      digitalWrite(ledVerde, LOW); // Stinge LED-ul verde
      digitalWrite(ledGalben, HIGH); // Aprinde LED-ul galben
      digitalWrite(ledRosu, LOW); // Stinge LED-ul roșu
    } else if (umiditate > 60 && umiditate <= 95) {
      digitalWrite(ledVerde, LOW); // Stinge LED-ul verde
      digitalWrite(ledGalben, LOW); // Stinge LED-ul galben
      digitalWrite(ledRosu, HIGH); // Aprinde LED-ul roșu
    }
  }
}
