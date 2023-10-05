#include <LedControl.h>
#include <stdlib.h>

LedControl lc = LedControl(11, 12, 13, 1); // Pinos DIN, CLK, CS e número de dispositivos

byte olhoAberto1[] = {
  B00111100,
  B01000010,
  B10000001,
  B10011001,
  B10011001,
  B10000001,
  B01000010,
  B00111100,
};

byte olhoAberto2[] = {
  B00111100,
  B01000010,
  B10000001,
  B10011001,
  B10011001,
  B10000001,
  B01000010,
  B00111100,
};

byte olhoAberto3[] = {
  B00111100,
  B01000010,
  B10000001,
  B10000111,
  B10000111,
  B10000001,
  B01000010,
  B00111100,
};

byte olhoAberto4[] = {
  B00111100,
  B01000010,
  B10000001,
  B11100001,
  B11100001,
  B10000001,
  B01000010,
  B00111100,
};

byte olhoFechado[] = {
  B00000000,
  B00000000,
  B00000000,
  B11111111,
  B11111111,
  B00000000,
  B00000000,
  B00000000,
};

void setup() {
  lc.shutdown(0, false); // Ativa o MAX7219
  lc.setIntensity(0, 8); // Define a intensidade do brilho (0-15)
  lc.clearDisplay(0);    // Limpa a matriz
  randomSeed(analogRead(0)); // Inicializa a semente do gerador de números aleatórios
}

void loop() {
  while (true) {
    olhoOlhaAleatoriamente();
    delay(1000 + random(1000));  // Mantém os olhos movendo por um tempo aleatório
    olhoFecha();
    delay(500);  // Mantém o olho fechado por 0,5 segundos
  }
}

void olhoOlhaAleatoriamente() {
  for (int i = 0; i < 5; i++) {
    byte *olhoAberto;
    int pattern = random(1, 5); // Escolhe aleatoriamente entre 1, 2, 3 e 4
    switch (pattern) {
      case 1:
        olhoAberto = olhoAberto1;
        break;
      case 2:
        olhoAberto = olhoAberto2;
        break;
      case 3:
        olhoAberto = olhoAberto3;
        break;
      case 4:
        olhoAberto = olhoAberto4;
        break;
      default:
        olhoAberto = olhoAberto1;
    }

    for (int j = 0; j < 8; j++) {
      lc.setRow(0, j, olhoAberto[j]);
    }
    
    delay(100 + random(300)); // Adiciona aleatoriedade ao tempo de visualização
  }
}

void olhoFecha() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, olhoFechado[i]);
  }
}
