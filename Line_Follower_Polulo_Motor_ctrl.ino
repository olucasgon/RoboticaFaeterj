//Arduino PWM Speed Control：
#define s1  A1 
#define s2  A2
#define s3  A3
#define s4  A4
#define s5  A5

int PWMA = 9;
int PWMB = 3;
int AIN1 = 6;
int AIN2 = 5;
int BIN1 = 4;
int BIN2 = 2;
int STBY = 8;


void tras(int value){
    digitalWrite(STBY, HIGH);
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    analogWrite(PWMA, value);
    digitalWrite(STBY, HIGH);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMB, value);
    delay(30);
}

void frente(int value){
    digitalWrite(STBY, HIGH);
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, value);
    digitalWrite(STBY, HIGH);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, value);
    delay(30);
}

void direita(int value){
    digitalWrite(STBY, HIGH);
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, value);
    digitalWrite(STBY, HIGH);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMB, value);
    delay(30);
}

void esquerda(int value){
    digitalWrite(STBY, HIGH);
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    analogWrite(PWMA, value);
    digitalWrite(STBY, HIGH);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, value);
    delay(30);
}

void setup()
{
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);
}

void loop()
{
  //int SCLP = digitalRead(CLP);
  //int Snear = digitalRead(near);
  //
  int sens3 = digitalRead(s3);
  int sens2 = digitalRead(s2);
  int sens4 = digitalRead(s4);
  int val = 60;

  if (sens2 and sens4){
        //frente
        val = 60;
        frente(val);
  }
  if (!sens2){
        //esquerda
        val = 60;
        esquerda(val);
  }
  if (!sens4){
        //direita
        val = 60;
        direita(val);
  }
  if (!sens2 and !sens4){
        //direita
        val = 0;
        tras(val);
  }

  delay(100);
}