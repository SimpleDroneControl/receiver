#define main_time 1000

volatile int counter = 0;
int analogPin = A2;

void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT);
  pinMode(5, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(3), sign, CHANGE);
}

void sign() {
  counter++; 
}

void loop() {

  int i = 0;

  while (i < main_time){

    if (analogRead(analogPin) > 500){
      digitalWrite(5, LOW);
      delay(5);
      i+=1;
    }
    else {
      digitalWrite(5, HIGH);
      delay(5);
      i+=1;
    }
  }
  
  Serial.println(counter); 
  counter = 0;
  Serial.print(" "); 
  Serial.println(analogRead(analogPin));  
}