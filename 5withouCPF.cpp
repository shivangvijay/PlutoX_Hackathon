// Do not remove the include below
#include "PlutoPilot.h"
#include "Xshield.h"
#include "Control.h"
#include "Led.h"
#include "Print.h"

 float e_1=0;
 float F = 0;
//The setup function is called once at Pluto's hardware startup
void plutoInit()
{
	  Xshield.init(); //Initialize the Xshield
// Add your hardware initialization code here
}



//The function is called once before plutoPilot when you activate Developer Mode
void onPilotStart()
{
	 Xshield.startRanging();
  // do your one time stuffs here

}



// The loop function is called in an endless loop
void plutoPilot()
{
	 Print.monitor(" L RANGE: ", Xshield.getRange(LS_LEFT));
	 Print.monitor(" R RANGE: ", Xshield.getRange(LS_RIGHT));
	 int L = Xshield.getRange(LS_LEFT);
	 int R = Xshield.getRange(LS_RIGHT);

	if(L>0 && R>0){
		   F = L+R;
		   int kp,kd;
		   float e_2 = (L-R)/2;
		   kp= 6;
		   kd = 6;
		   float del_e = e_2 - e_1;
		     e_1 = e_2;
		    float u = kp*e_2 + kd*del_e;
		    Control.setRcCommand(RC_ROLL, 1500+u);
	      }

	 if(L>0 && R<0){
			int kp,kd;

			float e_2 = (L-(F/2));
			kp= 6;
		    kd = 6;
		   float del_e = e_2 - e_1;
		   e_1 = e_2;
		   float u = kp*e_2 + kd*del_e;
		   Control.setRcCommand(RC_ROLL, 1500+u);
	     }

	 if(L<0 && R>0){
			int kp,kd;

			float e_2 = (R-(F/2)); ///to be decided the sign to 1500 + u//
			kp= 6;
		    kd = 6;
		   float del_e = e_2 - e_1;
		   e_1 = e_2;
		   float u = kp*e_2 + kd*del_e;
		   Control.setRcCommand(RC_ROLL, 1500+u);
	     }


	 if(L<0 && R<0){
		   Control.setRcCommand(RC_ROLL, 1500);
	     }
//Add your repeated code here

}



//The function is called once after plutoPilot when you deactivate Developer Mode
void onPilotFinish()
{
	Xshield.stopRanging();

// do your cleanup stuffs here

}
