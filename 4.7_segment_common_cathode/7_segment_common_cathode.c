#include<reg51.h>

//Function for generating delay
void delay(int itime){
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<itime;j++);

}

	

int  main()
{	
	//0
	P2=0x3F;
	delay(10);
	
	//1
	P2=0x06;
	delay(10);
	
	//2
	P2=0x5B;
	delay(10);
	
	//3
	P2=0x4F;
	delay(10);
	
	//4
	P2=0x66;
	delay(10);
	
	//5
	P2=0x6D;
	delay(10);
	
	//6
	P2=0x7D;
	delay(10);
	
	//7
	P2=0x07;
	delay(10);
	
	//8
	P2=0x7F;
	delay(10);
	
	//9
	P2=0x6F;
	delay(10);
		
    return 0;
}
