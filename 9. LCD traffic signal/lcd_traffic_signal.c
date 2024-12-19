
#include <reg51.h>

// Function for generating delay
void delay(int itime)
{
    int i, j;
    for (i = 0; i < 1000; i++)
        for (j = 0; j < itime; j++)
            ;
}

// Defining LED's
sbit red = P1 ^ 0;
sbit yellow = P1 ^ 1;
sbit green = P1 ^ 2;
sbit sw = P1 ^ 3;

// Declaring LCD pins
sbit rs = P2 ^ 0;
sbit rw = P2 ^ 1;
sbit en = P2 ^ 2;

// Special funtions declaring , 0xB0 is the address for port 3.
// Addresses for all ports are different
sfr ldata = 0xB0;

// Function for giving commands to LCD
void lcdcmd(char value)
{
    ldata = value;
    rs = 0; // when rs = 0 --> recieving commands
    rw = 0; // when w = 0 --> write dataa

    // Triggereing en pin
    en = 1;
    delay(10);
    en = 0;
}

// funtion for printing data on LCD
void lcddata(char value)
{
    ldata = value;
    rs = 1; // when rs = 0  --> recieving dataa
    rw = 0; // when w = 0 --> write dataa

    en = 1;
    delay(10);
    en = 0;
}

// Funtion for emergency
void emerg(int  redState ,int greenState ,int yellowState)
{
    char emm[] = "EMERGENCY!";
		int j=0;
    
    red = 1;
    yellow = 0;
    green = 0;

    for (j = 0; j < 10; j++)
    {

        lcddata(emm[j]);
        //delay(2);
    }
    lcdcmd(0x01);
		
		red = redState;
    yellow = greenState;
    green = yellowState;
}

int main()
{
    int i;

    char green_lcd[] = {'9', '8', '7', '6', '5', '4', '3', '2', '1', '0'};
	

    lcdcmd(0x0E); // Display ON , cursor BLINKING;
    lcdcmd(0x38); // 5x7 matrix

    // Green
    red = 0;
    yellow = 0;
    green = 1;

    for (i = 0; i < 5; i++)
    {
        if (sw == 1)
        {
            emerg(red,yellow,green);
        }
        else
        {
            lcddata(green_lcd[i]);
            delay(7);
            lcdcmd(0x01);
        }
    }
    // lcdcmd(0x01);

    // yellow
    red = 0;
    yellow = 1;
    green = 0;

    for (i = 5; i < 10; i++)
    {
        if (sw == 1)
        {
            emerg(red,yellow,green);
        }
        else
        {
            lcddata(green_lcd[i]);
            delay(7);
            lcdcmd(0x01);
        }
    }

    // red
    red = 1;
    yellow = 0;
    green = 0;

    for (i = 0; i < 10; i++)
    {
        if (sw == 1)
        {
            emerg(red,yellow,green);
        }
        else
        {
            lcddata(green_lcd[i]);
            delay(7);
            lcdcmd(0x01);
        }
    }

    return 0;
}
