// Alarm_Clock_v1.0
// Author: Sergio Vigorra Treviño
// e-mail: svigorra@gmail.com

#include <LiquidCrystal.h>                          

int MODO=1;
int Horas;
int Minutos;
int Segundos;
int Resto;
int Numero=1;
int PIN_Boton_Cambio_Modo = 3;
int PIN_Boton_Cambio_Numero = 4;
int PIN_Numero_Arriba = 5;
int PIN_Paro_Alarma = 6;
long Contador_segundos=43500;
long Contador_segundos_Alarma=43510;
long current_time;
long reference_time;
int Modo_Alarma = 1;
LiquidCrystal myLCD(7,8,9,10,11,12);
int ALARMA=0;
float lectura_fotorresistencia=0;

void setup(){
  myLCD.begin(16,2);
  pinMode(A0,INPUT);
}

void loop(){
  
  if (Contador_segundos>86400){
    Contador_segundos=Contador_segundos-86400;
  }
  
  if (Contador_segundos_Alarma>86400){
    Contador_segundos_Alarma=Contador_segundos_Alarma-86400;
  }
  
  if (digitalRead(PIN_Boton_Cambio_Modo)==HIGH) {
    MODO++; 
    if (MODO==4){
      MODO=1;
    }
    delay(500);
  }
  
  switch (MODO) {
    case 1:
      
      if (Modo_Alarma == 1 && Contador_segundos_Alarma == Contador_segundos){
        ALARMA = 1;
        lectura_fotorresistencia=analogRead(A0);
      }
      
      if (ALARMA ==1){
        tone(13,1519);
      }
      
      if (ALARMA==0){
        noTone(13);}
      
      if (digitalRead(PIN_Paro_Alarma) || (analogRead(A0) <= 0.8*lectura_fotorresistencia)){
        ALARMA=0;
        lectura_fotorresistencia=0;
        
      }
  
      
      Horas=Contador_segundos/3600;  //Calcular Horas
      Resto=Contador_segundos%3600;
      Minutos=Resto/60;              //Calcular Minutos
      Segundos=Resto%60;             //Calcular Segundos 
      myLCD.setCursor(2,0);
      if (Horas/10==0){
        myLCD.print("0");
      }
      myLCD.print(Horas);
      myLCD.print(":");
      if (Minutos/10==0){
        myLCD.print("0");
      }
      myLCD.print(Minutos);
      myLCD.print(":");
      if (Segundos/10==0){
        myLCD.print("0");
      }
      myLCD.print(Segundos);
      
      
      //3 variables, current_time, previous_time, reference_time
      current_time=millis();
      if (current_time-reference_time >= 1000) {
        reference_time=current_time;
        Contador_segundos++;
      }
      
      
      
      //do something when var equals 1
      break;
    
    
    
    
    case 2:   //Ajuste HORA
      
      //Numero=1 es hora, Numero=2 es Minutos, Numero=3 es segundos
      
      if (digitalRead(PIN_Boton_Cambio_Numero)==HIGH) {
        Numero++;
        if (Numero==4){
          Numero=1;
        }
        delay(500);
      }
      
      if (digitalRead(PIN_Numero_Arriba)==HIGH){
        
        if (Numero==1){
          Contador_segundos=Contador_segundos+3600;
        }
        
        if (Numero==2){
          Contador_segundos=Contador_segundos+60;
        }
        
        if (Numero==3){
          Contador_segundos=Contador_segundos+1;
        }
      
        delay(500);
      }      
      
      
      
      
    
      Horas=Contador_segundos/3600;  //Calcular Horas
      Resto=Contador_segundos%3600;
      Minutos=Resto/60;              //Calcular Minutos
      Segundos=Resto%60;             //Calcular Segundos 
      myLCD.setCursor(2,0);
      if (Horas/10==0){
        myLCD.print("0");
      }
      myLCD.print(Horas);
      myLCD.print(":");
      if (Minutos/10==0){
        myLCD.print("0");
      }
      myLCD.print(Minutos);
      myLCD.print(":");
      if (Segundos/10==0){
        myLCD.print("0");
      }
      myLCD.print(Segundos);
      break;
    case 3:   //Ajuste HORA Alarma
      
      //Numero=1 es hora, Numero=2 es Minutos, Numero=3 es segundos
      
      if (digitalRead(PIN_Boton_Cambio_Numero)==HIGH) {
        Numero++;
        if (Numero==4){
          Numero=1;
        }
        delay(500);
      }
      
      if (digitalRead(PIN_Numero_Arriba)==HIGH){
        
        if (Numero==1){
          Contador_segundos_Alarma=Contador_segundos_Alarma+3600;
        }
        
        if (Numero==2){
          Contador_segundos_Alarma=Contador_segundos_Alarma+60;
        }
        
        if (Numero==3){
          Contador_segundos_Alarma=Contador_segundos_Alarma+1;
        }
      
        delay(500);
      }      
      
      
      
      
    
      Horas=Contador_segundos_Alarma/3600;  //Calcular Horas
      Resto=Contador_segundos_Alarma%3600;
      Minutos=Resto/60;              //Calcular Minutos
      Segundos=Resto%60;             //Calcular Segundos 
      myLCD.setCursor(2,0);
      if (Horas/10==0){
        myLCD.print("0");
      }
      myLCD.print(Horas);
      myLCD.print(":");
      if (Minutos/10==0){
        myLCD.print("0");
      }
      myLCD.print(Minutos);
      myLCD.print(":");
      if (Segundos/10==0){
        myLCD.print("0");
      }
      myLCD.print(Segundos);  
 break;     
    
  
}
}
