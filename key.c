#include <LPC214x.h>
unsigned char dig[]={0x88,0xeb,0x4c,0x49,0x2b,0x19,0x18,0xcb,0x8,0x9,0xa,0x38,0x9c,0x68};
void delay(unsigned int count)
{
int i=0,j=0;
for(j=0;j<count;j++)
{
for(i=0;i<120;i++);
}
}
int main(void)
{
unsigned char count=0;
unsigned int i=0;
IO0DIR|=(1<<11);
IO0SET=(1<<11);
IO0DIR|=0x007F8000;
while(1)
{
count++;
if(count==16)count=0;
for(i=0;i<800;i++)
{
IO0CLR=0x007F8000;
IO0SET=(dig[count]<<15);
delay(20);
}
}
}