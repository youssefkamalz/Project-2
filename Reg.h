//Set bit to 1

#define SET(reg, bit)    (reg |= (1<<bit))

//Set bit to 0

#define CLEAR(reg, bit)  (reg &= ~(1<<bit)) 

//Fetches Values from register 

#define GET(reg, bit)    ((reg >> bit) & 1)