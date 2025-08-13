#include <stdio.h>
#include <ctype.h>

typedef enum
{
	NUM,
	ADD,
	MUL,
	L_PAR,
	R_PAR,
	END,
	ERR
} token_type;


typedef struct s_token
{
	token_type type;
	int	val;
} t_token;

t_token current;
char *operation;

int next_token()
{
	while (*operation == ' ')
		operation++;
	if (isdigit(*operation))
	{
		current.type = NUM;
		current.val = *operation - '0';
		operation++;
		if (isdigit(*operation))
		{
			printf("ERR: nums must contain 1 digit only\n");
			return (0);
		}
	}
	else if (*operation == '(')
	{
		current.type = L_PAR;
		operation++;
	}
	else if (*operation == ')')
	{
		current.type = R_PAR;
		operation++;
	}
	else if (*operation == '\0')
	{
		current.type = END;
		operation++;
	}
	else if (*operation == '+')
	{
		current.type = ADD;
		operation++;
	}
	else if (*operation == '*')
	{
		current.type = MUL;
		operation++;
	}
	else
	{
		printf("ERR: Unexpected token '%c'\n", *operation);
		return (0);
	}
	return (1);
}

void print_token()
{
	printf("[type: %d]\n", current.type);
}
int apply_operation(int left, token_type operation);
int parse_operation(int lbp);

int get_number()
{
	int ret = -1;

	if (current.type == NUM)
	{
		ret = current.val;
		next_token();
	}
	else if (current.type == L_PAR)
	{
		next_token();
		ret = parse_operation(0);
		if (current.type != R_PAR)
		{
			printf("ERR: Unclosed parenthesis ");
			return(-1);
		}
		next_token();
	}
	return (ret);
}

int binding_power(token_type type)
{
	if (type == ADD)
		return (10);
	else if (type == MUL)
		return (20);
	return (0);
}


int apply_operation(int left, token_type operation)
{
	int right = parse_operation(binding_power(operation));
	if (operation == ADD)
		return (left + right);
	else if (operation == MUL)
		return (left*right);
	return (-1);
}

int parse_operation(int lbp)
{
	int left = get_number();
	if (left == -1)
		return (-1);
	int rbp = binding_power(current.type);
	while(rbp > lbp)
	{
		token_type operation = current.type;
		next_token();
		left = apply_operation(left, operation);
		if (left < 0)
			return (-1);
		rbp = binding_power(current.type);
	}
	return (left);
}

int main(void)
{
	operation = "(9+9*2";
	char *operation_cpy = operation;
	if (!next_token())
		return (1);
	print_token();
	while (current.type != END)
	{
		if (!next_token())
			return (1);
		print_token();
	}
	operation = operation_cpy;
	next_token();
	int result = parse_operation(0);
	if (result <0)
		return (1);

	printf("RESULT: %d \n ", result);
	return (0);
}