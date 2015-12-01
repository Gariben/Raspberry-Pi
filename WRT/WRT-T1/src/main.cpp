/*
------------------------------------------------------------------------------

project: TinyTank, Raspberry-pi based teleoperated tank.
Program: TinyTank driver program
Author: Jacob Arlo Leibeck / Gariben
Revision: v1

Overview:
This program takes wiimote inputs via usb bluetooth adapter, and turns them
into digital outputs for SN754410-based motor shield.


External Libraries: WiiC, WiringPi
Hardwares: Raspberry Pi, Wiimote/BlueTooth, GPIO/H-bridge

Project information can be found at:
http://leibeckj.blogspot.com/2015/11/wrt-t1-wireless-raspberry-pi-tank.html

Repository can be found at:
https://github.com/Gariben/Raspberry-Pi/tree/master/WRT/WRT-T1

=============================================================================
*/




#include <wiringPi.h>
#include <softPwm.h>
#include <wiicpp.h>
#include <string.h>

using namespace std;

CWii wii;
static const string HEADER = "TinyTank.v1: ";

class Shield{
	//Motor shield as class
	//So that it can be destructed!

	//WiringPi pinout:
	//Pin 0: indicator LED
	//Pin 1: Motor 1, pole 1
	//Pin 2: Motor 1, pole 2
	//Pin 3: Motor 2, pole 1
	//Pin 4: Motor 2, pole 2

  public:
	static const int m_iLED = 0;
	static const int m_iMotor1Speed = 1;
	static const int m_iMotor1A = 2;
	static const int m_iMotor1B = 4;

	static const int m_iMotor2Speed = 23;
	static const int m_iMotor2A = 24;
	static const int m_iMotor2B = 25;

	Shield(){
		pinMode(m_iLED, OUTPUT);
		pinMode(m_iMotor1Speed, OUTPUT);
		pinMode(m_iMotor1A, OUTPUT);
		pinMode(m_iMotor1B, OUTPUT);

		pinMode(m_iMotor2Speed, OUTPUT);
		pinMode(m_iMotor2A, OUTPUT);
		pinMode(m_iMotor2B, OUTPUT);

		softPwmCreate(m_iMotor1Speed, 0, 100);
		softPwmCreate(m_iMotor2Speed, 0, 100);
	};

	~Shield(){
		digitalWrite(m_iLED, LOW);
		digitalWrite(m_iMotor1A, LOW);
		digitalWrite(m_iMotor1B, LOW);
		digitalWrite(m_iMotor2A, LOW);
		digitalWrite(m_iMotor2B, LOW);
	};


	void Glow(){
		digitalWrite(m_iLED, HIGH);
	};

	void BlinkOnce(){
		digitalWrite(m_iLED, HIGH);
		delay(200);
		digitalWrite(m_iLED, LOW);
		delay(200);
	};

    	void Forward(){
		softPwmWrite(m_iMotor1Speed, 100);
		digitalWrite(m_iMotor1A, HIGH);
		digitalWrite(m_iMotor1B, LOW);

		softPwmWrite(m_iMotor2Speed, 100);
		digitalWrite(m_iMotor2A, HIGH);
		digitalWrite(m_iMotor2B, LOW);
	};

	void Reverse(){
		softPwmWrite(m_iMotor1Speed, 100);
		digitalWrite(m_iMotor1A, LOW);
		digitalWrite(m_iMotor1B, HIGH);

		softPwmWrite(m_iMotor2Speed, 100);
		digitalWrite(m_iMotor2A, LOW);
		digitalWrite(m_iMotor2B, HIGH);
	};

	void Left(){
		softPwmWrite(m_iMotor1Speed, 100);
		digitalWrite(m_iMotor1A, LOW);
		digitalWrite(m_iMotor1B, HIGH);

		softPwmWrite(m_iMotor2Speed, 100);
		digitalWrite(m_iMotor2A, HIGH);
		digitalWrite(m_iMotor2B, LOW);
	};

	void Right(){
		softPwmWrite(m_iMotor1Speed, 100);
		digitalWrite(m_iMotor1A, HIGH);
		digitalWrite(m_iMotor1B, LOW);

		softPwmWrite(m_iMotor2Speed, 100);
		digitalWrite(m_iMotor2A, LOW);
		digitalWrite(m_iMotor2B, HIGH);
	};

	void ForwardLeft(){
		softPwmWrite(m_iMotor1Speed, 50);
		digitalWrite(m_iMotor1A, HIGH);
		digitalWrite(m_iMotor1B, LOW);

		softPwmWrite(m_iMotor2Speed, 100);
		digitalWrite(m_iMotor2A, HIGH);
		digitalWrite(m_iMotor2B, LOW);

	};

	void ForwardRight(){

		softPwmWrite(m_iMotor1Speed, 100);
		digitalWrite(m_iMotor1A, HIGH);
		digitalWrite(m_iMotor1B, LOW);

		softPwmWrite(m_iMotor2Speed, 50);
		digitalWrite(m_iMotor2A, HIGH);
		digitalWrite(m_iMotor2B, LOW);
	};

	void ReverseLeft(){
		softPwmWrite(m_iMotor1Speed, 50);
		digitalWrite(m_iMotor1A, LOW);
		digitalWrite(m_iMotor1B, HIGH);

		softPwmWrite(m_iMotor2Speed, 100);
		digitalWrite(m_iMotor2A, LOW);
		digitalWrite(m_iMotor2B, HIGH);
	};

	void ReverseRight(){
		softPwmWrite(m_iMotor1Speed, 100);
		digitalWrite(m_iMotor1A, LOW);
		digitalWrite(m_iMotor1B, HIGH);

		softPwmWrite(m_iMotor2Speed, 50);
		digitalWrite(m_iMotor2A, LOW);
		digitalWrite(m_iMotor2B, HIGH);

	};


	void Kill(){
		softPwmWrite(m_iMotor1Speed, 0);
		digitalWrite(m_iMotor1A, LOW);
		digitalWrite(m_iMotor1B, LOW);

		softPwmWrite(m_iMotor2Speed, 0);
		digitalWrite(m_iMotor2A, LOW);
		digitalWrite(m_iMotor2B, LOW);
	};
};


bool HandleInput(CWiimote &wm, Shield &mc, int &count){
	printf("%s\tInput Received:\n", HEADER.c_str());

	if(wm.Buttons.isPressed(CButtons::BUTTON_HOME)){
		printf("%s\t\tHOME (exit code)\n", HEADER.c_str());
		mc.Kill();
		return false;
	}

	if(wm.Buttons.isPressed(CButtons::BUTTON_ONE)){
		printf("%s\t\tREVERSE\n", HEADER.c_str());
		mc.Reverse();

		if(wm.Buttons.isPressed(CButtons::BUTTON_DOWN)){
			printf("%s\t\tREVERSE RIGHT\n", HEADER.c_str());
			mc.ReverseRight();
			return true;
		}

		if(wm.Buttons.isPressed(CButtons::BUTTON_UP)){
			printf("%s\t\tREVERSE LEFT\n", HEADER.c_str());
			mc.ReverseLeft();
			return true;
		}

		return true;
	}


	if(wm.Buttons.isPressed(CButtons::BUTTON_TWO)){
		printf("%s\t\tFORWARD\n", HEADER.c_str());
		mc.Forward();

		if(wm.Buttons.isPressed(CButtons::BUTTON_DOWN)){
			printf("%s\t\tFORWARD RIGHT\n", HEADER.c_str());
			mc.ForwardRight();
			return true;
		}

		if(wm.Buttons.isPressed(CButtons::BUTTON_UP)){
			printf("%s\t\tFORWARD LEFT\n", HEADER.c_str());
			mc.ForwardLeft();
			return true;
		}

		return true;
	}

	if(wm.Buttons.isPressed(CButtons::BUTTON_UP)){
		printf("%s\t\tLEFT\n", HEADER.c_str());
		mc.Left();
		return true;
	}

	if(wm.Buttons.isPressed(CButtons::BUTTON_DOWN)){
		printf("%s\t\tRIGHT\n", HEADER.c_str());
		mc.Right();
		return true;
	}


	printf("%s\t\tNEUTRAL\n", HEADER.c_str());
	mc.Kill();
	return true;

}


int main(){


//wiringPi setup--------------------------------------------------------------
	wiringPiSetup();
	Shield gpio;

	bool bSpin = true;
	bool bReconnect = false;
//wiimote synack-------------------------------------------------------------

 	std::vector<CWiimote>& wiimotes = wii.FindAndConnect(1);

	while(!wiimotes.size()) {
		printf("%sAttempting to connect to wiimote...\n", HEADER.c_str());
		wiimotes = wii.FindAndConnect(1);
		gpio.BlinkOnce();
		delay(200);
	}


	gpio.Glow();
	CWiimote& wiimote = wiimotes[0];
	wiimote.SetLEDs(CWiimote::LED_1);

	printf("\n***********************************************************************\n");
	printf("%sBeginning Control sequence:\n\n\n", HEADER.c_str());

		int count = 1;

	do{
		if(bReconnect){
			// Regenerate the list of wiimotes
			printf("%sUnexpected disconnect. Attempting to reconnect...\n", HEADER.c_str());
			wiimotes = wii.GetWiimotes();
			bReconnect = false;
		}

		bool sync = false;



		if(wii.Poll()){
				CWiimote & wiimote = *wiimotes.begin();
				switch(wiimote.GetEvent()){
					case CWiimote::EVENT_EVENT:
						bSpin = HandleInput(wiimote, gpio, count);
						count++;
						break;
					case CWiimote::EVENT_DISCONNECT:
					case CWiimote::EVENT_UNEXPECTED_DISCONNECT:
						bReconnect = true;
						break;
					default:
						break;
					}
			}
	} while(wiimotes.size() && bSpin); 

	printf("\n***********************************************************************\n");


	printf("%sExiting Application.\n", HEADER.c_str());
	digitalWrite(0, LOW);
	//Shield destructor automatically kills pins!
	return 0;

}
