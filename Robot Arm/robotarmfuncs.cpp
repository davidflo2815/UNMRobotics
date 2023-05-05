#include "robotarm.h"


//function for calculating the number of actuators
//Will be used in getGeneralInfo function as a sanity check
int RobotArm::numMotors()
{
	int total = 0;
	struct motor *ptr = mBegin;
	while(ptr != NULL){
		total += 1;
		ptr = ptr->next;
	}
	return total;
};
//function for calculating the number of joints
//Will be used in getGeneralInfo function as a sanity check
int RobotArm::numArms()
{
	int total = 0;
	struct arm *ptr = aBegin;
	while(ptr != NULL){
		total += 1;
		ptr=ptr->next;
	}
	return total;
};
//find the specs of the actuator at a certain position
//Will be used by the getGeneralInfo function to output info of each motor
string RobotArm::motorAt(int num)
{
	int val = 0;
	struct motor *ptr = mBegin;
	while(ptr != NULL){
		ptr=ptr->next;
		val += 1;
		if(val == num){
			break;
		}
	}

	string inf = "Motor name: "+ptr->mName+"\tMotor num: "+to_string(ptr->mNum)+"\tTorque: "+to_string((float)ptr->mTorque)+" Nm\nMin Voltage: "+to_string(ptr->mVoltageMn)+" V\tmax Voltage: "+to_string(ptr->mVoltageMx)+" V\tOperating Current: "+to_string(ptr->mCurrent);
	return inf;
};
//find the specs of the joint at a certain position
//Will be used by the getGeneralInfo function to output info of each motor
string RobotArm::armAt(int num)
{
	int val = 0;
	struct arm *ptr = aBegin;
	while(ptr != NULL){
		ptr=ptr->next;
		val += 1;
		if(val == num){
			break;
		}
	}
	string inf = "Arm Number: "+to_string(ptr->aNum)+"Arm Name: "+ptr->aName+"\nArm Length: "+to_string(ptr->aLength)+",\tArm Weight: "+to_string(ptr->aWeight)+",\tArm Material: "+ptr->aMaterial;
	return inf;
};
//adds an motor to the linked list of motors
//implementation in calc.cpp or by maybe user input after the function is already running
void RobotArm::addMotor(string name,int num,double weight,double torque,double RPM,double voltageMin,double voltageMax, double currentRating,double inertia)
{
	struct motor *ptr = mBegin;
	if(ptr == NULL)
	{
		mBegin = new struct motor;
		mBegin->next = NULL;
		mBegin->mName = name;
		mBegin->mNum = num;
		mBegin->mWeight = weight;
		mBegin->mTorque = torque;
		mBegin->mRPM = RPM;
		mBegin->mVoltageMn = voltageMin;
		mBegin->mVoltageMx = voltageMax;
		mBegin->mCurrent = currentRating;
	}
	else{
		while(ptr->next != NULL){
			ptr=ptr->next;
		}
		struct motor *m = new struct motor;
		m->mName = name;
		m->mNum = num;
		m->mWeight = weight;
		m->mTorque = torque;
		m->mRPM = RPM;
		m->mVoltageMn = voltageMin;
		m->mVoltageMx = voltageMax;
		m->mCurrent = currentRating;
		m->next = NULL;
		ptr->next = m;
	}
};
//adds an arm to the linked list of arms
////implementation in calc.cpp or by maybe user input after the function is already running
void RobotArm::addArm(string name, int num, double length,double weight,string material)
{
	struct arm *ptr = aBegin;
	if(ptr == NULL)
	{
		aBegin = new struct arm;
		aBegin->next = NULL;
		aBegin->aName = name;
		aBegin->aNum = num;
		aBegin->aLength = length;
		aBegin->aWeight = weight;
		aBegin->aMaterial = material;
	}
	else{
		while(ptr->next != NULL){
			ptr=ptr->next;
		}
		struct arm *a = new struct arm;
		a->aName = name;
		a->aNum = num;
		a->aWeight = weight;
		a->aLength = length;
		a->aMaterial = material;
		a->next = NULL;
		ptr->next = a;
	}
};
//finds total length of all arms given
double RobotArm::totalLength(){
	double totalL = 0.0;
	struct arm *ptr = aBegin;
	while(ptr != NULL){
		totalL += ptr->aLength;
		ptr=ptr->next;
	}
	return totalL;
}


//checks to make sure the lengths of all the arms matches the total envelope
//use in getGeneralInfo
bool RobotArm::lengthContinuity()
{
	double precision = .05;
	if((envelope-precision)<=totalLength() && totalLength()<=(envelope+precision)){
		return true;
	}else{
		return false;
	}
	
}
//counts the number of motors

//checks to make sure enough motors were provided for the desired DOF
//use in getGeneralInfo

bool RobotArm::dofContinuity()
{
	if(DOF == numMotors()){
		return true;
	}else{
		return false;
	}
}
//The importance of calculating holding torque is that it sets the minimum torque required from a motor to hold up weight
//
void RobotArm::CalcHoldingTorque(int motorNum)
{
	double t = 0; //temp total torque
	double gr = 0; //gear ratio, gear ratio = outputT / inT
	double mA = 0; //mass of Arm
	double a = 9.8; //acceleration of gravity 9.8m/s^2
	struct arm *ptr = aBegin;
	while(ptr != NULL){//adds up the weight of all the joints
		mA += ptr->aWeight;
		ptr=ptr->next;
	}
	struct motor *ptr2 = mBegin;
	while(ptr2->mNum != motorNum+1){//points the pointer to the starting motor. Prevents total Mass from including any motor before the wanted motorNum
		ptr=ptr->next;
	}
	while(ptr2 != NULL){//adds up the weight of all the motors
		mA += ptr2->mWeight;
		ptr2 = ptr2->next;
	}
	t = (payload*a*envelope)+(a*mA*CoMArm);//adds up the torques of both the payload torque and the arm torque from center of mass

	holdingTorque = t; //sets holding Torque to calculated total torque
	struct motor *ptr3 = mBegin;
	while(ptr3->mNum != 2){//searches for second motor which would be shoulder joint
		ptr3=ptr3->next;
	}
	gr = t/(ptr3->mNum);//calculates gear ratio 
	grShoulderHolding = gr;

}
