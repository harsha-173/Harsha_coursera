/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
 
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include "memory.h"
/***********************************************************
 Function Definitions
***********************************************************/

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
		uint8_t isCopyRequire = 0;  
    uint8_t *pcSource =(uint8_t *)src;
    uint8_t *pcDstn =(uint8_t *)dst;
    
    if ((pcSource == NULL) || (pcDstn == NULL))
    {
        return NULL;
    }
    
    if((pcSource < pcDstn) && (pcDstn < pcSource + length))
    {
        for (pcDstn += length, pcSource += length; length--;)
        {
            *--pcDstn = *--pcSource;
        }
    }
    else
    {
        while(length--)
        {
            *pcDstn++ = *pcSource++;
        }
    }
    return dst;
}


uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length)
{
		uint8_t *pszDest = (uint8_t *)dst;
    const uint8_t *pszSource =( const uint8_t*)src;
    if((pszDest!= NULL) && (pszSource!= NULL))
    {
        while(length)
        {
            *(pszDest++)= *(pszSource++);
            --length;
        }
    }
    return dst;
}


uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
		uint8_t* p=src;
    while(length--)
    {
        *p++ = (uint8_t)value;
    }
    return src;
}


uint8_t * my_memzero(uint8_t * src, size_t length)
{
		my_memset(src, length, 0);	
}


uint8_t * my_reverse(uint8_t * src, size_t length)
{
		if(!src)
    {
        return NULL;
    }
    
    uint8_t my_array[length];  
    my_memcopy(src, my_array, length); 
    uint8_t * my_array_ptr = &my_array[length-1];    
    size_t i = 0;
    
    for(i=0;i<length;i++)
    {
        *src++ = *my_array_ptr--;
    }
    return src;
}


uint32_t * reserve_words(size_t length)
{
		uint32_t * src;
    src = (uint32_t *)malloc(length*sizeof(uint32_t *));
    return src;
}


void free_words(uint32_t * src)
{
		free(src);
}


