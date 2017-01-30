from model import *

if __name__ == "__main__":
  
  try:
    StartUpCheck.create_table()
  except:
    print "TABLES ALREADY EXISTS!"

  try:
    MinsCheck.create_table()
  except:
    print "TABLES ALREADY EXISTS!"
  
  try:
    SecondsCheck.create_table()
  except:
    print "TABLES ALREADY EXISTS!"
  
  try:
    ErrorMsg.create_table()
  except:
    print "TABLES ALREADY EXISTS!"