#include <reg51.h>
#define ldata P3
sbit rs=P2^5;
sbit rw=P2^6;
sbit en=P2^7;
void delay(unsigned int time)  // Function for creating delay in milliseconds.
{
    unsigned i,j ;
    for(i=0;i<time;i++)    
    for(j=0;j<1250;j++);
}
void lcdcmd(unsigned char cmd)
{
	ldata=cmd;
	rs=0;
	rw=0;
	en=1;
	delay(1);
	en=0;
}
void lcddata(unsigned char lcdata)
{
	ldata=lcdata;
	rs=1;
	rw=0;
	en=1;
	delay(1);
	en=0;
}
void lcdstring(unsigned char str[])
{
	unsigned int k=0;
	for (k=0;str[k]!=0;k++)
	{
		lcddata(str[k]);
	}
}
void lcdinit()
{
	lcdcmd(0x02);
	lcdcmd(0x01);
	lcdcmd(0x38);
	lcdcmd(0x0C);
	lcdcmd(0x06);
	lcdcmd(0x80);
}