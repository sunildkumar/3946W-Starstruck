#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in1,    clawRightPot,   sensorPotentiometer)
#pragma config(Sensor, in2,    clawLeftPot,    sensorPotentiometer)
#pragma config(Sensor, dgtl1,  driveRightQuad, sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  driveLeftQuad,  sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  liftQuad,       sensorQuadEncoder)
#pragma config(Motor,  port1,           liftLeftMid,   tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           clawLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           driveLeft,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           liftRightMid,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           driveRight,    tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           liftRightTop,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           liftLeftTop,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           liftRightOut,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           liftLeftOut,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          clawRight,     tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"
#include "Drive Functions.c"
#include "Lift Functions.c"
#include "Sensor Functions.c"
#include "Claw Left Functions.c"
#include "Claw Right Functions.c"
#include "Autonomous Functions.c"
#include "Throw Functions.c"



/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	SensorValue(liftQuad) = 0;
	SensorValue(driveLeftQuad) = 0;
	SensorValue(driveRightQuad) = 0;


	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
task driveControl(){

	while(true){
		//setDriveRight(vexRT[Ch3] - vexRT[Ch1]);
		//setDriveLeft(vexRT[Ch3] + vexRT[Ch1]);
		motor[port3] = vexRT[Ch3]+ vexRT[Ch1];
		motor[port5] = vexRT[Ch3] -vexRT[Ch1];
		wait1Msec(5);

	}
}

task liftControl(){
	while(true){
		if(vexRT[Btn5U] == 1){
			setLift(127);
			setPosition_lift = SensorValue(liftQuad);
		}
		else if (vexRT[Btn5D]==1){
			setLift(-80);
			setPosition_lift = SensorValue(liftQuad);
		}
		else{
			currentPositon_lift = SensorValue(liftQuad);

			error_lift = setPosition_lift - currentPositon_lift;
			int speed = kP_lift * error_lift;
			setLift(speed);

		}

		if(vexRT[Btn8UXmtr2]==1){
			SensorValue(liftQuad) = 0;
		}
		wait1Msec(5);

	}
}

task liftControlAuton(){
	while(true){
		while(runPID_lift){
				currentPositon_lift = SensorValue(liftQuad);

			error_lift = setPosition_lift - currentPositon_lift;
			int speed = kP_lift * error_lift;
			setLift(speed);

		}
		wait1Msec(5);
	}
}

task liftThrow(){
	while(true){

	liftPosition = SensorValue(liftQuad);

	if((liftPosition>lastLiftPosition) && liftPosition>throwThreshold){
		clawLeftSetPosition(clawLeftPositionOpen);
		clawRightSetPosition(clawRightPositionOpen);
	}


		lastLiftPosition = SensorValue(liftQuad);
		wait1Msec(10);
	}
}
task clawLeftControl(){
	while(true){
		while(runPID_CL){
			currentPosition_CL = SensorValue(clawLeftPot);
			error_CL=setPosition_CL-currentPosition_CL;

			derivative_CL = (currentPosition_CL-lastCurrentPosition_CL/10);
			lastCurrentPosition_CL = currentPosition_CL;

			speed_CL = (kP_CL * error_CL + kD_CL*derivative_CL);

			setClawLeft(speed_CL);

			wait1Msec(10);
		}

	}

}

task clawRightControl(){
	while(true){
		while(runPID_CR){
			currentPosition_CR = SensorValue(clawRightPot);
			error_CR=setPosition_CR-currentPosition_CR;

			derivative_CR = (currentPosition_CR-lastCurrentPosition_CR/10);

			lastCurrentPosition_CR = currentPosition_CR;

			speed_CR = (kP_CR * error_CR + kD_CR*derivative_CR);

			setClawRight(speed_CR);

			wait1Msec(10);
		}

	}

}



task testInput(){
	while(true){
		if(vexRT[Btn7DXmtr2]==1){
			clawRightSetPosition(clawRightPositionOpen);
		}
		if(vexRT[Btn7UXmtr2]==1){
			clawRightSetPosition(clawRightPositionClosed);
		}
	}
}
task clawInput(){
	while(true){
		if(vexRT[Btn7LXmtr2]==1){
			runPID_CL = true;
			clawLeftSetPosition(clawLeftPositionOpen);
		}
		else if(vexRT[Btn8RXmtr2]==1){
			runPID_CL = true;
			clawLeftSetPosition(clawLeftPositionClosed);
		}
		else if(vexRT[Btn5UXmtr2]==1){
			runPID_CL=false;
			setPosition_CL = SensorValue(clawLeftPot);
			setClawLeft(127);
		}
		else if(vexRT[Btn5DXmtr2]==1){
			runPID_CL = false;
			setPosition_CL = SensorValue(clawLeftPot);
			setClawLeft(-127);
		}
		else{
			runPID_CL=true;
		}

		if(vexRT[Btn7LXmtr2]==1){
			runPID_CR = true;
			clawRightSetPosition(clawRightPositionOpen);
		}
		else if(vexRT[Btn8RXmtr2]==1){
			runPID_CR = true;
			clawRightSetPosition(clawRightPositionClosed);
		}
		else if(vexRT[Btn6UXmtr2]==1){
			runPID_CR=false;
			setPosition_CR = SensorValue(clawRightPot);
			setClawRight(127);
		}
		else if(vexRT[Btn6DXmtr2]==1){
			runPID_CR = false;
			setPosition_CR = SensorValue(clawRightPot);
			setClawRight(-127);
		}
		else{
			runPID_CR=true;
		}

	}

}




task autonomous()
{


	auton_fencecube();

}

task usercontrol()
{
	startTask(driveControl);
	startTask(liftControl);
	//startTask(clawLeftControl);
	//startTask(clawRightControl);
	//startTask(testInput);
	//startTask(clawInput);

	// User control code here, inside the loop
}
