/*
 ================================================================================================
 Name        : fan_controller.c
 Author      : Mohamed Aboelezz
 Description : Read the temperature from the sensor with this value control the FAN speed
 	 	 	   ,and display in LCD the FAN statues and temperature
 Date        : 4/10/2022
 ================================================================================================
 */

#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "dc_motor.h"

int main(void)
{
	uint8 temp;
	/* Create configuration structure for ADC driver */
	ADC_ConfigType Adc_Config = {Internal,F_CPU_8};

	LCD_init(); 			/* initialize LCD driver */
	DcMotor_Init();			/* initialize DC MOTOR driver */
	ADC_init(&Adc_Config);  /* initialize ADC driver */

	/* Display this string "FAN is " only once on LCD at the First row col 4 */
	LCD_displayStringRowColumn(0,4,"FAN is ");
	/* Display this string "Temp =   C" only once on LCD at the Second row col 4 */
	LCD_displayStringRowColumn(1,4,"Temp =    C");

	while(1)
	{
		temp = LM35_getTemperature();

		/* Display the temperature value every time at same position */
		LCD_moveCursor(1,11);
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		/* Display the Motor Statues every time at same position */
		LCD_moveCursor(0,11);
		if(temp >= 120)
		{
			LCD_displayString("ON");
			/* In case the statues value is ON print space in the next digit place */
			LCD_displayCharacter(' ');
			/* move the motor in CW direction with 100% of its speed */
			DcMotor_Rotate(CW,100);
		}
		else if(temp >= 90)
		{
			LCD_displayString("ON");
			/* In case the statues value is ON print space in the next digit place */
			LCD_displayCharacter(' ');
			/* move the motor in CW direction with 75% of its speed */
			DcMotor_Rotate(CW,75);
		}
		else if(temp >= 60)
		{
			LCD_displayString("ON");
			/* In case the statues value is ON print space in the next digit place */
			LCD_displayCharacter(' ');
			/* move the motor in CW direction with 50% of its speed */
			DcMotor_Rotate(CW,50);
		}
		else if(temp >= 30)
		{
			LCD_displayString("ON");
			/* In case the statues value is ON print space in the next digit place */
			LCD_displayCharacter(' ');
			/* move the motor in CW direction with 25% of its speed */
			DcMotor_Rotate(CW,25);
		}
		else
		{
			LCD_displayString("OFF");
			/* stop the motor */
			DcMotor_Rotate(stop,0);
		}
	}
}

