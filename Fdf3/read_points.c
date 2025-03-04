#include "fdf.h"

t_list *read_arguments(int argc, char **argv, int *size) {
    int fd;
    int i = 0;

    if (argc != 2)
        return NULL;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return NULL;
    }
    return create_points(fd, size, i);
}

void imprimir_nodos(t_list *head) {
    t_list *nodo = head;
    while (nodo) {
        if (!nodo->content)
            return;

        float *valores = (float *)nodo->content;
        printf("Valores: [%.2f, %.2f, %.2f, %.2f, %.2f]\n", 
               valores[0], valores[1], valores[2], valores[3], valores[4]);
        nodo = nodo->next;
    }
}

int main(int argc, char **argv) {
    int size;
    t_list *world_points;

    world_points = read_arguments(argc, argv, &size);
    if (!world_points)
        return 1;

    imprimir_nodos(world_points);

    ft_lstclear(&world_points, free);
    return 0;
}
