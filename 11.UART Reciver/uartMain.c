#include <reg51.h>

// pin declarations
sbit led = P2 ^ 0;


void delay(int itime)

{
    int i, j;
    for (i = 0; i < 1000; i++)
        for (j = 0; j < itime; j++)
            ;
}

int main()

{
    char ch;
    // UART sfr
     TMOD = 0x20;
     TH1  = 0Xfd; // FD is baudrate 9600
     SCON = 0x50;
     TR1 =1;

    while (RI==0);
    ch = SBUF;
    P2 = ch;
    RI = 0;

    return 0;
}