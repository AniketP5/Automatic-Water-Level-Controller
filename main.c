#include<avr/sfr_defs.h>
#include <avr/io.h>

int main()
 {
    int flag = 0;
    DDRC = 0xFF;
    DDRD = 0x00;
    DDRB = 0xFF;
    PORTB = 0x00;
    PORTC = 0x00;
    PORTD = 0xFF;
   while (1)
   {
      if(bit_is_clear(PIND,4))	//100% full
      {
	 PORTC = (1<<PC4);
	 PORTB = 0x00;
	 flag = 1;
      }
      else if(bit_is_clear(PIND,5))	//75% full
      {
	 PORTC = (1<<PC3);
	 PORTB = (1<<PB0);
	 flag = 1;
      }
      else if(bit_is_clear(PIND,6))	//50% full
      {
	 PORTC = (1<<PC2);
	 PORTB = (1<<PB0);
	 flag = 1;
      }
      else if(bit_is_clear(PIND,7))	//25% full
      {
	 PORTC = (1<<PC1);
	 PORTB = (1<<PB0);
	 flag = 1;
      }
      else
	 flag = 0;

      if(flag == 0)	//0% full
      {
	 PORTC = (1<<PC0);
	 PORTB = (1<<PB0);
      }
   }
   return 0;
 }
