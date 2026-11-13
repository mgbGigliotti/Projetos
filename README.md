Reprodutor de Músicas com Arduino

Sobre o projeto

Este projeto consiste no desenvolvimento de um reprodutor de músicas utilizando um Arduino UNO. O sistema permite selecionar músicas por meio de botões, reproduzir melodias em um buzzer e acompanhar as informações pelo display LCD.

O desenvolvimento começou no Tinkercad, onde foi realizada a montagem do circuito e os testes dos componentes. Depois, foi desenvolvido o código principal do reprodutor.

Objetivo

Criar um sistema capaz de reproduzir pelo menos cinco músicas, permitindo ao usuário navegar entre as opções, iniciar a reprodução, pausar, continuar e interromper a música.

Componentes utilizados

- Arduino UNO R3;
- Protoboard;
- Display LCD 16x2;
- 4 botões;
- 1 LED verde;
- 1 LED vermelho;
- Buzzer;
- 3 resistores de 220 Ω;
- Potenciômetro de 10 kΩ;
- Fios de conexão.

Funcionamento do sistema

O reprodutor possui quatro botões para controlar suas funções:

Botão| Função
UP| Seleciona a música anterior
DOWN| Seleciona a próxima música
PLAY/PAUSE| Inicia, pausa ou continua a reprodução
STOP| Interrompe a música e retorna ao menu

O display LCD apresenta o nome da música selecionada e informa quando ela está tocando ou pausada.

Os LEDs indicam o estado do sistema:

- LED verde: música em reprodução.
- LED vermelho: música pausada ou menu de seleção.

O buzzer é responsável por reproduzir as notas musicais.

Músicas disponíveis

O projeto possui cinco músicas programadas:

1. Marcha Imperial;
2. Ode à Alegria;
3. Frère Jacques;
4. Brilha Estrelinha;
5. Jingle Bells.

As notas das músicas são armazenadas na memória Flash do Arduino utilizando "PROGMEM".

Organização dos arquivos

O repositório está organizado da seguinte forma:

- "codigo_reprodutor_de_musicas_final.ino": código principal do reprodutor.
- "etapa 1 montagem/": arquivos referentes à montagem e aos testes iniciais do circuito.
  - "teste.ino": código utilizado para testar os componentes.
  - "README.md": descrição da primeira etapa.
  - "conexoes.md": informações sobre as ligações dos componentes.
  - "Reprodutor de Musicas - CCP020.png": imagem do circuito montado no Tinkercad.

Desenvolvimento

Etapa 1 - Montagem e testes

Foi realizada a montagem do circuito no Tinkercad, seguida de testes individuais dos componentes. Foram verificados o funcionamento dos botões, LEDs, buzzer e display LCD.

Desenvolvimento do reprodutor

Após os testes iniciais, foi desenvolvido o código principal, com o menu de seleção, as cinco músicas e os controles de reprodução, pausa e parada.

Tecnologias utilizadas

- Arduino UNO;
- Tinkercad;
- Linguagem C/C++ para Arduino;
- GitHub.

Conclusão

O projeto reúne conhecimentos de programação e eletrônica para desenvolver um reprodutor de músicas utilizando Arduino. Durante o desenvolvimento, foram realizadas a montagem do circuito, os testes dos componentes e a programação das funções de controle e reprodução das músicas.

Este repositório reúne os arquivos do desenvolvimento, incluindo o circuito, os códigos e as informações necessárias para entender a montagem e o funcionamento do sistema.



https://github.com/user-attachments/assets/2f4d272d-875b-4336-a3db-bad13310fc3f

<img width="1920" height="820" alt="image" src="https://github.com/user-attachments/assets/a22d299c-c975-416f-a8e4-c78f2460cfbb" />
