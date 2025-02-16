#include "ft_printf.h"
#include "Libft/libft.h"

int	put_char_with_return(char c)
{
    return (write(1,&c,1));
}
int	ft_print_percent(void)
{
	return (write(1,"%%",1));
}

int	put_str_with_return(char *s)
{
	int	len;
	if (!s)
		return (write(1, "(null)", 6));
	len = ft_strlen(s);
	ft_putstr_fd(s,1);
	return (len);
}
