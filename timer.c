/*****************************************************
This program was produced by the
CodeWizardAVR V1.25.7 beta 5 Professional
Automatic Program Generator
© Copyright 1998-2007 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 04.06.2010
Author  : F4CG                            
Company : F4CG                            
Comments: 


Chip type           : ATtiny2313V
Clock frequency     : 8,000000 MHz
Memory model        : Tiny
External SRAM size  : 0
Data Stack size     : 32
*****************************************************/

#include <tiny2313.h>
#include "delay.h"
             

unsigned char hh=0,hl=0,mh=0,ml=0,butt=0,data;
                                 
unsigned char array[]={
  0xe7,
  0x44,
  0xad,
  0xcd,
  0x4e,
  0xcb,
  0xeb,
  0x45,
  0xef,
  0xcf,  
  0x00
};
unsigned time=0;



// Timer 1 overflow interrupt service routine
interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
// Reinitialize Timer 1 value
TCNT1H=0x9e;
TCNT1L=0x6c;
// Place your code here
 
      time++;
       if(time==19200){
       

       
         time=0;
         ml++;
         if(ml==10){
           ml=0;
           mh++;
           if(mh==6){
            mh=0; 
            hl++;
            if(hl==10){
              hl=0;
              hh++;
            }
            if((hh==2)&(hl==4)){
              hh=0;
              hl=0;             
            }
           }
         }
       }

        
       

}

// Declare your global variables here


void main(void)
{
// Declare your local variables here
unsigned n=0, m=0, p=0;

// Crystal Oscillator division factor: 1
#pragma optsize-
CLKPR=0x80;
CLKPR=0x00;
#ifdef _OPTIMIZE_SIZE_
#pragma optsize+
#endif

// Input/Output Ports initialization
// Port A initialization
// Func2=In Func1=In Func0=In 
// State2=T State1=T State0=T 
PORTA=0x00;
DDRA=0x00;

// Port B initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTB=0x00;
DDRB=0xFF;

// Port D initialization
// Func6=Out Func5=Out Func4=Out Func3=Out Func2=In Func1=In Func0=In 
// State6=0 State5=0 State4=0 State3=0 State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0x78;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=FFh
// OC0A output: Disconnected
// OC0B output: Disconnected
TCCR0A=0x00;
TCCR0B=0x00;
TCNT0=0x00;
OCR0A=0x00;
OCR0B=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 1000,000 kHz
// Mode: Normal top=FFFFh
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer 1 Overflow Interrupt: On
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x01;
TCNT1H=0x9e;
TCNT1L=0x6c;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// Interrupt on any change on pins PCINT0-7: Off
GIMSK=0x00;
MCUCR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x80;

// Universal Serial Interface initialization
// Mode: Disabled
// Clock source: Register & Counter=no clk.
// USI Counter Overflow Interrupt: Off
USICR=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;

// Global enable interrupts
#asm("sei")

while (1)
      {
      // Place your code here   
          
     if(hh!=0){
     PORTB=array[hh];
       } else{
       PORTB=array[10];
       }
       PORTD=0x3f; 
  
       delay_ms (3);
       PORTD=0;
       PORTB=array[hl]|0x10;
       PORTD=0xdf; 
       
       delay_ms (3);
       PORTD=0;
       PORTB=array[mh];
   
       PORTD=0xf7;
        
       delay_ms (3);
       PORTD=0;
       PORTB=array[ml];
       PORTD=0xef; 
        
       delay_ms (3);
       PORTD=0; 
       
       PORTB=0XFF;
       PORTD=0x78;
   
       
             
            
   

     
       
data=PIND&0x02;
  if (data==0) {
    delay_ms(5);
    data=PIND&0x02;
    if (data==0) {
        butt=1;
        //n=n+1;
        m=m+1;
         if (m==10){
             p=10;
          if (m==20){
             p=5;
        if (n==p){ 
            time=0;
            //n=0;
            p=0;
            m=0;
            ml=ml+1;  

              if (ml==10){
                  ml=0;
                  mh=mh+1; 
                if (mh==6){
                    mh=0;
                    hl=hl+1;
                    
                    if (hl==10){
                        hl=0;
                        hh=hh+1;
                    };    
              
              
                };
               };
               };      
            };    
       };    
       if ((hh==2)&(hl==4)){
            hh=0;
            hl=0;
       };
      
       
   }; 
 };
};
 


  if (data!=0) {
      if (butt==1) {
          delay_ms(5);
          data=PIND&0x02; 
          if (data!=0) {
              butt=0;
              m=0; 
          };  
      };
  };
 };