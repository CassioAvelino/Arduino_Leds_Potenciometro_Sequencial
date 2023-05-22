int valorLido = 0;
float tensao = 0;

int tipoEscala = 2;
int faixa = 0;

int led5 = 12;
int led4 = 11;
int led3 = 10;
int led2 = 9;
int led1 = 8;

int mapearEscala(float tensao)
{
  int faixaTemp = 0;
  if(tensao > 0 && tensao <=0.2)
  {
  	faixaTemp = 0;
    return faixaTemp;
  }
  
  if(tensao > 0.2 && tensao <= 1.0)
  {
    faixaTemp = 1;
    return faixaTemp;
  }
  if(tensao>1.0 && tensao <= 2.0)
  {
    faixaTemp = 2;
    return faixaTemp;
  }
  if(tensao>2.0 && tensao <= 3.0)
  {
    faixaTemp = 3;
    return faixaTemp;
  }
  if(tensao> 3.0 && tensao <= 4.0)
  {
    faixaTemp = 4;
    return faixaTemp;
  }
  if(tensao>4.0)
  {
    faixaTemp = 5;
    return faixaTemp;
  }
}

void ligaLed (int faixa, int tipoEscala)
{
  if (faixa == 0)
  {
  	digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
  }
  if (faixa == 1 && tipoEscala == 1)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
  }
  
  if (faixa == 2 && tipoEscala == 1)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
  }
  
  if (faixa == 3 && tipoEscala == 1)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
  }
  
  if (faixa == 4 && tipoEscala == 1)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
  }
  
  if (faixa == 5 && tipoEscala == 1)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, HIGH);
  }
  
  // TipoEscala 2
  
  if (faixa == 1 && tipoEscala == 2)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
  }
    if (faixa == 2 && tipoEscala == 2)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
  }
    if (faixa == 3 && tipoEscala == 2)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
  }
    if (faixa == 4 && tipoEscala == 2)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
  }
    if (faixa == 5 && tipoEscala == 2)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop()
{
  valorLido = analogRead(A5);
  tensao = valorLido * (5.0 / 1023.0);
  faixa = mapearEscala(tensao);
  ligaLed(faixa, tipoEscala);
}
