Botões

Foram utilizados quatro botões conectados às entradas analógicas do Arduino, que serão usadas como entradas digitais.

| Botão | Pino |
|---|---|
| UP | A0 |
| DOWN | A1 |
| PLAY/PAUSE | A2 |
| STOP | A3 |

Todos os botões possuem uma ligação com o GND e utilizam INPUT_PULLUP no código.

LEDs

 LED verde  D9
 LED vermelho D10 

Cada LED utiliza um resistor de 220 Ω e possui o terminal negativo conectado ao GND.

O LED verde será utilizado para indicar quando a música estiver tocando, enquanto o vermelho indicará quando estiver pausada.

Buzzer

O terminal positivo do buzzer foi conectado ao pino D8 e o negativo ao GND.

Ele será responsável por reproduzir as notas das músicas.

Display LCD 16x2
Pino do LCD  Conexão 

GND | GND
VCC | 5V
VO | Potenciômetro 
RS | D12 
RW | GND 
E | D11 
DB4 | D5 
DB5 | D4 
DB6 | D3 
DB7 | D2 
LED+ | 5V com resistor de 220 Ω 
LED- | GND 

Os pinos DB0, DB1, DB2 e DB3 não foram utilizados.

Potenciômetro

Foi utilizado um potenciômetro de 10 kΩ para controlar o contraste do display.

As duas extremidades foram conectadas ao 5V e ao GND, enquanto o terminal central foi ligado ao pino VO do LCD.

Alimentação

O Arduino fornece 5V e GND para a protoboard, permitindo alimentar os componentes utilizados no circuito.