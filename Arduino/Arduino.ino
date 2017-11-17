volatile unsigned long tiempo[6] = {0, 0, 0, 0, 0, 0};
unsigned long deltaTiempo[6];
volatile int count = 0;
int i;
short lectura;
bool paso;
void sensorInterrupt(void);
void formatData(void);

void setup() {
  pinMode(4, OUTPUT);
  //attachInterrupt(0, sensorInterrupt, FALLING);
  //noInterrupts();
  Serial.begin(9600);
  digitalWrite(4, LOW);
}

void loop() {
  if (!paso)
  {
    paso = digitalRead(2);
  }
  if (count >= 6)
  {
    formatData();
    for(i = 0; i < 6; i++)
    {
      Serial.println(deltaTiempo[i]);
    }
    count = 0;
  }
  if(!digitalRead(2) && paso)
  {
    if (count < 6)
    {
      digitalWrite(4, HIGH);
      tiempo[count] = millis();
      count++;
      digitalWrite(4, LOW);
    }
    paso = false;
  }
  
}

/*void sensorInterrupt ()
{
  if (count < 6)
  {
    digitalWrite(4, HIGH);
    tiempo[count] = millis();
    count++;
    noInterrupts();
    delay(2);
    interrupts();
    digitalWrite(4, LOW);
  } 
}*/

void formatData()
{
  deltaTiempo[0] = 0;
  for(i = 1; i < 6; i++)
  {
    deltaTiempo[i] = tiempo[i] - tiempo[i - 1];
    tiempo[i - 1] = 0;
  } 
}

/*void serialEvent()
{
  lectura = Serial.read();
  switch(lectura)
  {
    case 0:
      noInterrupts();
      break;
    case 1:
      interrupts();
      break;
  }
}*/
