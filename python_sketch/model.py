from peewee import *
import sys
from datetime import datetime

db = SqliteDatabase('my_vehicle.db')
tables = ["temperature", "vehicle", "voltage"]

class Base(Model):
  class Meta:
    database = db 
  
  def all():
    select()

class Temperature(Base):
  temperature = FloatField()
  created_at = DateTimeField(default=datetime.now)

class Voltage(Base):
  voltage = FloatField()
  created_at = DateTimeField(default=datetime.now)

class Vehicle(Base):
  brand = CharField()
  model = CharField()
  vin_number = CharField()
  manufactured_at = DateTimeField()
  created_at = DateTimeField(default=datetime.now)
  updated_at = DateTimeField(default=datetime.now)

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
  