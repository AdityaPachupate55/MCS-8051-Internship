#include<reg51.h>

//Function for generating delay
void delay(int itime){
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<itime;j++);

}

	// Declaring switch P1 is the port and 0 is the pin
	sbit sw = P1^0;

int  main()
{	
	if(sw==1){
		P2 = 0xAA;   
	}
	else{
		P2 = 0x55;
	}	
    return 0;
}
