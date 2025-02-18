#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main() {
    // Posición de la cámara, el objetivo y el vector Up
    float camera[3] = {0, 0, 5};
    float target[3] = {0, 0, 0};
    float up[3] = {0, 1, 0};

    // Crear la matriz de vista
    float *view_matrix = create_view_matrix(camera, target, up);
    if (!view_matrix) {
        printf("Error al crear la matriz de vista.\n");
        return -1;
    }

    // Definir un punto 3D
    float point[4] = {1, 1, 1, 1};  // x, y, z, w

    apply_isometric_projection(view_matrix, point);
    convert_to_screen_coordinates(point, 800, 600);

    // Liberar memoria
    free(view_matrix);

    return 0;
}
