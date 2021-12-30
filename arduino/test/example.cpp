#include <unity.h>
#include <Arduino.h>
#include <list>

//Function pointer to list all tests

typedef void (*test)();

void setUp(void){
	//All the needed setup variables here
}

void tearDown(void){
	//All the needed teardown values here
}


void test1(){
	TEST_ASSERT_EQUAL(1 + 1, 2);
}

void test2(){
	TEST_ASSERT_EQUAL("string", "string");
}


void setup(){
	
	//List all tests here
	std::list<test> tests = std::list<test>({test1,test2});



	//If the program doesn't support software reset
	delay(2000);
	
	UNITY_BEGIN();
	
	for (auto t : tests) RUN_TEST(t);

	UNITY_END();
}


void loop(){}
