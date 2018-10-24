#include <at89x52.h>

#define CAMERA1 P1_0
#define CAMERA2 P1_1
#define CAMERA3 P1_2
#define CAMERA4 P1_3

#define ROOM1 P0_0
#define ROOM2 P0_1
#define ROOM3 P0_2
#define ROOM4 P0_3
 
const HIGH = 1;
const LOW = 0;
int counter = 0;

void foundSomeOne() interrupt 0
{
	if(ROOM1 == 1 || ROOM2 == 1 || ROOM3 == 1 || ROOM4 == 1 )
	{
			P3_1 = ~P3_1;
			P3_3 = ~P3_3;
			P3_3 = ~P3_4;
			P3_5 = ~P3_5;
			P3_6 = ~P3_6;
			P3_7 = ~P3_7;
	}
}

void takeABreak()
{
	while(ROOM1 == 0 && ROOM2 == 0 && ROOM3 == 0 && ROOM4 == 0)
	{
		CAMERA1 = 0;
		CAMERA2 = 0;
		CAMERA3 = 0;
		CAMERA4 = 0;
		counter = 0;
		
		if(ROOM1 == 1 && ROOM2 == 0 && ROOM3 == 0 && ROOM4 == 0)
		{
			counter = 60;
			break;
		}
		else if(ROOM1 == 0 && ROOM2 == 1 && ROOM3 == 0 && ROOM4 == 0)
		{
			counter = 120;
			break;
		}
		else if(ROOM1 == 0 && ROOM2 == 0 && ROOM3 == 1 && ROOM4 == 0)
		{
			counter = 180;
			break;
		}
		else if(ROOM1 == 0 && ROOM2 == 0 && ROOM3 == 0 && ROOM4 == 1)
		{
			counter = 220;
			break;
		}
	}
}

void caixaCheiaInterrupt() interrupt 1
{
	TR0 = 0;
	TH0 = 0x3C;
	TL0 = 0xAF;
	TR0 = 1;
	
	if(counter == 60)
	{ 
		CAMERA1 = 1;
		CAMERA2 = 0;
		CAMERA3 = 0;
		CAMERA4 = 0;
		
	}else if(counter == 120)
	{ 
		CAMERA2 = 1;
		CAMERA1 = 0;
		CAMERA3 = 0;
		CAMERA4 = 0;
	} else if(counter == 180)
	{
		CAMERA3 = 1;
		CAMERA1 = 0;
		CAMERA2 = 0;
		CAMERA4 = 0;
	}else if(counter == 240)
	{
		CAMERA4 = 1;
		CAMERA1 = 0;
		CAMERA2 = 0;
		CAMERA3 = 0;
		counter = 0;
	}
	counter++;
	takeABreak();
}

int main()
	{
		EA = 1;
		EX0 = 1;
		ET0 = 1;
		TMOD = 1; 
		TR0 = 1;
		P1 = 0;
		
		while(1)
		{
		}
}