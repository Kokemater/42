#include "push_swap.h"
#include <stdio.h>



int main(int argc, char **argv)
{
	t_list	*head;

	head = create_list(argc, argv);
	if (!head)
		return (1);
	print_list(head);
}