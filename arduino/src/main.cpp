#include <Arduino.h>
#include "temperature.h"
#include "softap.h"
#define PIN 32

void simpleAnalogSensor(){
	
	Serial.write("Temperature: ");
	Serial.println(getTemperature(PIN));
}

#undef PIN

void setup(){

	//2 seconds before it starts
	Serial.begin(9600);
	delay(2000);
	Serial.println("Start");
	setup_scan();
}



void loop(){

	start_scan();

}
