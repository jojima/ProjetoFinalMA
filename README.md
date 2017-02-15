# Projeto Final de Microcontroladores e Aplicações
Caixa para filhotes
![IMG_0599](/IMG_0599.JPG)

## Proposta do projeto
Deixar uma caixa ou abrigo para filhotes aconchegante utilizando um arduino.
![IMG_0598](/IMG_0598.JPG)

## Objetivos
 - Controlar a temperatura com uma lâmpada ou outra fonte de calor acionado por um relé que depende do sensor de temperatura.
 - Permitir que o filhote se sinta próximo a mãe através de um ambiente aconchegante, com a reprodução de sons que imitam as batidas do coração, o que o tranquiliza.
 ![IMG_0591](/IMG_0591.JPG)
 
## Componentes que foram utilizados
 - Arduino Mega
 - Sensor de temperatura
 - Relé
 - Lâmpada e soquete para lâmpada
 - Speaker 8 Ohms 
 - Cartão SD
 - Shield para cartão SD
 - Shield para sensores
 
# Esquemático
![Esquematico](/Esquematico.PNG)

# Implementação

 Para controle da temperatura foi utilizado um sensor de temperatura, e através do código que o Arduino Mega foi submetido, quando a temperatura está abaixo de 27ºC a lâmpada é ligada, para aquecer a caixa.
 
 A temperatura de 27ºC foi pesquisada com veterinários e considerada a temperatura ideal para filhotes até 4 meses de vida.
 
 Para evitar que a lâmpada fique piscando quando alcancar uma temperatura por volta dos da temperatura ideal foi realizado uma prevenção, assim, a lâmpada somente é desligada quando atingido 25ºC. 
 
  Um relé foi utilizado para fazer a ligação elétrica da lâmpada. O shield para sensores para ser possível a ligação do sensor de temperatura no arduino e o mesmo para o shield para cartão SD, que foi utilizado para armazenar o arquivo .wav contendo as batidas do coração. 
  
 O speaker foi o responsável por reproduzir o arquivo com as batidas de coração, para reprodução de áudio a partir do cartão SD foi utilizada a biblioteca TMRpcm.h .
 
 
 O vídeo com o projeto em execução pode ser encontrado [aqui](https://www.youtube.com/upload)

