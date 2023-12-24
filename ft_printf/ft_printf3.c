#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void      ft_putstr(char *str, int *count)
{
          if(!str) str = "(null)";
          while(*str) *count += write(1, str++, 1);
}

void       ft_putnbr(long num, int base, int *count)
{
          if(num < 0)
          {
                num *= -1;
                *count += write(1, "-", 1);
          }
          else if(num > (base - 1))
                    ft_putnbr(num / base, base, count);
          *count += write(1, &"0123456789abcdef"[num % base], 1);
}

int       ft_printf(const char *format, ...)
{
          int count = 0;
          va_list ptr;
          va_start(ptr, format);
          while(*format)
          {
                    if((*format == '%') && (*format + 1))
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
                    format++;
          }
          return(va_end(ptr), count);
}

int main()
{
	ft_printf("%d\n",ft_printf("%s\n", "toto"));
    	printf("%d\n",printf("%s\n", "toto"));
	ft_printf("%d\n",ft_printf("Magic %s is %d\n", "number", 42));
	printf("%d\n",printf("Magic %s is %d\n", "number", 42));
	ft_printf("%d\n",ft_printf("Hexadecimal for %d is %x\n", 42, 42));
	printf("%d\n",printf("Hexadecimal for %d is %x\n", 42, 42));
	ft_printf("%d\n",ft_printf("Merhaba, %s! Sayi: %d, Hex: %x\n", "Dunya", 42, 42));
    	printf("%d\n",printf("Merhaba, %s! Sayi: %d, Hex: %x\n", "Dunya", 42, 42));
    return 0;
}
//Rank 3'te geçiyor mu denemedim.
