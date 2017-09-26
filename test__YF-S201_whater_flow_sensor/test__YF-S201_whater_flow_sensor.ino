int FlowPin = 2;
double FlowRate;
volatile int count;

void setup() {
  pinMode(FlowPin, INPUT);
  attachInterrupt(0, Flow, RISING);
  Serial.begin(9600);
}
void loop() { 
  count = 0;
  interrupts();
  delay (1000);
  noInterrupts();
  
  FlowRate = (count * 2.25);
  FlowRate = FlowRate * 60;
  FlowRate = FlowRate / 1000;

  Serial.println(FlowRate);
}

void Flow()
{
   count++;
}
