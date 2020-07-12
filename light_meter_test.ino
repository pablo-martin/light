//pin assignments that won't change
const int button0Pin = 3;
const int button1Pin = 4;
const int button2Pin = 5;
const int button3Pin = 6;
const int button4Pin = 7;
const int channel = 13;

//variables that will change
int button0, button1, button2, button3, button4 = 0;

void square_pulse(int channel, int delayON, int delayOFF)
{
  digitalWrite(channel, HIGH); delay(delayON);
  digitalWrite(channel, LOW); delay(delayOFF);
}

void micro_square_pulse(int channel, int delayON, int delayOFF)
{
  digitalWrite(channel, HIGH); delayMicroseconds(delayON);
  digitalWrite(channel, LOW); delayMicroseconds(delayOFF);
}

void profile_zero(int channel)
{
  square_pulse(channel, 1000,1000);
}

void profile_one(int channel)
{
  square_pulse(channel, 10, 10);
}

void profile_two(int channel)
{
  square_pulse(channel, 2, 2);
  square_pulse(channel, 2, 2);
  square_pulse(channel, 2, 10);
}

void profile_three(int channel)
{
  square_pulse(channel, 1, 1);
  square_pulse(channel, 1, 1);
  square_pulse(channel, 1, 1);
  square_pulse(channel, 1, 1);
  square_pulse(channel, 1, 11);  
}

void profile_four(int channel)
{
  micro_square_pulse(channel, 2, 2);
  micro_square_pulse(channel, 2, 2);
  micro_square_pulse(channel, 2, 10);  
}

void setup() {
  pinMode(channel,OUTPUT);
  pinMode(button0Pin, INPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
}

void loop() {
  button0 = digitalRead(button0Pin);
  button1 = digitalRead(button1Pin);
  button2 = digitalRead(button2Pin);
  button3 = digitalRead(button3Pin);
  button4 = digitalRead(button4Pin);
  
  if (button0 == HIGH){
    profile_zero(channel);
  } else if (button1 == HIGH){
    profile_one(channel);
  } else if (button2 == HIGH){
    profile_two(channel);
  } else if (button3 == HIGH){
    profile_three(channel);
  } else if (button4 == HIGH){
    profile_four(channel);    
  }
  
}
