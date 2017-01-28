#define TEMP_SIZE 1
#define VEHICLE_SIZE 4
#define VOLTAGE_SIZE 1

String database = "/root/work/vehicle_arduino_yun/my_vehicle.db";
String temperature_columns[TEMP_SIZE] = {"temperature"};
String voltage_columns[VOLTAGE_SIZE] = {"voltage"};
String vehicle[VEHICLE_SIZE] = {"brand", "model", "vin_number", "manufacture_at"};
