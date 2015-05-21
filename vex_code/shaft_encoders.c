#pragma config(Sensor, dgtl6,  rightEncoder,        sensorQuadEncoder)
#pragma config(Motor,  port9,           rightMotor,    tmotorNormal, openLoop)
#pragma config(Motor,  port8,           leftMotor,     tmotorNormal, openLoop)

task main()
{
  wait1Msec(500);

  SensorValue[rightEncoder] = 0;

  while(SensorValue[rightEncoder] > -1620)  // While less than 1 rotation on the leftEncoder...
  {
    motor[rightMotor] = -20;
    motor[leftMotor] = 20;
  }
}
