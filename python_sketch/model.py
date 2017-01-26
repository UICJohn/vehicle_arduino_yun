from peewee import *
from datetime import datetime
db = SqliteDatabase('my_vehicle.db')

class Base(Model):
  class Meta:
    database = db 

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