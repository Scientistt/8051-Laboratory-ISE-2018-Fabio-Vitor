#include <at89x52.h>

#define stopBoxes P1_7
#define stopProducts P1_1

#define products P1_0
#define boxes P1_6




int counter = 0;

const HIGH = 1;
const LOW = 0;

void fullBox() interrupt 1
	{
	TR0 = 0;
	TH0 = 0x3C;
	TL0 = 0xAF;
	TR0 = 1; 
	counter++;
		
	if(counter == 2500)
	{
		stopProducts = HIGH;
		stopBoxes = HIGH;
		products = LOW;
		boxes = LOW;
	}else if(counter == 5000)
	{
		stopProducts = LOW; 
		stopBoxes = LOW;
		products = HIGH;
		boxes = HIGH;
		counter = 0;
	}
}

int main()
{
		EA = 1; 
		ET0 = 1;
		TMOD = 1; 
		TR0 = 1;
	
	products = HIGH;
		boxes   = HIGH;
	
		P1 = LOW;
		 
		while(1)
		{
		}
}