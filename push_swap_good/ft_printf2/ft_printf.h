/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:57:28 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/04 08:57:39 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *text, ...);
int	put_num_to_hex_with_return(unsigned long long n, int upper);
int	put_pointer_with_return(unsigned long long n);
int	put_char_with_return(char c);
int	ft_print_percent(void);
int	put_str_with_return(char *s);
int	put_number_with_return(int n);
int	put_unsigned_with_return(unsigned int n);
#endif