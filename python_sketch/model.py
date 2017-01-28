from peewee import *
import sys
from datetime import datetime

db = SqliteDatabase('/root/work/vehicle_arduino_yun/my_vehicle.db')

class Base(Model):
  class Meta:
    database = db 
  
  def all():
    select()

class StartUpCheck(Base):
  voltage = FloatField()
  ignition_time = FloatField()
  created_at = DateTimeField(default = datetime.now().strftime('%Y-%m-%d %H:%M'))

class MinsCheck(Base):
  engine_oil_temp = IntegerField()
  coolant_temp = IntegerField()
  engine_load = IntegerField()
  engine_torque = IntegerField()
  intake_temp = IntegerField()
  intake_pressure = IntegerField()
  ambient_temp = IntegerField()
  created_at = DateTimeField(default = datetime.now().strftime('%Y-%m-%d %H:%M'))

class SecondsCheck(Base):
  speed = IntegerField()
  rpm = IntegerField()
  throttle = IntegerField()
  created_at = DateTimeField(default = datetime.now().strftime('%Y-%m-%d %H:%M:%S'))

class ErrorMsg(Base):
  code = CharField()
  created_at = DateTimeField(default = datetime.now().strftime('%Y-%m-%d %H:%M'))

class VehicleInfo(Base):
  brand = CharField()
  model = CharField()
  vin_number = CharField()
  manufactured_at = DateTimeField()
  created_at = DateTimeField(default = datetime.now().strftime('%Y-%m-%d %H:%M'))
  updated_at = DateTimeField(default = datetime.now)