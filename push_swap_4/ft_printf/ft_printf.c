#include "ft_printf.h"
#include "Libft/libft.h"

#include <stdio.h>


static int print_element(char c, va_list args)
{   
	int len;

	len = 0;
	if (c =='c')
		len = put_char_with_return((char) va_arg(args, int));
	else if (c == 's')
		len = put_str_with_return(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
        len = put_number_with_return(va_arg(args, int));
	else if (c == 'p')
		len = put_pointer_with_return(va_arg(args, unsigned long long));
	else if (c == 'u')
		len += put_unsigned_with_return(va_arg(args, unsigned int));
	else if (c == 'x')
		len += put_num_to_hex_with_return(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		len += put_num_to_hex_with_return(va_arg(args, unsigned int), 1);
	else if (c == '%')
		len += ft_print_percent();
	return (len);
}

int ft_printf(const char *text, ...)
{
    va_list args;
    unsigned int i;
	unsigned int total_len;

	total_len = 0;
    i = 0;
	va_start(args, text);
    while(text[i])
    { 
        if (text[i] == '%' && text[i+1])
            total_len += print_element(text[++i],args);
		else
			total_len += write(1,&text[i],1);
        i++;
    }

	va_end(args);
    return (total_len);
}
