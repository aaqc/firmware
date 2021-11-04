#include <Arduino.h>
#include <Servo.h>

#define CONTROLLER_GPIO 17
#define ACCELERATION 1
unsigned int thrust = 0;
int ang;

#define ESC1 32
#define ESC2 33

#define ESC3 25
#define ESC4 26

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;

void setup()
{
	pinMode(CONTROLLER_GPIO, INPUT_PULLUP);
	Serial.begin(9600);

	motor1.attach(ESC1, 1000, 2000);
	motor2.attach(ESC2, 1000, 2000);
	motor3.attach(ESC3, 1000, 2000);
	motor4.attach(ESC4, 1000, 2000);
}

void loop()
{
	if (digitalRead(CONTROLLER_GPIO) == HIGH)
	{
		thrust += ACCELERATION;
		ang = map(thrust, 0, 20, 0, 180);

		motor1.write(ang);
		motor2.write(ang);
		motor3.write(ang);
		motor4.write(ang);

		Serial.print(thrust);
		Serial.print(" : ");
		Serial.println(ang);
	}
	else
	{
		thrust = 0;
		motor1.write(0);
		motor2.write(0);
		motor3.write(0);
		motor4.write(0);
		Serial.println("OFF");
	}

	delay(500);
}