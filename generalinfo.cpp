#include "robotarm.h"

//function for returning general info of the arm(not the mathy shit).
//Intentions are to make it so this function returns all the provided information to an ofile
//It was also output the missing variables the user needs to still input for the calculating functions to start

void RobotArm::GeneralInfo(RobotArm &arm)
{
	ofstream ofile;
	ofile.open("General_Info.txt");
	if(ofile.is_open()){
		ofile<< "------------------### GENERAL INFO ###------------------\n\n"<<endl;
		ofile<<"Degrees of Freedom: "<<arm.DOF<<endl;
		ofile<<"Envelope: "<<arm.envelope<<" m"<<endl;
		ofile<<"Payload: "<<arm.payload<<" kg"<<endl;
		ofile<<"minimun Speed: "<<arm.minSpeed<<" m/s"<<endl;
		ofile<<"Center of Mass of Arm: "<<arm.CoMArm<<" m"<<endl;
		ofile<<"\n\n------------------# Motor Info #------------------------\n\n"<<endl;
		struct motor *ptr = mBegin;
		while(ptr->mNum != arm.numMotors()){
			ofile << motorAt(ptr->mNum)<<endl;
			ofile << "\n\n" <<endl;
			ptr=ptr->next;
		}
		ofile<<"\n\n#------------------# Arm Info #------------------\n\n"<<endl;
		struct arm *ptr2 = aBegin;
		while(ptr2 != NULL){
			ofile<<"Arm type: "<<ptr2->aName<<"\tArm number: "<<ptr2->aNum<<endl;
			ofile<<"Arm Length: "<<ptr2->aLength<<"\tArm weight: "<<ptr2->aWeight<<"\tArm Material: "<<ptr2->aMaterial<<"\n\n"<<endl;
			ptr2=ptr2->next;
		}
		ofile<<"\n\n------------------!!! Errors !!! ------------------\n\n"<<endl;
		if(!(arm.lengthContinuity())){
			ofile<<"The total length of given arms and envelope doesn't match.\nTotal Envelope: "<<arm.envelope<<" m\ttotal length of arms: "<< arm.totalLength() <<" m"<<endl;
		}
		if(!(arm.dofContinuity())){
			ofile<<"The total DOF provided does not match the number of motors,\nTotal DOF: "<<arm.DOF<<"\tTotal motors: "<<arm.numMotors()<<endl;
		}
	}
	ofile.close();

};


