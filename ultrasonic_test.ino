// C++ code


int inches = 0;

int cm = 0;

long readDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode (5, OUTPUT);

}

void loop()
{
  // measure the ping time in cm
  cm = 0.01723 * readDistance(3, 2);
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  
  if (inches < 24){
    digitalWrite(9, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }
      else if (inches > 24 and inches < 48){
        digitalWrite(9, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(5, LOW);
      }
      else {
        digitalWrite(9, LOW);
        digitalWrite(6, LOW);
        digitalWrite(5, HIGH);
      }
      
      
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
}
