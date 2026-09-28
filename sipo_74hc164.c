#include <LPC21xx.H>

#include "defines.h"
#include "types.h"
#include "delay.h"


//shift registers signals
#define SIN_1 16          //data
#define CP_1  17          //clock
#define SIN_2 18        //data
#define CP_2  19        //clock
#define SIN_3 20        //data
#define CP_3  21        //clock
#define SIN_4 22        //data
#define CP_4  23        //clock

void Init_SIPO()
{
        SETBIT(IODIR1,SIN_1);
        SETBIT(IODIR1,CP_1);
        SETBIT(IODIR1,SIN_2);
        SETBIT(IODIR1,CP_2);
        SETBIT(IODIR1,SIN_3);
        SETBIT(IODIR1,CP_3);
        SETBIT(IODIR1,SIN_4);
        SETBIT(IODIR1,CP_4);
}

void SIPO_74HC164_1(u8 ch)
{
        u8 i;

        for(i=0;i<8;i++)
        {
        WRITEBIT(IOPIN1,SIN_1,((ch>>(7-i))&1));
                IOCLR1 = 1<<CP_1;
                delay_us(1);
                IOSET1 = 1<<CP_1;
                delay_us(1);
        }
}

void SIPO_74HC164_2(u8 ch)
{
        u8 i;

        for(i=0;i<8;i++)
        {
                WRITEBIT(IOPIN1,SIN_2,((ch>>(7-i))&1));
                IOCLR1 = 1<<CP_2;
                delay_us(1);
                IOSET1 = 1<<CP_2;
                delay_us(1);
        }
}

void SIPO_74HC164_3(u8 ch)
{
        u8 i;

        for(i=0;i<8;i++)
        {
                WRITEBIT(IOPIN1,SIN_3,((ch>>(7-i))&1));
                IOCLR1 = 1<<CP_3;
                delay_us(1);
                IOSET1 = 1<<CP_3;
                delay_us(1);
        }
}

void SIPO_74HC164_4(u8 ch)
{
        u8 i;

        for(i=0;i<8;i++)
        {
                WRITEBIT(IOPIN1,SIN_4,((ch>>(7-i))&1));
                IOCLR1 = 1<<CP_4;
                delay_us(1);
                IOSET1 = 1<<CP_4;
                delay_us(1);
        }
}
