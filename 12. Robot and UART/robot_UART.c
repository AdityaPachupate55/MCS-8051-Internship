 #include <reg51.h>

//  LCD pins
sbit rs = P1 ^ 5;
sbit rw = P1 ^ 6;
sbit en = P1 ^ 7;
sfr ldata = 0xB0;

//  L298 pins
sbit m1 = P1 ^ 1;
sbit m2 = P1 ^ 2;
sbit m3 = P1 ^ 3;
sbit m4 = P1 ^ 4;

// Declaring switch
sbit s1 = P3 ^ 0;
sbit s2 = P3 ^ 1;

// Function for generating delay
void delay(int itime)
{
	int i, j;
	for (i = 0; i < 1000; i++)
		for (j = 0; j < itime; j++)
			;
}

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

// funtion for printing dataa on LCD
void lcddata(char value)
{
	ldata = value;
	rs = 1; // when rs = 0  --> recieving dataa
	rw = 0; // when w = 0 --> write dataa

	en = 1;
	delay(10);
	en = 0;
}

// Funtion for transmitting dataa
void txData(char value)
{
    SBUF = value;
    while (TI == 0)
        ;
    //delay(3);
    TI = 0;
}

void forwardFuntion()
{
	int i;
	char forw[] = "FORWARD";
	m1 = 1;
	m2 = 0;
	m3 = 1;
	m4 = 0;

	for (i = 0; i < 7; i++)
	{
		lcddata(forw[i]);
	}
	delay(10);
	lcdcmd(0x01);
}


int main()
{
	 
    
    char a = 'a';
    char w = 'w';
    char s = 's';
    char d = 'd';
    char value;

    TMOD = 0x20;
    TH1  = 0Xfd; // FD is baudrate 9600
    SCON = 0x50;
    TR1  = 1;

    lcdcmd(0x0E); // Display ON , cursor BLINKING;
	lcdcmd(0x38); // 5x7 matrix

    while (RI == 0) ;
    value = SBUF;
    RI = 0;

    if (w == value)
    {
        forwardFuntion();
    }
    


	return 0;
}