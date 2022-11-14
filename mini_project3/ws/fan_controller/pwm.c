/******************************************************************************
 *
 * Module: PWM TIMER0
 *
 * File Name: pwm.h
 *
 * Description: header file for the PWM driver
 *
 * Author: Mohamed Aboelezz
 *
 *******************************************************************************/

#include "pwm.h"
#include "avr/io.h"
#include "gpio.h"

/*
 * Description :
 * The function responsible for trigger the Timer0 with the PWM Mode.
 * Setup the PWM mode with Non-Inverting.
 * Setup the prescaler with F_CPU/8.
 * Setup the compare value based on the required input duty cycle
 * Setup the direction for OC0 as output pin through the GPIO driver.
 * The generated PWM signal frequency will be 500Hz to control the DC
 * Motor speed.
 */
void PWM_Timer0_Start(uint8 duty_cycle)
{
	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS01);
	/* Set Timer Initial value */
	TCNT0=0;
	/* Set Compare Value equal the required present of the speed */
	OCR0=((float)duty_cycle/100)*255;
	/* set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC. */
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);
}
