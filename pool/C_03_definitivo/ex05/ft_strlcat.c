/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:57:20 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/10 13:00:42 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	num_chars(char *word)
{
	unsigned int	i;

	i = 0;
	while (word[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	last_index;
	unsigned int	initial_l_src;

	i = 0;
	initial_l_src = num_chars(src);
	last_index = num_chars(dest);
	if (size <= last_index)
		return (initial_l_src + size);
	while (src[i] != '\0' && last_index + i < size -1)
	{
		dest[last_index + i] = src[i];
		i++;
	}
	dest[i + last_index] = '\0';
	return (initial_l_src + last_index);
}
/*
#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char s1[16];
	char s2[6];
	char s1_cp[16];
	char s2_cp[6];
	while (1)
	{
		
		for (int i = 0; i < 5; i++)
		{
			s1[i] = rand() % ('~' -' ') + ' ';
			s2[i] = rand() % ('~' -' ') + ' ';
			s1_cp[i] = s1[i];
			s2_cp[i] = s2[i];
		}
		s1[5] = '\0';
		s2[5] = '\0';
		s1_cp[5] = '\0';
		s2_cp[5] = '\0';
		int a = rand() % 10;

		printf("\n \n \n--------------------------------- \n ");
		printf(" %s, %s, (a= %d) \n", s1, s2,a);
		int mine = ft_strlcat(s1, s2, a);
		int bot = strlcat(s1_cp, s2_cp, a);
		printf("%s, %s, (a= %d)", s1, s2,a);
		printf("\n------------------------------\n \n \n");

		if (strcmp(s1, s1_cp) != 0 || mine != bot)
		{	
		printf("\n \n \n*******************************\n ");
		printf("[YO] %s != %s [BOT] \n a= %d", s1, s1_cp, a);
		printf("[YO] %d != %d [BOT] \n (a= %d)", mine, bot, a);
		printf("\n************************************\n \n \n");
			for (int i = 0; i < 16; i++)
			{
				printf("%d + ", s1[i]);
			}
			printf("\n");
                        for (int i = 0; i< 16; i++)
                        {
                                printf("%d + ", s1_cp[i]);
                        }
			printf("\n");
			break;
		}
	}
}*/
