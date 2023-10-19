#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
	{
		i++;
	}
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	check_for_zero(int nb)
{
	if (nb == 0)
	{
		return ('0');
	}
	return (0);
}

void	ft_putnbr(int nb)
{
	int		size;
	char	num_to_write[12];

	size = ft_strlen(nb);
	num_to_write[0] = check_for_zero(nb);
	if (nb == -2147483648)
	{
		ft_putstr("-2");
		ft_putnbr(147483648);
		return ;
	}
	if (nb < 0)
	{
		num_to_write[0] = '-';
		nb *= -1;
	}
	num_to_write[size] = 0;
	while (nb != 0)
	{
		size--;
		num_to_write[size] = (nb % 10) + '0';
		nb /= 10;
	}
	ft_putstr(num_to_write);
}
/*
int	main(void)
{
	ft_putnbr(2147483647);
}*/
