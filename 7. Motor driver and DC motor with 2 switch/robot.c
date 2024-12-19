#include<reg51.h>
void delay(int itime){
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<itime;j++);

}

sbit m1 = P2^0;
sbit m2 = P2^1;

sbit m3 = P2^2;
sbit m4 = P2^3;

sbit sw1 = P1^0;
sbit sw2 = P1^6;




int main(){
	
	if(sw1==1 && sw2==1){
		m1=0;
		m2=1;
		
		m3=0;
		m4=1;
		//
		
		
		
	}
	
	if(sw1==0 && sw2==1){
		m1=0;
		m2=0;
		
		m3=1;
		m4=0;
		
	}
	
	if(sw1==1 && sw2==0){
		m1=1;
		m2=0;
		
		m3=0;
		m4=0;
		
	}
	
	if(sw1==0 && sw2==0){
		m1=1;
		m2=0;
		m3=1;
		m4=0;
		
	}
	
	
	
	
	return 0;
}