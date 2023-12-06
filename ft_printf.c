#include <stdarg.h>
#include <unistd.h>

void ft_putstr(char *str, int *count)
{
    if (!str) str = "(null)";
    *count += write(1, str, strlen(str));
}

int ft_putnbr(long num, int base)
{
    int count = 0;
    if (num < 0)
    {
        num *= -1;
        count += write(1, "-", 1);
    }
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
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            if (*str == 's')
                ft_putstr(va_arg(ptr, char*), &count);
            else if (*str == 'd')
                count += ft_putnbr(va_arg(ptr, int), 10);
            else if (*str == 'x')
                count += ft_putnbr(va_arg(ptr, unsigned int), 16);
        }
        else
        {
            count += write(1, str, 1);
        }
        str++;
    }
    return (va_end(ptr), count);
}

int main()
{
    ft_printf("Merhaba, %s! Sayi: %d, Hex: %x\n", "Dunya", 42, 42);
    return 0;
}
