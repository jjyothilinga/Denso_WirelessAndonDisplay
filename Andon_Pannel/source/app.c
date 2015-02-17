
/* ------------------------------------------------
	header files
------------------------------------------------ */

#include "app.h"
#include "communication.h"
#include "config.h"
#include "linearkeypad.h"



typedef struct _STATION_
{
	UINT8 red_state;
	UINT8 yellow_state;
	UINT8 blue_state;
	UINT8 buzzer_state;


}STATION;



typedef  struct _APP
{
	STATION stn[MAX_STATION];
	UINT8 buzzprevstate;
	UINT8 buzzerstate ;
	UINT8 OFFIndication;
	UINT8 ONIndication;

}APP;

#pragma idata APPDATA
APP app ={0};
#pragma idata

/*------------------------------------------------------------
public function
------------------------------------------------------------*/
void reset_indication(UINT8 data);
void set_yellow(UINT8 data);
void set_red(UINT8 data);
void set_buzzer(UINT8 data);



/*
--------------------------------------------------------------------------
Number of statons = 9. Number of PB's = 9*3 = 27
Blue PB (reset): 0, 3, 6, 9, 12, 15, 18, 21, 24	
Yellow PB: 		 1, 4, 7, 10, 13, 16, 19, 22, 25
Red PB:			 2, 5, 8, 11, 14, 17, 20, 23, 26

--------------------------------------------------------------------------
*/

void APP_init()
{
	UINT8 i;
	COM_init(CMD_SOP , CMD_EOP ,RESP_SOP , RESP_EOP , APP_comCallBack);


}

void APP_task(void)
{

	UINT8 i;


	for( i = 0 ; i< MAX_STATION; i++ )
	{
		if( (LinearKeyPad_getKeyState(i*3)) == 1 )     // check for blue
		{
			if((app.stn[i].blue_state == 0) && ((	app.stn[i].yellow_state ==1 )||(app.stn[i].red_state == 1)))
			{
				app.stn[i].blue_state = 1;
				app.stn[i].red_state = 0;
				app.stn[i].yellow_state = 0;
				app.stn[i].buzzer_state = 0;

			//	app.stn[i].blue_tx = 1;
				
			}
		}
		
	
		else
		{
			if( (LinearKeyPad_getKeyState((i*3)+1)) == 1 )   // check for yellow
			{
				if(	app.stn[i].yellow_state == 0 )
				{
					app.stn[i].yellow_state = 1;
					app.stn[i].blue_state = 0;
								 	
					app.stn[i].buzzer_state = 1;

				//	app.stn[i].yellow_tx = 1;
					
				}				
			}
			if((LinearKeyPad_getKeyState((i*3)+2)) == 1)			// // check for red
			{
				if(	app.stn[i].red_state == 0 )
				{
					app.stn[i].blue_state = 0;
					app.stn[i].red_state = 1;
					
					app.stn[i].buzzer_state = 1;

				//	app.stn[i].red_tx = 1;
					
				}
			}
		}
	}


	

	app.buzzerstate = 0;

	for(i = 0; i < MAX_STATION ; i++)
	{
		if (app.stn[i].blue_state == 1) //&& (app.stn[i].blue_tx == 1) )
		{
			app.OFFIndication = 1;	
			reset_indication(i);
		//	app.stn[i].blue_tx = 0;
			
		}
		else
		{
			if (app.stn[i].yellow_state == 1) //&& (app.stn[i].yellow_tx == 1) )
			{
				app.ONIndication = 1;
				set_yellow(i);
			//	app.stn[i].yellow_tx = 0;
			}
			if(app.stn[i].red_state == 1)// && (app.stn[i].red_tx == 1))
			{
				app.ONIndication = 1;
				set_red(i);
			//	app.stn[i].red_tx = 0;
			}
		}
		if( app.stn[i].buzzer_state == 1 )
			app.buzzerstate = 1;
	}
	
	if((app.OFFIndication == 1) && ( app.buzzerstate == 0))
	{
		app.OFFIndication = 0 ;
		set_buzzer(0);
	}
	else if ((app.ONIndication == 1 )&&(app.buzzerstate == 1))
	{
		app.ONIndication = 0;
		set_buzzer(1);
	}

}


void reset_indication(UINT8 data)
{
	
	COM_txCMD(DEVICE_ADDRESS,	CMD_RESET_INDICATION,  data ,  CMD_LENGTH );

}

void set_yellow(UINT8 data)
{

	COM_txCMD( DEVICE_ADDRESS,	CMD_SET_YELLOW ,  data ,  CMD_LENGTH );

}
void set_red(UINT8 data)
{

	COM_txCMD(DEVICE_ADDRESS,	CMD_SET_RED,  data ,  CMD_LENGTH );

}
void set_buzzer(UINT8 data)
{

	COM_txCMD(DEVICE_ADDRESS, CMD_SET_BUZZER, data ,  CMD_LENGTH );

}



UINT8 APP_comCallBack( far UINT8 *rxPacket, far UINT8* txCode,far UINT8** txPacket)
{

	UINT8 i;

	UINT8 rxCode = rxPacket[0];
	UINT8 length = 0;


	return length;

}
	
		

		