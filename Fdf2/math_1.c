#include "fdf.h"

void	subtract_vectors(const float *a, const float *b, float *result)
{
	result[0] = a[0] - b[0];
	result[1] = a[1] - b[1];
	result[2] = a[2] - b[2];
}

void	normalize(float *v)
{
	float	length;

	length = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	v[0] /= length;
	v[1] /= length;
	v[2] /= length;
}

void	cross_product(const float *a, const float *b, float *result)
{
	result[0] = a[1] * b[2] - a[2] * b[1];
	result[1] = a[2] * b[0] - a[0] * b[2];
	result[2] = a[0] * b[1] - a[1] * b[0];
}

float	*create_view_matrix(const float *camera, const float *target,
		const float *up)
{
	float	*view_matrix;
	float	x[3], y[3], z[3];

	view_matrix = (float *)calloc(16, sizeof(float));
	if (!view_matrix)
		return (NULL);
	// Calculando el eje Z (dirección de la vista)
	subtract_vectors(camera, target, z);
	normalize(z);
	// Calculando el eje X (derecha)
	cross_product(up, z, x);
	normalize(x);
	// Calculando el eje Y (arriba corregido)
	cross_product(z, x, y);
	normalize(y);
	// Construcción de la matriz de vista
	view_matrix[0] = x[0];
	view_matrix[1] = y[0];
	view_matrix[2] = z[0];
	view_matrix[3] = 0;
	view_matrix[4] = x[1];
	view_matrix[5] = y[1];
	view_matrix[6] = z[1];
	view_matrix[7] = 0;
	view_matrix[8] = x[2];
	view_matrix[9] = y[2];
	view_matrix[10] = z[2];
	view_matrix[11] = 0;
	// Traslación en la matriz de vista
	view_matrix[12] = -(x[0] * camera[0] + x[1] * camera[1] + x[2] * camera[2]);
	view_matrix[13] = -(y[0] * camera[0] + y[1] * camera[1] + y[2] * camera[2]);
	view_matrix[14] = -(z[0] * camera[0] + z[1] * camera[1] + z[2] * camera[2]);
	view_matrix[15] = 1;
	return (view_matrix);
}

// Multiplicación de una matriz 4x4 con un vector 4D
void	multiply_matrix_vector(const float *matrix, const float *point,
		float *result)
{
	for (int i = 0; i < 4; i++)
	{
		result[i] = 0;
		for (int j = 0; j < 4; j++)
		{
			result[i] += matrix[i * 4 + j] * point[j];
		}
	}
}

// Aplicar la proyección isométrica
void	apply_isometric_projection(const float *view_matrix, float *point)
{
	float	projection_matrix[16] = {sqrt(2) / 2, sqrt(6) / 6, 0, 0, 0, sqrt(6)
			/ 3, 0, 0, -sqrt(2) / 2, sqrt(6) / 6, 0, 0, 0, 0, 0, 1};
	float	temp[4];

	// Aplicar la matriz de vista al punto
	multiply_matrix_vector(view_matrix, point, temp);
	// Aplicar la proyección isométrica
	for (int i = 0; i < 4; ++i)
	{
		point[i] = 0;
		for (int j = 0; j < 4; ++j)
		{
			point[i] += projection_matrix[i * 4 + j] * temp[j];
		}
	}
	// Normalizar si w != 1
	if (point[3] != 0.0f)
	{
		for (int i = 0; i < 3; i++)
		{
			point[i] /= point[3];
		}
		point[3] = 1.0f;
	}
}

// Convertir a coordenadas de pantalla
void	convert_to_screen_coordinates(float *point, int width, int height)
{
	float	scale;

	scale = 100;
	point[0] = scale * point[0] + width / 2;
	point[1] = height / 2 - scale * point[1];
	printf("Coordenadas en pantalla: (%.2f, %.2f)\n", point[0], point[1]);
}

float	*create_ortho_projection_matrix(const float left_right[2],
		const float bottom_top[2], const float near_far[2])
{
	float *matrix = (float *)calloc(16, sizeof(float));
	if (!matrix)
		return (NULL);

	float l = left_right[0], r = left_right[1];
	float b = bottom_top[0], t = bottom_top[1];
	float n = near_far[0], f = near_far[1];

	matrix[0] = 2.0f / (r - l);
	matrix[5] = 2.0f / (t - b);
	matrix[10] = -2.0f / (f - n);
	matrix[12] = -(r + l) / (r - l);
	matrix[13] = -(t + b) / (t - b);
	matrix[14] = -(f + n) / (f - n);
	matrix[15] = 1.0f;

	return (matrix);
}