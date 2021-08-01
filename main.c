/**
 * @file main.c
 * @author 260213 (you@domain.com)
 * @brief Activity_1
 * @version 0.1
 * @date 2021-04-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "ledstat.h"
#include "ReadADC.h"
#include "OutPWM.h"
#include"UART.h"
#include<avr/io.h>


/**
 * @brief Initialize all the peripherals
 * 
 */

void peripheral_init(void)
{
    /*Configure LED and Switch pins*/
    InitLED();
    /*Configure ADC registers and pins*/
    InitADC();
    /*Configure PWM registers and pins*/
    InitPWM();
    /*Configure UART serial communication pin*/
    InitUART(103);
}
    
   
uint16_t temp;
char temp_data;
int main(void)
{
    /*uint16_t temp;*/
    // Initialize peripherals
    peripheral_init();
    
    while(1)
    {
        if(SENSOR_ON) //If switch_1 is ON
        {
            if(HEAT_ON) //If switch_2 is ON
            {
                ledstat(LED_ON);//LED is ON
                temp=ReadADC(0);
                temp_data = OutPWM(temp);
                UARTwrite(temp_data);

            }
            else
            {
                
                ledstat(LED_OFF);
            }
        }
        else
        {
            ledstat(LED_OFF);//LED is OFF
            OCR1A=0;
        }
    }
    return 0;
}
