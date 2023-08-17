#include <Servo.h>
const int TRIGGER_PIN = 17;
const int ECHO_PIN = 18;
const int MP1 = 16;
const int MP2 = 15;
const int distanciaObjetivo = 10;
const int servoPin = 14;
int M1IN1 = 6;
int M1IN2 = 7;
int M2IN1 = 8;
int M2IN2 = 9;
int M3IN1 = 10;
int M3IN2 = 11;
int M4IN1 = 12;
int M4IN2 = 13;

int Signal1 = 5;
int Signal2 = 4;
int Signal3 = 3;
int Signal4 = 2;

int Signal1E = LOW;
int Signal2E = LOW;
int Signal3E = LOW;
int Signal4E = LOW;

Servo servoMotor;


void setup() {
  // inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);
  servoMotor.attach(servoPin);
  // configuramos los pines como salida
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(MP1, OUTPUT);
  pinMode(MP2, OUTPUT);
  digitalWrite(MP1, LOW); // Apaga el motor inicialmente
  digitalWrite(MP2, LOW);
    
  pinMode(M1IN1, OUTPUT);
  pinMode(M1IN2, OUTPUT);
  pinMode(M2IN1, OUTPUT);
  pinMode(M2IN2, OUTPUT);
  pinMode(M3IN1, OUTPUT);
  pinMode(M3IN2, OUTPUT);
  pinMode(M4IN1, OUTPUT);
  pinMode(M4IN2, OUTPUT);
  digitalWrite(M1IN1,LOW);
  digitalWrite(M1IN2,LOW);
  digitalWrite(M2IN1,LOW);
  digitalWrite(M2IN2,LOW);
  digitalWrite(M3IN1,LOW);
  digitalWrite(M3IN2,LOW);
  digitalWrite(M4IN1,LOW);
  digitalWrite(M4IN2,LOW);
 
  pinMode(Signal1, INPUT);
  pinMode(Signal2, INPUT);
  pinMode(Signal3, INPUT);
  pinMode(Signal4, INPUT);
   
}

void loop() {
//delay(500);
  Serial.println(Signal1E);
   Serial.println(Signal2E);
    Serial.println(Signal3E);
     Serial.println(Signal4E);
  

  Signal1E = digitalRead(Signal1);
  Signal2E = digitalRead(Signal2);
  Signal3E = digitalRead(Signal3);
  Signal4E = digitalRead(Signal4);

   Detener();
   servoMotor.write(35);

  if (Signal1E == HIGH){
    Derecho();
  }
    if (Signal2E == HIGH){
    Detener();
  }
  if (Signal3E == HIGH){
    Derecha();
  }
  if (Signal4E == HIGH){
    Izquierda();
  }
  long tiempoEcho;
  float distancia;

  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);

    digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(10);
  

  tiempoEcho = pulseIn(ECHO_PIN, HIGH);
  distancia = tiempoEcho / 58.0;

  Serial.println(distancia);

  // Comprueba si la distancia medida es menor o igual a la distancia objetivo
  if (distancia <= distanciaObjetivo && distancia != 0) {
    // Enciende el motor
    digitalWrite(MP1, HIGH);
    digitalWrite(MP2, HIGH);
  } else {
    // Apaga el motor
    digitalWrite(MP1, LOW);
    digitalWrite(MP2, LOW);
  }



  
}

void Derecho (){
  digitalWrite (M1IN1, HIGH);
  digitalWrite (M2IN1, LOW);
  digitalWrite (M3IN1, LOW);
  digitalWrite (M4IN1, HIGH);
  digitalWrite (M1IN2, LOW);
  digitalWrite (M2IN2, HIGH);
  digitalWrite (M3IN2, HIGH);
  digitalWrite (M4IN2, LOW);
  
  
}

void Izquierda (){
  servoMotor.write(10);
  digitalWrite (M1IN1, HIGH);
  digitalWrite (M2IN1, LOW);
  digitalWrite (M3IN1, LOW);
  digitalWrite (M4IN1, HIGH);
  digitalWrite (M1IN2, LOW);
  digitalWrite (M2IN2, HIGH);
  digitalWrite (M3IN2, HIGH);
  digitalWrite (M4IN2, LOW);
  
}
 
void Derecha (){
  servoMotor.write(70);
  digitalWrite (M1IN1, HIGH);
  digitalWrite (M2IN1, LOW);
  digitalWrite (M3IN1, LOW);
  digitalWrite (M4IN1, HIGH);
  digitalWrite (M1IN2, LOW);
  digitalWrite (M2IN2, HIGH);
  digitalWrite (M3IN2, HIGH);
  digitalWrite (M4IN2, LOW);
  
}

void Detener (){
  digitalWrite (M1IN1, LOW);
  digitalWrite (M2IN1, LOW);
  digitalWrite (M3IN1, LOW);
  digitalWrite (M4IN1, LOW);
  digitalWrite (M1IN2, LOW);
  digitalWrite (M2IN2, LOW);
  digitalWrite (M3IN2, LOW);
  digitalWrite (M4IN2, LOW);
  
  
}