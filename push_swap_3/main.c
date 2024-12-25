#include "push_swap.h"
#include <stdio.h>



int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = create_list(argc, argv);
	if (!a)
		return (1);
	b = NULL;

	//printf("------ before ------- \n");
	 //print_list(a, b);
	
	order_list(&a, &b);


	//printf("------ after ------- \n");
	//print_list(a, b);
	char *str = ft_itoa_binary_len(3,4);
	////printf("number : %s", str);
	free(str);
	ft_lstclear(&a);
	ft_lstclear(&b);
	}