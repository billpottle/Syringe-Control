// printercontroller.cpp: implementation of the printercontroller class.
// Written by Bill Pottle. Final Version- 7/11/2002
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "printercontroller.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


/*
 * Includes: 
 */

#include "nidaqex.h"
#include "time.h"
#include "windows.h"

//variables used. Note NIDAQ i16 data type used. 
	i16 counter;
	i16 iStatus;
	i16 iRetVal;
	i16 iDevice;
    i16 iPort;
	i16 iPort2;
	i16 iPort3;
    i16 iMode;
    i16 iDir;
    i32 iPattern;
    i32 NumLoops;
    i16 iIgnoreWarning;
    i16 iYieldON;
	i16 numsteps;
	i16 stepdelay;
	i16 headdelay;
	i16	counter2;
	i16 ofsetdelay;


// Constructor for printcontroller class
printercontroller::printercontroller() {

	 counter=0;
     iStatus = 0;
     iRetVal = 0;
     iDevice = 1;
     iPort = 0;
	 //Port A
	 iPort2 = 2;
	 //Port C
	 iPort3=1;
	 //Port B- Not Used
     iMode = 0;
     iDir = 1;
     iPattern = 0;
     iIgnoreWarning = 0;
     iYieldON = 1;
//default values specified but not used
	 numsteps=30;
	 stepdelay= 1;
	 headdelay= 200;
	 counter2=0;
	 ofsetdelay=0;

}
// function to set changable values

/*********************************************************************/
void printercontroller::setValues(i16 a, i16 b, i16 c, i16 d, i16 e) {
	NumLoops=a;
	headdelay=b;
	numsteps=c;
	stepdelay=d;
	ofsetdelay=e;
}

/*********************************************************************/
//Delay Function

void delay (int dt)
{
//delays a specified number of milliseconds
	unsigned long final;
	final = dt+ GetTickCount();
		while (final>GetTickCount());
		return;

}

/*********************************************************************/
//Motor up function
//Gives the stepper motor a specified number of steps to go up.
//Opposite of the MotorDown function
//This function is currently not used. 


void MotorUp (int steps)
{	
		counter=0;
		while ((counter < numsteps) && (iStatus == 0)) {
	//Note- Output goes on Pins C7, C6, C2 and C0
		
		// output - 1001 //132
		iPattern =132;
        iStatus = DIG_Out_Prt(iDevice, iPort2, iPattern);
        iRetVal = NIDAQErrorHandler(iStatus, "DIG_Out_Prt",
         iIgnoreWarning);
		delay(stepdelay);

		// output - 0101 //68
		iPattern=68;
        iStatus = DIG_Out_Prt(iDevice, iPort2, iPattern);
        iRetVal = NIDAQErrorHandler(iStatus, "DIG_Out_Prt",
         iIgnoreWarning);
		delay(stepdelay);
		 
		// output - 0110 //65 
		iPattern=65;
        iStatus = DIG_Out_Prt(iDevice, iPort2, iPattern);
        iRetVal = NIDAQErrorHandler(iStatus, "DIG_Out_Prt",
         iIgnoreWarning);
		delay(stepdelay);

		// output  - 1010 =  //129
		iPattern=129;
        iStatus = DIG_Out_Prt(iDevice, iPort2, iPattern);
        iRetVal = NIDAQErrorHandler(iStatus, "DIG_Out_Prt",
        iIgnoreWarning);
		delay(stepdelay);
        iRetVal = NIDAQYield(iYieldON);

		printf("Counter= %d", counter);
		counter++;
		
    }


	iPattern=0;
        iStatus = DIG_Out_Prt(iDevice, iPort2, iPattern);
    // Output zero to turn off stepper motor to avoid overheating    
		iRetVal = NIDAQErrorHandler(iStatus, "DIG_Out_Prt",
        iIgnoreWarning);

}


/*********************************************************************/
//Motor down Function
//Gives the stepper motor a specified number of steps to go down.
//Opposite of the MotorUp function


void MotorDown (int steps)
{	
		counter=0;
		while ((counter < numsteps) && (iStatus == 0)) {
	//Note- Output goes on Pins C7, C6, C2 and C0
		// output  - 1010 =  //129
		iPattern=129;
        iStatus = DIG_Out_Prt(iDevice, iPort2, iPattern);
        iRetVal = NIDAQErrorHandler(iStatus, "DIG_Out_Prt",
        iIgnoreWarning);
		delay(stepdelay);
        iRetVal = NIDAQYield(iYieldON);
		
		// output - 0110 //65 
		iPattern=65;
        iStatus = DIG_Out_Prt(iDevice, iPort2, iPattern);
        iRetVal = NIDAQErrorHandler(iStatus, "DIG_Out_Prt",
         iIgnoreWarning);
		delay(stepdelay);

		// output - 0101 //68
		iPattern=68;
        iStatus = DIG_Out_Prt(iDevice, iPort2, iPattern);
        iRetVal = NIDAQErrorHandler(iStatus, "DIG_Out_Prt",
         iIgnoreWarning);
		delay(stepdelay);
		
		
		// output - 1001 //132
		iPattern =132;
        iStatus = DIG_Out_Prt(iDevice, iPort2, iPattern);
        iRetVal = NIDAQErrorHandler(iStatus, "DIG_Out_Prt",
         iIgnoreWarning);
		delay(stepdelay);
		 
		printf("Counter= %d", counter);
		counter++;
		
    }


	iPattern=0;
        iStatus = DIG_Out_Prt(iDevice, iPort2, iPattern);
    // Output zero to turn off stepper motor to avoid overheating    
		iRetVal = NIDAQErrorHandler(iStatus, "DIG_Out_Prt",
        iIgnoreWarning);
		


}


/*
 * Main function to run the system 
 */
void printercontroller::run()
{	

    /* Configure port A as output for printer head control, no handshaking. */

    iStatus = DIG_Prt_Config(iDevice, iPort, iMode, iDir);

    iRetVal = NIDAQErrorHandler(iStatus, "DIG_Prt_Config",
     iIgnoreWarning);

	/* Configure port C as output for stepper motor */
	iStatus = DIG_Prt_Config(iDevice, iPort2, iMode, iDir);

    iRetVal = NIDAQErrorHandler(iStatus, "DIG_Prt_Config",
     iIgnoreWarning);


	// Loop to set the print head moving back and forth. 	

    while ((counter2 < NumLoops) && (iStatus == 0)) {
		
		// output 0 1 to move print head right
		iPattern=16;
        iStatus = DIG_Out_Prt(iDevice, iPort, iPattern);
        iRetVal = NIDAQErrorHandler(iStatus, "DIG_Out_Prt",
         iIgnoreWarning);
//Diagnostic Controlls not displayed in windows GUI mode
        printf(" The digital  chk pattern on port %d is set to (DECIMAL) %ld\n", iPort, iPattern);
		MotorDown(numsteps);
		delay(headdelay);
		
		// output 1 0 = 8 to move motor left. If ofsetdelay is 0, then do not move the print head left at all. 
		//This is a default flag. 

		if (ofsetdelay==0) {
			iPattern=0;
		}
		else {
		iPattern=8;
		}
        iStatus = DIG_Out_Prt(iDevice, iPort, iPattern);
        iRetVal = NIDAQErrorHandler(iStatus, "DIG_Out_Prt",
         iIgnoreWarning);

        printf(" The digital pattern on port %d is set to (DECIMAL) %ld\n", iPort, iPattern);
		
		
		//MotorUp(numsteps);

		//Delay comming back
        delay(headdelay+ ofsetdelay);
	
        iRetVal = NIDAQYield(iYieldON);
		counter2++;

    }
		// Write 0 to turn off port A and the print head motor. 
		iPattern=0;
        iStatus = DIG_Out_Prt(iDevice, iPort, iPattern);
        iRetVal = NIDAQErrorHandler(iStatus, "DIG_Out_Prt",
         iIgnoreWarning);
		 printf(" The digital pattern on port %d is set to (DECIMAL) %ld\n", iPort, iPattern);

}

/* End of program */