#include <Servo.h>

#define M1 8
#define M2 9
#define M3 10
#define M4 11
#define M5 12
#define M6 13
#define M7 4
#define M8 5


#define ANG_M1 87
#define ANG_M2 86
#define ANG_M3 85

#define ANG_M4 86
#define ANG_M5 87
#define ANG_M6 87

#define ANG_M7 120
#define ANG_M8 90
#define LI 0
#define LS 180

#define CAM1_RIGHT_FWD '\xf5'
#define CAM1_LEFT_BWD '\xf6'
#define CAM1_LEFT '\xf7' 
#define CAM1_RIGHT '\xf8'
#define CAM2_UP '\xf9'
#define CAM2_DOWN '\xfa'
#define ADELANTE '\xfb'
#define RETROCEDER '\xfc'
#define IZQUIERDA '\xfd'
#define DERECHA '\xfe'
#define PARAR '\xff'

Servo motor1,motor2,motor3,motor4,motor5,motor6, cam1, cam2;
char cmd;

void setup(){
  
  atachar();
  ini();
  detachar();
  
  
  camatach();
  cam1.write(ANG_M7);
  cam2.write(ANG_M8);
  delay(1000);
  camdetach();
  Serial.begin(9600);
 
}

void loop(){
  if(Serial.available() > 0){
    cmd = (char) Serial.read();
    if(cmd == ADELANTE){
      Serial.println("adelante");
      avanzar();      
    }else{
      if(cmd == RETROCEDER){
        Serial.println("retroceder");
        retroceder();
      }else{
        if(cmd == IZQUIERDA){
          Serial.println("izquierda");
          izq();
        }else{
          if(cmd == DERECHA){
            Serial.println("derecha");
            der();
          }else{
            if(cmd == PARAR){
              Serial.println("parar");
              parar();
            }else{
              if(cmd == CAM1_LEFT){
                Serial.println("moviendo camara hacia la izq");
                cam1izq();
              }else{
                if(cmd == CAM1_RIGHT){
                  Serial.println("moviendo camara hacia la der");
                  cam1der();
                }else{
                  if(cmd == CAM2_UP){
                    Serial.println("moviendo camara hacia arriba");
                    cam2up();
                  }else{
                    if(cmd == CAM2_DOWN){
                      Serial.println("moviendo camara hacia abajo");
                      cam2down();                    
                    }else{
                      if(cmd == CAM1_LEFT_BWD){
                        Serial.println("moviendo camara hacia la izq BWD");
                        cam1izqbwd();
                      }else{
                        if(cmd == CAM1_RIGHT_FWD){
                          Serial.println("moviendo camara hacia la der FWD");
                          cam1derfwd();
                        }
                      }
                    }
                  }
                }
              }  
            }
          }
        }
      }
    }
  } 
  Serial.flush(); 
}


void detachar(){
  motor1.detach();
  motor2.detach();
  motor3.detach();
  motor4.detach();
  motor5.detach();
  motor6.detach();
    
}

void atachar(){
  motor1.attach(M1);
  motor2.attach(M2);
  motor3.attach(M3);
  motor4.attach(M4);
  motor5.attach(M5);
  motor6.attach(M6);
    
}


void camatach(){
    cam1.attach(M7);
    cam2.attach(M8);

}

void camdetach(){
    cam1.detach();
    cam2.detach();

}


void adelante(Servo motor, int li){
  if(li==1){
    motor.write(50);
  }else{
    motor.write(135);
  }
}

void atras(Servo motor, int li){
  if(li==1){
    motor.write(180);
  }else{
    motor.write(0);
  }

}


void parar(){
  ini();    
  detachar();
}

void izq(){
  atachar();
  adelante(motor1,0);
  adelante(motor3,0);
  adelante(motor5,0);
  atras(motor2,1);
  atras(motor4,1);
  atras(motor6,1);  
  delay(2000);
  detachar();
}

void der(){
 atachar();
 adelante(motor2,1);
 adelante(motor4,1);
 adelante(motor6,1);
 atras(motor1,0);
 atras(motor3,0);
 atras(motor5,0);
 delay(2000);
 detachar();
}

void avanzar(){
  atachar();
  adelante(motor1,0);
  adelante(motor2,1);
  adelante(motor3,0);
  adelante(motor4,1);
  adelante(motor5,0);
  adelante(motor6,1);
  delay(2000);
  detachar();
}

void retroceder(){
  atachar();
  atras(motor1,0);
  atras(motor3,0);
  atras(motor5,0);
  atras(motor2,1);
  atras(motor4,1);
  atras(motor6,1);
  delay(2000);
  detachar();
}

void cam1izq(){
  camatach();
  int ang = cam1.read() - 10;
  if(ang < LS && ang > LI){
    cam1.write(ang);
  }
  delay(100);
  camdetach();
}

void cam1izqbwd(){
  int nro = 0;
  camatach();
  Serial.println(cam1.read());
  int ang = cam1.read() - 35;
  if(ang < LS && ang > LI){
    while(nro < 7){
      cam1.write(cam1.read()-5);
      delay(70);
      nro = nro + 1;
    }
  }
  Serial.println(cam1.read());
  camdetach();

}

void cam1derfwd(){
  int nro = 0;
  camatach();
  Serial.println(cam1.read());
  int ang = cam1.read() + 35;
  if(ang < LS && ang > LI){
    while(nro < 7){
      cam1.write(cam1.read()+5);
      delay(70);
      nro = nro + 1;
    }
  }
  Serial.println(cam1.read());
  camdetach();
}

void cam1der(){
  camatach();
  int ang = cam1.read() + 10;
  if(ang < LS && ang > LI){
    cam1.write(ang);
  }
  delay(100);
  camdetach();

}

void cam2up(){
  camatach();
  int ang = cam2.read() + 10;
  if(ang < LS && ang > LI){
    cam2.write(ang);
  }
  delay(1000);
  camdetach();
}

void cam2down(){
  camatach();
  int ang = cam2.read() - 10;
  if(ang < LS && ang > LI){
    cam2.write(ang);
  }
  delay(1000);
  camdetach();
}

void ini(){
  motor1.write(ANG_M1);
  motor2.write(ANG_M2);
  motor3.write(ANG_M3);
  motor4.write(ANG_M4);
  motor5.write(ANG_M5);
  motor6.write(ANG_M6);
}










