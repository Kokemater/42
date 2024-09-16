/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:22:44 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/10 14:14:41 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char) s1[i] - (unsigned char) s2[i] != 0)
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
        char s1[6];
        char s2[6];

        while (1)
        {
                for (int i = 0; i < 5; i++)
                {
                        s1[i] = rand() % 256;
                        s2[i] = rand() % 256;
                }
                s1[5] = '\0';
                s2[5] = '\0';
                int a = rand() % 10;
 printf("%d == %d \n %s \n %s)\n",ft_strcmp(s1, s2), strcmp(s1, s2), s1, s2);

                if (ft_strcmp(s1, s2) != strcmp(s1, s2))
                {
                        for (int i = 0; i< 5; i++)
                        {
                                printf("%d + ", s1[i]);
                        }
                        printf("\n");
                        for (int i = 0; i< 5; i++)
                        {
                                printf("%d + ", s2[i]);
                        }
                        printf("\n");
                        break;
                }
        }

}
*/
