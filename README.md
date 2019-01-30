# Remote-Health-Monitoring
	HEALTH MONITORING SYSTEM FOR MINING WORKERS

As per the given problem statement, we need to know the environment conditions of the mine workers. Some of which includes:
	1. Temperature of the area
	2. Humidity of the area
	3. Detection of any harmful gases.
	For temperature and humidity, we use DST sensors and for detecting any poisonous gas, we use a gas detector sensor.
*	RUN 'TempHum.ino' for DST working and detecting the analog range given by Gas Sensor.

	The SENSORS are connected to the database (Firebase) and UBIDOTS (a platform that I have used to send alert messages, and plotting of graphs) through the ESP8266 module and can be observed over the app (Screenshot of which has been provided.)
For measuring the body vitalities, we can consider many conditions like breathing rate, pulse rate, body temperature etc. But for the given case, only pulse rate and body temperature has been considered.
	Pulse sensor and Temperature sensors are connected to ESP8266 and Raspberry Pi respectively. Temperature is stored in database (FIREBASE), and Pulse is reflected in UBIDOTS. This can be seen through the app.
RUN “tempSensor.py” for Thermoprobe Sensor and “pulse.ino” to know about the pulse rate of the individual.


WORKING:
1.	Sensors will send data to firebase.
2.	From firebase, the app created from MIT app inventor will show data on your mobile screen.
3.	UBIDOTS will get data from the sensors and the ideal values will be set. If anytime the value given by the sensors goes above these ideal values, UBIDOTS will send alert messages/mails to the number/mail id provided beforehand.

CONNECTING FIREBASE TO APP (BACKEND) AND FOR TRIGGERING EFFECT:
 REFER READ_ME.DOCX
  


