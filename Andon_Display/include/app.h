#ifndef _APP_H_
#define _APP_H_


/*
*----------------------------------------------------------------------------------------------------------------
*	MACROS
*-----------------------------------------------------------------------------------------------------------------
*/

//#define __FACTORY_CONFIGURATION__


/*
*----------------------------------------------------------------------------------------------------------------
*	Enumerations
*-----------------------------------------------------------------------------------------------------------------
*/
typedef enum 
{
	OFF,
	ON
}INDICATOR_STATE;

#define MAX_STATION 9

enum
{
	CMD_RESET_INDICATION = 0X80,
	CMD_SET_YELLOW 		= 0X81,
	CMD_SET_RED			= 0X82,
	CMD_SET_BUZZER		= 0X83
};


extern void APP_init(void);
UINT8 APP_comCallBack( UINT8 *rxPacket, UINT8* txCode, UINT8** txPacket);
void APP_task(void);



#endif