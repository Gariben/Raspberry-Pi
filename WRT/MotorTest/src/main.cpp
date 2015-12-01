#include <wiringPi.h>
#include <stdio.h>
#include <iostream>
#include <softPwm.h>
#include <string.h>

using namespace std;

int main(){


	wiringPiSetup();
	static const int led = 0;
	static const int m_iMotor1Speed = 1;
	static const int m_iMotor1A = 2;
	static const int m_iMotor1B = 4;

	static const int m_iMotor2Speed = 23;
	static const int m_iMotor2A = 24;
	static const int m_iMotor2B = 25;

	pinMode(led, OUTPUT);
	pinMode(m_iMotor1Speed, OUTPUT);
	pinMode(m_iMotor1A, OUTPUT);
	pinMode(m_iMotor1B, OUTPUT);

	pinMode(m_iMotor2Speed, OUTPUT);
	pinMode(m_iMotor2A, OUTPUT);
	pinMode(m_iMotor2B, OUTPUT);

for (;;){
	digitalWrite(led, HIGH);
//Spin Motor 1 slowly forward -------------------------------------------------------------------------------
	printf("Motor 1 slowly forward.\n");
	softPwmCreate(m_iMotor1Speed, 0, 100);
	softPwmWrite(m_iMotor1Speed, 50);
	digitalWrite(m_iMotor1Speed, HIGH);

	digitalWrite(m_iMotor1A, HIGH);
	digitalWrite(m_iMotor1B, LOW);

	cin.ignore();
//Spin Motor 1 quickly forward ------------------------------------------------------------------------------
	printf("Motor 1 quickly forward.\n");
	softPwmWrite(m_iMotor1Speed, 100);

	digitalWrite(m_iMotor1A, HIGH);
	digitalWrite(m_iMotor1B, LOW);

	cin.ignore();

//Spin Motor 1 slowly backward ------------------------------------------------------------------------------
	printf("Motor 1 slowly backward.\n");

	softPwmWrite(m_iMotor1Speed, 50);

	digitalWrite(m_iMotor1A, LOW);
	digitalWrite(m_iMotor1B, HIGH);

	cin.ignore();

//Spin Motor 1 quickly backward -----------------------------------------------------------------------------
	printf("Motor 1 quickly backward.\n");

	softPwmWrite(m_iMotor1Speed, 100);

	digitalWrite(m_iMotor1A, LOW);
	digitalWrite(m_iMotor1B, HIGH);

	cin.ignore();

//==========================================================================================================
	softPwmWrite(m_iMotor1Speed, 0);
	digitalWrite(m_iMotor1A, LOW);
	digitalWrite(m_iMotor1B, LOW);


//==========================================================================================================


	digitalWrite(led, LOW);
//Spin Motor 2 slowly forward -------------------------------------------------------------------------------
	printf("Motor 2 slowly forward.\n");

	softPwmCreate(m_iMotor2Speed, 0, 100);
	softPwmWrite(m_iMotor2Speed, 50);

	digitalWrite(m_iMotor2A, HIGH);
	digitalWrite(m_iMotor2B, LOW);


	cin.ignore();

//Spin Motor 2 quickly forward ------------------------------------------------------------------------------
	printf("Motor 2 quickly forward.\n");

	softPwmWrite(m_iMotor2Speed, 100);

	digitalWrite(m_iMotor2A, HIGH);
	digitalWrite(m_iMotor2B, LOW);

	cin.ignore();

//Spin Motor 2 slowly backward ------------------------------------------------------------------------------
	printf("Motor 2 slowly backward.\n");

	softPwmWrite(m_iMotor2Speed, 50);

	digitalWrite(m_iMotor2A, LOW);
	digitalWrite(m_iMotor2B, HIGH);

	cin.ignore();
//Spin Motor 2 quickly backward -----------------------------------------------------------------------------
	printf("Motor 2 quickly backward.\n");


	softPwmWrite(m_iMotor2Speed, 100);

	digitalWrite(m_iMotor2A, LOW);
	digitalWrite(m_iMotor2B, HIGH);

	cin.ignore();
//==========================================================================================================

	softPwmWrite(m_iMotor2Speed, 0);
	digitalWrite(m_iMotor2A, LOW);
	digitalWrite(m_iMotor2B, LOW);

//==========================================================================================================

//Forward Combo---------------------------------------------------------------------------------------------


//Backward Combo---------------------------------------------------------------------------------------------


//Left Combo---------------------------------------------------------------------------------------------


//Right Combo---------------------------------------------------------------------------------------------

}
	return 0;
}
