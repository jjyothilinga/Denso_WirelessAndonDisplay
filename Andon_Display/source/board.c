
/*
*------------------------------------------------------------------------------
* device.c
*
* Board specipic drivers module(BSP)
*
*
* The copyright notice above does not evidence any
* actual or intended publication of such source code.
*
*------------------------------------------------------------------------------
*/


/*
*------------------------------------------------------------------------------
* Include Files
*------------------------------------------------------------------------------
*/


#include "board.h"
#include "config.h"
#include "typedefs.h"




/*
*------------------------------------------------------------------------------
* Private Defines
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Private Macros
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Private Data Types
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Variables
*------------------------------------------------------------------------------
*/
UINT16 tickPeriod = 0;
/*
*------------------------------------------------------------------------------
* Private Variables (static)
*------------------------------------------------------------------------------
*/

static BOOL ledState;

/*
*------------------------------------------------------------------------------
* Public Constants
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Private Constants (static)
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Private Function Prototypes (static)
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Functions
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* void InitializeBoard(void)

* Summary	: This function configures all i/o pin directions
*
* Input		: None
*
* Output	: None
*
*------------------------------------------------------------------------------
*/
void BRD_init(void)
{
	unsigned long clock, temp;

	//Store sytem clock
	clock = SYSTEM_CLOCK;

	switch(clock)
	{
		case 64000000UL:
		default:
				OSCCON = 0X70; 		//internal oscillator 16MHz
				OSCTUNEbits.PLLEN = 1;	//PLL Enable
		break;
		
		case 16000000UL:
				OSCCON = 0X70; 		//internal oscillator 16MHz
				OSCTUNEbits.PLLEN = 0;	//PLL Enable
		break;
	}

	//calculating tick period for timer-0
	temp = (clock / 4);	
	temp /= TIMER0_TIMEOUT_DURATION;		

	tickPeriod = (FULLSCALE_16BIT - (UINT16)temp);



	// set all anolog channels as Digital I/O
	ADCON0 = 0x00;	
	ANSELA = 0;
	ANSELB = 0;
	ANSELC = 0;
	ANSELD = 0;
	ANSELE = 0;



	HEART_BEAT_DIRECTION = PORT_OUT;
    
	//configure lamp direction

	STAT_1_RED_LAMP_DIRECTION	=PORT_OUT;
	
	STAT_2_RED_LAMP_DIRECTION	=PORT_OUT;
	
	STAT_3_RED_LAMP_DIRECTION	=PORT_OUT;
	
	STAT_4_RED_LAMP_DIRECTION	=PORT_OUT;
	
	STAT_5_RED_LAMP_DIRECTION	=PORT_OUT;
	
	STAT_6_RED_LAMP_DIRECTION	=PORT_OUT;
	
	STAT_7_RED_LAMP_DIRECTION	=PORT_OUT;
	
	STAT_8_RED_LAMP_DIRECTION	=PORT_OUT;
	
	STAT_9_RED_LAMP_DIRECTION	=PORT_OUT;
	
	STAT_1_RED_LAMP = 0;
	STAT_2_RED_LAMP = 0;
	STAT_3_RED_LAMP = 0;
	STAT_4_RED_LAMP = 0;
	STAT_5_RED_LAMP = 0;
	STAT_6_RED_LAMP = 0;
	STAT_7_RED_LAMP = 0;
	STAT_8_RED_LAMP = 0;	
	STAT_9_RED_LAMP = 0;
		
	STAT_1_YEL_LAMP_DIRECTION	=PORT_OUT;
	
	STAT_2_YEL_LAMP_DIRECTION	=PORT_OUT;
	
	STAT_3_YEL_LAMP_DIRECTION	=PORT_OUT;
	
	STAT_4_YEL_LAMP_DIRECTION	=PORT_OUT;
	
	STAT_5_YEL_LAMP_DIRECTION	=PORT_OUT;
	
	STAT_6_YEL_LAMP_DIRECTION	=PORT_OUT;
	
	STAT_7_YEL_LAMP_DIRECTION	=PORT_OUT;
					
	STAT_8_YEL_LAMP_DIRECTION	=PORT_OUT;
	
	STAT_9_YEL_LAMP_DIRECTION	=PORT_OUT;

	STAT_1_YEL_LAMP = 0;
	STAT_2_YEL_LAMP = 0;
	STAT_3_YEL_LAMP = 0;
	STAT_4_YEL_LAMP = 0;
	STAT_5_YEL_LAMP = 0;
	STAT_6_YEL_LAMP = 0;
	STAT_7_YEL_LAMP = 0;
	STAT_8_YEL_LAMP = 0;	
	STAT_9_YEL_LAMP = 0;	
	
	HOOTER_DIRECTION			=PORT_OUT;
	HOOTER   = 0;


	SER_TX_DIR = PORT_OUT;
    SER_RX_DIR = PORT_IN;
   

   // Enable internal PORTB pull-ups
    INTCON2bits.RBPU = 0;

	

}



/*
*------------------------------------------------------------------------------
* Private Functions
*------------------------------------------------------------------------------
*/

/*
*  End of device.c
*/
