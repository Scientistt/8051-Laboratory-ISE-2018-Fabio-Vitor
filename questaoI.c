#include<at89x52.h>

#define Tea P0_1
#define Coffee P0_2
#define Glass P0_3

const HIGH = 1;
const LOW = 0;

void delay(unsigned int time_ms)
{
	unsigned int i, j;
	for (i = 0; i < time_ms; i++)
	{
		for (j = 0; j < 12750; j++)
		{
		}
	}
}

void coinInterrupt() interrupt 0 
{
	if(Tea == HIGH && Coffee == LOW)
	{
		Glass = HIGH;
		delay(1000);
		Glass = LOW;
		Tea = LOW;
		P3_2 = 1;
	}
	else if(Coffee == HIGH && Tea == LOW)
	{
		Glass = HIGH;					 
		delay(1000); 						
		Glass = LOW; 		 
		Coffee = LOW;
		P3_2 = 1;
	}
}

int main()
{
		EA = 1;  
		EX0 = 1; 
		P0 = LOW;
		P1 = LOW;
		
		while(1)
		{
		}
}