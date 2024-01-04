#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void    ft_putstr(char *str, int *count)
{
    if(!str) str = "(null)";
    while(*str) *count += write(1, str++, 1);
}

void    ft_putnbr(long long num, int base, int *count)
{
    if(num < 0)
    {
        num *= -1;
        *count += write(1, "-", 1);
    }
    else if(num >= base)
        ft_putnbr((num / base), base, count);
    *count += write(1, &"0123456789abcdef"[num % base], 1);
}

int ft_printf(const char *format, ...)
{
    int count = 0;
    va_list ptr;
    va_start(ptr, format);

    for(; *format; format++)
    {
        if((*format == '%') && *(format + 1)) 
        {
            format++;
            if(*format == 's')
                ft_putstr(va_arg(ptr, char *), &count);
            else if(*format == 'd')
                ft_putnbr((long long int)va_arg(ptr, int), 10, &count);
            else if(*format == 'x')
                ft_putnbr((long long int)va_arg(ptr, unsigned int), 16, &count);
        }
        else
            count += write(1, format, 1);
    }
    return(va_end(ptr), count);
}

int main()
{
	ft_printf("%d\n", ft_printf("Merhaba, %s! Sayi: %d, Hex: %x\n", "Dunya", 0, -42));
	printf("%d\n", printf("Merhaba, %s! Sayi: %d, Hex: %x\n", "Dunya", 0, -42));
	return 0;
}
