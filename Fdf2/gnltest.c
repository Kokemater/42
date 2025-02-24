#include <stdio.h>
#include <math.h>

void normalize(float *v) {
    float length = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    if (length == 0.0f)  // Evitar división por cero
        return;
    v[0] /= length;
    v[1] /= length;
    v[2] /= length;
}

void cross_product(const float *a, const float *b, float *result) {
    result[0] = a[1] * b[2] - a[2] * b[1];
    result[1] = a[2] * b[0] - a[0] * b[2];
    result[2] = a[0] * b[1] - a[1] * b[0];
}

void look_at(const float *eye, const float *target, const float *up, float *view_matrix) {
    float z[3] = {eye[0] - target[0], eye[1] - target[1], eye[2] - target[2]};
    normalize(z);

    float x[3];
    cross_product(up, z, x);
    normalize(x);

    float y[3];
    cross_product(z, x, y);

    float translation[3] = {
        - (x[0] * eye[0] + x[1] * eye[1] + x[2] * eye[2]),
        - (y[0] * eye[0] + y[1] * eye[1] + y[2] * eye[2]),
        - (z[0] * eye[0] + z[1] * eye[1] + z[2] * eye[2])
    };

    view_matrix[0] = x[0]; view_matrix[1] = y[0]; view_matrix[2] = z[0]; view_matrix[3] = 0;
    view_matrix[4] = x[1]; view_matrix[5] = y[1]; view_matrix[6] = z[1]; view_matrix[7] = 0;
    view_matrix[8] = x[2]; view_matrix[9] = y[2]; view_matrix[10] = z[2]; view_matrix[11] = 0;
    view_matrix[12] = translation[0]; view_matrix[13] = translation[1]; view_matrix[14] = translation[2]; view_matrix[15] = 1;
}

void multiply_matrix_vector(const float *matrix, const float *point, float *result) {
    for (int i = 0; i < 4; i++) {
        result[i] = 0;
        for (int j = 0; j < 4; j++) {
            result[i] += matrix[i * 4 + j] * point[j];
        }
    }
}

void apply_isometric_projection(const float *view_matrix, float *point) {
    float transformed[4];
    multiply_matrix_vector(view_matrix, point, transformed);
    
    if (transformed[3] != 0.0f) {  
        for (int i = 0; i < 3; i++) {
            transformed[i] /= transformed[3];
        }
        transformed[3] = 1.0f;
    }

    point[0] = transformed[0];
    point[1] = transformed[1];
    point[2] = transformed[2];
}

int main() {
    float eye[] = {2.0f, 2.0f, 2.0f};
    float target[] = {0.0f, 0.0f, 0.0f};
    float up[] = {0.0f, 1.0f, 0.0f};
    float view_matrix[16];

    look_at(eye, target, up, view_matrix);

    printf("Matriz de vista:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%.2f ", view_matrix[i * 4 + j]);
        }
        printf("\n");
    }

    float point[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    
    printf("Antes de la proyección: (%.2f, %.2f, %.2f)\n", point[0], point[1], point[2]);
    
    apply_isometric_projection(view_matrix, point);
    
    printf("Después de la proyección: (%.2f, %.2f, %.2f)\n", point[0], point[1], point[2]);

    return 0;
}
