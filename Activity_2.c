#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1600000UL



void InitADC()
{
    ADMUX=(1<<REFS0); //For ARef=Avcc
    ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);//enabling ADC
}
uint16_t ReadADC(uint8_t ch)
{
    //Select ADC channel algorithm
    ADMUX&=0xf8;
    ch=ch&0b00000111;
    ADMUX|=ch;
    //Start single conversion
    ADCSRA|=(1<<ADSC);
    //Wait for conversion to complete
    while(!(ADCSRA & (1<<ADIF)));
    //clear ADIF by writing one to it
    ADCSRA|=(1<<ADIF);
    return(ADC);

}
int main()
{


    // Direction of port
    DDRB |= (1 << PB0);
    DDRD &= ~(1 << PD0);
    DDRD &= ~(1 << PD4);

    // PULL-UP configuration
    PORTD |= (1 << PD0);
    PORTD |= (1 << PD4);
    while (1)
    {
        // condition to check if both switches are on
        if (!(PIND&(1<<PD0)) && !(PIND&(1<<PD4)))
        {
            // set LED
            PORTB |= (1 << PB0);
            _delay_ms(200);
        }
        else
        {
            // set off led
            PORTB &= ~(1 << PB0);
            _delay_ms(200);
        }

    }
          InitADC();
          uint16_t temp=0;
          temp=ReadADC(0); //select channel 0
          _delay_ms(200);

}
