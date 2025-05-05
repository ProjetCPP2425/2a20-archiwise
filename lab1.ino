#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Clavier
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Buffer de l’ID saisi
String enteredID = "";

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Entrez ID:");
  lcd.setCursor(0, 1);
}

void loop() {
  // Lecture des touches
  char key = keypad.getKey();

  if (key) {
    if (key == '#') {
      // Fin de saisie
      if (enteredID.length() > 0) {
        String message = "ID_COMPLET:" + enteredID;
        Serial.println(message); // Envoie l'ID complet à Qt
        lcd.clear();
        lcd.print("Verif ID...");
        enteredID = "";  // Réinitialiser l'ID saisi
      }
    } else if (key == '*') {
      // Reset de la saisie
      enteredID = "";
      lcd.clear();
      lcd.print("Entrez ID:");
      lcd.setCursor(0, 1);
    } else {
      // Ajouter chiffre
      if (enteredID.length() < 10) {
        enteredID += key;
        lcd.print(key);
      }
    }
  }

  // Réception depuis Qt
  if (Serial.available()) {
    String message = Serial.readStringUntil('\n');
    message.trim();
    
    // Eviter de vider l'écran trop souvent pour éviter le scintillement
    lcd.clear();

    if (message == "CONTRAT_EN_COURS") {
      lcd.print("Contrat actif");
    } else if (message == "CONTRAT_EXPIRE") {
      lcd.print("Contrat expire");
    } else if (message == "CONTRAT_NON_COMMENCE") {
      lcd.print("Pas encore actif");
    } else if (message == "INCONNU") {
      lcd.print("ID inconnu");
    } else {
      lcd.print("Rep inconnue");
    }

    delay(2000);  // Affichage pendant 2 secondes avant de réinitialiser
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Entrez ID:");
    lcd.setCursor(0, 1);
  }
}
