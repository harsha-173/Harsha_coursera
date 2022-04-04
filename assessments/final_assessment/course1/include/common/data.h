#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

#define BASE_2  (2)
#define BASE_3  (3)
#define BASE_4  (4)
#define BASE_5  (5)
#define BASE_6  (6)
#define BASE_7  (7)
#define BASE_8  (8)
#define BASE_9  (9)
#define BASE_10  (10)
#define BASE_11  (11)
#define BASE_12  (12)
#define BASE_13  (13)
#define BASE_14  (14)
#define BASE_15  (15)
#define BASE_16  (16)

#define BASE_2_MAXDIGITS (32)

#ifndef __ASCII_OFFSETS__
#define __ASCII_OFFSETS__
#define ASCII_OFFSET_0  (48)
#define ASCII_OFFSET_9  (57)
#define ASCII_OFFSET_A  (65)
#define ASCII_OFFSET_Z  (90)
#define ASCII_OFFSET_A_ADDITION  (55)/*10+55= 'A' in hexadecimal*/
#define ASCII_OFFSET_F  (70)
#define ASCII_OFFSET_LA  (97)
#define ASCII_OFFSET_LZ  (122)
#define ASCII_OFFSET_LA_ADDITION  (87)/*10+87= 'a' in hexadecimal*/
#define ASCII_OFFSET_LF  (102)
#define ASCII_OFFSET_EOF  (4)
#endif /* __ASCII_OFFSETS__ */

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

int32_t exponent(int32_t base,int32_t power);

#endif /* __DATA_H__ */

