/*
* common.h
*
* Created: 2016-01-30 17:27:13
*  Author: r-gal
*/


#ifndef COMMON_H_
#define COMMON_H_

#define F_CPU 8000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include "Slave.h"

#include <util/delay.h>

typedef uint8_t W8;
typedef uint16_t W16;
#define AND &&
#define OR ||

//#define SW3_DEVICE
//#define SW6_DEVICE
//define REL2_DEVICE
//#define REL4_DEVICE
//#define REL8_DEVICE
//#define HIG_DEVICE
//#define SPEC1_DEVICE

#ifdef SW3_DEVICE
#define SW_DEVICE
#define ATTINY25
#define I_MASC 0x1A
#define I_DIR DDRB
#define I_PORT PORTB
#define I_PIN PINB
#define ADR3 0x10
#endif

#ifdef SW6_DEVICE
#define SW_DEVICE
#define ATTINY24
#define I_MASC 0xAF
#define I_DIR DDRA
#define I_PORT PORTA
#define I_PIN PINA
#define ADR3 0x20
#endif

#ifdef REL2_DEVICE
#define TR_DEVICE
#define ATTINY25
#define O_MASC 0x18
#define O_DIR DDRB
#define O_PORT PORTB
#define O_PIN PINB
#define ADR3 0x50
#endif

#ifdef REL4_DEVICE
#define TR_DEVICE
#define ATTINY24
#define O_MASC 0x8B
#define O_DIR DDRA
#define O_PORT PORTA
#define O_PIN PINA
#define ADR3 0x60
#endif

#ifdef REL8_DEVICE
#define TR_DEVICE
#define ATTINY261A
#define O_MASC 0xFF
#define O_DIR DDRA
#define O_PORT PORTA
#define O_PIN PINA
#define ADR3 0x70
#endif

#ifdef HIGRO_DEVICE
#define HG_DEVICE
#define ATTINY25
#define H_DDR DDRB
#define H_PORT PORTB
#define H_PIN PINB
#define H_MASC
#define ADC_NR 3
#define HIGRO_ONE_MASC 0x10
#define HIGRO_TWO_MASC 0x02 
#define ADR3 0xA0

#define USE_FRAME_REQUEST

const W8 portType[] = { 0x10, 0x10};
const W8 higroMasc[] = {HIGRO_ONE_MASC, HIGRO_TWO_MASC};
const W8 maxPort = 2;
#endif

#ifdef SPEC1_DEVICE
#define ATTINY24
#define SW_DEVICE
#define I_MASC 0x81
#define I_DIR DDRA
#define I_PORT PORTA
#define I_PIN PINA
#define TR_DEVICE
#define O_MASC 0x0E
#define O_DIR DDRA
#define O_PORT PORTA
#define O_PIN PINA
#define ADR3 0xB0
#endif

#ifdef SPEC2_DEVICE
#define ATTINY261A
#define SW_DEVICE
#define I_MASC 0x07
#define I_DIR DDRA
#define I_PORT PORTA
#define I_PIN PINA
#define TR_DEVICE
#define O_MASC 0xF8
#define O_DIR DDRA
#define O_PORT PORTA
#define O_PIN PINA
#define ADR3 0xC0
#endif

#ifdef PRESS_DEVICE
#define ADC_DEVICE
#define ATTINY25
#define ADC_NR 2
#define ADR3 0xD0

#define USE_FRAME_REQUEST
const W8 portType[] = { 0x00 };
const W8 maxPort = 1;
#endif

#ifdef PWM3_DEVICE
#define PWM_DEVICE
#define ATTINY44
#define ADR3 0xE0
#define SW_DEVICE
#define I_MASC 0x06
#define I_DIR DDRA
#define I_PORT PORTA
#define I_PIN PINA
#define TR_DEVICE
#define O_MASC 0x01
#define O_DIR DDRA
#define O_PORT PORTA
#define O_PIN PINA
#endif

/*end defining values */
#ifdef ATTINY25
#define CLK_DIR DDRB
#define DAT_DIR DDRB
#define CLK_OUT PORTB
#define DAT_OUT PORTB
#define CLK_IN PINB
#define DAT_IN PINB
#define CLK_NR 2
#define DAT_NR 0

#define PCIF_CUSTOM PCIF	
#endif

#ifdef ATTINY24
#define CLK_DIR DDRA
#define DAT_DIR DDRA
#define CLK_OUT PORTA
#define DAT_OUT PORTA
#define CLK_IN PINA
#define DAT_IN PINA
#define CLK_NR 4
#define DAT_NR 6

#define PCIF_CUSTOM PCIF0	

#endif

#ifdef ATTINY44
#define CLK_DIR DDRA
#define DAT_DIR DDRA
#define CLK_OUT PORTA
#define DAT_OUT PORTA
#define CLK_IN PINA
#define DAT_IN PINA
#define CLK_NR 4
#define DAT_NR 6

#define PCIF_CUSTOM PCIF0
#endif

#ifdef ATTINY261A
#define CLK_DIR DDRB
#define DAT_DIR DDRB
#define CLK_OUT PORTB
#define DAT_OUT PORTB
#define CLK_IN PINB
#define DAT_IN PINB
#define CLK_NR 2
#define DAT_NR 0

#define PCIF_CUSTOM PCIF
#endif

const W8 LONGADR[] = {ADR3,ADR2,ADR1,ADR0};

void clkDirIn(void) { CLK_DIR &= ~(1<<CLK_NR); }
void clkDirOut(void) { CLK_DIR |= (1<<CLK_NR); }
void datDirIn(void) { DAT_DIR &= ~(1<<DAT_NR); }
void datDirOut(void) { DAT_DIR |= (1<<DAT_NR); }

#define INPUTCHECKCOUNTERMAX 200
#define INPUTBUFFERSIZE 16
#define OUTPUTBUFFERSIZE 14
#define EVENTBUFFERSIZE 10
#define NOOFRETRIES 10

enum frameCode_et
{
	FRAME_ADRCONQUEST = 0,
	FRAME_DEVCONFIG = 1,
	FRAME_CHECKDEVICE = 2,
	FRAME_DATA_SW = 3,
	FRAME_DATA_TR = 4,
	FRAME_READ_IO = 5,
	FRAME_READ_STATUS = 6,
	FRAME_DETACH_ALL = 7,
	FRAME_REQUEST = 8,
	FRAME_DATA = 9,
	FRAME_READ_IO_EXT = 10
};

enum frameAck_et
{
	ACK_NORMAL = 0,
	ACK_ERROR = 1,
	ACK_UNKNOWN = 2,
	ACK_INVALID_ARG = 3,
	ACK_DISABLED = 4,
	ACK_BUSY = 5,
	ACK_INVALID_CHECKSUM = 0xF
};
#define DEFAULT_1B_ACK (ACK_NORMAL | (ACK_NORMAL<<4))
#define UNKNOWN_1B_ACK (ACK_UNKNOWN | (ACK_UNKNOWN<<4))
#define INVARG_1B_ACK (ACK_INVALID_ARG | (ACK_INVALID_ARG<<4))
#define DISABLED_1B_ACK (ACK_DISABLED | (ACK_DISABLED<<4))
#define BUSY_1B_ACK (ACK_BUSY | (ACK_BUSY<<4))
#define ADRCONQ_1B_ACK_CALCVAR (LONGADR[0] ^ LONGADR[1] ^ LONGADR[2] ^ LONGADR[3])
#define ADRCONQ_1B_ACK ((ADRCONQ_1B_ACK_CALCVAR ^ (ADRCONQ_1B_ACK_CALCVAR>>4)) & 0x0F)

enum state_et
{
	IDLE,
	BUSY,
	STARTING,
	RECEIVING,
	RECEIVINGACK,
	SENDING,
	SENDINGACK,
	ADRCONQUEST,
	SENDINGIOSTATE,
	SENDINGSTATUS,
	SENDINGIOSTATEEXT,
};

enum event_et
{
	EVENT_NO_EVENT = 0,
	EVENT_CHANGE_UP = 1,
	EVENT_CHANGE_DOWN = 2,
	EVENT_PRESSED = 3,
	EVENT_RELEASED = 4,
	EVENT_SERIES_CLICK = 5,
	EVENT_HOLD = 6
};

/* Global variables */

#ifdef SW_DEVICE
volatile W8 InputCheckCounter;
volatile bool inputCheckIndic;
#endif

volatile W8 shortAdr;
volatile bool attached;

volatile enum state_et devState;

volatile W8 commonBufferCounter;

volatile W8 inputBuffer[INPUTBUFFERSIZE];
volatile W8 inputSender;
volatile W8 inputBytesToReceive;
volatile W8 inputCheckSum;

volatile W8 outputBuffer[OUTPUTBUFFERSIZE];
volatile W8 outputBytesToSend;
volatile bool outputBufferReady;
volatile W8 outputCheckSum;
volatile W8 retriesCnt;

volatile W8 PCINTstoredPin;

#ifdef SW_DEVICE
volatile W8 eventBuffer[EVENTBUFFERSIZE];
volatile W8 noOfEventsStored;
volatile W8 frameInd;

volatile W8 monostable;
volatile W8 inverted;
volatile W8 pressCounter[8];
volatile W8 pressCounterMax;
volatile W8 waitCounter[8];
volatile W8 waitCounterMax;
volatile W8 storedState;
volatile W8 pressState;
volatile W8 seriesState;

#endif

#ifdef ADC_DEVICE
#define ADC_PIN_MASC (1<<ADC_NR)
volatile W16 adc;
volatile W16 adcCollector;
volatile W8  adcCounter;
volatile W8  adcReqFlag;
#endif

#ifdef HG_DEVICE

volatile W8 higroL[2],higroH[2], termL[2], termH[2];
volatile W8 actDevMasc;
volatile W8 wireBuffer[5];
volatile W8 wireByteCnt, wireBitCnt;
volatile W8 phase;

volatile W8 startTime[2];

#endif

#ifdef PWM_DEVICE
volatile W8 pwmStat[4];
volatile W8 pwmStatCnt;
#endif


volatile W8 enableIO;

int main(void)
{

	
	wdt_enable(WDTO_8S);
	devState = IDLE;
	attached = false;

	#ifdef SW_DEVICE
	frameInd = 0;
	inputCheckIndic = false;
	noOfEventsStored = 0;
	pressCounterMax = 75; /* about 1.5s */
	waitCounterMax = 150; /* about 3s */
	/* ustawienie portów IO */
	I_DIR &= ~I_MASC;
	I_PORT |= I_MASC;
	storedState = I_PIN;
	pressState = 0;
	seriesState = 0;
	#endif

	#ifdef TR_DEVICE
	O_DIR |= O_MASC;
	O_PORT &= ~O_MASC;
	#endif



	#ifdef ADC_DEVICE
	/* set and run ADC */
	ADMUX = 0x00 | ADC_NR; 
	DIDR0 = ADC_PIN_MASC;
	ADCSRA |= (1<<ADEN) | (1<<ADIE) | 0x07;	/* prescaler 128, freq = 156khz */	
	ADCSRA |= 1<<ADSC;

	adcCounter = 0;
	adcCollector = 0;
	adcReqFlag = 0xFF;
	adc = 1234;
	#endif

	#ifdef HG_DEVICE
	/* set IO pins */
	
	H_PORT &= ~(HIGRO_ONE_MASC | HIGRO_TWO_MASC);
	H_DDR &=  ~(HIGRO_ONE_MASC | HIGRO_TWO_MASC);


	

	/* set and run interrupt  for transfer*/

	/* set variables */
	actDevMasc = HIGRO_ONE_MASC;
	phase = 0;
	#endif

	clkDirIn();
	datDirIn();	
	CLK_OUT |= 1<<CLK_NR;
	DAT_OUT |= 1<<DAT_NR;
	outputBufferReady = false;
	#ifdef _AVR_IOTN25_H_
		USICR = 0xF8  ; /* USISIE = 1, USIOIE = 1, USIWM = 11, USICS = 10, USICLK = 0 */
		TCCR0A = 0x02; /* CTC Mode, prescaler = 8 */
		TCCR0B = 0x02;
		OCR0A = 124; /* when FCLK = 20Mhz, interrupt frequency = 10khz */
		TIMSK |= (1<<OCIE0A);
	
	
		/*enable PCINT  on CLK pin*/
		PCINTstoredPin = CLK_IN;
	
		GIMSK |= 1<<PCIE;
		PCMSK |= 1<<CLK_NR;	
	
		#ifdef HG_DEVICE
		PCMSK |= HIGRO_ONE_MASC | HIGRO_TWO_MASC;
		#endif

	
	#endif
	#if defined _AVR_ATtiny24A_H_ || defined _AVR_ATtiny44A_H_
      USICR = 0xF8  ; /* USISIE = 1, USIOIE = 1, USIWM = 11, USICS = 10, USICLK = 0 */
	  #ifdef PWM_DEVICE
	    TCCR1A = 0b00100010; /* WGM = 1010 (phase correct PWM) OC1B connected*/
		TCCR1B = 0b00010010; /* WGM = 1010(phase correct PWM), prescaler = 8 */
		ICR1 = 255; /* when FCLK = 20Mhz, interrupt frequency = 5khz */
		TIMSK1 |= (1<<TOIE1);
		
		TCCR0A = 0b10100001;   /* OC0A and OC0B connected, WGM = 001 (phase correct PWM) */
		TCCR0B = 0b00000010;   /* WGM = 001(phase correct PWM), prescaler = 8 */
		
		//OCR0A = 50; /*red  0-255*/
		//OCR0B = 50; /*blue 0-255*/
		//OCR1B = 0; /* green 0-127*/
		
		DDRA |= 0b10100000;
		DDRB |= 0b00000100;

		
	  #else
		TCCR0A = 0x02; /* CTC Mode, prescaler = 8 */
		TCCR0B = 0x02;
		OCR0A = 124; /* when FCLK = 20Mhz, interrupt frequency = 10khz */
		TIMSK0 |= (1<<OCIE0A);
	  #endif
	  
	  	PCINTstoredPin = CLK_IN;
	  	
	  	GIMSK |= 1<<PCIE0;
	  	PCMSK0 |= 1<<CLK_NR;
	#endif
	#ifdef _AVR_ATtiny261A_H_
	USICR = 0xF8  ; /* USISIE = 1, USIOIE = 1, USIWM = 11, USICS = 10, USICLK = 0 */
	TCCR0A = 0x02; /* CTC Mode, prescaler = 8 */
	TCCR0B = 0x02;
	OCR0A = 124; /* when FCLK = 20Mhz, interrupt frequency = 10khz */
	TIMSK |= (1<<OCIE0A);
	
	/*enable PCINT  on CLK pin*/
	PCINTstoredPin = CLK_IN;
			
	GIMSK |= 1<<PCIE0;
	PCMSK1 |= 1<<CLK_NR;
	#endif

	
	sei();

	

	
	
	while(1)
	{
		
		#ifdef SW_DEVICE
		if(inputCheckIndic == true)
		{
			enableIO &= I_MASC;
			W8 chCounter = 0;
			W8 counterMasc;
			W8 actState = I_PIN;
			for(counterMasc = 0x01;counterMasc!=00;counterMasc=counterMasc<<1)
			{
				if(counterMasc & enableIO)
				{					
					event_et currentEvent = EVENT_NO_EVENT;

					if(monostable & counterMasc)
					{
						if(counterMasc & (storedState ^ actState)) /* any change */
						{
							if((actState ^ inverted) & counterMasc)
							{
								pressState |= counterMasc;
								pressCounter[chCounter] = 0;
								if(waitCounter[chCounter] < waitCounterMax)
								{
									seriesState |= counterMasc;
									currentEvent = EVENT_SERIES_CLICK;
								}
								else
								{
									seriesState &= ~counterMasc;
									currentEvent = EVENT_PRESSED;
								}
							}
							else
							{
								if((seriesState & counterMasc)==0)
								{
									currentEvent = EVENT_RELEASED;									
								}
								pressState &= ~counterMasc;
								waitCounter[chCounter] = 0;
								
							}							
						}
						else if(pressState & counterMasc)
						{
							if(pressCounter[chCounter] < pressCounterMax)
							{
								pressCounter[chCounter]++;
							}
							else
							{
								pressCounter[chCounter] = 0;
								currentEvent = EVENT_HOLD;
							}
						}
					}
					else /*bistable */
					{
						if(counterMasc & (storedState ^ actState)) /* any change */
						{
							if((actState ^ inverted) & counterMasc)
							{
								currentEvent = EVENT_CHANGE_UP;
							}
							else
							{
								currentEvent = EVENT_CHANGE_DOWN;
							}
						}						
					}
					if(waitCounter[chCounter] < waitCounterMax)
					{
						waitCounter[chCounter]++;					
					}

					if(currentEvent != EVENT_NO_EVENT)
					{
						if(noOfEventsStored < EVENTBUFFERSIZE)
						{
							eventBuffer[noOfEventsStored] = chCounter<<4 | currentEvent;
							noOfEventsStored++;
						}
					}
				}
				chCounter++;
			}
			inputCheckIndic = false;
			storedState = actState;
		} /* inputCheckIndic == true */
			
		#endif
			

		#ifdef SW_DEVICE
		if((outputBufferReady == false)
		AND
		(attached == true)
		AND
		(noOfEventsStored>0))
		{
			//previous frame has been succesfully sent, create new. 
			W8 counter = 0;
			W8 checkSum = shortAdr;
			outputBuffer[counter++] = shortAdr;
			W8 code = (FRAME_DATA_SW<<4) | (noOfEventsStored+4);
			outputBuffer[counter++] = code;
			checkSum ^=code;
			outputBuffer[counter++] = (frameInd | 0x80);
			checkSum ^= (frameInd | 0x80);
			if(++frameInd >=16) {frameInd = 0;}
			for(W8 i=0;i<noOfEventsStored;i++)
			{
				W8 event = eventBuffer[i];
				outputBuffer[counter++] = event;
				checkSum ^= event;
			}
			outputBuffer[counter] = checkSum;
			retriesCnt = NOOFRETRIES;
			noOfEventsStored = 0;
			outputBufferReady = true;				
		}
		#endif

		#ifdef HG_DEVICE
		if(phase >= 6) /*transfer completed */
		{
			
			/* check CS */
			if((W8)(wireBuffer[0]+ wireBuffer[1] + wireBuffer[2] + wireBuffer[3]) == wireBuffer[4])
			{
		    	if((outputBufferReady == false)
		    	AND
		    	(attached == true))
				{

					
					W8 counter = 0;
					W8 checkSum = shortAdr;
					outputBuffer[counter++] = shortAdr;
					W8 code = (FRAME_DATA<<4) | (5+4);
					outputBuffer[counter++] = code;
					checkSum ^=code;
					outputBuffer[counter++] = 0; /* B2 - data code, always 0 */
					
					W8 devNo =  (actDevMasc == HIGRO_TWO_MASC) ? 1 : 0;	
					if(phase > 6) { devNo = phase;}
					checkSum ^=devNo;					
					outputBuffer[counter++] =devNo;				
					
					checkSum ^=wireBuffer[0];
					outputBuffer[counter++] = wireBuffer[0];									
					checkSum ^=wireBuffer[1];
					outputBuffer[counter++] = wireBuffer[1];
		
					checkSum ^=wireBuffer[2];
					outputBuffer[counter++] = wireBuffer[2];										
					checkSum ^=wireBuffer[3];
					outputBuffer[counter++] = wireBuffer[3];					
					outputBuffer[counter] = checkSum;
					retriesCnt = NOOFRETRIES;
					outputBufferReady = true;
					
					phase =0;
				}
			}
			else
			{
				phase =0;		
			}
			
		}
		if(phase == 1)
		{		
			
			wireBitCnt = 0x80;
			wireByteCnt = 0;
			for(W8 i=0;i<5;i++) { wireBuffer[i] = 0; }
			/* init timer interrupt - start over 18ms */
			/* prescaler 1/1024, compare value = 140 */
			TCCR1 = 0b00001011;		
			OCR1A = (actDevMasc == HIGRO_ONE_MASC) ? startTime[0] : startTime[1];
			TCNT1 = 0;
			TIMSK |= (1<<OCIE1A);
			H_PORT &= ~actDevMasc;
			H_DDR |= actDevMasc;			
			
			phase = 2;
			
			
			
		}
		#endif
		
		#ifdef ADC_DEVICE
	  	if((adcReqFlag != 0xFF)
		AND
		(outputBufferReady == false)
	  	AND
	  	(attached == true))
	  	{
			W8 counter = 0;
			W8 checkSum = shortAdr;
			outputBuffer[counter++] = shortAdr;
			W8 byteTmp = (FRAME_DATA<<4) | (5+2);
			outputBuffer[counter++] = byteTmp;
			checkSum ^=byteTmp;
			outputBuffer[counter++] = 0; /* B2 - data code, always 0 */

			checkSum ^=adcReqFlag;
			outputBuffer[counter++]  = adcReqFlag;
			
			byteTmp = (adc>>8) & 0x00FF;
			checkSum ^=byteTmp;
			outputBuffer[counter++] = byteTmp;
			byteTmp = adc & 0x00FF;
			checkSum ^=byteTmp;
			outputBuffer[counter++] = byteTmp;
			
			outputBuffer[counter] = checkSum;
			retriesCnt = NOOFRETRIES;
			outputBufferReady = true;	
			adcReqFlag = 0xFF;		  			  
		}
		
		
		#endif

	} /* main loop */
} /*main */

#ifdef ADC_DEVICE

  ISR(ADC_vect)
  {
	  
	adcCollector += ADC;
	 
	adcCounter++;  
    if(adcCounter >= 64)	  
	{
	  adc = adcCollector;
	  adcCollector = 0;
	  adcCounter = 0;		
	}
	ADCSRA |= 1<<ADSC;	
  }

#endif
    #ifdef _AVR_IOTN25_H_
    ISR(PCINT0_vect)
	#endif
	#ifdef _AVR_ATtiny24A_H_
	ISR(PCINT0_vect)
	#endif
	#ifdef _AVR_ATtiny44A_H_
    ISR(PCINT0_vect)
	#endif
	#ifdef _AVR_ATtiny261A_H_
	ISR(PCINT_vect)
	#endif
	{
		W8 changedPins = PCINTstoredPin ^ CLK_IN;
		if(changedPins & (1<<CLK_NR))
		{

			if((USISR & (1<<USIDC))&&((CLK_IN & (1<<CLK_NR)) != 0))
			{
				//_delay_us(20);
				switch(devState)
				{
					case SENDING:
					devState = RECEIVING;					
					datDirIn();
					break;
					case ADRCONQUEST:
					devState = IDLE;
					datDirIn();
					default:
					break;
					
				}
			}

		}
		
		#ifdef HG_DEVICE
		if(changedPins & actDevMasc)
		{
			//DDRB |= (1<<3);
			//PORTB ^= (1<<3);
			if((H_PIN & actDevMasc) == 0)
			{
				
				
				
				switch(phase)
				{
					case 0:
					case 1:
					case 2:
					
					break;
					case 3:
					case 4:
					
					
					phase++;
					break;
					case 5:
					
					if(TCNT1 >50) { wireBuffer[wireByteCnt] |= wireBitCnt; }
					
					if(wireBitCnt == 0x01)
					{
						
						if(wireByteCnt ==4)
						{
							TCCR1 = 0;
							TIMSK &= ~(1<<OCIE1A);
							TIFR |= OCF1A;
							phase = 6;
							
							
						}
						else
						{
							wireByteCnt++;
							wireBitCnt = 0x80;
						}
					}
					else
					{
						wireBitCnt = wireBitCnt>>1;
					}
					
					break;
					default:
					
					TIMSK &= ~(1<<OCIE1A);
					TIFR |= 1<<OCF1A;
					TCCR1 = 0;
					phase = 9;
					break;
					
				}
				
				
			}
			
			TCNT1 = 0;
		}
		#endif
		
		GIFR |= PCIF_CUSTOM;
		PCINTstoredPin = CLK_IN;
	}


	#ifdef _AVR_IOTN25_H_
	ISR(TIMER0_COMPA_vect)
	#endif
    #if defined _AVR_ATtiny24A_H_ || defined _AVR_ATtiny44A_H_
	  #ifdef PWM_DEVICE
	    ISR(TIM1_OVF_vect)
	  #else
	    ISR(TIM0_COMPA_vect)
	  #endif
	#endif
	#ifdef _AVR_ATtiny261A_H_
	ISR(TIMER0_COMPA_vect)
	#endif
	{
		#ifdef SW_DEVICE
		if(InputCheckCounter <INPUTCHECKCOUNTERMAX)
		{
			InputCheckCounter++;
		}
		else
		{
			InputCheckCounter = 0;
			inputCheckIndic = true;		
		}
		#endif
		
		//			DDRA |= (1<<2);
		//			PORTA ^= (1<<2);
		/* collision detected */
		/*
		if((USISR & (1<<USIDC))&&((CLK_IN & (1<<CLK_NR)) == 0)) 
		{
            switch(devState)
			{
			  case SENDING:
			  	devState = RECEIVING;
			  	datDirIn();
			  	break;
			  case ADRCONQUEST:
			   	devState = IDLE;
			   	datDirIn();
	          default:
					   break;		  
				
			}
		}
		*/
	} /*interrupt(counter 10khz) */

	ISR(USI_OVF_vect)
	{
						
		W8 tmpVal;
		#ifdef TR_DEVICE
		W8 masc;
		#endif
		/*One byte has been transmitted, check all, and allow to transmit next byte. */
				
		switch(devState)
		{		
			case STARTING:
			//clear watchdog counter
			wdt_reset();
						
			commonBufferCounter = 0;
			if(outputBufferReady == true)
			{
				if(retriesCnt == 0)
				{
					devState = RECEIVING;								
					inputBytesToReceive = INPUTBUFFERSIZE;
					inputCheckSum = 0;
					datDirIn();								
					outputBufferReady = false; // abort this frame								
				}	
				else
				{
					retriesCnt--;
					devState = SENDING;
					USIDR =  outputBuffer[commonBufferCounter++];
					outputBytesToSend = outputBuffer[commonBufferCounter] &0x0F;
					datDirOut();
								
				}	
			}
			else
			{
				devState = RECEIVING;
				inputBytesToReceive = INPUTBUFFERSIZE;
				inputCheckSum = 0;
				datDirIn();
			}
			break;
										
			case RECEIVING:
			{	
																												
				W8 dataIn = USIDR;
				inputBuffer[commonBufferCounter] = dataIn;
				commonBufferCounter++;
				inputCheckSum ^= dataIn;

				if(commonBufferCounter == 2)
				{
					inputBytesToReceive = dataIn&0x0F;															
				}    
				if(commonBufferCounter == inputBytesToReceive)
				{								
					if(inputCheckSum == 0x00)
					{
						W8 code = inputBuffer[1] >> 4;
						if(code == FRAME_ADRCONQUEST)
						{										
							if(attached == false)
							{
								commonBufferCounter = 0;
								datDirOut();	
								USIDR = LONGADR[commonBufferCounter++];																					
								devState = ADRCONQUEST;																																											
							}
							else
							{
								devState = IDLE;
							}
							USISR = 0x80; /* clear USICNT counter and another status bits, also clock holding*/
							break;
						}
						else if(code == FRAME_DEVCONFIG)
						{	
										
							//FRAME_DEVCONFIG   | 0  | C/13 | A0..A3 | Sadr|Conf0|Conf1|Conf2|Conf3|Conf4|CS| [ACK/CS]
							W8 i = 2;										
							if((inputBuffer[i++] == LONGADR[0]) &&
								(inputBuffer[i++] == LONGADR[1]) &&
								(inputBuffer[i++] == LONGADR[2]) &&
								(inputBuffer[i++] == LONGADR[3]))
							{		
								shortAdr = inputBuffer[i++];
								attached = true;
								enableIO = inputBuffer[i++];
								#ifdef SW_DEVICE
								monostable = inputBuffer[i++];
								inverted = inputBuffer[i++];
								pressCounterMax = inputBuffer[i++];
								waitCounterMax = inputBuffer[i];
								#endif
								#ifdef HIGRO_DEVICE
								startTime[0] = inputBuffer[i++];
								startTime[1] = inputBuffer[i];
								#endif
								USIDR = DEFAULT_1B_ACK;
								devState = RECEIVINGACK;
								datDirOut();	
								break;
							}	
							else
							{
								devState = IDLE;
							}	
						}
						else if(code == FRAME_CHECKDEVICE)
						{
							W8 i = 2;
							if((inputBuffer[i++] == LONGADR[0]) &&
							(inputBuffer[i++] == LONGADR[1]) &&
							(inputBuffer[i++] == LONGADR[2]) &&
							(inputBuffer[i++] == LONGADR[3]))
							{
								USIDR = DEFAULT_1B_ACK;
								devState = RECEIVINGACK;
								datDirOut();
							}
							else
							{
								devState = IDLE;
							}
						}
						else if(code == FRAME_DETACH_ALL)
						{
							attached = false;
							USIDR = DEFAULT_1B_ACK;
							devState = RECEIVINGACK;
							datDirOut();
						}
						else if(inputBuffer[2] == shortAdr)
						{
										
							/* Frame correct, send ACK */
							devState = RECEIVINGACK;
							switch(code)
							{
								case FRAME_READ_IO:
								#ifdef SW_DEVICE
								tmpVal = I_PIN;
								#endif
								#ifdef TR_DEVICE
								tmpVal = O_PIN;
								#endif
								/* if ACK_NORMAL == 0 */
								outputCheckSum = tmpVal;
								USIDR = tmpVal;
								devState = SENDINGIOSTATE;
								break;
								#ifdef PWM_DEVICE
								case FRAME_READ_IO_EXT:
								
								pwmStat[0] = OCR0A; 
								pwmStat[1] = OCR0B;
								pwmStat[2] = OCR1B;
								pwmStat[3] = O_PIN;
								outputCheckSum = pwmStat[0] ^ pwmStat[1] ^ pwmStat[2] ^ pwmStat[3]; 
								pwmStatCnt = 1;
								USIDR = pwmStat[0];
								devState = SENDINGIOSTATEEXT;
								break;
								#endif
								case FRAME_READ_STATUS:
								if(inputBuffer[3] == 0)
								{
									tmpVal = 0;
									outputCheckSum = tmpVal;
									USIDR = tmpVal;
									devState = SENDINGSTATUS;
									commonBufferCounter = 0;
								}
								else
								{
									USIDR = INVARG_1B_ACK;
								}
								break;

								#ifdef TR_DEVICE
								case FRAME_DATA_TR:
								//PORTB ^= (1<<3);
								masc = 1<<inputBuffer[3];
								if(masc & O_MASC)
								{
									if(inputBuffer[4] > 0 )
									{
										O_PORT |= masc;
										#ifdef SPEC1_DEVICE 
										O_DIR |= masc;
										#endif
									}
									else
									{
										O_PORT &= ~masc;
										#ifdef SPEC1_DEVICE
										O_DIR &= ~masc;
										#endif
									}
								}
								#ifdef PWM_DEVICE

							    switch(inputBuffer[3] )
								{
								  case 0xB: 
								  OCR0A = inputBuffer[4];
								  break;
								  case 0xC:
								  OCR0B = inputBuffer[4];
								  break;
								  case 0xD:
								  OCR1B = (inputBuffer[4]);
								  default:
								  break;
								  									
								}
							
								#endif
								
								USIDR = DEFAULT_1B_ACK;
								break;
								#endif
								
								case FRAME_REQUEST:
								{
									#ifdef USE_FRAME_REQUEST
										W8 reqPort = inputBuffer[4];
										
										if(reqPort < maxPort )
										{
											if((enableIO & (1<<reqPort)) == 0)
											{
												USIDR = DISABLED_1B_ACK;												
											}
											#ifdef ADC_DEVICE
											else if(portType[reqPort] == 0x00)  //ADC port
											{
												adcReqFlag = reqPort;

												USIDR = DEFAULT_1B_ACK;
											}
											#endif
											#ifdef HG_DEVICE
											else  if(portType[reqPort] == 0x10)  //DHTxx Port
											{
												if(phase == 0)
												{

													actDevMasc = higroMasc[reqPort];
													phase = 1;
													USIDR = DEFAULT_1B_ACK;
												}
												else
												{
													USIDR = BUSY_1B_ACK;													
												}
												
											}
											#endif
											else
											{
												USIDR = UNKNOWN_1B_ACK;												
											}
											
										}
										else
										{
											USIDR = UNKNOWN_1B_ACK;											
										}
									
									
									#else
										USIDR = UNKNOWN_1B_ACK;
									#endif
								
								
									/*
									#ifdef HG_DEVICE
								
									if((inputBuffer[3] == 0) && (phase == 0))
									{															
										if((inputBuffer[4]==0)&&(enableIO & 0x01))
										{
											actDevMasc = HIGRO_ONE_MASC;
											phase = 1;									
										} 
										else if((inputBuffer[4]==1) && (enableIO & 0x02))
										{
											actDevMasc = HIGRO_TWO_MASC;
											phase = 1;
										}									
			
									}
									USIDR = DEFAULT_1B_ACK;								
								
									#endif
									*/
									/*
									#ifdef ADC_DEVICE
								
									if(inputBuffer[3] == 0)
									{
										if((inputBuffer[4]==2)&&(enableIO & 0x04))
										{
											adcReqFlag = 1;
										}
									}
									USIDR = DEFAULT_1B_ACK;	
									#endif
									*/
									break;
								}
								
								default:
								USIDR = UNKNOWN_1B_ACK;
								break;
							}
							datDirOut();
						}
						else
						{
							devState = IDLE;
						}
					}
					else
					{
						devState = IDLE;
					}

				}
				else if(commonBufferCounter > inputBytesToReceive) /* error */
				{
					devState = IDLE;
				}
				USISR = 0x00; /* clear USICNT counter and another status bits, also clock holding*/
			    break;
			}
			case RECEIVINGACK:
			{
				devState = IDLE;
				datDirIn();
				USISR = 0x00; /* clear USICNT counter and another status bits, also clock holding*/
				break;
			}
			case SENDING:
			{
				if(commonBufferCounter < outputBytesToSend)
				{
					USIDR = outputBuffer[commonBufferCounter];
					commonBufferCounter++;
				}
				else
				{
					devState = SENDINGACK;
					datDirIn();
				}
				USISR = 0x00; /* clear USICNT counter and another status bits, also clock holding*/
				break;
			}
			case SENDINGACK:
			{
				if(USIDR == 0)
				{
					outputBufferReady = false;
				}
				USISR = 0x00; /* clear USICNT counter and another status bits, also clock holding*/
				break;
			}
			case ADRCONQUEST:
			{
							
				if(commonBufferCounter<4)
				{
					USIDR = LONGADR[commonBufferCounter++];
					datDirOut();
				}
				else
				{
					USIDR =  ADRCONQ_1B_ACK ;
					devState = RECEIVINGACK;
				}
							
				USISR = 0x00; /* clear USICNT counter and another status bits, also clock holding*/
				break;
			}
			case SENDINGIOSTATE:
			case SENDINGSTATUS:
			{
				tmpVal = outputCheckSum;
				USIDR =  (tmpVal ^ ( tmpVal>>4)) & 0x0F;
				USISR = 0x00; /* clear USICNT counter and another status bits, also clock holding*/
				devState = RECEIVINGACK;
				break;
			}
			#ifdef PWM_DEVICE
			case SENDINGIOSTATEEXT:
			
			{
				if(pwmStatCnt<4)
				{
					USIDR = pwmStat[pwmStatCnt++];
				}
				else
				{
			    	tmpVal = outputCheckSum;
			    	USIDR =  (tmpVal ^ ( tmpVal>>4)) & 0x0F;
					devState = RECEIVINGACK;
				}
								
				USISR = 0x00; /* clear USICNT counter and another status bits, also clock holding*/
				break;
			}
			#endif
			default:
			{
				devState = IDLE;
				USISR = 0x00; /* clear USICNT counter and another status bits, also clock holding*/
				break;
			}
		}
		USISR = 0x40;
	} /* interrupt(counter_USI_overflow) */

					
	#ifdef _AVR_IOTN25_H_
	ISR(USI_START_vect)
	#endif
    #if defined _AVR_ATtiny24A_H_ || defined _AVR_ATtiny44A_H_
	ISR(USI_STR_vect)
	#endif
	#ifdef _AVR_ATtiny261A_H_
	ISR(USI_START_vect)
	#endif
	{
		/* interrupt occured, clock is hold, when block is ready it should be cleared to start transmision */
		devState = STARTING;
		USISR = 0x8F;
						
	} /* interrupt(USI_start) */

  #ifdef HG_DEVICE
	#ifdef _AVR_IOTN25_H_
	ISR(TIMER1_COMPA_vect)
	#endif
	#if defined _AVR_ATtiny24A_H_ || defined _AVR_ATtiny44A_H_
    ISR(TIM1_COMPA_vect)
	#endif
	#ifdef _AVR_ATtiny261A_H_
	ISR(TIMER1_COMPA_vect)
	#endif
	{
		
		
		H_PORT &= ~actDevMasc;
		H_DDR &= ~actDevMasc;
		if(phase ==2)
		{
            phase = 3;

			TCNT1 = 0;
			OCR1A = 250;		
			TCCR1 = 0b00000100;
			GTCCR |= (1<<PSR1);
				
			TIMSK |= (1<<OCIE1A);
			

		}
		else
		{

			TIMSK &= ~(1<<OCIE1A);
            TIFR |= 1<<OCF1A;
			GIFR |= 1<<PCIF;
            TCCR1 = 0;
			phase += 10;
		
		}
		
	}
  #endif
  
	





#endif /* COMMON_H_ */