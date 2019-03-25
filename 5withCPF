	// Do not remove the include below
#include "PlutoPilot.h"
#include "Xshield.h"
#include "Control.h"
#include "Led.h"
#include "Print.h"

 float e_1=0;
 float F = 0;
 int array_left[10];
 int array_right[10];
 int sumL =0;
 int sumR =0;

void plutoInit()
{
	  Xshield.init();
// Add your hardware initialization code here
}

void onPilotStart()
{
	 Xshield.startRanging();
  // do your one time stuffs here

}




void plutoPilot()
{
	for (int i=0; i<10; i++){
	    	Print.monitor(" L RANGE: ", Xshield.getRange(LS_LEFT));
		    Print.monitor(" R RANGE: ", Xshield.getRange(LS_RIGHT));

		if(Xshield.getRange(LS_LEFT)<0 || Xshield.getRange(LS_LEFT)>2000)
		{
			array_left[i]=0;
		}
		else
			{array_left[i] = Xshield.getRange(LS_LEFT);}

		 sumL+= array_left[i];

	  	  if(Xshield.getRange(LS_RIGHT)<0 || Xshield.getRange(LS_RIGHT)>2000)
		  {
			array_right[i]= 0;
		   }
		else
		    {array_right[i] = Xshield.getRange(LS_RIGHT);}

		 sumR = sumR + array_right[i];

	}


	     Print.monitor("\n");
		int L = (sumL)/10;
		Print.monitor("average L:", L);
	    int R = (sumR)/10;
	    Print.monitor("average R:", R);




	if(L>0 && R>0){
	    F = L+R;

		   float kp,kd;
		   float e_2 = (L-R)/2;
		   kp= 4;
		   kd = 11;
		   float del_e = e_2 - e_1;
		     e_1 = e_2;
		    float u = kp*e_2 + kd*del_e;
		    Control.setRcCommand(RC_ROLL, 1500+u);
	      }


	 if(L>0 && R==0){
			int kp,kd;

																																																													float e_2 = (L-(F/2));
			kp= 7;//to be setted
		    kd = 3;// to be setted
		   float del_e = e_2 - e_1;
		   e_1 = e_2;
		   float u = kp*e_2 + kd*del_e;
		   Control.setRcCommand(RC_ROLL, 1500-u);
	     }

	 if(L==0 && R>0){
			int kp,kd;

			float e_2 = (R-(F/2)); ///to be decided the sign to 1500 + u//
			kp= 7;// to be setted
		    kd = 3;//to be setted
		   float del_e = e_2 - e_1;
		   e_1 = e_2;
		   float u = kp*e_2 + kd*del_e;
		   Control.setRcCommand(RC_ROLL, 1500-u);
	     }


	 if(L==0 && R==0){
		   Control.setRcCommand(RC_ROLL, 1500);
	     }
//Add your repeated code here

	 sumL = 0;
	 sumR = 0;
}



//The function is called once after plutoPilot when you deactivate Developer Mode
void onPilotFinish()
{
	//Xshield.stopRanging();

// do your cleanup stuffs here

}
