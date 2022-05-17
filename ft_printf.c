#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	g_var = 0;

void	ft_putnbr(int num, int len, char *sign)
{
	if (num >= len)
		ft_putnbr(num/len, len, sign);
	write(1, &sign[num % len], 1);
	g_var++;
}

void ft_puthex(unsigned dig, unsigned len, char *sign) //len для  %d == 16 / unsigned для сравнения с deg
{
 if (dig >= len)
  ft_puthex(dig/len, len, sign);
 write(1, &sign[dig % len], 1);
 g_var++;
}

int	ft_printf(const char *format, ...)
{
	g_var = 0;
	va_list ap;
	va_start(ap, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				int len = 0;
				char *str = va_arg(ap, char *);
				if (!str)
					str = "(null)";
				while (str[len])
					len++;
				g_var += len;
				write(1, str, len);
			}
			else if (*format == 'd')
			{
				long long num = va_arg(ap, int);
				if (num < 0)
				{
					write(1, "-", 1);
					g_var++;
					num *= -1;
				}
				ft_putnbr(num, 10, "0123456789");
			}
			else if (*format == 'x')
			{
				int hex = va_arg(ap, int);
				ft_puthex(hex, 16, "0123456789abcdef");
			}
			format++;
		}
		else
			g_var += write(1, format++, 1);
	}
	va_end(ap);
	return (g_var);
}

int	main(void)
{
	printf("I - %d\n", printf("qwerty %s\t%d\t%x\n", "stroka1", 2147148145, -42));
	printf("II - %d\n", ft_printf("qwerty %s\t%d\t%x\n", "stroka2", 2147148145, -42));
	return 0;
}