
#include<reg51.h>

//Function for generating delay
void delay(unsigned int time)  // Function for creating delay in milliseconds.
{
    unsigned i,j ;
    for(i=0;i<time;i++)    
    for(j=0;j<1275;j++);
}
sbit sw = P1^0;
	

int  main()
{	
	int numbers[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
	int i;
		
	
		for(i=0;i<10;i++){
			if(sw==1){
			P2=numbers[i];
			delay(100);
			}
		}
	
		
	
	
    return 0;
}
