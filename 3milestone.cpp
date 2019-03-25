// Do not remove the include below
#include "PlutoPilot.h"
#include "Xshield.h"
#include "Control.h"
#include "Led.h"
#include "Print.h"




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
   Control.disableFlightStatus(true);

}

void plutoPilot()
{

//Add your repeated code here
	Print.monitor("LEFT RANGE: ", Xshield.getRange(LS_LEFT));
	Print.monitor("RIGHT RANGE: ", Xshield.getRange(LS_RIGHT));

   if(Xshield.getRange(LS_LEFT)<300){

      Control.setRcCommand(RC_ROLL, 2000);
      ledOp(L_LEFT, ON);
      ledOp(L_RIGHT, OFF);

                                }

   if(Xshield.getRange(LS_RIGHT)<300){

      Control.setRcCommand(RC_ROLL, 1000);
      ledOp(L_LEFT, OFF);
      ledOp(L_RIGHT, ON);
                              }

}



void onPilotFinish()
{
// do your cleanup stuffs here

   Xshield.stopRanging();
  Control.disableFlightStatus(false);

}
