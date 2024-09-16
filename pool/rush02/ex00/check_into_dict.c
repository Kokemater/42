#include "rush.h"

char	*dict_to_string(const char *dict)
{
	int		fd;
	int		numbytes;
	char	*buffer;

       	buffer = (char *) malloc(sizeof(char) * N);
	if (!buffer)
	{
		print_error();
		return (NULL);
	}
	fd = open(dict, O_RDONLY);
	if (fd == -1) {
		print_error();
		free(buffer);
		return (NULL);
	}
	numbytes = read(fd, buffer, N - 1);
	if (numbytes > 0)
		buffer[numbytes] = '\0';
	else
	{
		print_error();
		free(buffer);
		close(fd);
		return NULL;
	}
	close(fd);
	return buffer;
}

num_node*	create_node(void)
{
	int	ceros;

	num_node *new_node;
	new_node = (num_node *) malloc(sizeof(num_node)+ 1);
	if (!new_node) 
		return (NULL);
	new_node->key = (char *) malloc(sizeof(char) * 37 + 1);
	if (!(new_node->key)) 
		return (NULL);
	new_node->value = (char *) malloc(sizeof(char) * 11 + 1);
	if (!(new_node->value)) 
		return (NULL);
	ceros = 0;
	while(ceros < 37 )
		new_node->key[ceros++] = 0;
	ceros = 0;
	while(ceros < 11)
		new_node->value[ceros++] = 0;
	return (new_node);
}

num_node	**create_array_of_structs(const char *dict) 
{
	int	i;
	int	index_arr;
	int	index_num;
	int	write_key;
	char	*dict_str = dict_to_string(dict);

	num_node *new_node = 0;
	num_node **array = (num_node **) malloc(sizeof(num_node *) * DICT_SIZE + 1);
	i = 0;
	index_arr = 0;
	if (!array) return (NULL);
	if (!dict_str) return (NULL);
	while (dict_str[i] != '\0')
	{
		if (dict_str[i] == ' ')
			i++;
		else if (dict_str[i] == '\n' || (i == 0 && dict_str[0] != ' ')) 
		{
			if (new_node)
				new_node->value[index_num] = '\0';
			new_node = create_node();
			index_num = 0;
			write_key = TRUE;
			i++; 
			array[index_arr++] = new_node;
		}
		else if (dict_str[i] == ':') 
		{
			new_node->key[index_num] = '\0';  
			index_num = 0;
			write_key = FALSE;
			i++;
		}
		else
		{
			if (write_key == TRUE)
				new_node->key[index_num++] = dict_str[i];
			else
				new_node->value[index_num++] = dict_str[i];
			i++;
		}  
	}
	new_node->value[index_num] = '\0';  // Terminar el último valor
	free(dict_str);
	return (array);
}

char	*check_into_dict(char *num, int n)
{
	int	i;

	i = 0;
	num_node **array = create_array_of_structs(DICT_FILE);

	if (!array) {
		print_error();
		return (NULL);
	}
	while (i < DICT_SIZE )
	{
		if (ft_strncmp(array[i]->key, num, n) == 0) 
			return (array[i] -> value);
		i++;
	}
	i = 0;
	return (NULL);
}
