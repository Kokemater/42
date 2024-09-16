int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\n' || base[i] == '\f' || base[i] == '\r'
			|| base[i] == '\t' || base[i] == '\v' || base[i] == ' ')
			return (-1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (-1);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (-1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	calculate_and_print(int nbr, int *digit, char *base, int nbase)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		if (nbr > 0)
			digit[i] = base[nbr % nbase];
		else
			digit[i] = base[(nbr % nbase) * -1];
		nbr = nbr / nbase;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &digit[i], 1);
		i--;
	}
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int	nbase;
	int	i;
	int	digit[100];

	i = 0;
	while (i < 100)
		digit[i++] = 0;
	if (check_base(base) == -1 || nbr == 0)
	{
		if (nbr == 0)
			return ("0");
	}
	nbase = ft_strlen(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
	}
	calculate_and_print(nbr, digit, base, nbase);
}




int	val_2dec(char letter, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == letter)
			return (i);
		i++;
	}
	return (0);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\n' || base[i] == '\f' || base[i] == '\r'
			|| base[i] == '\t' || base[i] == '\v' || base[i] == ' ')
			return (-1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (-1);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (-1);
	return (0);
}

int	is_in_the_base(char letter, char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == letter)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i] != 0)
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	num;
	int	sign;
	int	i;
	int	nbase;

	i = 0;
	num = 0;
	sign = 1;
	if (check_base(base) == -1)
		return (0);
	nbase = ft_strlen(base);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] != '\0') && is_in_the_base(str[i], base))
		num = num * nbase + val_2dec(str[i++], base);
	if (sign == -1)
		num = num * -1;
	return (num);
}
char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int i;
	int dec_num;

	dec_num = ft_atoi_base(nbr, base_from);
	new_base_num = ft_putnbr_base(dec_num, base_to);
	return (new_base_num);
}

int main(void)
{
	printf("%s",ft_convert_base("123", "0123456789", "01"));
}