#include <OBD2UART.h>
#include <Process.h>
#include <SoftwareSerial.h>
#include "config.h"

COBD obd;

void setup() {
  Console.begin(); 
  while (!Console);
  String value[4] = {"12", "5"};
  insertToDB(startUpCheck, value, "startupcheck", STARTUP_CHECK_SIZE);
}

void loop(){

}

unsigned int insertToDB(String cols[], String value[], String table, int col_size){
  Process p;
  String cmd = "sqlite3 -line "+database +" ";
  String columns_string = "'insert into " + table + " (";
  String values_string = "Values (";
  for(int i = 0 ;  i < col_size; i++) {
    columns_string = columns_string + '\"' + cols[i] + '\"';
    values_string = values_string + '\"'+value[i] + '\"';
    if(i != (col_size-1)){
      columns_string += ", ";
      values_string += ", ";
    }
  }
  cmd = cmd + columns_string + ") " +values_string + ")'";
  p.runShellCommand(cmd);
}



void readPID(){
  static const byte pids[] = {};
  int values[sizeof(pids)];
  if(obd.readPID(pids, sizeof(pids), values)){
    // process pid  
  }else{
    // error log
  }
}

void processDTC(){
  unsigned int codes[6];
  if(obd.readDTC(codes, 6) != 0){
    //process DTC
  }
}

void clearDTC(){
  obd.clearDTC();
}
