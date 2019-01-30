import RPi.GPIO as GPIO
from time import sleep
import datetime
from firebase import firebase

import urllib2,urllib,httplib
import json
import os
from functools import partial

firebase = firebase.FirebaseApplication("https://temperature-e4e01.firebase.com/",None)		#firebase URL link to connect the prog to firebase

firebase.put("tempe","/alert","0")

GPIO.setmode(GPIO.BOARD)
GPIO.setup(7,GPIO.IN)
GPIO.setwarnings(False)
GPIO.cleanup()

from w1thermsensor import W1ThermSensor

sensor = W1ThermSensor()

while 1:
	temp = sensor.get_temperature()
	print("The temperature is %s celsius" % temp)
	time.sleep(2)
	firebase.put("tempe","/alert", temp)