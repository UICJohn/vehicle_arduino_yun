#include <ILI9341_due_config.h>
#include <ILI9341_due.h>
#include "fonts/digit.h"
#include "fonts/font.h"
#include <Event.h>
#include <Timer.h>

#include <OBD2UART.h>
#include <Process.h>
#include <SoftwareSerial.h>
#include "config.h"

#define TFT_CS 5 // Chip Select for LCD
#define TFT_DC 6  // Command/Data for LCD
#define TFT_RST 4 // Command/Data for LCD
#define TFT_LED 7

ILI9341_due tft = ILI9341_due(TFT_CS, TFT_DC, TFT_RST);
//Timer t;

gTextArea speedArea{ 40, 40, 240, 150 };
int rpm = 1000;
COBD obd;
void setup() {
  obd.begin();
  tft.begin();
  pinMode(TFT_LED, OUTPUT);
  digitalWrite(TFT_LED, HIGH);
  tft.setRotation(iliRotation270);
  tft.fillScreen(ILI9341_WHITE);
  lcdPrint("Welcome", 60, 90, 2);
  delay(3000);
  tft.clearTextArea();
  digitalWrite(TFT_LED, LOW);
  while(!obd.init());
  lcdPrint("km/h", 140, 170, 1);
  if(errorExisted()){
    obd.clearDTC(); 
  }
}

void lcdPrint(String str,int x, int y, int scale){
  tft.setTextColor(ILI9341_BLUE, ILI9341_WHITE);
  tft.setFont(font);
  tft.setTextScale(scale);
  tft.printAt(str, x, y);
}

void loop(){
  readPID();
  delay(50);
}


void printInfo(int sp){
  tft.setTextArea(speedArea);
  tft.setFont(digit);
  tft.setTextScale(2);
  if(sp >= 10 && sp <100){
    tft.printAt(String(sp), 60, 20, 30, 30);
  }
  else if(sp >= 100){
    tft.printAt(String(sp), 30+(sp-100)/10, 30, 30, 30);
  }else{
    tft.printAt(String(sp), 90, 20, 30, 30);
  }
}

void readPID(){
  static const byte pids[] = {PID_SPEED, PID_RPM};
  int values[sizeof(pids)];
  if(obd.readPID(pids, sizeof(pids), values) == sizeof(pids)){
    if(values[1] != 0){
      digitalWrite(TFT_LED, HIGH); 
    }
    printInfo(values[0]);
    rpm = values[1];
  }else{
    digitalWrite(TFT_LED, LOW);
    while(!obd.init());
  }
  
}

void processDTC(){
  unsigned int codes[6];
  if(obd.readDTC(codes, 6) != 0){
    //process DTC
  }
}

boolean errorExisted(){
  unsigned int codes[6];
  if(obd.readDTC(codes, 6) != 0){
    return true;
  }
  return false;
}

void clearDTC(){
  obd.clearDTC();
}
