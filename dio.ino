#include "Reg.h"

void DIO_init(){
  DIO_SPD('b', 3 ,'o');
  DIO_SPD('b', 4 ,'o');
}

// set Pin to INPUT or OUTput
void DIO_SPD(unsigned char port, int pin, unsigned char direction){ 
  if (port == 'b' & pin <= 7 & pin >= 0){ 
    if(direction == 'o'){
      DDRB = DDRB|(1<<pin); 
    }else if(direction == 'i'){
      DDRB = DDRB&!(1<<pin); 
    }
  }
  if (port == 'c' & pin <= 7 & pin >= 0){ 
    if(direction == 'o'){
      DDRC = DDRC|(1<<pin); 
    }else if(direction == 'i'){
      DDRC = DDRC&!(1<<pin); 
    }
  }
  if (port == 'd' & pin <= 7 & pin >= 0){ 
    if(direction == 'o'){
      DDRD = DDRD|(1<<pin); 
    }else if(direction == 'i'){
      DDRD = DDRD&!(1<<pin); 
    }
  }
}

void DIO_SPS(unsigned char port, int pin, unsigned char state){
  if (port == 'b' & pin <= 7 & pin >= 0){ 
    if(state == 'h'){
      PORTB = PORTB|(1<<pin); 
    }else if(state == 'l'){
      PORTB &= ~(1<<pin); 
    }
  }
  if (port == 'd' & pin <= 7 & pin >= 0){ 
    if(state == 'h'){
      PORTD = PORTD|(1<<pin); 
    }else if(state == 'l'){
      PORTD &= ~(1<<pin); 
    }
  }
  if (port == 'c' & pin <= 7 & pin >= 0){ 
    if(state == 'h'){
      PORTC = PORTC|(1<<pin); 
    }else if(state == 'l'){
      PORTC &= ~(1<<pin); 
    }
  }
}

int DIO_GPS(unsigned char port, int pin){ 
  int state;
  switch(port){ 
    case 'd':
      if((pin <= 7) && (pin >= 0)){
        state = GET(PIND, pin);
      }
      break;
    case 'b':
      if((pin <= 5) && (pin >= 0)){
        state = GET(PINB, pin);
      }
      break;
  }
  return state;
}
  