#include <SPI.h>
#include "LedMatrix.h"

#define NUMBER_OF_DEVICES 1
#define CS_PIN D4

LedMatrix ledMatrix = LedMatrix(NUMBER_OF_DEVICES, CS_PIN);

int video_timer = 10000;
int delay_seed  = 200;
long current_flow = 0;

void DrawSnowRow(int row){
  if ( row!=7 ){
    for (int x=0+row%2; x<=7; x=x+2){
      ledMatrix.setPixel(x,row);
      ledMatrix.commit();
      delay(200);
    }
  } else {
    for (int x=0; x<=7; x++){
      ledMatrix.setPixel(x,row);
      ledMatrix.commit();
      delay(200);
      delay(100);
    }
  }
}

void DrawSnow_fall1(){
  ledMatrix.clear();
  ledMatrix.commit();
  for (int x=7; x>=0; x--){
    ledMatrix.setPixel(x,7);

    ledMatrix.commit();
  }

  for (int y=7; y>=0; y--){
    for (int x=7-y%2; x>=0; x=x-2){
      ledMatrix.setPixel(x,y);
      ledMatrix.commit();
    }
  }
  delay(200);
}
void DrawSnow_fall2(){
  ledMatrix.clear();
  ledMatrix.commit();
  for (int x=7; x>=0; x--){
    ledMatrix.setPixel(x,7);
    ledMatrix.commit();
  }

  for (int y=7; y>=0; y--){
    for (int x=7-y%2+1; x>=0; x=x-2){
      ledMatrix.setPixel(x,y);
      ledMatrix.commit();
    }
  }
  delay(200);
}

void setup() {
  ledMatrix.init();
  ledMatrix.setIntensity(8);
  ledMatrix.setText("3 H O B N M P O K O M");
  Serial.begin(9600);
}


void loop() {
  for (int t=0;t<=155;t++){
    Serial.println("Start draw");
    ledMatrix.clear();
    ledMatrix.scrollTextLeft();
    ledMatrix.drawText();
    ledMatrix.commit();
    delay(200);
  }
//    delay(5000);

    Serial.println("Snow fall");
    ledMatrix.clear();
    ledMatrix.commit();
    for (int y=0; y<=7; y++) {
        DrawSnowRow(y);
    }

    for (int i=0; i<=15; i++) {
        DrawSnow_fall2();
        DrawSnow_fall1();
    }
}
