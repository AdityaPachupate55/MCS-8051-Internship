#include <reg51.h>

void delay(int itime)
{
	int i, j;
	for (i = 0; i < 1000; i++)
		for (j = 0; j < itime; j++)
			;
}

// Declaring pins
sbit rs = P2 ^ 0;
sbit rw = P2 ^ 1;
sbit en = P2 ^ 2;

// Special funtions declaring , 0x90 is the address for port 1.
// Addresses for all ports are different
sfr ldata = 0xB0;

// Function for giving commands to LCD
void lcdcmd(char value)
{
	ldata = value;
	rs = 0; // when rs = 0 --> command is recieved
	rw = 0; // when w = 0 --> write dataa

	// Triggereing en pin
	en = 1;
	delay(10);
	en = 0;
}

void lcddata(char value)
{
	ldata = value;
	rs = 1; // when rs = 0 dataa is recieved
	rw = 0; // when w = 0 --> write dataa

	en = 1;
	delay(10);
	en = 0;
}

// Funtion for displaying dataa on LCD
void show(char data , int lcddelay){
	int i=0;
	for (i = 0; i <= data.lenght(); i++)
	{
		lcddata(data[i]);
		delay(lcddelay);
	}

}

int main()
{
	int i = 0;
	char name[] = "ADITYA";
	char last[] = "PACHUPATE";

	lcdcmd(0x0E);// Display ON , cursor BLINKING;
	lcdcmd(0x38);//5x7 matrix

	show(name,7); 
	lcdcmd(0xC0); // force display to 2nd line

	show(last,7);
	lcdcmd(0x01);// Clear display

	

	return 0;
}