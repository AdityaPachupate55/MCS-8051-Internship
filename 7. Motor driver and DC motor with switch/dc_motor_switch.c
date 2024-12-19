#include<reg51.h>
void delay(int itime){
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<itime;j++);

}

sbit m1 = P2^0;
sbit m2 = P2^1;
sbit sw = P1^0;



int main(){
	
	if(sw==1){
		m1=1;
	  m2=0;
//	delay(20);
	}else{
		
	m1=0;
	m2=1;
	//delay(20);
	}
	
	
	
	return 0;
}