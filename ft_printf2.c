#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	g_num = 0;

void	ft_putnbr(int num, int len, char *arr)
{
	if (num >= len)
		ft_putnbr(num/len, len, arr);
	g_num++;
	write(1, &arr[num % len], 1);
}

void	ft_puthex(unsigned int x, unsigned int len, char *arr)
{
	if (x >= len)
		ft_puthex(x/len, len, arr);
	write(1, &arr[x%len], 1);
	g_num++;
}

int	ft_printf(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);

	g_num = 0;
	int	i = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
			{
				char *arr = va_arg(ap, char *);
				int k = 0;
				while (arr[k])
					k++;
				write(1, arr, k);
				g_num += k;
			}
			if (str[i] == 'd')
			{
				int d = va_arg(ap, int);
				if (d < 0)
				{
					write(1, "-", 1);
					d = -d;
					g_num++;
				}
				ft_putnbr(d, 10, "0123456789");
			}
			if (str[i] == 'x')
			{
				int x = va_arg(ap, int);
				ft_puthex(x, 16, "0123456789abcdef");
			}
		}
		else
		{
			write(1, &str[i], 1);
			g_num++;
		}
		i++;
	}
	return (g_num);
}

int	main(void)
{
	printf("I - %d\n", printf("qwerty %s\t%d\t%x\n", "stroka1", 2147148145, -42));
	printf("II - %d\n", ft_printf("qwerty %s\t%d\t%x\n", "stroka2", 2147148145, -42));
}