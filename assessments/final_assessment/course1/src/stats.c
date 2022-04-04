/**
 * @file <stats.c> 
 * @brief <This is the main source file containing main function and all function definitions >
 *
 * <Consists of a main function along with a total of 7 function definitons for statistical analysis on a dataset>
 *
 * @author <Harsha Y>
 * @date <March 14, 2022>
 *
 */

#include <stdint.h>
#include "stats.h"
#include "platform.h"


/* Add other Implementation File Code Here */


	uint8_t print_array(uint8_t * start, uint32_t length)
{
    #ifdef VERBOSE
    uint32_t i=0;
    uint8_t* temp=(uint8_t*)start;
    for(i=0;i<length;i++)
    {
        if((i)%16==0)
        {
            PRINTF("%p ",(uint8_t *)temp);
        }
        PRINTF("%02X ",*(temp++));
        if((i+1)%16==0)
        {
            PRINTF("\n");
        }
    }
    #endif
}

