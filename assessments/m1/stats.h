/**
 * @file <stats.h> 
 * @brief <This is an header file for ststs.c which consists of function declarations>
 *
 * <Contains a total of 7 function declarations for statistical analysis on a dataset>
 *
 * @author <Harsha Y>
 * @date <March 14, 2022>
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <function for printing statistics of array(like Mean, Median,etc.)>
 *
 * @param <data_array> <an array containing data values>
 * @param <array_length> <size or length of the above array>
 *
 * @return <NULL>
 */
void print_statistics(unsigned char data_array[], unsigned int array_length);


/**
 * @brief <function for printing out the array>
 *
 * @param <data_array> <an array containing data values>
 * @param <array_length> <size or length of the above array>
 *
 * @return <NULL>
*/
void print_array(unsigned char data_array[], unsigned int array_length);

/**
 * @brief <function for finding Median of the array>
 *
 * @param <data_array> <an array containing data values>
 * @param <array_length> <size or length of the above array>
 *
 * @return <Median>
*/
unsigned char find_median(unsigned char data_array[], unsigned int array_length);


/**
 * @brief <function for finding Mean of the array>
 *
 * @param <data_array> <an array containing data values>
 * @param <array_length> <size or length of the above array>
 *
 * @return <Mean value>
*/
unsigned char find_mean(unsigned char data_array[], unsigned int array_length);

/**
 * @brief <function for finding maximum value of the array>
 *
 * @param <data_array> <an array containing data values>
 * @param <array_length> <size or length of the above array>
 *
 * @return <Maximum value of the data_array>
*/
unsigned char find_max(unsigned char data_array[], unsigned int array_length);


/**
 * @brief <function for finding mimimum value of the array>
 *
 * @param <data_array> <an array containing data values>
 * @param <array_length> <size or length of the above array>
 *
 * @return <Minimum value in the data_array>
*/
unsigned char find_min(unsigned char data_array[], unsigned int array_length);


/**
 * @brief <function for sorting the array from largest to smallest>
 *
 * @param <data_array> <an array containing data values>
 * @param <array_length> <size or length of the above array>
 *
 * @return <NULL>
*/
void sort_array(unsigned char data_array[], unsigned int array_length);

#endif /* __STATS_H__ */

