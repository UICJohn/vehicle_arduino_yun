from model import *

if __name__ == "__main__":
  try:
    Vehicle.create_table()
  except:
    print "TABLES ALREADY EXISTS!"

  try:
    Temperature.create_table()
  except:
    print "TABLES ALREADY EXISTS!"
  
  try:
    Voltage.create_table()
  except:
    print "TABLES ALREADY EXISTS!"
  