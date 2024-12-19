#include<reg51.h>

//Function for generating delay
void delay(int itime){
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<itime;j++);

}
int  main()
{
	//Port 2 pin 1 
	// here 0x01 is the address of the first pin of the port 2 , Which is a hex value
	// The led which ned to be switched ON its hex value is assigned to be 1 and others are 0
	//  Below is example is you want to glow only ODD/EVEN LED's 
	// For even
	// 8  7  6  5  4  3  2  1 --> LED number
	
	// 8  4  2  1  8  4  2  1 --> HEX value
	// 1  0  1  0  1  0  1  0 
	
	// Addition of even bits is 8+1 =10 in hexadecimal it is AA
  
		P2 = 0xAA;
    delay(10);
		
		
	
	
    return 0;
}
