
/*
*------------------------------------------------------------------------------
* Include Files
*------------------------------------------------------------------------------
*/
#include "config.h"
#include "board.h"
#include "timer.h"
#include "communication.h"
#include "app.h"
#include "string.h"
#include "eep.h"




typedef struct _STATION_
{
	UINT8 red_state;
	UINT8 yellow_state;
	UINT8 blue_state;

}STATION;


typedef  struct _APP
{
	STATION stn[MAX_STATION];
	UINT8 buzzer_state;

}APP;

#pragma idata APPDATA
APP app ={0};
#pragma idata




/*
*------------------------------------------------------------------------------
* void APP-init(void)
*------------------------------------------------------------------------------
*/

void APP_init(void)
{


#ifdef __POWERON_TEST__
	
	UINT8 i,j;

	for ( i = 0; i < 8; i++)
	{
		PORTB = (1<<i);
		DelayMs(1000);
	}
	PORTB = 0;

	for ( j=0; j < 8;j++)
	{
		PORTD = (1<<j);
		DelayMs(1000);
	}

	
	PORTD = 0;

	for ( j=0; j < 2;j++)
	{
		PORTA = (1<<j);
		DelayMs(1000);
	}

	
	PORTA = 0;

#endif


}

void APP_task()
{
	UINT8 i;

	for( i = 0; i < MAX_STATION; i++)
	{
			switch(i)
			{
				case 0: 
						if(app.stn[i].blue_state == 1)
						{
							app.stn[i].blue_state = 0;	
							STAT_1_RED_LAMP = 0;
							STAT_1_YEL_LAMP = 0;
						}
						else
						{ 
							if(app.stn[i].yellow_state == 1)
							{
								app.stn[i].yellow_state = 0;
								STAT_1_YEL_LAMP = 1;
							}
							else if(app.stn[i].red_state ==1)
							{
								app.stn[i].red_state = 0;
								STAT_1_RED_LAMP = 1;
							}
						}
						
						break;
	
				case 1: 
						if(app.stn[i].blue_state == 1)
						{
							app.stn[i].blue_state = 0;
							STAT_2_RED_LAMP = 0;
							STAT_2_YEL_LAMP = 0;
						}
						else
						{ 
							if(app.stn[i].yellow_state == 1)
							{
								app.stn[i].yellow_state = 0;
								STAT_2_YEL_LAMP = 1;
							}
							else if(app.stn[i].red_state ==1)
							{
								app.stn[i].red_state = 0;
								STAT_2_RED_LAMP = 1;
							}
						}
						break;
	
				case 2:
						if(app.stn[i].blue_state == 1)
						{
							app.stn[i].blue_state = 0;
							STAT_3_RED_LAMP = 0;
							STAT_3_YEL_LAMP = 0;
						}
						else
						{ 
							if(app.stn[i].yellow_state == 1)
							{
								app.stn[i].yellow_state = 0;
								STAT_3_YEL_LAMP = 1;
							}
							else if(app.stn[i].red_state ==1)
							{
								app.stn[i].red_state = 0;
								STAT_3_RED_LAMP = 1;
							}
						}							
						break;
	
				case 3: 
						if(app.stn[i].blue_state == 1)
						{
							app.stn[i].blue_state = 0;
							STAT_4_RED_LAMP = 0;
							STAT_4_YEL_LAMP = 0;
						}
						else
						{ 
							if(app.stn[i].yellow_state == 1)
							{
								app.stn[i].yellow_state = 0;
								STAT_4_YEL_LAMP = 1;
							}
							else if(app.stn[i].red_state ==1)
							{
								app.stn[i].red_state = 0;
								STAT_4_RED_LAMP = 1;
							}
						}
						break;
	
				case 4: 
						if(app.stn[i].blue_state == 1)
						{
							app.stn[i].blue_state = 0;
							STAT_5_RED_LAMP = 0;
							STAT_5_YEL_LAMP = 0;
						}
						else
						{ 
							if(app.stn[i].yellow_state == 1)
							{
								app.stn[i].yellow_state = 0;
								STAT_5_YEL_LAMP = 1;
							}
							else if(app.stn[i].red_state ==1)
							{
								app.stn[i].red_state = 0;
								STAT_5_RED_LAMP = 1;
							}
						}
						break;
	
				case 5:
						if(app.stn[i].blue_state == 1)
						{
							app.stn[i].blue_state = 0;
							STAT_6_RED_LAMP = 0;
							STAT_6_YEL_LAMP = 0;
						}
						else
						{ 
							if(app.stn[i].yellow_state == 1)
							{
								app.stn[i].yellow_state = 0;
								STAT_6_YEL_LAMP = 1;
							}
							else if(app.stn[i].red_state ==1)
							{
								app.stn[i].red_state = 0;
								STAT_6_RED_LAMP = 1;
							}
						}
						break;
				case 6:
						if(app.stn[i].blue_state == 1)
						{
							app.stn[i].blue_state = 0;
							STAT_7_RED_LAMP = 0;
							STAT_7_YEL_LAMP = 0;
						}
						else
						{ 
							if(app.stn[i].yellow_state == 1)
							{
								app.stn[i].yellow_state = 0;
								STAT_7_YEL_LAMP = 1;
							}
							else if(app.stn[i].red_state ==1)
							{
								app.stn[i].red_state = 0;
								STAT_7_RED_LAMP = 1;
							}
						}
						break;
				case 7:
						if(app.stn[i].blue_state == 1)
						{
							app.stn[i].blue_state = 0;
							STAT_8_RED_LAMP = 0;
							STAT_8_YEL_LAMP = 0;
						}
						else
						{ 
							if(app.stn[i].yellow_state == 1)
							{
								app.stn[i].yellow_state = 0;
								STAT_8_YEL_LAMP = 1;
							}
							else if(app.stn[i].red_state ==1)
							{
								app.stn[i].red_state = 0;
								STAT_8_RED_LAMP = 1;
							}
						}
						break;
				case 8:
						if(app.stn[i].blue_state == 1)
						{
							app.stn[i].blue_state = 0;
							STAT_9_RED_LAMP = 0;
							STAT_9_YEL_LAMP = 0;
						}
						else
						{ 
							if(app.stn[i].yellow_state == 1)
							{
								app.stn[i].yellow_state = 0;
								STAT_9_YEL_LAMP = 1;
							}
							else if(app.stn[i].red_state ==1)
							{
								app.stn[i].red_state = 0;
								STAT_9_RED_LAMP = 1;
							}
						}
						break;

			default:break;			
		}
		
	}

	HOOTER = app.buzzer_state;
}


UINT8 APP_comCallBack( far UINT8 *rxPacket, far UINT8* txCode,far UINT8** txPacket)
{

	UINT8 i;

	UINT8 rxCode = rxPacket[0];
	UINT8 data = rxPacket[1];
	UINT8 length = 0;
	*txCode = rxCode;


	switch( rxCode )
	{
		case CMD_RESET_INDICATION:
			 for( i = 0; i < MAX_STATION; i++)
			 {
				if(i == data)
				{
					app.stn[i].blue_state = 1;
					break;
				}
			 }

			break;

		case CMD_SET_YELLOW :
			 for( i = 0; i < MAX_STATION; i++)
			 {
				if(i == data)
				{
					app.stn[i].yellow_state = 1;
					break;
				}
			 }
			
			break;

		case CMD_SET_RED:
			 for( i = 0; i < MAX_STATION; i++)
			 {
				if(i == data)
				{
					app.stn[i].red_state = 1;
					break;
				}
			 }
			
			break;

	

		case CMD_SET_BUZZER:
			 app.buzzer_state = data;

			break;

		default:
			break;

	}

	return length;

}
	
		

		
	

