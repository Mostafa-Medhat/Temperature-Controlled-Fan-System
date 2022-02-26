/*
 ======================================================================================
 Name        : miniproject3_main.c
 Author      : Mostafa Medhat
 Description : design a temperature-controlled fan using ATmega16 microcontroller,LM35 & DC Motor
 ======================================================================================
 */

#include "lcd.h"
#include "dc_motor.h"
#include "lm35_sensor.h"
#include "adc.h"
#include <avr/io.h>

int main(void)
{
	uint8 temperature = 0;
	DcMotor_State motor_state=STOP;	 //variable of type DcMotor_State to indicate motor state: STOP/CW/A_CW
	uint8 motor_speed=0;	 //variable to indicate motor speed
	char* fan_state="OFF"; 	 //A string to be printed on the LCD indicating for fan state : ON/OFF
	SREG |= (1<<7);			 //Enable I-bit

	/*	ADC Configuration: e internal reference voltage 2.56 voltage and
	 * 	prescaler F_CPU/8 (125kHz).
	 */
	ADC_ConfigType Adc_Config = {INTERNAL_REFERENCE_VOLTAGE,F_CPU_8};

	LCD_init(); 						//Initializing LCD
	ADC_init(&Adc_Config);				//Initializing ADC
	DcMotor_Init();						//Initializing DcMotor
	LCD_moveCursor(0, 3);				//Move to first row and column #3
	LCD_displayString("FAN is  ");		//Print "Fan is" on LCD
	LCD_moveCursor(1, 3);				//Move to second row and column #3
	LCD_displayString("Temp =    C");	//Print "Temp =   C" on LCD
	while(1)
	{
		LCD_moveCursor(1, 10);				//move cursor after "Fan is" to print its state ON/OFF
		temperature=LM35_getTemperature();	//get temperature from LM35 Sensor
		LCD_intgerToString(temperature);	//print temperature value on LCD
		if(temperature<100)
		{
			LCD_displayCharacter(' ');
		}
				if(temperature < 30)
				{
					/*if temperature is less than 30 :
					 * change  state of fan to OFF
					 * speed of  fan = 0
					 */
					motor_speed=0;
					motor_state=STOP;
					fan_state="OFF";

				}else{
					/*if temperature is less than 30 :
					 * change state of fan to ON and control direction to clockwise
					 * speed of fan depends on temperature
					 */
					fan_state = "ON";
					motor_state=CW;

					if (temperature < 60) {
						motor_speed=25;
					}
					else if(temperature<90) {
						motor_speed=50;
					}
					else if(temperature<120) {
						motor_speed=75;
					}
					else if(temperature<=150) {
						motor_speed=100;
					}
				}

				/*motor state (direction) and motor speed*/
				DcMotor_Rotate(motor_state,motor_speed);

				/*print fan working: OFF/ON */
				LCD_moveCursor(0, 10);

				/*	if fan is OFF, print it on LCD
				 *  if it's ON, print it on LCD and erase last character by adding space
				 */
				if(fan_state == "OFF")
				{
					LCD_displayString(fan_state);
				}
				else
				{
					LCD_displayString(fan_state);
					LCD_displayCharacter(' ');
				}
		}
}
