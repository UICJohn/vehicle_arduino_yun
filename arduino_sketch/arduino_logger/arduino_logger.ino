#include <Bridge.h>
#include <BridgeServer.h>
#include <BridgeClient.h>
#include <SoftwareSerial.h>
#include <OBD2UART.h>
#include <Process.h>
#include "config.h"

void setup() {
  Bridge.begin();
  Console.begin(); 
  while (!Console);
  int a = 1;
  String value[4] = {"\"1\"", "2", "3", "\"2002\""};
  insertToDB(vehicle, value, "vehicle", VEHICLE_SIZE);
}

void loop() {

}

unsigned int insertToDB(String cols[], String value[], String table, int col_size){
  Process p;
  String cmd = "sqlite3 -line "+database +" ";
  String columns_string = "' insert into " + table + " (";
  String values_string = "Values (";
  for(int i = 0 ;  i < col_size; i++) {
    columns_string = columns_string + '\"' + cols[i] + '\"';
    values_string = values_string + value[i];
    if(i != (col_size-1)){
      columns_string += ", ";
      values_string += ", ";
    }
  }
  cmd = cmd + columns_string + ") " +values_string + ") `";
  Console.print(cmd);
}
