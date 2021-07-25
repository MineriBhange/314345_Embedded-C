#include <avr/io.h>
#include <util/delay.h>



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
}
