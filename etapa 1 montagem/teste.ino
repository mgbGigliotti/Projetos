
#include <LiquidCrystal.h>

// LCD 16x2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Botoes
const int botaoUP = A0;
const int botaoDOWN = A1;
const int botaoPLAY = A2;
const int botaoSTOP = A3;

// LEDs e Buzzer
const int ledVerde = 9;
const int ledVermelho = 10;
const int buzzer = 8;

void setup() {

  // Configuracao dos botoes
  pinMode(botaoUP, INPUT_PULLUP);
  pinMode(botaoDOWN, INPUT_PULLUP);
  pinMode(botaoPLAY, INPUT_PULLUP);
  pinMode(botaoSTOP, INPUT_PULLUP);

  // Configuracao dos LEDs
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  // LCD
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("Projeto CCP020");

  lcd.setCursor(0, 1);
  lcd.print("Teste inicial");

  // Teste LED verde
  digitalWrite(ledVerde, HIGH);
  delay(1000);
  digitalWrite(ledVerde, LOW);

  // Teste LED vermelho
  digitalWrite(ledVermelho, HIGH);
  delay(1000);
  digitalWrite(ledVermelho, LOW);

  // Teste do buzzer (som curto)
  tone(buzzer, 700, 150);
  delay(200);
  noTone(buzzer);

  lcd.clear();
  lcd.print("Pressione botao");
}

void loop() {

  if (digitalRead(botaoUP) == LOW) {
    testarBotao("UP", 523);
  }

  else if (digitalRead(botaoDOWN) == LOW) {
    testarBotao("DOWN", 587);
  }

  else if (digitalRead(botaoPLAY) == LOW) {
    testarBotao("PLAY/PAUSE", 659);
  }

  else if (digitalRead(botaoSTOP) == LOW) {
    testarBotao("STOP", 698);
  }
}

void testarBotao(const char* nome, int nota) {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Botao detectado");

  lcd.setCursor(0, 1);
  lcd.print(nome);

  // Liga LED verde
  digitalWrite(ledVerde, HIGH);

  // Som curto
  tone(buzzer, nota, 100);
  delay(150);
  noTone(buzzer);

  digitalWrite(ledVerde, LOW);

  // Liga LED vermelho
  digitalWrite(ledVermelho, HIGH);
  delay(250);
  digitalWrite(ledVermelho, LOW);

  delay(200);

  lcd.clear();
  lcd.print("Pressione botao");
}
