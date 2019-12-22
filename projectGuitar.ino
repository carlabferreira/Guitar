#include <LiquidCrystal.h>
//PROJETO DO GUITAR HERO - 105A/106
//Por Carla, Debora, Aryane, Matheus M. e João H.

//Definir as notas e ver quais vão ser utilizadas
//Programação do buzzer - cada som
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

//NOTAS PARA COLOCAR EM LIVRES]
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523

int Buzzer = 8;
int DURACAO;
int TEMPO = 0;
int HERO;
int BG = 9;//green
int BR = 10; //red
int BY = 7;//yellow CONFRMAR NO REAL
int BB = 13;//blue


int posicao  = 0;

int EB, EG, ER, EY = 0;


LiquidCrystal lcd(12, 11 , 5, 4, 3, 2);

byte customChar[] = {
  B01000,
  B01001,
  B01001,
  B01111,
  B11111,
  B11111,
  B01111,
  B00000,
};

void setup()
{
  lcd.begin(16, 2);
  lcd.createChar(0, customChar);
  lcd.home();
  lcd.write((uint8_t)0);
  lcd.setCursor(15, 1);
  lcd.write((uint8_t)0);//DESENHAR A MAO
  lcd.setCursor(10, 0); //POSIÇÃO DA MAO
  lcd.write((uint8_t)0);//DESENHAR A MAO

  pinMode(Buzzer, OUTPUT);
  pinMode(BG, INPUT);
  pinMode(BR, INPUT);
  pinMode(BY, INPUT);
  pinMode(BB, INPUT);

  HERO = 640; // HERO É UMA FREQUÊNCIA QUE
  //EQUIVALE A nota Mí no 6º tom

}
void loop () {
  //estado de cada botão
  EB = digitalRead(BB);
  ER = digitalRead(BR);
  EY = digitalRead(BY);
  EG = digitalRead(BG);

  //PARA COMEÇAR O JOGO SE OS 4 BOTOES PRESSIONADOS
  if (EB == 1 && ER == 1 && EY == 1 && EG == 1) {
    lcd.clear();//Limpa a tela
    lcd.setCursor(0, 0); //Posiciona o cursor na coluna 0, linha 0;
    lcd.print("Musica Despacito");
    lcd.setCursor(0, 1);
    lcd.print("Q vc pode tocar sozinho");
    Despacito();

      Serial.print("Aqui");

    //Rolagem para a direita
    /*for (int posicao = 0; posicao <=16; posicao++)
      {
      lcd.scrollDisplayRight();
      delay(300);
      }
      delay(1000);//1 segundo
      }//FIM DO IF*/
  }
  
  // else{ //Enquanto o jogo não está rodando
  lcd.clear();
  lcd.setCursor(10, 0);
  lcd.write((uint8_t)0);
  lcd.print("Toque livre");
  lcd.write((uint8_t)0);
  lcd.setCursor(15, 1);
  lcd.write((uint8_t)0);
  lcd.print("P/ ouvir despacito os 4");
  lcd.write((uint8_t)0);

  for (int posicao  = 0; posicao <= 15; posicao++) {
    lcd.scrollDisplayLeft();
    delay(50);
  }

  if (EB == 1 && ER == 0 && EY == 0 && EG == 0) {
    tone(Buzzer, NOTE_C4, 100);
  }
  else if (EB == 0 && ER == 1 && EY == 0 && EG == 0) {
    tone(Buzzer, NOTE_CS4, 100);
  }
  else if (EB == 0 && ER == 0 && EY == 1 && EG == 0) {
    tone(Buzzer, NOTE_D4, 100);
  }

  else if (EB == 0 && ER == 0 && EY == 0 && EG == 1) {
    tone(Buzzer, NOTE_DS4, 100);
  }//AGORA COM DOIS BOTÕES:
  else if (EB == 1 && ER == 1 && EY == 0 && EG == 0) {
    tone(Buzzer, NOTE_E4, 100);
  }
  else if (EB == 1 && ER == 0 && EY == 1 && EG == 0) {
    tone(Buzzer, NOTE_F4, 100);
  }
  else if (EB == 1 && ER == 1 && EY == 0 && EG == 1) {
    tone(Buzzer, NOTE_FS4, 100);
  }
  else if (EB == 0 && ER == 1 && EY == 1 && EG == 0) {
    tone(Buzzer, NOTE_G4, 100);
  }
  else if (EB == 0 && ER == 1 && EY == 0 && EG == 1) {
    tone(Buzzer, NOTE_GS4, 100);
  }
  else if (EB == 0 && ER == 0 && EY == 1 && EG == 1) {
    tone(Buzzer, NOTE_A4, 100);
  }//PRESSIONANDO 3 NOTAS AO MESMO TEMPO:
  else if (EB == 1 && ER == 1 && EY ==1  && EG == 0){
    tone(Buzzer, NOTE_AS4, 100);
  } 
  else if (EB == 1 && ER == 1 && EY ==0  && EG == 1){
    tone(Buzzer, NOTE_B4, 100);
  }
  else if (EB == 1 && ER == 0 && EY ==1  && EG == 1){
    tone(Buzzer, NOTE_G3, 100);
  }
  else if (EB == 0 && ER == 1 && EY ==1  && EG == 1){
    tone(Buzzer, NOTE_AS3, 100);
  }
  
  
  else if (EB == 1 && ER == 1 && EY == 1 && EG == 1) {
    lcd.clear();//Limpa a tela
    lcd.setCursor(0, 0); //Posiciona o cursor na coluna 0, linha 0;
    lcd.print("Musica Despacito");
    lcd.setCursor(0, 1);
    lcd.print("Q vc pode tocar sozinho");
    Despacito();
  }

  //ESPAÇO PRA MAIS COMBINAÇOES


  //FIM DO FOR
  //FIM DO ELSE
}//FIM DO VOID LOOP




//Programação das notas em sequencia sendo uma música

void Despacito() {
  notars(HERO, NOTE_D5);
  notars(HERO, NOTE_CS5);
  notars(HERO / 2, NOTE_B4);
  notars(HERO / 4, NOTE_FS4);
  delay(HERO / 4);
  notars(HERO / 4, NOTE_FS4);
  notars(HERO / 4, NOTE_FS4);
  //► ♫♫♫♫♫ ►
  notars(HERO / 4, NOTE_FS4);
  notars(HERO / 4, NOTE_FS4);
  //► ♫♫♫♫♫ ►
  notars(HERO / 4, NOTE_FS4);
  //► ♫♫♫♫♫ ►
  notars(HERO / 4, NOTE_B4);
  notars(HERO / 4, NOTE_B4);
  notars(HERO / 4, NOTE_B4);
  notars(HERO / 2, NOTE_B4);
  //► ♫♫♫♫♫ ►
  notars(HERO / 4, NOTE_A4);
  //► ♫♫♫♫♫ ►
  notars(HERO / 4, NOTE_B4);
  delay(HERO / 4);
  delay(HERO / 4);
  notars(HERO / 4, NOTE_G4);
  delay(HERO / 4);
  //► ♫♫♫♫♫ ►
  notars(HERO / 4, NOTE_G4);
  notars(HERO / 4, NOTE_G4);
  notars(HERO / 4, NOTE_G4);
  notars(HERO / 4, NOTE_G4);
  notars(HERO / 4, NOTE_G4);
  //► ♫♫♫♫♫ ►
  notars(HERO / 4, NOTE_B4);
  notars(HERO / 4, NOTE_B4);
  notars(HERO / 4, NOTE_B4);
  notars(HERO / 2, NOTE_B4);
  //► ♫♫♫♫♫ ►
  notars(HERO / 4, NOTE_CS5);
  notars(HERO / 4, NOTE_D5);
  delay(HERO / 4);
  delay(HERO / 4);
  notars(HERO / 4, NOTE_A4);
  delay(HERO / 4);
  //► ♫♫♫♫♫ ►
  notars(HERO / 4, NOTE_A4);
  notars(HERO / 4, NOTE_A4);
  notars(HERO / 4, NOTE_A4);
  notars(HERO / 4, NOTE_A4);
  //► ♫♫♫♫♫ ►
  notars(HERO / 4, NOTE_D5);
  notars(HERO / 4, NOTE_CS5);
  notars(HERO / 4, NOTE_D5);
  notars(HERO / 4, NOTE_CS5);
  notars(HERO / 2, NOTE_D5);
  //► ♫♫♫♫♫ ►
  notars(HERO / 4, NOTE_E5);
  notars_jai(HERO / 2, NOTE_E5, HERO / 4);

  //[̲̅G̲̅υ̲̅I̲̅т̲̅α̲̅я̲̅ ̲̅н̲̅є̲̅я̲̅σ̲̅][̲̅G̲̅υ̲̅I̲̅т̲̅α̲̅я̲̅ ̲̅н̲̅є̲̅я̲̅σ̲̅]
  tone(Buzzer, NOTE_CS5 , HERO * 3 / 4);
  //[̲̅G̲̅υ̲̅I̲̅т̲̅α̲̅я̲̅ ̲̅н̲̅є̲̅я̲̅σ̲̅][̲̅G̲̅υ̲̅I̲̅т̲̅α̲̅я̲̅ ̲̅н̲̅є̲̅я̲̅σ̲̅]
  delay(HERO / 4);
  delay(HERO / 4);

  delay(HERO / 4);

  noTone(Buzzer);
  delay(HERO / 4);

  //--------------
  delay(HERO / 4);


  delay(HERO / 4);
  delay(HERO / 4);

    Serial.print("1");

  return;
}
void notars(int DURACAO, int LaNota ) {

  //noteDuration=HERO/4;
  tone(Buzzer, LaNota , DURACAO * 0.9);
  //      TEMPO = DURACAO * 1.30;
  TEMPO = DURACAO * 1.1;
  delay(TEMPO);
  noTone(Buzzer);
  return;
}
void notars_jai(int DURACAO, int LaNota , int Desfase) {

  //DURACAO=HERO/4;
  tone(Buzzer, LaNota , DURACAO * 0.9);
  //      TEMPO = DURACAO * 1.30;
  TEMPO = DURACAO * 1.1;
  delay(Desfase);
  delay(TEMPO - Desfase);
  noTone(Buzzer);

    return;

}