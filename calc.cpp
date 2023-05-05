#include "robotarm.h"

int main()
{
	RobotArm SARA;
	SARA.setEnvelope(1.0);
	SARA.setDOF(4);
	SARA.setPayload(10.0);
	SARA.setMinSpeed(.05);
	SARA.addMotor("NEMA 23", 1,1.0,1.26,2500,12,24,2.8,0);
	SARA.addMotor("NEMA 23", 2,1.0,1.26,2500,12,24,2.8,0);
	SARA.addMotor("NEMA 17",3,0.5,1.2,2000,12,24,2,0);
	SARA.addMotor("NEMA 17",4,0.5,1.2,2000,12,24,2,0);


	SARA.addArm("Shoulder",1,.48,3,"PLA");
	SARA.addArm("Forearm",2,.48,3,"PLA");
	SARA.addArm("End effector",3,.04,.5,"PLA");
	SARA.GeneralInfo(SARA);

	return 0;
}

