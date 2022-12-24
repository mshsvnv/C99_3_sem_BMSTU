#include "../inc/my_snprintf.h"

int my_snprintf(char *restrict buf, size_t num, const char *restrict format, ...)
{
    size_t len = 0;

    va_list args;
    va_start(args, format);

    char *tmp_str;
    int tmp_digit;
    short tmp_digit_2;

    const char *tmp = format;

    while (*tmp)
    {
        if (*tmp != '%')
        {
            if (buf && num && len < num)
                buf[len] = *tmp;

            tmp++;
            len++;
        }
        else
        {
            if (*(tmp + 1) == 's')
            {
                tmp_str = va_arg(args, char *);

                write_string(buf, tmp_str, num, &len);

                tmp += 2;
            }
            else if (*(tmp + 1) == 'h' && *(tmp + 2) == 'd')
            {
                tmp_digit = va_arg(args, int);
                
                tmp_digit_2 = tmp_digit;
                tmp_digit = tmp_digit_2;

                write_short_int(buf, tmp_digit, num, &len);

                tmp += 3;
            }
            else
            {
                if (buf && num && len < num)
                    buf[len] = *tmp;

                tmp++;
                len++;
            }
        }
    }

    if (buf && num)
    {
        if (num > len)
            buf[len] = '\0';
        else
            buf[num - 1] = '\0';
    }

    va_end(args);

    return len;
}