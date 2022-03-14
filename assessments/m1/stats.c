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



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
	print_statistics(test, SIZE);
	
}

/* Add other Implementation File Code Here */

	void print_statistics(unsigned char data_array[], unsigned int array_length)
	{
		printf("Given array : \n\n");
		print_array(data_array, array_length);
		sort_array(data_array, array_length);
		printf("Sorted array : \n\n");
		print_array(data_array, array_length);
		printf(" Median = %d\n", find_median(data_array, array_length));
		printf(" Mean = %d\n", find_mean(data_array, array_length));
		printf(" Max = %d\n", find_max(data_array, array_length));
		printf(" Min = %d\n", find_min(data_array, array_length));
		return;
	}
	
	void print_array(unsigned char data_array[], unsigned int array_length)
	{
		for(int i=0; i<array_length; i++)
			printf(" %d,", data_array[i]);
			
		printf("\n\n");
		return;
	}
	
	unsigned char find_median(unsigned char data_array[], unsigned int array_length)
	{
		return (data_array[(array_length-1)/2] + data_array[array_length/2])/2;
	}
	
	unsigned char find_mean(unsigned char data_array[], unsigned int array_length)
	{
		unsigned int sum = 0;
			for(int i= 0; i<array_length; i++)
				sum = sum + data_array[i];
		
		return (unsigned char) (sum/array_length);
	}
	
	unsigned char find_max(unsigned char data_array[], unsigned int array_length)
	{
		return data_array[0];
	}
	
	unsigned char find_min(unsigned char data_array[], unsigned int array_length)
	{
		return data_array[array_length-1];
	}
	
	void sort_array(unsigned char data_array[], unsigned int array_length)
	{
		unsigned char temp;
			for(int i=0; i<array_length; i++){
				for(int j=i; j<array_length; j++){
					if(data_array[j] > data_array[i])
					{
						temp = data_array[j];
						data_array[j] = data_array[i];
						data_array[i] = temp;
					}
				}
			}
		return;
	}

