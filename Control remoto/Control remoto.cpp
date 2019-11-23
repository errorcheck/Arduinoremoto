#include <mbq.h>
#include <PingIRReceiver.h>

void setup()
{
	initBoard();
	float sensor = 0;
	while(true)
	{
		sensor = irReceiver.getIRRemoteCode();
		serial0.println(sensor);
		delay(500);
		if(((int)(sensor)==(int)(6)))
		{
			DigitalWrite(D9, true);
			motor0.setPower(-(100));
			motor1.setPower(-(100));
		}
		else
		{
			if(((int)(sensor)==(int)(3)))
			{
				DigitalWrite(D9, false);
				motor0.setPower(0);
				motor1.setPower(0);
			}
			else
			{
			}
		}
	}
}

void loop()
{
}
