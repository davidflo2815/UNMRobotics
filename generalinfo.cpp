#include "arm.h"

//function for returning general info of the arm(not the mathy shit).
//Intentions are to make it so this function returns all the provided information to an ofile
//It was also output the missing variables the user needs to still input for the calculating functions to start

void Arm::GeneralInfo(Arm &arm)
{
	cout<<"\t\t### GENERAL INFO ###\n\n"<<endl;
	cout<<"Degrees of Freedom: "<<arm.DOF<<endl;
	cout<<"Envelope(meters): "<<arm.envelope<<endl;
	cout<<"Payload(Kilograms): "<<arm.payload<<endl;
	cout<<"minimun Speed(Meters per Second): "<<arm.minSpeed<<endl;
	cout<<"Center of Mass of Arm(Meters): "<<arm.CoMArm<<endl;
	cout<<"\n\t\t# Motor Info #\n\n"<<endl;
	struct actuator *ptr = aBegin;
	while(ptr != NULL){
		cout<<"Motor Name: "<<ptr->aName<<"\tMotor Number: "<<ptr->aNum<<endl;
		cout<<"Motor Weight: "<<ptr->aWeight<<"\tMotor Base Torque: "<<ptr->aTorque<<endl;
		cout<<"Minimum Voltage: "<<ptr->aVoltageMn<<"\tMaximum Voltage: "<<ptr->aVoltageMx<<"\tMotor Current: "<<ptr->aCurrent<<endl;
	}


};


