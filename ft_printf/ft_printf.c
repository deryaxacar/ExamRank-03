#include <stdarg.h>
#include <unistd.h>
//#include <stdio.h>

int      ft_putstr(char *str)
{
          int count = 0;
          if(!str) str = "(null)";
          while(*str) count += write(1, str++, 1);
          return count;
}

int       ft_putnbr(long num, int base)
{
          int count = 0;
          if(num < 0)
          {
                    num *= -1;
                    count += write(1, "-", 1);
          }
          else if(num > (base - 1))
                    count += ft_putnbr(num / base, base);
          count += write(1, &"0123456789abcdef"[num % base], 1);
          return count;
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
                                        count += ft_putstr(va_arg(ptr, char *));
                              else if(*format == 'd')
                                        count += ft_putnbr(va_arg(ptr, int), 10);
                              else if(*format == 'x')
                                        count += ft_putnbr(va_arg(ptr, unsigned int), 16);
                    }
                    else
                              count += write(1, format, 1);
                    format++;
          }
          return(va_end(ptr), count);
}

int main()
{
	//ft_printf("%s\n", "toto");
	//printf("%s\n", "toto");
	//ft_printf("Magic %s is %d\n", "number", 42);
	//printf("Magic %s is %d\n", "number", 42);
	//ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	//printf("Hexadecimal for %d is %x\n", 42, 42);
	ft_printf("Merhaba, %s! Sayi: %d, Hex: %x\n", "Dunya", 42, 42);
    return 0;
}
//Rank 3'te geçmiyor
