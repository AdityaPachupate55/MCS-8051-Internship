 #include <reg51.h>

// Declaring LCD pins
sbit rs = P2 ^ 0;
sbit rw = P2 ^ 1;
sbit en = P2 ^ 2;
sfr ldata = 0xB0;

// Declaring L298 pins
sbit m1 = P2 ^ 3;
sbit m2 = P2 ^ 4;
sbit m3 = P2 ^ 7;
sbit m4 = P2 ^ 6;

// Declaring switch
sbit s1 = P1 ^ 0;
sbit s2 = P1 ^ 1;

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

// driving functions
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

void backFunction()
{
	int i;
	char back[] = "BACKWARD";
	m1 = 0;
	m2 = 1;
	m3 = 0;
	m4 = 1;

	for (i = 0; i < 8; i++)
	{
		lcddata(back[i]);
	}
	delay(10);
	lcdcmd(0x01);
}

void leftFunction()
{
	int i;
	char left[] = "LEFT";
	m1 = 0;
	m2 = 0;
	m3 = 1;
	m4 = 0;

	for (i = 0; i < 4; i++)
	{
		lcddata(left[i]);
	}
	delay(10);
	lcdcmd(0x01);
}

void rightFunction()
{
	int i;
	char right[] = "RIGHT";
	m1 = 1;
	m2 = 0;
	m3 = 0;
	m4 = 0;

	for (i = 0; i < 5; i++)
	{
		lcddata(right[i]);
	}
	delay(10);
	lcdcmd(0x01);
}

int main()
{
	int i;

	lcdcmd(0x0E); // Display ON , cursor BLINKING;
	lcdcmd(0x38); // 5x7 matrix

	// Forward
	if (s1 == 1 && s2 == 1)
		forwardFuntion();

	// Backward
	if (s1 == 0 && s2 == 0)
		backFunction();

	// Left
	if (s1 == 1 && s2 == 0)
		rightFunction();

	// right
	if (s1 == 0 && s2 == 1)
		leftFunction();

	return 0;
}