#ifndef _ROBOTARM_H
#define _ROBOTARM_H
using namespace std;
#include<string>
#include<cmath>
#include<iostream>
#include<fstream>

class RobotArm
{
	private:
		struct motor{//used to create linked lists for the actuators(AKA motors)
			string mName;//name of the motor(EX: Nema23)
			int mNum;//The motor number. For example the base motors will have a number of 1
			double mTorque;//units of newton meters
			double mRPM;//This would be the safe RPM
			double mVoltageMn;//units of Volts
			double mVoltageMx;
			double mCurrent;//units of Amps
			double mWeight;//units of kilograms
			double mInertia;
			struct motor *next;//used to link motors together
		};
		struct motor *mBegin;//initializes a starting motor

		struct arm{//used to create a linked list for the details of the arms
			string aName;//the joint name(EX: shoulder, forearm, end-effector
			int aNum;//The joint number. For example the shoulder joint would be joint 1
			double aLength;//units of meters
			double aWeight;//units of kg
			string aMaterial;//printing filament used(EX: PLA)
			struct arm *next;//used to link joints together
		};
		struct arm *aBegin;//initializes a starting joint


		double envelope;//units of meters
		int DOF;//the number of unique motions in the arm system
		double payload;//units of kilograms
		double minSpeed;//units of meters per second
		double CoMArm; //center of mass from the base
		double holdingTorque; //The calculated holding torque of the shoulder joint
		double grShoulderHolding; //The minimum gear ratio of the shoulder joint to hold the weight of the payload and arm straight out



	public:
		RobotArm(){envelope=0.0,DOF=0,payload=0.0,minSpeed=0.0,mBegin= NULL,aBegin = NULL,CoMArm=0,holdingTorque=0;}//initializes all relevant values to zero so the generalInfo function knows what to alert about
		void setEnvelope(double n_envelope){envelope=n_envelope;}//set functions initialize the private variables when the function and parameter are called
		void setDOF(int n_dof){DOF=n_dof;}
		void setPayload(double n_payload){payload=n_payload;}
		void setMinSpeed(double n_minSpeed){minSpeed = n_minSpeed;}
		void setCoM(double COM){CoMArm = COM;}


		void GeneralInfo(RobotArm &arm);//Face value info such as dof, motors, weight, envelope, etc.
		void CalculatedInfo(){}//calculated torque, gear ratio, etc.

		int numMotors();//returns the number of motors in the system
		int numArms();//returns the number of joints in the system
		string motorAt(int num);//returns the information of the motor at a specific place
		string armAt(int num);//returns the information of the joint at a specific place
		void addMotor(string name,int num,double weight,double torque,double RPM,double voltageMin,double voltageMax,double currentRating,double inertia);
		void addArm(string name, int num, double length,double weight,string material);
		double totalLength();
		bool lengthContinuity();//checks to make sure that the length of all the arms matches the envelope
		bool dofContinuity();//checks to make sure the dof matches the number of actuators
		void CalcHoldingTorque(int motorNum);



};
		
	
#endif
