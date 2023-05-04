#include "robotarm.h"

//function for returning general info of the arm(not the mathy shit).
//Intentions are to make it so this function returns all the provided information to an ofile
//It was also output the missing variables the user needs to still input for the calculating functions to start

void RobotArm::GeneralInfo(RobotArm &arm)
{
	cout<<"------------------### GENERAL INFO ###------------------\n\n"<<endl;

	cout<<"Degrees of Freedom: "<<arm.DOF<<endl;
	cout<<"Envelope: "<<arm.envelope<<" m"<<endl;
	cout<<"Payload: "<<arm.payload<<" kg"<<endl;
	cout<<"minimun Speed: "<<arm.minSpeed<<" m/s"<<endl;
	cout<<"Center of Mass of Arm: "<<arm.CoMArm<<" m"<<endl;
	cout<<"\n\n------------------# Motor Info #------------------------\n\n"<<endl;
	struct motor *ptr = mBegin;
	while(ptr != NULL){
		cout<<"Motor Name: "<<ptr->mName<<"\tMotor Number: "<<ptr->mNum<<endl;
		cout<<"Motor Weight: "<<ptr->mWeight<<" kg\tMotor Base Torque: "<<ptr->mTorque<<" Nm"<<endl;
		cout<<"Minimum Voltage: "<<ptr->mVoltageMn<<" V\tMaximum Voltage: "<<ptr->mVoltageMx<<" V\tMotor Current: "<<ptr->mCurrent<<" a\n\n"<<endl;
		ptr=ptr->next;
	}


};


