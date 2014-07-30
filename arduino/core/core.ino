#include <Servo.h>
#include "DHT11.h"
#include <string.h>

#define DHTPIN 3
#define DHTTYPE DHT11

#define M1 8
#define M2 9
#define M3 10
#define M4 11
#define M5 12
#define M6 13
#define M7 4
#define M8 5
#define M9 6
#define M10 7


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

#define TEMP_CALC '\xee'
#define CHANGE_MODE '\xef'
#define MEDIR_DIST '\xf0'
#define IR_RIGHT '\xf1'
#define IR_LEFT '\xf2'
#define MIC_UP '\xf3'
#define MIC_DOWN '\xf4'
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

Servo motor1,motor2,motor3,motor4,motor5,motor6, cam1, cam2, mic, ir;
char cmd;
int ir_sensor = A0;
DHT11 dht(DHTPIN);
void setup(){
  pinMode(DHTPIN, INPUT);
  atachar();
  ini();
  detachar();
  

  camatach();
  cam1.write(ANG_M7);
  cam2.write(ANG_M8);
  delay(1000);
  camdetach();
  
  mic.attach(M10);
  mic.write(80);
  delay(1000);
  mic.detach();
  
  ir.attach(M9);
  ir.write(70);
  delay(1000);
  ir.detach();
  
  
  Serial.begin(9600);
 
}

void loop(){
  if(Serial.available() > 0){
    cmd = (char) Serial.read();
    if(cmd == ADELANTE){
      //Serial.println("adelante");
      avanzar();      
    }else{
      if(cmd == RETROCEDER){
        //Serial.println("retroceder");
        retroceder();
      }else{
        if(cmd == IZQUIERDA){
          //Serial.println("izquierda");
          izq();
        }else{
          if(cmd == DERECHA){
            //Serial.println("derecha");
            der();
          }else{
            if(cmd == PARAR){
              //Serial.println("parar");
              parar();
            }else{
              if(cmd == CAM1_LEFT){
                //Serial.println("moviendo camara hacia la izq");
                cam1izq();
              }else{
                if(cmd == CAM1_RIGHT){
                  //Serial.println("moviendo camara hacia la der");
                  cam1der();
                }else{
                  if(cmd == CAM2_UP){
                    //Serial.println("moviendo camara hacia arriba");
                    cam2up();
                  }else{
                    if(cmd == CAM2_DOWN){
                      //Serial.println("moviendo camara hacia abajo");
                      cam2down();                    
                    }else{
                      if(cmd == CAM1_LEFT_BWD){
                        //Serial.println("moviendo camara hacia la izq BWD");
                        cam1izqbwd();
                      }else{
                        if(cmd == CAM1_RIGHT_FWD){
                          //Serial.println("moviendo camara hacia la der FWD");
                          cam1derfwd();
                        }else{
                          if(cmd == MIC_DOWN){
                            //Serial.println("moviendo microscopio hacia abajo");
                            micdown();
                          }else{
                            if(cmd == MIC_UP){
                              //Serial.println("moviendo microscopio hacia arriba");
                              micup();
                            }else{
                              if(cmd == IR_LEFT){
                                irder();
                              }else{
                                if(cmd == IR_RIGHT){
                                  irizq();
                                }else{
                                  if(cmd == MEDIR_DIST ){
                                    medir();
                                  }else{
                                    if(cmd == CHANGE_MODE){
                                      //Serial.println("cambiando de modo");
                                      changemode();
                                    }else{
                                      if(cmd == TEMP_CALC){
                                        readtemph();
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

void micup(){
  mic.attach(M10);
  Serial.println(Serial.read());
  for(int i = 110; i > 90; i--){
    mic.write(mic.read()-5);
    delay(70);
  }
  Serial.println(mic.read());
  mic.detach();
}

void micdown(){
  mic.attach(M10);
  Serial.println(Serial.read());
  for(int i = 90; i < 110; i++){
    mic.write(mic.read() + 5);
    delay(70);
  }
  Serial.println(mic.read());
  mic.detach();
}

void ini(){
  motor1.write(ANG_M1);
  motor2.write(ANG_M2);
  motor3.write(ANG_M3);
  motor4.write(ANG_M4);
  motor5.write(ANG_M5);
  motor6.write(ANG_M6);
}

void irder(){
  ir.attach(M9);
  Serial.println(ir.read());
  if(ir.read() == 70){
    for(int i = 0; i < 14; i++){
    ir.write(ir.read() - 5);
    delay(70);
    }
  }else{
    for(int i = 0; i < 22; i++){
    ir.write(ir.read() - 5);
    delay(70);
    }
  }
  ir.detach();
}

void irizq(){
  ir.attach(M9);
  Serial.println(ir.read());
  if(ir.read() == 70){
    for(int i = 0; i < 22 ; i++){
    ir.write(ir.read() + 5);
    delay(70);
    }
  }else{
    //if(ir.read() == 0){
      for(int i = 0; i < 14; i++){
        ir.write(ir.read() + 5);
        delay(70);
      }
    //}
  }
  ir.detach();
}

void readtemph(){
  float temp, humedad;
  dht.read(humedad,temp);
  delay(100);
  String puntos = ":";
  char tmp[10];
  char hm[10];
  dtostrf(temp,1,2,tmp);
  dtostrf(humedad,1,2,hm);
  String lectura = tmp + puntos;
  String medicion = lectura + hm; 
  Serial.println(medicion);
  
}

void medir(){
  int lectura, cm;
  lectura = analogRead(ir_sensor); //lectura del sensor ir
  cm = pow(3027.4/lectura, 1.2134); //conversion a centimetros
  Serial.println(cm);
  delay(100);
}

void changemode(){

}
