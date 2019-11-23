#include <mbq.h>
#include <PingIRReceiver.h>

void setup()
{
	initBoard();
	float tiempo3 = 0;
	float contador = 0;
	float tiempo1 = 0;
	float sensor = 0;
	float tiempo2 = 0;
	while((contador!=2))
	{
		sensor = AnalogRead(sensor1);
		if(((sensor>16)&&(contador<1)))
		{
			contador = (contador+1);
			tiempo1 = millis();
			DigitalWrite(D8, true);
			serial0.println("Primera lectura del sensor:");
			serial0.println(sensor);
			serial0.println("aqui el sensor se pone en cero");
			sensor = 0;
			serial0.println("todavia dentro del primer if");
			serial0.println(sensor);
			delay(1000);
		}
		else
		{
		}
		if(((sensor>16)&&((int)(contador)==(int)(1))))
		{
			serial0.println("sensor dentro del segundo if");
			serial0.println(sensor);
			tiempo2 = millis();
			DigitalWrite(D8, false);
			contador = 2;
			tiempo3 = (tiempo2-tiempo1);
			serial0.println(tiempo3);
			tiempo3 = (tiempo3/1000);
			if((tiempo3>=60))
			{
				serial0.println("Cantidad de Minutos");
				tiempo3 = (tiempo3/60);
				serial0.println(tiempo3);
			}
			else
			{
				serial0.println("Cantidad de segundos");
				serial0.println(tiempo3);
			}
		}
		else
		{
		}
	}
}

void loop()
{
}
