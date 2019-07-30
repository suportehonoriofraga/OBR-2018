#include <Ultrasonic.h>

#define TRIGGER_PIN  12
#define ECHO_PIN     13

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

//Definição dos pinos

int ENA = 3; //Habilita pino do motor direito (PWM)
int IN1 = 1; //Controle do pino
int IN2 = 2;

int ENB = 6; //Habilita pino do motor esquerdo (PWM)
int IN3 = 4;
int IN4 = 5;

//Velocidade dos motores (em 5v)
#define ENASpeed 250 //tocar velocidade ENA sem jumper na ponte H  
#define ENBSpeed 250 //tocar velocidade ENB sem jumper na ponte H

int distancia = 0;

void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

}

void loop(){
  long microsec = ultrasonic.timing();

  distancia = ultrasonic.convert(microsec, Ultrasonic::CM);
  //Usa analogWrite para ajustar a velocidade dos motores
  analogWrite(ENA, ENASpeed);
  analogWrite(ENB, ENBSpeed);
    
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    
    if(distancia < 10){

     digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay (3000);
    // virar para a esquerda

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(3000);
    //ande reto

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(3000);
    
    // pare novamente
     digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay (500);
    // virar para a direita

    digitalWrite(IN1, HIGH);
    digitalWrite(IN1, LOW);
    digitalWrite(IN1, LOW);
    digitalWrite(IN1, HIGH);
    delay (3000);
    //ande reto

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(3000);
    // para pela terceira vez
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay (500);
    // vira para a direita 

    digitalWrite(IN1, HIGH);
    digitalWrite(IN1, LOW);
    digitalWrite(IN1, LOW);
    digitalWrite(IN1, HIGH);
    delay (3000);
    // ande reto

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(3000);
    // vire um pouco pra esquerda a esquerda para alinhar

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(300);}
}
   
