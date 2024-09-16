/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:59:55 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/10 16:53:47 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	coincidence;

	i = 0;
	j = 0;
	while (str[i] != '\0' || to_find[0] == '\0')
	{
		j = 0;
		coincidence = 1;
		while (to_find[j] != '\0' && str[i + j] != '\0')
		{
			if (str[i + j] != to_find[j])
			{
				coincidence = 0;
			}
			j++;
		}
		if (coincidence == 1 && to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char s1[20];
	s1[19] = 0;
	char s2[5];
	s2[4] = 0;

	while (1)
	{
		
		for (int i = 0; i < 19; i++)
			s1[i] = rand() % 256;
		for (int i = 0; i < 4; i++)
			s2[i] = rand() % 256; 
		int j = rand() % 30;
		for (int i = 0; i + j < 19 && i < 4; ++i)
			s1[i+j] = s2[i];
		
		// s1[5] = 6;
		// s2[3] = 5;
		// int a = rand() % 10;

		printf("\n \n \n--------------------------------- \n ");
		printf(" %s, %s\n", s1, s2);
		printf("%p, %p", ft_strstr(s1, s2), strstr(s1, s2));
		printf("\n------------------------------\n \n \n");

		if (strstr(s1,s2) != ft_strstr(s1,s2))
		{
			for (int i = 0; i < 19; ++i)
				printf("%i ", s1[i]);
			printf("\n");
			for (int i = 0; i < 4; ++i)
				printf("%i ", s2[i]);
			printf("\n");

			printf("\n \n \n *******************************\n ");
			printf("[YO] %s != %s [BOT] \n", ft_strstr(s1,s2), strstr(s1,s2));
			printf("\n************************************\n \n \n");
			break;
		}
	}
*/
