#include <Arduino.h>
#include <string>
#include <cmath>

#define PIN 32

double temp(int in){
	
	float R1 = 10000;
	float logR2, R2, T;
	float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
	
	R2 = R1 * (1023.0 / (float)in - 1.0);
	logR2 = log(R2);
	T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
	T = T - 273.15;

	return T;
}

void simpleAnalogSensor(){
	int val = analogRead(PIN);
	Serial.println(val);
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
