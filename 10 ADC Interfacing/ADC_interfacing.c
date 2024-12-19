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

// port declartion
sfr ldata = 0xB0;

int main()
{
    char d;

    // All pins are declared as 1;
    ldata = 0xFF;

    rd    = 1;
    wd    = 1;
    int_r = 1;

    while (1) {
        wd = 0;
        delay(10);
        wd = 1;

        while (int_r == 1);
        rd = 0;
        d  = ldata;
        P1 = d;
		rd = 1 ;
    }

    return 0;
}