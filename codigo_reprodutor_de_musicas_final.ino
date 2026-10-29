#include <LiquidCrystal.h>
// Biblioteca para guardar e ler dados da memoria flash
#include <avr/pgmspace.h>

// LCD 16x2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Botoes
const int botaoUP = A0;
const int botaoDOWN = A1;
const int botaoPLAY = A2;
const int botaoSTOP = A3;

// LED e Buzzer
const int ledVerde = 9;
const int ledVermelho = 10;
const int buzzer = 8;

// Frequencias das notas musicais
#define DO4  262
#define RE4  294
#define MI4  330
#define FA4  349
#define SOL4 392
#define LA4  440
#define SI4  494
#define DO5  523
#define RE5  587
#define MI5  659
#define FA5  698
#define SOL5 784
#define LA5  880

// Usar PROGMEM para armazenar na memoria flash
// Memoria flash 32KB :) | Memoria RAM 2KB :(

// Musica 1: Marcha Imperial
const uint16_t musica1[] PROGMEM = {
  LA4, LA4, LA4, FA4, DO5, LA4, FA4, DO5,
  LA4, 0, MI5, MI5, MI5, FA5, DO5, SOL4,
  FA4, DO5, LA4, 0, LA5, LA4, LA4, LA5,
  SOL5, FA5, MI5, RE5, MI5, 0, FA5, 0
};

// Musica 2: Ode a Alegria
const uint16_t musica2[] PROGMEM = {
  MI4, MI4, FA4, SOL4, SOL4, FA4, MI4, RE4,
  DO4, DO4, RE4, MI4, MI4, RE4, RE4, 0,
  MI4, MI4, FA4, SOL4, SOL4, FA4, MI4, RE4,
  DO4, DO4, RE4, MI4, RE4, DO4, DO4, 0
};

// Musica 3: Frere Jacques
const uint16_t musica3[] PROGMEM = {
  DO4, RE4, MI4, DO4, DO4, RE4, MI4, DO4,
  MI4, FA4, SOL4, MI4, FA4, SOL4, 0, 0,
  SOL4, LA4, SOL4, FA4, MI4, DO4, SOL4, LA4,
  SOL4, FA4, MI4, DO4, DO4, SOL4, DO4, 0
};

// Musica 4: Brilha Estrelinha
const uint16_t musica4[] PROGMEM = {
  DO4, DO4, SOL4, SOL4, LA4, LA4, SOL4, 0,
  FA4, FA4, MI4, MI4, RE4, RE4, DO4, 0,
  SOL4, SOL4, FA4, FA4, MI4, MI4, RE4, 0,
  SOL4, SOL4, FA4, FA4, MI4, MI4, RE4, 0
};

// Musica 5: Jingle Bells (trecho simplificado)
const uint16_t musica5[] PROGMEM = {
  MI4, MI4, MI4, 0, MI4, MI4, MI4, 0,
  MI4, SOL4, DO4, RE4, MI4, 0, 0, 0,
  FA4, FA4, FA4, FA4, FA4, MI4, MI4, MI4,
  MI4, RE4, RE4, MI4, RE4, 0, SOL4, 0
};

// Nomes das musicas
const char* nomes[] = {
  "Marcha Imperial",
  "Ode a Alegria",
  "Frere Jacques",
  "Brilha Estrelinha",
  "Jingle Bells"
};

// Quantidade de notas de cada musica
const int quantidades[] = {32, 32, 32, 32, 32};


// Estados do reprodutor
int musicaSelecionada = 0;
int indiceNota = 0;

bool reproduzindo = false;
bool pausada = false;

// Controle do tempo em long pq pode passar da capacidade em int
unsigned long tempoNota = 0;
const unsigned long duracaoNota = 240;

// Retorna o vetor da musica selecionada
// uint16_t pq nao vamos usar valores negativos de int msm
const uint16_t* obterMusica(int musica) {
  switch (musica) {
    case 0: return musica1;
    case 1: return musica2;
    case 2: return musica3;
    case 3: return musica4;
    default: return musica5;
  }
}

// Le uma nota da memoria Flash
// pgm_read_word(x) para ler da memoria flash no endereco (x)
uint16_t lerNota(int musica, int indice) {
  const uint16_t* notas = obterMusica(musica);
  return pgm_read_word(&notas[indice]);
}

// Desliga os LEDs
void apagarLEDs() {
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, LOW);
}

// Mostra o menu de selecao
void mostrarMenu() {
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Selecione musica");

  lcd.setCursor(0, 1);
  lcd.print(">");
  lcd.print(nomes[musicaSelecionada]);

  // Vermelho aceso quando nao esta tocando nada
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, HIGH);

  noTone(buzzer);
}


// Mostra a musica tocando
void mostrarReproducao() {
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Tocando:");

  lcd.setCursor(0, 1);
  lcd.print(nomes[musicaSelecionada]);

  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledVermelho, LOW);
}

// Mostra que a musica esta pausada
void mostrarPausa() {
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("PAUSADO:");

  lcd.setCursor(0, 1);
  lcd.print(nomes[musicaSelecionada]);

  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, HIGH);

  noTone(buzzer);
}

// Toca a nota atual
void tocarNotaAtual() {
  uint16_t frequencia = lerNota(musicaSelecionada, indiceNota);

  if (frequencia == 0) {
    noTone(buzzer);
  } else {
    tone(buzzer, frequencia);
  }
  tempoNota = millis();
}

// Inicia a musica selecionada
void iniciarMusica() {
  indiceNota = 0;
  reproduzindo = true;
  pausada = false;

  mostrarReproducao();
  tocarNotaAtual();
}

// Para a musica e retorna ao menu
void pararMusica() {
  noTone(buzzer);

  reproduzindo = false;
  pausada = false;
  indiceNota = 0;

  mostrarMenu();
}

// Aguarda o botao ser solto
void aguardarSoltar(int botao) {
  while (digitalRead(botao) == LOW) {
    delay(5);
  }
}

// Verifica os quatro botoes
void verificarBotoes() {

  // UP: musica anterior
  if (digitalRead(botaoUP) == LOW) {
    delay(30);
    if (digitalRead(botaoUP) == LOW) {
      aguardarSoltar(botaoUP);
      if (!reproduzindo) {
        musicaSelecionada--;
        if (musicaSelecionada < 0) {
          musicaSelecionada = 4;
        }
        mostrarMenu();
      }
    }
  }

  // DOWN: proxima musica
  if (digitalRead(botaoDOWN) == LOW) {
    delay(30);
    if (digitalRead(botaoDOWN) == LOW) {
      aguardarSoltar(botaoDOWN);
      if (!reproduzindo) {
        musicaSelecionada++;
        if (musicaSelecionada > 4) {
          musicaSelecionada = 0;
        }
        mostrarMenu();
      }
    }
  }

  // PLAY: iniciar, pausar ou retomar
  if (digitalRead(botaoPLAY) == LOW) {
    delay(30);
    if (digitalRead(botaoPLAY) == LOW) {
      aguardarSoltar(botaoPLAY);
      if (!reproduzindo) {
        iniciarMusica();
      } else if (!pausada) {
        pausada = true;
        mostrarPausa();
      } else {
        pausada = false;
        mostrarReproducao();

        // Retoma a nota atual
        tocarNotaAtual();
      }
    }
  }

  // STOP: interromper e voltar ao menu
  if (digitalRead(botaoSTOP) == LOW) {
    delay(30);

    if (digitalRead(botaoSTOP) == LOW) {
      aguardarSoltar(botaoSTOP);
      pararMusica();
    }
  }
}

void setup() {
  pinMode(botaoUP, INPUT_PULLUP);
  pinMode(botaoDOWN, INPUT_PULLUP);
  pinMode(botaoPLAY, INPUT_PULLUP);
  pinMode(botaoSTOP, INPUT_PULLUP);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("Reprodutor");
  lcd.setCursor(0, 1);
  lcd.print("de musicas");

  apagarLEDs();
  noTone(buzzer);

  delay(1500);
  mostrarMenu();
}

void loop() {
  verificarBotoes();
  // Reproduz as notas sem bloquear o programa
  if (reproduzindo && !pausada) {
    if (millis() - tempoNota >= duracaoNota) {
      noTone(buzzer);
      indiceNota++;
      // Verifica se a musica terminou
      if (indiceNota >= quantidades[musicaSelecionada]) {
        pararMusica();
      } else {
        tocarNotaAtual();
      }
    }
  }
}
