#include <stdio.h>
#include <stdlib.h>

#ifndef SIZE
#define SIZE 500
#endif

int randint(int min, int max) 
{
    return min + rand() % (max - min + 1);
}

int	*create_list(void)
{
	int *numbers;

	numbers = malloc(sizeof(int) * (500 + 1));
	numbers[SIZE] = 0;
	for (int i = 0; i < SIZE; i++)
	{
		numbers[i] = i;
	}
	return numbers;
}

void pick_from_list(int **list, int *numbers_left)
{
	int election = randint(0, *numbers_left-1);

	printf("%d ", (*list)[election]);

	for (int i = election; i < *numbers_left-1; i++)
	{
		(*list)[i] = (*list)[i+1];
	}
	(*numbers_left)--;
}


int main(void)
{
	srand(42);
	int	*list = create_list();
	int numbers_left = SIZE;

	while(numbers_left > 0)
	{
		pick_from_list(&list, &numbers_left);
	}
	free(list);

	return 0;
}