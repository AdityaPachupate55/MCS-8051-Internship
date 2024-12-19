#include<reg51.h>
void delay(int itime){
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<itime;j++);

}

sbit m1 = P2^0;
sbit m2 = P2^1;


int main(){
	
	m1=1;
	m2=0;
	delay(200);
	
	m1=0;
	m2=1;
	delay(200);
	
	return 0;
}