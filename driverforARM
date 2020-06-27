#include"header.h"
void io_dir(int port,int pin,int direction)
{
    switch(port)
    {
        case PORT0: //without setting the direction we can't use an i/o pin 
               if(direction==OUTPUT)
               IODIR0|=(1<<pin);//IODIR is used to set the direction of pin 
               else
               IODIR0&=~(1<<pin);//IODIR is used to clear the direction of pin 
               break;
        case PORT1:
               if(direction==OUTPUT)
               IODIR1|=(1<<pin);
               else
               IODIR1&=~(1<<pin);
               break;
    }
}

void io_write(int port,int pin,int value)//to write the data to the pin
{
    switch(port)
    {
    case PORT0:
               if(value==1)
               IOSET0=(1<<pin);//IOSET is used to set the i/o pin
               else
               IOCLR0=(1<<pin);//IOCLR is used to clear the i/o pin
               break;
        case PORT1:
               if(value==1)
               IOSET1=(1<<pin);
               else
               IOCLR1=(1<<pin);
               break;
    }
}

int io_read(int port,int pin)//to read the data from the pin
{
    int status;
    switch(port)
    {
        case PORT0:status=((IOPIN0>>pin)&1)?1:0;//IOPIN to read current status of i/o pin
        break;
        case PORT1:status=((IOPIN1>>pin)&1)?1:0;
        break;
    }
    return status;
}

}
