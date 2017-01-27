

int sensorTemperatura = A0;
int sinalRele = 4;




void setup() {
 pinMode (sinalRele, OUTPUT);
 
 Serial.begin(9600);
 
 }

void loop() {
  int leituraSensor = analogRead(sensorTemperatura);
  
  float volt = (leituraSensor*5.0);
  volt/=1024.0;
  
  float temperatura=(volt-0.5)*10; 
  
  Serial.print(temperatura); Serial.println(" celsius");
  
  
  if(temperatura < 27){
    digitalWrite (sinalRele, HIGH); 
    Serial.println("on");
  }
  else{
    digitalWrite (sinalRele,  LOW);
    Serial.println("off");
  }


}
