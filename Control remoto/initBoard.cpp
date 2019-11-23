#include <mbq.h>


DCMotor motor0(6,5, 7);
DCMotor motor1(3, 4, 2);
Servo servo0;
Servo servo1;
Servo servo2;
LiquidCrystal textLCD(12, 11, 5, 4, 3, 2);
IRrecv irReceiver(14);
HCSRSensor hcsr(0);
PingSensor ping(0);
IRRanger irRanger20to150(1, IRRanger::range20to150cm);
IRRanger irRanger10to80(1, IRRanger::range10to80cm);


void initBoard()
{
	Serial.begin(57600);

	//Uses the analog input 0, that may have the same value in some designs, but it's not so prabably:
	randomSeed(analogRead(0));

  analogWrite(6,0);

 analogWrite(3,0);

	//setPin() does not attach the servo (so the pin can be used by other library if the servo is not used).
	servo0.setPin(15);
	servo1.setPin(16);
	servo2.setPin(17);
	//;
}
