#include<reg51.h>

sbit relay = P2^1;

//Function for generating delay
void delay(int itime){
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<itime;j++);

}
int  main()
{
	
  
	relay =0;
    delay(50);
	relay =1;
    delay(50);
   
		
	
	
    return 0;
}
