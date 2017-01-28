from peewee import *
import sys
from datetime import datetime

db = SqliteDatabase('/root/work/vehicle_arduino_yun/my_vehicle.db')

class Base(Model):
  class Meta:
    database = db 
  
  def all():
    select()

class Temperature(Base):
  temperature = FloatField()
  created_at = DateTimeField(default = datetime.now().strftime('%Y-%m-%d %H:%M:%S'))

class Voltage(Base):
  voltage = FloatField()
  created_at = DateTimeField(default = datetime.now().strftime('%Y-%m-%d %H:%M:%S'))

class Vehicle(Base):
  brand = CharField()
  model = CharField()
  vin_number = CharField()
  manufactured_at = DateTimeField()
  created_at = DateTimeField(default = datetime.now().strftime('%Y-%m-%d %H:%M:%S') )
  updated_at = DateTimeField(default = datetime.now)