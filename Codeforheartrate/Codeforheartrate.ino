const int numReadings = 5;

int readings[numReadings];     
int readIndex = 0;              
int total = 0;                
int average = 0;               

int inputPin = A0;

void setup()
{
  Serial.begin(38400);                   
  // initialize all the readings to 0: 
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;      
  pinMode(4, OUTPUT);    
}

void loop() {
  digitalWrite(2, HIGH); 
  total= total - readings[readIndex];         
  readings[readIndex] = analogRead(inputPin); 
  total= total + readings[readIndex];       
  readIndex = readIndex + 1;                    

  if (readIndex >= numReadings)              
    readIndex = 0;                           

  average = total / numReadings;         
  Serial.println(average);                   
}


