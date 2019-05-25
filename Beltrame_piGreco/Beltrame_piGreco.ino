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
void SchermataGioco()
{
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Vite: " +String(Vite));
   lcd.setCursor(9,0);
   lcd.print("Punti:" + String(PuntiCorrentePartita));
}
void SchermataIniziale()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Start Game");
  lcd.setCursor(0,1);
  lcd.print("Record:" + String(Record));
}


void NumRandomMet(int valoreA, int valoreB)
{
  NumRandom = random(valoreA,  valoreB);
}

void BottoneInizialeMetodo (int bottone)
{
  bool fatto=false;

  while(!fatto)
  {
  if (digitalRead(bottone)==HIGH)
   {
    fatto=true;
   }
  }
}
void Gioco()
{bool fatto= false;
SchermataGioco();
while(!fatto && Vite>0)                                     //LOOP PER GIOCARE
{ NumRandomMet(0,9);
if(NumRandom >=0 && NumRandom <=5)
  {PosRandom = random(0,4);                                  //POSIZIONE RANDOM
   lcd.setCursor(ArrPos[PosRandom],1);
   lcd.print("n");
   int Tempo1 = millis();
   int Tempo2;
  bool finito=false;
while(!finito)
   {if (digitalRead(ArrButtons[PosRandom])==HIGH)
     {PuntiCorrentePartita++;
      finito=true;
     }
Tempo2=millis();
if(Tempo2- Tempo1>=2000)                                        //SE PASSANO 2 SECONDI PERDI
    {finito=true;
     Vite--;
    }
   }
  }

else if(NumRandom>=6 && NumRandom <=7)                       //SE è NELLA CATEGORIA MALUS TOGLI UNA VITA 
   {PosRandom=random(0,4);
   lcd.setCursor(ArrPos[PosRandom],1);
   lcd.print("malus");
   int Tempo1 = millis();
   int Tempo2;
   bool finito = false;
   while(!finito)
      {if(digitalRead(ArrButtons[PosRandom])==HIGH)
        {Vite --;
         finito=true;
        }
      }
   }

else
{PosRandom=random(0,4);
lcd.setCursor(ArrPos[PosRandom],1);
lcd.print("cuore");
int Tempo1 = millis();
int Tempo2;
bool finito = false;
while(!finito)
       {if(digitalRead(ArrButtons[PosRandom])==HIGH)
         {Vite++;
          finito=true;
         }
          Tempo2=millis();
          if(Tempo2-Tempo1>=1500)
          {finito=true;
          }
       }
    }
  }
}



void loop(){
if(PuntiCorrentePartita>Record)
{
  Record = PuntiCorrentePartita;
}
             Vite=5;
             PuntiCorrentePartita=0;
             SchermataIniziale();
             BottoneInizialeMetodo(BottoneIniziale);
             Gioco();
            }


  
