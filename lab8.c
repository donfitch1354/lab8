/*
 * lab7.c
 *
 *  Created on: Dec 10, 2013
 *      Author: C14Ethan.Snyder
 */
	#include <msp430.h>




void initClocksPins()
		{



		P1DIR|= BIT1; // TA0.0
	    P1DIR|= BIT2; // TA0.1
	    P2DIR|= BIT0; // TA1.0
	    P2DIR|= BIT1; // TA1.1


	    P1SEL |= BIT1;
	    P1SEL |= BIT2;
	    P2SEL |= BIT0;
	    P2SEL |= BIT1;

	    // set up timers
	    TA0CTL &= ~ MC1|MC0; // stop timer

	    TA0CTL |= TACLR; // clear timer

	    TA1CTL &= ~ MC1|MC0; // stop timer

	    TA1CTL |= TACLR; // clear timer

	    TA1CTL |= TASSEL1;
	    // configure SMCLK

	    TA0CTL |= TASSEL1;


		__delay_cycles(1000000);

	    TA0CCR0 = 100; //sets signal period to 100 clock cycles
	    TA0CCR1 = 40; // sets duty cycle

	    TA1CCR0 = 100; //sets signal period to 100 clock cycles
	    TA1CCR1 = 50; // sets duty cycle

	    TA0CTL |= MC0; // starts counting up
	    TA1CTL |= MC0;
}


void resetAll()
	{
		TA0CCTL0 &= ~OUTMOD_7;

		TA0CCTL1 &= ~OUTMOD_7;

		TA1CCTL0 &= ~OUTMOD_7;

		TA1CCTL1 &= ~OUTMOD_7;

	}
void turnRight()
	{
		resetAll();

		TA0CCTL1 |= OUTMOD_5;

		TA0CCTL0 |= OUTMOD_7;

		TA1CCTL1 |= OUTMOD_7;

		__delay_cycles(500000);

		resetAll();

		__delay_cycles(1000000);
	}

void turnLeft()
	{
		resetAll();

		TA1CCTL1 |= OUTMOD_5;

		TA1CCTL0 |= OUTMOD_7;

		TA0CCTL1 |= OUTMOD_7;

		__delay_cycles(500000);

		resetAll();

		__delay_cycles(1000000);
	}

void turnRightWide()
	{
		resetAll();

		TA0CCTL1 |= OUTMOD_5;

		TA0CCTL0 |= OUTMOD_7;

		TA1CCTL1 |= OUTMOD_7;
		__delay_cycles(12000);

		resetAll();

		__delay_cycles(10000);
	}

void turnLeftWide()
	{
		resetAll();

		TA1CCTL1 |= OUTMOD_5;

		TA1CCTL0 |= OUTMOD_7;

		TA0CCTL1 |= OUTMOD_7;

		__delay_cycles(80000);

		resetAll();

		__delay_cycles(10000);
	}

void moveForward()
	{
		resetAll();

		TA1CCR1 = 40;
		TA0CCR1 = 55; // sets duty cycle

		TA1CCTL1 |= OUTMOD_7;

		TA0CCTL1 |= OUTMOD_7;

		__delay_cycles(10000);

		resetAll();


	}

void moveBackwards()
	{

		resetAll();

		TA1CCR0 = 10;
		TA0CCR0 = 10; // sets duty cycle

		TA1CCTL1 |= OUTMOD_5;

		TA1CCTL0 |= OUTMOD_7;

		TA0CCTL1 |= OUTMOD_5;

		TA0CCTL0 |= OUTMOD_7;

		__delay_cycles(1);

		resetAll();
	}
