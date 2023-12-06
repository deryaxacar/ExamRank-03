#include <stdarg.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	if (!str) str = "(null)";
	write(1, str, strlen(str));
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
    count += write(1, &"0123456789abcdef"[num % base], 1);
    return count;
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
                ft_putstr(va_arg(ptr, char*));
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
    ft_printf("Merhaba, %s! Sayi: %d, Hex: %x\n", "Dunya", 42, 42);
    return 0;
}
