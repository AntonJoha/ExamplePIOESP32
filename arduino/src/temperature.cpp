#include "temperature.h"
#include <cmath>
#include <Arduino.h>

double getTemp(int in);

double getTemperature(int IO){
	
	int val = analogRead(IO);
	return getTemp(val);
}


double getTemp(int in){
	float R1 = 10000;
	float logR2, R2, T;
	float c1 = 0.00112918, c2 = 0.000234125, c3 = 0.0000000876741;
	R2 = R1 * (4096.0 / (float)in - 1.0);
	logR2 = log(R2);
	T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
	T = T - 273.15;
	return T;
}
