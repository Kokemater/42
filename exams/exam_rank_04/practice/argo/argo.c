#include "argo.h"
#include <stdlib.h>  // malloc, realloc, free

/* ---------- PARTIE FOURNIE PAR L’EXAMEN (argo.c initial) ---------- */

int	peek(FILE *stream)
{
	int	c = getc(stream);
	ungetc(c, stream);
	return c;
}

void	unexpected(FILE *stream)
{
	if (peek(stream) != EOF)
		printf("unexpected token '%c'\n", peek(stream));
	else
		printf("unexpected end of input\n");
}

int	accept(FILE *stream, char c)
{
	if (peek(stream) == c)
	{
		(void)getc(stream);
		return 1;
	}
	return 0;
}

int	expect(FILE *stream, char c)
{
	if (accept(stream, c))
		return 1;
	unexpected(stream);
	return 0;
}


static int	parse_value(json *dst, FILE *stream);
static int	parse_integer(json *dst, FILE *stream);
static int	parse_string(json *dst, FILE *stream);
static int	parse_map(json *dst, FILE *stream);


int	argo(json *dst, FILE *stream)
{
	if (parse_value(dst, stream) == -1)
		return -1;
	if (peek(stream) != EOF)
	{
		unexpected(stream);
		free_json(*dst);     /* <-- appelle la version de main.c */
		return -1;
	}
	return 1;
}

static int	parse_value(json *dst, FILE *stream)
{
	int	c = peek(stream);
	printf(">%c\n",c);
	if (c == '"')
		return parse_string(dst, stream);
	if (c == '{')
		return parse_map(dst, stream);
	if (c == '-' || isdigit(c))
		return parse_integer(dst, stream);

	unexpected(stream);
	return -1;
}

static int	parse_integer(json *dst, FILE *stream)
{
	long result = 0;
	int i = 0;
	int c;
	int sign = 1;
	c = peek(stream);
	if (c == '-')
	{
		getc(stream);
		sign = -1;
		c = peek(stream);
		if (!isdigit(c))
		{
			return (-1);
		}
	}
	while(isdigit(c))
	{
		result *= 10;
		result += c - '0';
		getc(stream);
		c = peek(stream);
	}
	result *= sign;
	dst->type = INTEGER;
	dst->integer = result;
	return (1);
}

static int	parse_string(json *dst, FILE *stream)
{
	size_t cap = 16;
	int i = 0;
	char *ret = malloc(sizeof(char) * cap);
	getc(stream);
	int c = peek(stream);
	while(c != '"' && c != EOF)
	{
		if (c == '\\')
		{
			getc(stream);
			c = peek(stream);
			if (c != '"' && c != '\\')
			{
				free(ret);
				return (-1);
			}
		}
		if (i + 1 >= cap)
		{
			cap *= 2;
			ret = realloc(ret, sizeof(char) * cap);
		}
		ret[i] = c;
		i++;
		getc(stream);
		c = peek(stream);
	}
	if (c != '"')
	{
		free(ret);
		return(-1);
	}
	getc(stream);
	ret[i] = 0;
	dst->type = STRING;
	dst->string = ret;
	return (1);
}

static int	parse_map(json *dst, FILE *stream)
{
	int cap = 4;
	int i = 0;
	pair *arr = malloc(sizeof(pair) * cap);
	json tmp_val, tmp_key;
	getc(stream);
	while (1)
	{
		if (parse_string(&tmp_key, stream) == -1)
			return (-1);
		if (!expect(stream, ':'))
		{
			free(tmp_key.string);
			return -1;
		}		if ((parse_value(&tmp_val, stream)) == -1)
			return (-1);
		if (i +1 >= cap)
		{
			cap *=2;
			arr = realloc(arr, sizeof(pair) * cap); 
		}
		arr[i].key = tmp_key.string;
		arr[i].value = tmp_val;
		i++;
		if (peek(stream) == ',')
			continue;
		break;
	}
	if (!accept(stream, '}'))
		return (-1);
	dst->type = MAP;
	dst->map.size = i;
	dst->map.data = arr;
	return (1);
}