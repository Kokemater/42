#include "Libft/libft.h"

int	put_number_with_return(int n)
{
	int		len;
	char	*num;

	num = ft_itoa(n);
	ft_putstr_fd(num, 1);
	len = ft_strlen(num);
	free(num);
	return (len);
}

int	put_unsigned_with_return(unsigned int n)
{
	int		len;
	char	*num;

	num = ft_itoa(n);
	ft_putstr_fd(num, 1);
	len = ft_strlen(num);
	free(num);
	return (len);
}