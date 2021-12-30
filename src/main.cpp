#include <Arduino.h>
#include "temperature.h"


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

}



void loop(){
	while (true){
		delay(500);
		simpleAnalogSensor();
	}
}
