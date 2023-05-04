#include "arm.h"
#include<fstream>

int main()
{
	ofstream ofile;
	ofile.open("General_Info.txt");
	if(ofile.is_open()){
		Arm SARA;
		SARA.setEnvelope(1.0);
		SARA.setDOF(6);
		SARA.setPayload(10.0);
		SARA.setMinSpeed(.05);
		SARA.addActuator("NEMA 23", 1,1.0,1.26,2500,12,24,2.8);
		SARA.addActuator("NEMA 23", 2,1.0,1.26,2500,12,24,2.8);

		SARA.addJoint("Shoulder",1,.48,3,"PLA");
		SARA.addJoint("Forearm",2,.48,3,"PLA");
		SARA.addJoint("End effector",3,.04,.5,"PLA");
		//ofile << SARA.GeneralInfo();
	}
	ofile.close();

	return 0;
}

