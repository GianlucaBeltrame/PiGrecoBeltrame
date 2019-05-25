#include <LiquidCrystal.h>
LiquidCrystal lcd(14, 13, 12, 11, 10, 9);

int NumRandom;
int BottoneIniziale;
int Record;
int Vite;
int PuntiCorrentePartita;
int Bottone1;
int Bottone2;
int Bottone3;
int Bottone4;
int Bottone5;
int PosRandom;
int ArrPos[5] = {0, 4, 8, 12, 15};
int ArrButtons[5] = { Bottone1, Bottone2, Bottone3, Bottone4, Bottone5};
  

void setup() {
  lcd.begin(16, 2);
  Record = 0;
  Bottone1 = 2;
  Bottone2 = 3;
  Bottone3 = 4;
  Bottone4 = 5;
  Bottone5 = 6;
  BottoneIniziale = 7;

  pinMode (Bottone1,INPUT);
  pinMode (Bottone2,INPUT);
  pinMode (Bottone3,INPUT);
  pinMode (Bottone4,INPUT);
  pinMode (Bottone5,INPUT);
  pinMode (BottoneIniziale,INPUT);

  SchermataIniziale();
}



  