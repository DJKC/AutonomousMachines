#pragma config(Sensor, dgtl2,  touch_1,        sensorTouch)
#pragma config(Sensor, dgtl4,  touch_2,        sensorTouch)
#pragma config(Sensor, dgtl3,  lever,          sensorTouch)
#pragma config(Motor,  port2,           big,           tmotorVex269, openLoop)
#pragma config(Motor,  port4,           med,           tmotorVex269, openLoop)
#pragma config(Motor,  port6,           small,         tmotorVex269, openLoop)

void stop_all_motors();
//stops motors in digitial ports 1, 2 and 3
//takes no parameters

//This example uses 3 motors (each with a different size gear
//	mounted to it, big, medium and small) and three sensors (2 bumpers and a limit).
//	The idea was to gain an idea on how the basics of a vex kit works.
//	There was no particular design, but just added parts until the concept (using
//	vex parts in conjuction with the library code) was grapsed

task main()
{
	do{
		stop_all_motors();
		wait1Msec(2000); //waits 2 seconds

		while(SensorValue(touch_1) == 0){		//while isnt pressed
			motor[big]  = 0;         // Mtr prt 2 is stoppped
			motor[small] = 0;				//Mtr prt 4 is stopped
		}

		while(SensorValue(touch_1) == 1){ //while sensor 1 is pressed
			motor[big]  = 20;								//Mtr prt 2 moves a bit
			motor[small] = 0;								//Mtr prt 4 is stopped
		}

		motor[big] = 0;

		while(SensorValue(touch_2) == 0)		//While sesnor 2 is not pressed
			motor[small]  = 126;

		while(SensorValue(touch_2) == 1){		//While sesnor 2 is not pressed
			wait1Msec(2000);

			motor[small]  = 20;

			if(SensorValue(touch_1) == 1)
				motor[big] = 20;

			else
				motor[big] = 0;
		}

		stop_all_motors();

		motor[med] = 15; //marks an iteration of the loop
		wait1Msec(2000); //gives time to push the lever arm or 3 sensor
	}while(SensorValue(lever) == 1);

	motor[med] = 40;
	wait1Msec(1000);

	return;
}

void stop_all_motors(){
	motor[big] = 0;
	motor[small] = 0;
	motor[med] = 0;
}
