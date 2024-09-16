/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_english.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvera-ve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:40:32 by jvera-ve          #+#    #+#             */
/*   Updated: 2024/07/20 12:03:14 by jvera-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush.h"

int	check_input(char *str)
{
	int	i;
	int	res;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 9 || str[i] > 13)
			&& str[i] != ' '
			&& str[i] != '+'
			&& (str[i] < '0' || str[i] > '9'))
			return (-1);
		i++;
	}
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+')
		i++;

	while(str[i] == '0')
		i++;
	res = i;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i == res)
		return (-1);
	return (res);
}

int	nbr_size(char *str, int index)
{
	int	tam;

	tam = 0;
	while (str[index] && str[index] >= '0' && str[index] <= '9')
	{
		index++;
		tam++;
	}
	return (tam);
}

int	check_teen(char *str)
{
	if (str[0] == '1' && str[1] >= '0' && str[1] <= '9')
		return (1);
	return (0);
}

void	less_than_99(char *str, int tam)
{
	char	*aux;
	aux = (char *)malloc(sizeof(char) * tam + 1);

	char t = tam + '0';
	if (!aux)
	{
		print_error();
		return ;
	}
	if (check_teen(str))
		ft_putstr(check_into_dict(str, 1));
	else if (tam == 2)
	{

		aux[0] = str[0];
		aux[1] = '0';
		if (aux[0] != '0')
			ft_putstr(check_into_dict(aux,2));

		free(aux);
		if (str[1] != '0')
		{
			write(1, " ", 1);
			ft_putstr(check_into_dict(&str[1], 1));
		}
	}
	else
		ft_putstr(check_into_dict(str, ALL));
}

void	print_3digits(char *str, int tam)
{
	while(tam > 0 && *str == '0')
	{
		tam--;
		str++;
	}
	if (tam == 0)
		return ;
	if (tam <= 2)
		less_than_99(str, tam);
	else
	{
		ft_putstr(check_into_dict(&str[0], 1));
		print_hundred();
		if (!(str[1] == '0' && str[2]== '0'))
			less_than_99(&str[1], 2);
	}
}


void	print_hundred(void)
{
	char	*aux;
	int	tam;

	tam = 3;
	write(1, " ", 1);
	aux = (char *) malloc(sizeof(char) * tam + 1);
	aux[0] = '1';
	aux[1] = '0';
	aux[2] = '0';
	ft_putstr(check_into_dict(aux, ALL));
	free(aux);
	write(1, " ", 1);
}

void	print_big_numbers(int tam)
{
	char	*aux;
	int i;
	if (tam < 3)
	 return ;
	i = 1;
	tam++;
	write(1, " ", 1);
	aux = (char *) malloc(sizeof(char) * tam + 1);
	aux[0] = '1';
	while (i <= tam)
	{
		aux[i] = '0';
		i++;
	}
		write(1, " ", 1);
	ft_putstr(check_into_dict(aux, tam));
	free(aux);

}
void	more_than_99(char *str, int tam)
{
	int	i;
	int	j;
	int k;
	char	*aux;
	int	n_numbers;
	int init_tam = tam;

	i = 0;
	j = 2;
	k = 3;
	if (tam == 3)
	{
		print_3digits(str,3);

	}
	if (tam > 3)
	{
		while (i < init_tam)
		{
			//printf("---%d- %d--", i, tam);
			n_numbers = (tam % 3);
			if (!n_numbers) n_numbers = 3;
			aux = (char *)malloc(sizeof(char) * 3 +1 );

			if (n_numbers == 1)
				{
					aux[0] = 0;
					aux[1] = 0;
					aux[2] = str[i];
				}
			if (n_numbers == 2)
				{
					aux[0] = 0;
					aux[1] = str[i];
					aux[2] = str[i + 1];
				}
			if (n_numbers == 3)
				{
					aux[0] = str[i];
					aux[1] = str[i + 1];
					aux[2] = str[i + 2];
				}

					print_3digits(aux,3);

//PROBLEMA: SÓLO IMPRIME BIEN PARA NUMEOS DE 3 EN 3
			//print_3digits(&str[i],n_numbers);
			i += n_numbers;
			tam -= n_numbers;
			print_big_numbers(tam);
			printf("\n");
			free(aux);
		}
	}
}



int	atoi_english(char *str)
{
	int		i;
	int		tam;
	int		initial_tam;

	i = check_input(str);
	if (i == -1)
	{
		print_error();
		return (-1);
	}
	tam = nbr_size(str, i);
	initial_tam = tam;
	if (tam <= 2)
		less_than_99(&str[i], tam);
	else
		more_than_99(&str[i], tam);
	return (0);
}
