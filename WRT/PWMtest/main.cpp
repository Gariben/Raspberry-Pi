#include <wiringPi.h>
#include <softPwm.h>


using namespace std;


int main(){

	int led = 0;
	int led2 = 1;
	int brightness = 0;
	int fadeAmount = 5;

	wiringPiSetup();
	pinMode(led, OUTPUT);
	pinMode(led2, OUTPUT);
	softPwmCreate(led, 0, 100);
	softPwmCreate(led2, 0, 100);


	for(;;){
		softPwmWrite(led, brightness);
		softPwmWrite(led2, brightness);
		//digitalWrite(led, HIGH);

		brightness = brightness + fadeAmount;

		if(brightness == 0 || brightness == 255){
			fadeAmount = -fadeAmount;
		}

		delay(30);
	}


	return 0;
}
