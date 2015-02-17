

/*
*------------------------------------------------------------------------------
* board.h
*
* Include file for port pin assignments
*

*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* File				: device.h
*------------------------------------------------------------------------------
*

*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Include Files
*------------------------------------------------------------------------------
*/


/*
*------------------------------------------------------------------------------
* Include Files
*------------------------------------------------------------------------------
*/

#include <p18f46k22.h>
#include <delays.h>
#include <timers.h>
#include "typedefs.h"
#include "config.h"



/*
*------------------------------------------------------------------------------
* Hardware Port Allocation
*------------------------------------------------------------------------------
*/


//Heart Beat
#define 	HEART_BEAT					PORTEbits.RE0
#define 	HEART_BEAT_DIRECTION		TRISEbits.TRISE0


///Key pad port
#define KEYPAD_PORT_0				PORTBbits.RB7
#define KEYPAD_PORT_0_DIRECTION		TRISBbits.TRISB7
#define KEYPAD_PORT_1				PORTBbits.RB6
#define KEYPAD_PORT_1_DIRECTION		TRISBbits.TRISB6
#define KEYPAD_PORT_2				PORTBbits.RB5
#define KEYPAD_PORT_2_DIRECTION		TRISBbits.TRISB5
#define KEYPAD_PORT_3				PORTBbits.RB4
#define KEYPAD_PORT_3_DIRECTION		TRISBbits.TRISB4
#define KEYPAD_PORT_4				PORTBbits.RB3
#define KEYPAD_PORT_4_DIRECTION		TRISBbits.TRISB3
#define KEYPAD_PORT_5				PORTBbits.RB2
#define KEYPAD_PORT_5_DIRECTION		TRISBbits.TRISB2
#define KEYPAD_PORT_6				PORTBbits.RB1
#define KEYPAD_PORT_6_DIRECTION		TRISBbits.TRISB1
#define KEYPAD_PORT_7				PORTBbits.RB0
#define KEYPAD_PORT_7_DIRECTION		TRISBbits.TRISB0



#define KEYPAD_PORT_8				PORTDbits.RD7
#define KEYPAD_PORT_8_DIRECTION		TRISDbits.TRISD7
#define KEYPAD_PORT_9				PORTDbits.RD6
#define KEYPAD_PORT_9_DIRECTION		TRISDbits.TRISD6
#define KEYPAD_PORT_10				PORTDbits.RD5
#define KEYPAD_PORT_10_DIRECTION	TRISDbits.TRISD5
#define KEYPAD_PORT_11				PORTDbits.RD4
#define KEYPAD_PORT_11_DIRECTION	TRISDbits.TRISD4
#define KEYPAD_PORT_12				PORTDbits.RD3
#define KEYPAD_PORT_12_DIRECTION	TRISDbits.TRISD3
#define KEYPAD_PORT_13				PORTDbits.RD2
#define KEYPAD_PORT_13_DIRECTION	TRISDbits.TRISD2
#define KEYPAD_PORT_14				PORTDbits.RD1
#define KEYPAD_PORT_14_DIRECTION	TRISDbits.TRISD1
#define KEYPAD_PORT_15				PORTDbits.RD0
#define KEYPAD_PORT_15_DIRECTION	TRISDbits.TRISD0




#define KEYPAD_PORT_16				PORTAbits.RA5
#define KEYPAD_PORT_16_DIRECTION	TRISAbits.TRISA5
#define KEYPAD_PORT_17				PORTAbits.RA4
#define KEYPAD_PORT_17_DIRECTION	TRISAbits.TRISA4
#define KEYPAD_PORT_18				PORTAbits.RA3
#define KEYPAD_PORT_18_DIRECTION	TRISAbits.TRISA3
#define KEYPAD_PORT_19				PORTAbits.RA2
#define KEYPAD_PORT_19_DIRECTION	TRISAbits.TRISA2
#define KEYPAD_PORT_20				PORTAbits.RA1
#define KEYPAD_PORT_20_DIRECTION	TRISAbits.TRISA1
#define KEYPAD_PORT_21				PORTAbits.RA0
#define KEYPAD_PORT_21_DIRECTION	TRISAbits.TRISA0
#define KEYPAD_PORT_22				PORTCbits.RC4
#define KEYPAD_PORT_22_DIRECTION	TRISCbits.TRISC4
#define KEYPAD_PORT_23				PORTCbits.RC3
#define KEYPAD_PORT_23_DIRECTION	TRISCbits.TRISC3

#define KEYPAD_PORT_24				PORTCbits.RC2
#define KEYPAD_PORT_24_DIRECTION	TRISCbits.TRISC2
#define KEYPAD_PORT_25				PORTCbits.RC1
#define KEYPAD_PORT_25_DIRECTION	TRISCbits.TRISC1
#define KEYPAD_PORT_26				PORTCbits.RC0
#define KEYPAD_PORT_26_DIRECTION	TRISCbits.TRISC0


//Serial Communication
#define 	SER_TX					PORTCbits.RC6   		// serial transmit
#define		SER_TX_DIR				TRISCbits.TRISC6
#define 	SER_RX					PORTCbits.RC7			// serial receive
#define		SER_RX_DIR				TRISCbits.TRISC7

	
/*
*------------------------------------------------------------------------------
* Public Defines
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Macros
*------------------------------------------------------------------------------
*/

#define DEVICE_ID			(0x01)


#define PERIPHERAL_CLOCK			(SYSTEM_CLOCK / 4)UL

#define PERIPHERAL_CLOCK_PERIOD 	(1 / PERIPHERAL_CLOCK)UL



// Direction controle bit is processor specific ,
#define PORT_OUT				(BOOL)(0)
#define PORT_IN					(0XFF)

#define OFF_FOREVER				(BOOL)(0)
#define LOOP_FOREVER			(BOOL)(1)

#define SWITCH_OFF				(BOOL)(0)
#define SWITCH_ON				(BOOL)(1)


#define DISPLAY_DISABLE			(BOOL)(1)
#define DISPLAY_ENABLE			(BOOL)(0)
void EnableInterrupts(void);

/*
#ifdef __74LS374__
#undef DISPLAY_DISABLE
#undef DISPLAY_ENABLE

#define DISPLAY_DISABLE			(BOOL)(0)
#define DISPLAY_ENABLE			(BOOL)(1)

#endif 			//__74LS374__
*/


#define GetSystemClock()		(SYSTEM_CLOCK)      // Hz
#define GetInstructionClock()	(GetSystemClock()/4)
#define GetPeripheralClock()	GetInstructionClock()


#define BUZZER_ON()			BUZ_OP = SWITCH_ON;
#define BUZZER_OFF()		BUZ_OP = SWITCH_OFF;

// Disable global interrupt bit.
#define ENTER_CRITICAL_SECTION()	INTCONbits.GIE = 0;

// Enable global interrupt bit.
#define EXIT_CRITICAL_SECTION()		INTCONbits.GIE = 1;

#define ENABLE_GLOBAL_INT()			EXIT_CRITICAL_SECTION()


#define DISABLE_ADC_INTERRUPT()		PIE1bits.ADIE = 0
#define ENABLE_ADC_INTERRUPT()		PIE1bits.ADIE = 1

#define DISABLE_INT0_INTERRUPT()	INTCONbits.INT0IE = 0
#define ENABLE_INT0_INTERRUPT()		INTCONbits.INT0IE = 1
#define CLEAR_INTO_INTERRUPT()		INTCONbits.INT0IF = 0


#define DISABLE_TMR0_INTERRUPT()	INTCONbits.TMR0IE = 0
#define ENABLE_TMR0_INTERRUPT()		INTCONbits.TMR0IE = 1

#define DISABLE_TMR1_INTERRUPT()	PIE1bits.TMR1IE = 0
#define ENABLE_TMR1_INTERRUPT()		PIE1bits.TMR1IE = 1


#define DISABLE_UART_TX_INTERRUPT()	PIE1bits.TXIE = 0
#define ENABLE_UART_TX_INTERRUPT()	PIE1bits.TXIE = 1

#define DISABLE_UART1_RX_INTERRUPT()	PIE1bits.RCIE = 0
#define ENABLE_UART1_RX_INTERRUPT()	PIE1bits.RCIE = 1

#define DISABLE_UART2_TX_INTERRUPT()	PIE3bits.TX2IE = 0
#define ENABLE_UART2_TX_INTERRUPT()	PIE3bits.TX2IE = 1

#define DISABLE_UART2_RX_INTERRUPT()	PIE3bits.RC2IE = 0
#define ENABLE_UART2_RX_INTERRUPT()	PIE3bits.RC2IE = 1


#define HOLD_ATKBD_CLOCK()		    ATKBD_CLK_DIR= PORT_OUT;\
									ATKBD_CLK = 0;

#define RELEASE_ATKBD_CLOCK()	  	ATKBD_CLK_DIR = PORT_IN;\
									ATKBD_CLK = 1;

#define SET_INT0_FALLING_EDGE_TRIGGER()	INTCON2bits.INTEDG0 = 0

#define	ATKBD_INTERRUPT_EDGE	INTCON2.INTEDG0		

#define ENB_485_TX()	TX_EN = 1;
#define ENB_485_RX()	TX_EN = 0

#define Delay10us(us)		Delay10TCYx(((GetInstructionClock()/1000000)*(us)))
#define DelayMs(ms)												\
	do																\
	{																\
		unsigned int _iTemp = (ms); 								\
		while(_iTemp--)												\
			Delay1KTCYx((GetInstructionClock()+999999)/1000000);	\
	} while(0)

/*
*------------------------------------------------------------------------------
* Public Data Types
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Variables (extern)
*------------------------------------------------------------------------------
*/


/*
*------------------------------------------------------------------------------
* Public Constants (extern)
*------------------------------------------------------------------------------
*/

/*
*------------------------------------------------------------------------------
* Public Function Prototypes (extern)
*------------------------------------------------------------------------------
*/

extern void BRD_init(void);


/*
*  End of board.h
*/