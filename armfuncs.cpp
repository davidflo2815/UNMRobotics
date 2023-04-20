#include "arm.h"

//function for calculating the number of actuators
//Will be used in getGeneralInfo function as a sanity check
int Arm::numActuators()
{
	int total = 0;
	struct actuator *ptr = aBegin;
	while(ptr != NULL){
		total += 1;
		ptr = ptr->next;
	}
	return total;
};
//function for calculating the number of joints
//Will be used in getGeneralInfo function as a sanity check
int Arm::numJoints()
{
	int total = 0;
	struct joint *ptr = jBegin;
	while(ptr != NULL){
		total += 1;
		ptr=ptr->next;
	}
	return total;
};
//find the specs of the actuator at a certain position
//Will be used by the getGeneralInfo function to output info of each motor
string Arm::actuatorAt(int num)
{
	int val = 0;
	struct actuator *ptr = aBegin;
	while(ptr != NULL){
		ptr=ptr->next;
		val += 1;
		if(val == num){
			break;
		}
	}

	string inf = "Motor name: "+ptr->aName+"\nTorque: "+to_string(ptr->aTorque)+" Nm,\tRPM: "+to_string(ptr->aRPM);
	return inf;
};
//find the specs of the joint at a certain position
//Will be used by the getGeneralInfo function to output info of each motor
string Arm::jointAt(int num)
{
	int val = 0;
	struct joint *ptr = jBegin;
	while(ptr != NULL){
		ptr=ptr->next;
		val += 1;
		if(val == num){
			break;
		}
	}
	string inf = "Joint Number: "+to_string(ptr->jNum)+"\nJoint Length: "+to_string(ptr->jLength)+",\tJoint Weight: "+to_string(ptr->jWeight)+",\tJoint Material: "+ptr->jMaterial;
	return inf;
};
//adds an actuator to the linked list of actuators
//implementation in calc.cpp or by maybe user input after the function is already running
void Arm::addActuator(string name,int num,double weight,double torque,double RPM,double voltageMin,double voltageMax, double currentRating)
{
	struct actuator *ptr = aBegin;
	if(ptr == NULL)
	{
		aBegin = new struct actuator;
		aBegin->next = NULL;
		aBegin->aName = name;
		aBegin->aNum = num;
		aBegin->aWeight = weight;
		aBegin->aTorque = torque;
		aBegin->aRPM = RPM;
		aBegin->aVoltageMn = voltageMin;
		aBegin->aVoltageMx = voltageMax;
		aBegin->aCurrent = currentRating;
	}
	else{
		while(ptr->next != NULL){
			ptr=ptr->next;
		}
		struct actuator *a = new struct actuator;
		a->aName = name;
		a->aNum = num;
		a->aWeight = weight;
		a->aTorque = torque;
		a->aRPM = RPM;
		a->aVoltageMn = voltageMin;
		a->aVoltageMx = voltageMax;
		a->aCurrent = currentRating;
		a->next = NULL;
		ptr->next = a;
	}
};
//adds a joint to the linked list of joints
////implementation in calc.cpp or by maybe user input after the function is already running
void Arm::addJoint(string name, int num, double length,double weight,string material)
{
	struct joint *ptr = jBegin;
	if(ptr == NULL)
	{
		jBegin = new struct joint;
		jBegin->next = NULL;
		jBegin->jName = name;
		jBegin->jNum = num;
		jBegin->jLength = length;
		jBegin->jWeight = weight;
		jBegin->jMaterial = material;
	}
	else{
		while(ptr->next != NULL){
			ptr=ptr->next;
		}
		struct joint *j = new struct joint;
		j->jName = name;
		j->jNum = num;
		j->jWeight = weight;
		j->jLength = length;
		j->jMaterial = material;
		j->next = NULL;
		ptr->next = j;
	}
};
//checks to make sure the lengths of all the arms matches the total envelope
//use in getGeneralInfo
bool Arm::lengthContinuity()
{
	struct joint *ptr = jBegin;
	double totalLength = 0.0;
	double precision = .05;
	while(ptr != NULL){
		totalLength += ptr->jLength;
		ptr=ptr->next;
	}
	if((envelope-precision)<=totalLength<=(envelope+precision)){
		return true;
	}else{
		return false;
	}
	
}
//checks to make sure enough actuators were provided for the desired DOF
//use in getGeneralInfo
bool Arm::dofContinuity()
{
	struct actuator *ptr = aBegin;
	int totalMotors = 0;
	while(ptr != NULL){
		totalMotors += 1;
		ptr=ptr->next;
	}
	if(DOF == totalMotors){
		return true;
	}else{
		return false;
	}
}
//function for returning general info of the arm(not the mathy shit).
//Intentions are to make it so this function returns all the provided information to an ofile
//It was also output the missing variables the user needs to still input for the calculating functions to start
void Arm::GeneralInfo()
{
	cout<<"### GENERAL INFO ###\n\n"<<endl;

};

