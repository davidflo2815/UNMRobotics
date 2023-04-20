#ifndef _HEADER_H
#define _HEADER_H
using namespace std;
#include<string>
#include<cmath>
class Arm
{
	private:
		struct actuator{//used to create linked lists for the actuators(AKA motors)
			string aName;//name of the motor(EX: Nema23)
			int aNum;//The motor number. For example the base motors will have a number of 1
			double aTorque;//units of newton meters
			double aRPM;//This would be the safe RPM
			double aVoltageMn;//units of Volts
			double aVoltageMx;
			double aCurrent;//units of Amps
			double aWeight;//units of kilograms
			struct actuator *next;//used to link motors together
		};
		struct actuator *aBegin;//initializes a starting motor

		struct joint{//used to create a linked list for the details of the arms
			string jName;//the joint name(EX: shoulder, forearm, end-effector
			int jNum;//The joint number. For example the shoulder joint would be joint 1
			double jLength;//units of meters
			double jWeight;//units of kg
			string jMaterial;//printing filament used(EX: PLA)
			struct joint *next;//used to link joints together
		};
		struct joint *jBegin;//initializes a starting joint


		double envelope;//units of meters
		int DOF;//the number of unique motions in the arm system
		double payload;//units of kilograms
		double minSpeed;//units of meters per second


	public:
		Arm(){envelope=0.0,DOF=0,payload=0.0,minSpeed=0.0,aBegin= NULL,jBegin = NULL;}
		void setEnvelope(double n_envelope){envelope=n_envelope;}//set functions initialize the private variables when the function and parameter are called
		void setDOF(int n_dof){DOF=n_dof;}
		void setPayload(double n_payload){payload=n_payload;}
		void setMinSpeed(double n_minSpeed){minSpeed = n_minSpeed;}

		void GeneralInfo();//Face value info such as dof, motors, weight, envelope, etc.
		void CalculatedInfo(){}//calculated torque, gear ratio, etc.

		int numActuators();//returns the number of motors in the system
		int numJoints();//returns the number of joints in the system
		string actuatorAt(int num);//returns the information of the motor at a specific place
		string jointAt(int num);//returns the information of the joint at a specific place
		void addActuator(string name,int num,double weight,double torque,double RPM,double voltageMin,double voltageMax,double currentRating);
		void addJoint(string name, int num, double length,double weight,string material);
		bool lengthContinuity();//checks to make sure that the length of all the arms matches the envelope
		bool dofContinuity();//checks to make sure the dof matches the number of actuators



};
		
	
#endif
