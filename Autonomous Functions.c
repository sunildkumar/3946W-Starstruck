

void auton_red_left_E(){
}

void auton_red_right_main(){
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	wait1Msec(500);
	setDriveForwardDistance(1000,1);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(250);
	setLiftPosition(281);
	gyroTurn("l",120,1,15);
	setDriveForwardDistance(-500,-1,2000,false);
	setLiftPosition(746);
	setDriveForwardDistance(-1000,-1,2000);
	setDrive(-50);
	wait1Msec(3800);
	setDrive(0);
	wait1Msec(1000);
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	setLiftPosition(liftPositionBottom);
	wait1Msec(1100);
	setDriveForwardDistance(1250,1,1500);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(400);
	setLiftPosition(746);
	setDriveForwardDistance(-1250,-1,2000);


}


void auton_red_right_alt(){
	setDriveForwardDistance(-300,-1,2000,false);
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	setLiftPosition(746);
	setDriveForwardDistance(-1325,-1,2500);
	wait1Msec(5000);
	setDrive(-40);
	wait1Msec(1000);
	setDrive(0);
	setLiftPosition(0);
	wait1Msec(1100);
	gyroTurn("l",15,1,15);
	setDriveForwardDistance(1300,1,3000);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(200);
	setLiftPosition(746);
	setDriveForwardDistance(-1300,-1,3000);

}

void auton_red_right_E(){
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	wait1Msec(500);
	setDriveForwardDistance(1000,1);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(250);
	setLiftPosition(281);
	gyroTurn("l",80,1,30);
	setDriveForwardDistance(-500,-1,2000,false);
	setLiftPosition(746);
	setDriveForwardDistance(-1500,-1,1000);
		clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	wait1Msec(250);
	setLiftPosition(0);
	setDrive(-40);
	wait1Msec(1000);
	setDriveForwardDistance(100,1,500);
	gyroTurn("r",65,1,20);
	setDriveForwardDistance(1600,1,2000);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(250);
	setLiftPosition(281);
	gyroTurn("l",45,1,20);
	setDriveForwardDistance(-600,-1,2000,false);
	setLiftPosition(746);
	setDriveForwardDistance(-700,-1,2000);










}

void auton_blue_left_main(){



}

void auton_blue_left_alt(){
	runThrow = false;
	clawLeftSetPosition(clawLeftPositionFlat);
	clawRightSetPosition(clawRightPositionFlat);
	wait1Msec(100);
	setLiftPosition(480);
	setDriveForwardDistance(700,1,1500);
	wait1Msec(300);
	setDriveForwardDistance(-400,-1);
	wait1Msec(100);
	setLiftPosition(0);
	wait1Msec(300);
	gyroTurn("l",170,1,15);
	SensorValue(liftQuad)= 0;
	setDriveForwardDistance(200,1);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(500);
	runThrow=true;
	setLiftPosition(200);
	setDriveForwardDistance(-500,-1);
	setDrive(-50);
	setLiftPosition(liftPositionTop);
	setDrive(0);
}

void auton_blue_left_E(){
}

void auton_blue_right_main(){
	auton_red_right_main();
}

void auton_blue_right_alt(){
	auton_red_right_alt();



}

void auton_blue_right_E(){
	auton_red_right_E();
}

void auton_programmingskills(){

	setDriveForwardDistance(-300,-1);
	clawLeftSetPosition(clawLeftPositionOpen);
	clawRightSetPosition(clawRightPositionOpen);
	wait1Msec(800);
	clawLeftSetPosition(clawLeftPositionClosed);
	clawRightSetPosition(clawRightPositionClosed);
	wait1Msec(500);
	setLiftPosition(746);
	setDriveForwardDistance(-1325,-1,2000);


	//wait1Msec(500);
	//SensorValue(liftQuad) = 0;
	//setDriveForwardDistance(500,1);
	//wait1Msec(666);
	//clawLeftSetPosition(clawLeftPositionClosed);
	//clawRightSetPosition(clawRightPositionClosed);
	//wait1Msec(300);
	//setLiftPosition(150);
	//setDriveForwardDistance(-500,-1,2000);
	//setDrive(-50);
	//setLiftPosition(liftPositionTop);
	//wait1Msec(100);
	//setLiftPosition(liftPositionBottom);
	//setDrive(0);

	//setDriveForwardDistance(500,1);
	//wait1Msec(1000);
	//clawLeftSetPosition(clawLeftPositionClosed);
	//clawRightSetPosition(clawRightPositionClosed);
	//wait1Msec(300);
	//setLiftPosition(150);
	//setDriveForwardDistance(-500,-1,2000);
	//setDrive(-50);
	//setLiftPosition(liftPositionTop);
	//wait1Msec(100);
	//setLiftPosition(liftPositionBottom);
	//setDrive(0);

	//clawLeftSetPosition(clawLeftPositionOpen);
	//clawRightSetPosition(clawRightPositionOpen);
	//setDriveForwardDistance(310,1);
	//gyroTurn("l",90,1,25);
	//setDriveForwardDistance(-500,-1,1000);
	//setDrive(-50);
	//wait1Msec(500);
	//setDrive(0);
	//setDriveForwardDistance(700,1);
	//clawLeftSetPosition(clawLeftPositionClosed);
	//clawRightSetPosition(clawRightPositionClosed);
	//wait1Msec(300);
	//setDriveForwardDistance(-490,-1);
	//setLiftPosition(liftPositionMid);
	//wait1Msec(300);
	//gyroTurn("r",90,1,20);
	//setDriveForwardDistance(-300,-1,2000);
	//setDrive(-50);
	//setLiftPosition(liftPositionTop);
	//wait1Msec(100);
	//setLiftPosition(liftPositionBottom);
	//setDrive(0);

	//clawLeftSetPosition(clawLeftPositionHalf);
	//clawRightSetPosition(clawRightPositionHalf);
	//setDriveForwardDistance(83,1);
	//gyroTurn("l",90,1,20);
	//setDriveForwardDistance(790,1);
	//clawLeftSetPosition(clawLeftPositionClosed);
	//clawRightSetPosition(clawRightPositionClosed);
	//wait1Msec(300);
	//setDriveForwardDistance(-150,-1);
	//setLiftPosition(liftPositionMid);
	//gyroTurn("r",90,1,20);
	//setDriveForwardDistance(-200,-1,700);
	//setDrive(-50);
	//setLiftPosition(liftPositionTop);
	//wait1Msec(100);
	//setLiftPosition(liftPositionBottom);
	//setDrive(0);

	//setDriveForwardDistance(500,1,1000);
	//clawLeftSetPosition(clawLeftPositionClosed);
	//clawRightSetPosition(clawRightPositionClosed);
	//wait1Msec(400);
	//setDriveForwardDistance(-500,-1,1000);
	//setDrive(-50);
	//setLiftPosition(liftPositionTop);
	//wait1Msec(100);
	//setLiftPosition(liftPositionBottom);
	//setDrive(0);

	//clawLeftSetPosition(clawLeftPositionClosed);
	//clawRightSetPosition(clawRightPositionClosed);
	//setDriveForwardDistance(110,1);
	//gyroTurn("l",89,1,15);
	//setDriveForwardDistance(400,1);
	//gyroTurn("r",90,1,15);
	//clawLeftSetPosition(clawLeftPositionOpen);
	//clawRightSetPosition(clawRightPositionOpen);
	//wait1Msec(500);
	//setDriveForwardDistance(470,1,1500);
	//clawLeftSetPosition(clawLeftPositionClosed);
	//clawRightSetPosition(clawRightPositionClosed);
	//wait1Msec(700);
	//setDriveForwardDistance(-500,-1,2000);
	//setDrive(-50);
	//setLiftPosition(liftPositionTop);
	//wait1Msec(100);
	//setLiftPosition(liftPositionBottom);
	//clawLeftSetPosition(clawLeftPositionHalf);
	//clawRightSetPosition(clawRightPositionHalf);
	//setDrive(0);
	//setDriveForwardDistance(300,1);
	//gyroTurn("l",46,1,15);
	//setDriveForwardDistance(200,1);
	//clawLeftSetPosition(clawLeftPositionClosed);
	//clawRightSetPosition(clawRightPositionClosed);
	//wait1Msec(200);
	//gyroTurn("r",180,1,15);
	//clawLeftSetPosition(clawLeftPositionOpen);
	//clawRightSetPosition(clawRightPositionOpen);
	//setDriveForwardDistance(-200,-1,1000);
	//setLiftPositionSlow(liftPositionTop);
}
void auton_red_left_main(){ //grabs 2 stars + cube, throw, grab 3 stars, throw
	auton_blue_left_main();
}



void auton_test(){
	setDriveForwardDistance(1000,1,4000);
}

void auton_red_left_alt(){
	auton_blue_left_alt();

}
