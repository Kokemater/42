/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:05:08 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/10 13:02:27 by jbutragu         ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	last_index;

	last_index = num_chars(dest);
	i = 0;
	while (src[i] != '\0' && i < nb)
	{
		dest[last_index + i] = src[i];
		i++;
	}
	dest[last_index + i] = '\0';
	return (dest);
}

/*
#include <string.h>
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
			s1[i] = rand() % 256;
			s2[i] = rand() % 256;
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
		ft_strncat(s1, s2, a);
		strncat(s1_cp, s2_cp, a);
		printf("%s, %s, (a= %d)", s1, s2,a);
		printf("\n------------------------------\n \n \n");

		if (strcmp(s1, s1_cp) != 0)
		{	

		printf("\n \n \n ***********************************\n ");
		printf("[YO] %s != %s [BOT] \n a= %d", s1, s1_cp, a);
		printf("\n****************************************\n \n \n");
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
}
*/
