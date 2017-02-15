#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>

#include <SD.h>
#include <SPI.h>
#define SD_ChipSelectPin 4
//declarações
int sensorTemperatura = A0;
int sinalRele = 5;
TMRpcm tmrpcm; //estrutura que contem funcoes para reproduzir o som
//int time = 0;
void setup() {
 //declaração de pinos
 pinMode (sinalRele, OUTPUT);
 tmrpcm.speakerPin = 11; //5,6,11 ou 46 on Mega, 9 no Uno, Nano, etc
 //pode ser utilizado outra saida como auxiliar para o som
 pinMode(53, OUTPUT);
 pinMode(10, OUTPUT); // Como não estamos usando ethernet é necessário desativar esta porta, explicitamente
 pinMode(11, OUTPUT);
 digitalWrite(10, HIGH); // Para isso, deixe em alto para desativar
 Serial.begin(9600); //Inicializa a conexão serial com o computador
  if (!SD.begin(SD_ChipSelectPin)) { //para o nano utiliza o 4
    Serial.println(" failed!"); //caso nao seja possivel ler o cartao sd
    while(true);
    //return;
  }
  Serial.println("Inicializacao completa!");
  tmrpcm.play("oi.wav");
 }
 
void loop() {
	
//leitura do sensor de temperatura
  int leituraSensor = analogRead (sensorTemperatura);
  //corvertendo a leitura para voltagem
  float volt = leituraSensor * 5.0;
  volt /= 1024.0;
  /*if(time == 0 || time - millis() >= 50000)
  {
    time = millis();
    tmrpcm.play("oi.wav");
  }*/
  
  //convertendo a temperatura de fahrenheit para Celsius
  float temperatura = (volt - 0.5) * 10; 
  
  Serial.print(temperatura); Serial.println(" celsius");
  
  //controlando a temperatura
  
  if (temperatura < 25)
  {
    //se a temperatura estiver abaixo de 25 graus a lâmpada é ligada
    digitalWrite (sinalRele, HIGH); 
    Serial.println("on");
  }
  
  if (temperatura > 27)
  {
    //caso a temperatura estiver acima de 27 graus a lâmpada é desligada
    digitalWrite (sinalRele,  LOW);
    Serial.println("off");
  }
 // A mudança se deu para evitar que a lâmpada fique piscando, assim 26 graus
//seria uma temperatura de segurança. Caso a lampada esteja apagada, somente ligará em 27 graus,
//e se estiver acesa, desligará em 25 graus. 
}
