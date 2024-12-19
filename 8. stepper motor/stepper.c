#include<reg51.h>
void delay(int itime){
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<itime;j++);

}

sbit sw = P1^0;

int main(){
	if(sw==1){
		P2=0X01;
		  delay(10);
		P2=0X02;
			delay(10);
		P2=0X04;
			delay(10);
		P2=0X08;
		  	delay(10);
		
	}
	else{
		P2=0X08;
		  	delay(10);
		P2=0X04;
			delay(10);
		P2=0X02;
			delay(10);
		P2=0X01;
		  delay(10);
	}
	
return 0;
}
	