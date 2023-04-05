/*
 * string_utils.c
 *
 *  Created on: 2023. 3. 23.
 *      Author: hwyi
 */



#include "my_utils.h"
#include <string.h>

#define DECIMAL_PRECISION       10 //precision for decimal digits
#define FRACTIONAL_PRECISION    6  //precision for fractional digits

static char numstr_buffer[BUF_SIZE];
static INT my_pow_int(INT x, INT y);
static INT my_floor(FLOAT f);


static INT my_pow_int(INT x, INT y)
{
    INT result = 1;
    INT i = 0;

    for (i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}

static INT my_floor(FLOAT f)
{
    INT n = (INT)f;
    if(n > f)
    {
        n--;
    }

    return n;
}

char *int_2_str(INT n)
{
    INT dec_num = n;
    INT i;
    INT buf_idx = 0;
    char *buf = numstr_buffer;

    memset(buf, 0x00, BUF_SIZE);

    // check for negetive
    if(dec_num < 0.0)
    {
        buf[buf_idx++] = '-';
        dec_num *=-1;
    }

    // extract decimal part
    for(i=DECIMAL_PRECISION; i>=0; i--)
    {
        INT tmp = (INT)my_pow_int(10, i);
        INT num = dec_num / tmp;

        if(num > 0)
        {
            buf[buf_idx++] = (char)num+48;
            dec_num %= tmp;
        }
    }

    buf[buf_idx] = '\0';
    return buf;
}

char *float_2_str(FLOAT f)
{
    FLOAT whole_num;
    INT dec_part;
    FLOAT frac_part;
    char *buf;
    INT str_len;
    INT i;
    INT n;

    whole_num = f;
    dec_part = my_floow(f);
    frac_part = whole_num - dec_part;

    buf = int_2_str(dec_part);
    str_len = strlen(buf);

    buf[str_len++] = '.';
    for(i=0; i<FRACTIONAL_PRECISION; i++)
    {
        frac_part *= 10.0;
        n = my_floor(frac_part);
        buf[str_len++] = (char)n + 48;
        frac_part -= n;
    }

    buf[str_len] = '\0';
    return buf;
}
