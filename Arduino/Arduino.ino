volatile unsigned long tiempo[6] = {0, 0, 0, 0, 0, 0};
volatile int count = 0;
int i;

void sensorInterrupt(void);
void formatData(void);

void setup() {
  pinMode(1, OUTPUT);
  attachInterrupt(0, sensorInterrupt, RISING);
  Serial.begin(9600);
}

void loop() {
  if (count >= 6)
  {
    formatData();
    for(i = 0; i < 6; i++)
    {
      Serial.println(tiempo[i]);
    }
  }
}

void sensorInterrupt ()
{
  if (count < 6)
  {
    tiempo[count] = millis();
    count++;
  } 
}

void formatData()
{
  for(i = 1; i < 6; i++)
  {
    tiempo[i] -= tiempo[i - 1];
  }
  tiempo[0] = 0;
}

