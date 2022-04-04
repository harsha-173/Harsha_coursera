#include <stdint.h>
#include "memory.h"
#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
		if(!ptr)
	{
		return (uint8_t)0;
	}
    uint8_t length=0;
    uint8_t negative=0;
    if(data == 0)
        return 0;
    if(base<BASE_2||base>BASE_16)
    {
        return 0;
    }
    if(data<0)
    {
        *ptr++='-';
        data=-data; 
        negative=1;
    }
    while(1) 
    {
        *(ptr+length) = data%base;
        data = data/base;
        length++;
        if ((data == 0) || (length > BASE_2_MAXDIGITS ))
            break;
    }
    
    my_reverse(ptr, length);
    int32_t j=length-1;
    
    uint8_t num;
    for(j=length-1;j>=0;j--)
    {
        num = *(ptr+j);
        if(num>9)
        {
            *(ptr+j)=num+ASCII_OFFSET_A_ADDITION;
        }
        else
        {
            *(ptr+j)=num+ASCII_OFFSET_0;
        }
    }
    length = length + negative;
    return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
		if(!ptr)
	{
		return (uint32_t)0;
	}
    int8_t i = 0;
    uint8_t negative = 0;
    int32_t return_value = 0;
    if(digits == 0)
        return 0;
    
    if(*ptr=='-')
    {
        negative = 1;
        ptr++;
        digits--;
    }
    
    digits--;
    
    for(i=digits;i>=0;i--)
    {
        
        if (*ptr >= ASCII_OFFSET_0 && *ptr <= ASCII_OFFSET_9)
        {
            if((*ptr - ASCII_OFFSET_0) > base)
                
                return 0;
            return_value += (*ptr++ - ASCII_OFFSET_0) * exponent(base, i);
        }
        
        else if (*ptr >= ASCII_OFFSET_A && *ptr <= ASCII_OFFSET_F)
        {
            if((*ptr - ASCII_OFFSET_A_ADDITION) > base)
                
                return 0;
            return_value += (*ptr++ - ASCII_OFFSET_A_ADDITION) * exponent(base, i);
        }
        
        else if (*ptr >= ASCII_OFFSET_LA && *ptr <= ASCII_OFFSET_LF)
        {
            if((*ptr - ASCII_OFFSET_LA_ADDITION) > base)
                
                return 0;
            return_value += (*ptr++ - ASCII_OFFSET_LA_ADDITION) * exponent(base, i);
        }
        else
        {
            return 0;
        }
    }
    if(negative)
    {
        return -return_value;
    }
    return return_value;
    
}

int32_t exponent(int32_t base,int32_t power)
{
    if(power<0) return 0;
    uint32_t i=0;
    int32_t retval=1;
    for(i=1;i<=power;i++)
    {
        retval*=base;
    }
    return retval;
}


