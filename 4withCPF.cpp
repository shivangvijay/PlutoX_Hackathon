// Do not remove the include below
#include "PlutoPilot.h"
#include "Xshield.h"
#include "Control.h"
#include "Led.h"
#include "Print.h"

 float e_1 = 0;//Disable default LED behaviour
  int array_left[10];
  int array_right[10];


  int sumL =0;
  int sumR =0;
//The setup function is called once at Pluto's hardware startup
void plutoInit()
{
// Add your hardware initialization code here

   Xshield.init();
}

//The function is called once before plutoPilot() when you activate Developer Mode
void onPilotStart()
{
// do your one time stuffs here

   Xshield.startRanging();


}

// The loop function is called in an endless loop
void plutoPilot()
{

//Add your repeated code here

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
    int kp,kd;

    float e_2 = (L-R)/2;
    kp= 4;
    kd = 11;
     float del_e = e_2 - e_1;
      e_1 = e_2;
     float u = kp*e_2 + kd*del_e;
     Control.setRcCommand(RC_ROLL, 1500+u);

    // Print.monitor(" RC ROLL :", u);

 for(int k=0; k<10;k++){
	 array_left[k] = 0;
	 array_right[k] = 0;
 }

sumR=0;
sumL=0;

}


void onPilotFinish()
{

// do your cleanup stuffs here

   Xshield.stopRanging();
}
