#include<reg51.h>

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

// switch
sbit sw = P1^0;

// motor
sbit m1 = P1^1;
sbit m2 = P1^2;



// Special funtions declaring , 0xBO is the address for port 3.
// Addresses for all ports are different
sfr ldata = 0xB0;

// Function for giving commands to LCD
void lcdcmd(char value)
{
    ldata = value;
    rs = 0; // when rs = 0 -->  recieving commands
    rw = 0; // when w = 0 --> writing dataa

    // Triggereing en pin
    en = 1;
    delay(10);
    en = 0;
}

void lcddata(char value)
{
    ldata = value;
    rs = 1; // when rs = 1 --> recieving dataa
    rw = 0; // when w = 0 --> write dataa

    en = 1;
    delay(10);
    en = 0;
}


// Funtion for displaying dataa on LCD
void show(char name , int lcddelay){
	int i=0;
	for (i = 0; i <= name.lenght(); i++)
	{
		lcddata(name[i]);
		delay(lcddelay);
	}

}

int main()
{
    
    char clockwise[10] = "Clockwise";
    char anticlock[20] = "Anticlockwise";
	
	    lcdcmd(0x0E);// display on cursor blinking
		lcdcmd(0x38);//5x7 matrix

    if (sw == 1)
    {
        m1 = 1;
        m2 = 0;

        show(clockwise,7);
    }
    else
    {
        m1 = 0;
        m2 = 1;

         show(anticlock,7);
    }
		lcdcmd(0x01);
    return 0;
}
