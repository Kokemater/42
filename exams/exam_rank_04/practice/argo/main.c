#include "argo.h"


void free_json(json j)
{
	if (j.type == STRING)
	{
		free(j.string);
	}
	else if (j.type == MAP)
	{
		for (int i = 0; i < j.map.size; i++)
		{
			free(j.map.data[i].key);
			free_json(j.map.data[i].value);
		}
	}
}

void print_json(json j)
{
	if (j.type == STRING)
	{
		printf("\"%s\"", j.string);
	}
	else if (j.type == INTEGER)
	{
		printf("%d", j.integer);
	}
	else if (j.type == MAP)
	{
		printf("{");
		for (int i = 0; i < j.map.size; i++)
		{
			print_json((json){.type =STRING, .string=j.map.data[i].key});
			printf(":");
			print_json(j.map.data[i].value);
			if (i +1 < j.map.size)
				printf(",");
		}
		printf("}");
	}
}


int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	FILE *stream = fopen(argv[1], "r");
	json j;
	if (argo(&j, stream) == -1)
	{
		free_json(j);
		return (1);
	}
	print_json(j);
	free_json(j);
	return (0);
}