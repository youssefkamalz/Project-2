#include <util/delay.h>
#include "Lcd.h"
#include "LED.h"
#include "dio.h"
#include "Reg.h"
#include "Conv.h"

int main()

{
  //Initializing everything:
  
	LCD_Init();			
  LED_Init();     
  DIO_init();     

  unsigned long pot_val;              //Potentiometer value
  unsigned long limit = 5000;         //Limit value
  int Button_ADD;
  int Button_SUB;
  unsigned char reading_buffer[5];    //LCD buffer
  unsigned char limit_buffer[5];      //LCD buffer limit

  while(1){

  Button_ADD = DIO_GPS('d',2);            //Assign digital pin 2 to button 1
  Button_SUB = DIO_GPS('d',3);            //Assign digital pin 3 to button 2

  pot_val = LED_Read(1);                  //Assign analog pin 1 to LCD
  unsigned long display_reading = round(((10000*pot_val)/1023));     //Simplify potentiometer value

  //BUTTONS:

  if(Button_ADD ==  HIGH)
  { 
    if(limit<10000)
    { 
      limit += 100;
    }
  }

  if(Button_SUB == HIGH)
  { 
    if(limit>0)
    { 
      limit -= 100; 
    }
  }

  //LED on/off:

  if(display_reading > limit){ 
    DIO_SPS('b', 3 , 'h');
  }else {
    DIO_SPS('b', 3 , 'l');
  }

  //Convert numbers to string:

  Convert(display_reading, reading_buffer,10); 
  Convert(limit, limit_buffer,10);   

  //First LCD row:

  LCD_CMD(0x80); 
	LCD_STR("VALUE = ");	  
  LCD_STR(reading_buffer); 

  //Second LCD row:

  LCD_CMD(0xC0);		      
  LCD_STR("LIMIT = ");     
  LCD_STR(limit_buffer);   

  _delay_ms(250); 
  }

	return 0;
}
