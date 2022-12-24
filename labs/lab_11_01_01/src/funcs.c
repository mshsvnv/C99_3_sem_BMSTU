#include "../inc/funcs.h"

void write_string(char *restrict buf, char *str, size_t num, size_t *len)
{
    int i;

    if (!str)
        str = "(null)\0";
    
    for (i = 0; str[i]; i++, (*len)++)
    {
        if (buf && num && *len < num)
            buf[*len] = str[i];
    }
}

void write_short_int(char *restrict buf, int digit, size_t num, size_t *len)
{
    char *str = from_dig_to_num(digit);

    write_string(buf, str, num, len);

    free(str);
}

char *from_dig_to_num(int digit)
{
    char *numbers = "0123456789-";

    int tmp = (digit >= 0) ? digit : digit * (-1); 
    size_t len = 0, mem_len, i;

    while (tmp)
    {
        len++;
        tmp = tmp / 10;
    }

    if (digit == 0)
        len = 1;
        
    mem_len = (digit >= 0) ? len + 1 : len + 2;

    char *str = malloc(mem_len);

    if (!str)
        return NULL;

    tmp = (digit >= 0) ? digit : digit * (-1); 

    for (i = 0; i < len; i++, tmp = tmp / 10)
        str[len - i - 1] = numbers[tmp % 10];

    if (mem_len - len == 2)
    {
        for (i = mem_len - 1; i > 0; i--)
            str[i] = str[i - 1];
        str[0] = numbers[10];
    }    

    str[mem_len - 1] = '\0';

    return str;
}