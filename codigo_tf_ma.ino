#include <SD.h>
#include <TMRpcm.h>
#include <SPI.h>

//declarações
int sensorTemperatura = A0;
int sinalRele = 10;
TMRpcm tmrpcm; //estrutura que contem funcoes para reproduzir o som

void setup() {
 //declaração de pinos
 pinMode (sinalRele, OUTPUT);
 tmrpcm.speakerPin = 9; //5,6,11 ou 46 on Mega, 9 no Uno, Nano, etc
 //pode ser utilizado outra saida como auxiliar para o som
 Serial.begin(9600); //Inicializa a conexão serial com o computador
  if (!SD.begin(4)) { //para o nano utiliza o 4
    Serial.println(" failed!"); //caso nao seja possivel ler o cartao sd
    while(true);
  }
 }
 
void loop() {
	
//leitura do sensor de temperatura
  int leituraSensor = analogRead (sensorTemperatura);
  //corvertendo a leitura para voltagem
  float volt = leituraSensor * 5.0;
  volt /= 1024.0;

  // File myFile = SD.open("coracao.wav");
  // if (!myFile) {
    //Erro se nao abrir o arquivo .wav
    // Serial.println("Nao foi possivel abrir coracao.wav");
    //fica em idle
    // while (true);
  // }

  // const int S = 1024; // Tamanho (size) do buffer a ser utilizado
  // short buffer[S];
  tmrpcm.play("heartbeats.wav"); //reproduz o arquivo "heartbeats.wav"
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
