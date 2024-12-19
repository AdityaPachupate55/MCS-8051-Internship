#include <reg51.h>

void delay(int itime)
{
    int i, j;
    for (i = 0; i < 1000; i++)
        for (j = 0; j < itime; j++)
            ;
}

// Pin declarations
sbit rd    = P2 ^ 0;
sbit wd    = P2 ^ 1;
sbit int_r = P2 ^ 2;

// LCD pins declaration
sbit lcd_rs = P2 ^ 4;
sbit lcd_rw = P2 ^ 5;
sbit lcd_en = P2 ^ 6;

// port declartion
sfr ldata    = 0xB0; // for ADC
sfr lcd_data = 0x90; // for LCD

// Function for giving commands to LCD
void lcdcmd(char value)
{
    lcd_data = value;
    lcd_rs   = 0; // when rs = 0 --> recieving commands
    lcd_rw   = 0; // when w = 0 --> write dataa

    // Triggereing en pin
    lcd_en = 1;
    delay(10);
    lcd_en = 0;
}

// funtion for printing dataa on LCD
void lcddata(char value)
{
    lcd_data = value;
    lcd_rs   = 1; // when rs = 0  --> recieving dataa
    lcd_rw   = 0; // when w = 0 --> write dataa

    lcd_en = 1;
    delay(10);
    lcd_en = 0;
}

void printNumber(int num)
{
    int noOfDigits   = 0, digit;
    int digitsArr[3] = {0};
    int i;
    int n = num;

    while (n > 0) {
        digit                 = n % 10;
        digitsArr[noOfDigits] = digit;
        n                     = n / 10;
        noOfDigits++;
    }

    for (i = 2; i >= 0; i--) {
        lcddata(digitsArr[i] + 48);
        delay(2);
    }
}
int main()
{
    int d;

    // All pins are declared as 1;
    ldata = 0xFF;

    rd    = 1;
    wd    = 1;
    int_r = 1;

    lcdcmd(0x0E); // Display ON , cursor BLINKING;
    lcdcmd(0x38); // 5x7 matrix

    while (1) {
        wd = 0;
        delay(10);
        wd = 1;

        while (int_r == 1)
            ;
        rd = 0;
        d  = ldata;
        printNumber(d);
        delay(5);
        lcdcmd(0x01);

        rd = 1;
    }

    return 0;
}