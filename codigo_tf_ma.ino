
//declarações
int sensorTemperatura = A0;
int sinalRele = 10;


void setup() {
 //declaração de pinos
 pinMode (sinalRele, OUTPUT);
 
 Serial.begin(9600); //Inicializa a conexão serial com o computador
 
 }

void loop() {
//leitura do sensor de temperatura
  int leituraSensor = analogRead (sensorTemperatura);
  
  //corvertendo a leitura para voltagem
  float volt = leituraSensor * 5.0;
  volt /= 1024.0;
  
  //convertendo a temperatura de fahrenheit para Celsius
  float temperatura = (volt - 0.5) * 10; 
  
  Serial.print(temperatura); Serial.println(" celsius");
  
  //controlando a temperatura
  
  if (temperatura < 27)
  {
    //se a temperatura estiver abaixo de 27 graus a lâmpada é ligada
    digitalWrite (sinalRele, HIGH); 
    Serial.println("on");
  }
  
  else 
  {
    //caso a temperatura estiver acima de 27 graus a lâmpada é desligada
    digitalWrite (sinalRele,  LOW);
    Serial.println("off");
  }


}
