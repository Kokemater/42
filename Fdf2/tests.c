#include <stdlib.h>
#include <stdio.h>

void append_point(int ***points, int *new_point, int *size)
{
    int **new_array;
    int i;

    new_array = malloc((*size + 1) * sizeof(int *));
    if (!new_array)
        return;
    for (i = 0; i < *size; i++)
        new_array[i] = (*points)[i];

    new_array[*size] = new_point;
    free(*points);
    *points = new_array;
    (*size)++;
}

void print_points(int **points, int n_points)
{
    for (int i = 0; i < n_points; i++)
    {
        printf("( %d, %d, %d )\n", points[i][0], points[i][1], points[i][2]);
    }
}

int main()
{
    int **points = NULL;
    int size = 0;
    
    int *p1 = malloc(3 * sizeof(int));
    p1[0] = 1; p1[1] = 2; p1[2] = 3;
    append_point(&points, p1, &size);
    p1[0] = 1; p1[1] = 2; p1[2] = 3;
    append_point(&points, p1, &size);
	p1[0] = 1; p1[1] = 2; p1[2] = 3;
    append_point(&points, p1, &size);

    print_points(points, size);

    // Liberar memoria
    for (int i = 0; i < 1; i++)
        free(points[i]);
    free(points);

    return 0;
}
