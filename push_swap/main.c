#include "push_swap.h"
#include <stdio.h>



int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = create_list(argc, argv);
	if (!a)
		return (1);
	printf("------ before ------- \n");
	print_list(a, b);
	printf("---------------------\n");
	
	//order_list(&a);
	ra(&a);

	printf("------ after ------- \n");
	print_list(a, b);
	printf("---------------------\n");

	ft_lstclear(&a);
	ft_lstclear(&b);
}