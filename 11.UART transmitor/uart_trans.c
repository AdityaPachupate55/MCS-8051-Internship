#include <reg51.h>

// pin declarations
// sbit led = P2 ^ 0;

void delay(int itime)

{
    int i, j;
    for (i = 0; i < 1000; i++)
        for (j = 0; j < itime; j++)
            ;
}

// Funtion for transmitting data
void txData(char value)
{
    SBUF = value;
    while (TI == 0)
        ;
    //delay(3);
    TI = 0;
}

// Funtion for recieving data
void rxData()
{
    char value;
    while (RI == 0)
        ;
    value = SBUF;
    txData(value); // funtion call for transmitting data
    RI = 0;
}

int main()

{

    // UART sfr
    TMOD = 0x20;
    TH1  = 0Xfd; // FD is baudrate 9600
    SCON = 0x50;
    TR1  = 1;

    rxData();

    return 0;
}