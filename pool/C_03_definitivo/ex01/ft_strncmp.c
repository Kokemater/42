/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:09:23 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/10 14:11:37 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n <= 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n -1)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
/*
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
		
		s1[5] = '\0';
		s2[5] = '\0';
		}
		int a = rand() % 10;

		printf("\n \n \n ---------------------------------\n ");

		printf("---------------------------------------\n \n \n");
		if (ft_strncmp(s1, s2, a) != strncmp(s1, s2,a))
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

}*/
