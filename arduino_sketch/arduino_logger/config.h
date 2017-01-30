#define TEMP_SIZE 1
#define STARTUP_CHECK_SIZE 2
#define MINSCHECK_SIZE 7
#define SECHECK_SIZE 3
#define EMSG_SIZE 1
String database = "/root/work/vehicle_arduino_yun/my_vehicle.db";
String startUpCheck[STARTUP_CHECK_SIZE] = {"voltage", "ignition_time"};
String minsCheck[MINSCHECK_SIZE] = {"engine_oil_temp", "coolant_temp", "engine_load", "engine_torque", "intake_temp","intake_pressure", "ambient_temp"};
String secondsCheck[SECHECK_SIZE] = {"speed", "rpm", "throttle"};
String eMsg[EMSG_SIZE] = {"code"};
