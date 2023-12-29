#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_putstr(char *str)
{
        int count = 0;
	if (!str) str = "(null)";
	count += write(1, str, strlen(str));
        return count;
}

int ft_putnbr(long num, int base)
{
    if (num < 0)
    {
    	write(1, "-", 1);
        num = -num;
    }
    int count = 0;
    if (num > (base - 1))
        count += ft_putnbr(num / base, base);
    return count + write(1, &"0123456789abcdef"[num % base], 1);
}

int ft_printf(const char *str, ...)
{
    int count = 0;
    va_list ptr;
    va_start(ptr, str);
    for (; *str; str++)
    {
        if (*str == '%') 
	{
            str++;
            if (*str == 's')
                count += ft_putstr(va_arg(ptr, char*));
            else if (*str == 'd')
                count += ft_putnbr(va_arg(ptr, int), 10);
            else if (*str == 'x')
                count += ft_putnbr(va_arg(ptr, unsigned int), 16);
        } 
	else
            count += write(1, str, 1);
    }
    return (va_end(ptr), count);
}

int main()
{
          ft_printf("%d\n", ft_printf("%s\n", "deneme"));
          printf("%d\n", printf("%s\n", "deneme"));
          ft_printf("%d\n", ft_printf("%d\n", 16));
          printf("%d\n", printf("%d\n", 16));
          ft_printf("%d\n", ft_printf("%x\n", 42));
          printf("%d\n", printf("%x\n", 42));
          return 0;
}
//Rank 3'te geçmez.
