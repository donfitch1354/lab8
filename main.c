#include <msp430g2553.h>
#include "lab8.h"
int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  initClocksPins();


  while(1){

	  moveForward();

















	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled


  ADC10CTL0 &= ~ENC;

  ADC10CTL1 |= ADC10DIV0|ADC10DIV1|ADC10DIV2; // divide clock by 8

  ADC10CTL1 = INCH_4;                       // input A4

  ADC10AE0 |= BIT4;                         // PA.1 ADC option select

  ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK





  P1DIR |= 0x01;                            // Set P1.0 to output direction


    ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
    __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
    if (ADC10MEM < 0x2FF)
    {
      P1OUT &= ~0x01;

    } // Clear P1.0 LED off
    else
    {

      P1OUT |= 0x01;
      turnRightWide();// Set P1.0 LED on
    }


    // start sensor 2 code
    ADC10CTL0 &= ~ENC;



    ADC10CTL1 = INCH_5;                       // input A4

      ADC10AE0 |= BIT5;                         // PA.1 ADC option select

      P1DIR |= 0x40;

      ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
          __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
          if (ADC10MEM < 0x29F)
          {
            P1OUT &= ~0x40;


          } // Clear P1.0 LED off
          else
          {
        	  turnRightWide();
            P1OUT |= 0x40;                        // Set P1.0 LED on
          }







}
    return 0;
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}
