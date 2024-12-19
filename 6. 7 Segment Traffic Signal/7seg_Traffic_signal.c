
#include<reg51.h>

//Function for generating delay
void delay(int itime){
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<itime;j++);

}

// Defining LED's
sbit red = P1^0;
sbit yellow = P1^1;
sbit green = P1^2;
sbit sw = P1^3;





int  main()
{	
	int numbers[10] = {0x6f,0x7f,0x07,0x7d,0x6d,0x66,0x4f,0x5b,0x06,0x3f};
	int i;
	
	//Green
		red=0;
		yellow=0;
		green=1;

	for( i = 0 ; i<6 ; i++){
		P2=numbers[i];
		delay(20);
		}
	
	// Yellow
		red=0;
		yellow=1;
		green=0;

	for( i = 6 ; i<10 ; i++){
		P2=numbers[i];
		delay(20);
		}
	
		// Red
		red=1;
		yellow=0;
		green=0;

	for( i = 0 ; i<10 ; i++){
		P2=numbers[i];
		delay(20);
		}
	
		
	
    return 0;
}
