#include <stdio.h>
#include <cmath>
#include <vector>
#include <chrono>

#include <nmmintrin.h> // SSE 4.2
#include <immintrin.h> // AVX

#define SIZE (2 * 2048)  // Taille des matrices (matrices carrées)
#define NB_THROW 10
//#pragma loop(no_vector)

//
// Version modifiée pour aider le compilateur à réaliser une vectorisation automatique
//
void matOpeAuto(const float*  matrixA, const float*  matrixB, float*  matrixOut, const int nrCols, const int nrRows)
{
	for (int i = 0; i < nrRows*nrCols; i++)
	{
		matrixOut[i] = 1.f/sqrt((matrixA[i] + matrixB[i]) / sqrt(matrixB[i]));
	}
}

void matrixInit(float *mat, int nb_cols, int nb_rows)
{
	int l, c;

	for (l = 0; l < nb_rows; l++)
		for (c = 0; c < nb_cols; c++)
			mat[l * nb_cols + c] = (float)((l + c) % 20 - 10) / 2.f;
}

//
// Main
//
int main()
{
    float* matrixA;
    float* matrixB;
    float* matrixOutStd;
    float* matrixOutSIMD;

    matrixA			= new float[SIZE * SIZE];
    matrixB			= new float[SIZE * SIZE];
    matrixOutStd	= new float[SIZE * SIZE];
	matrixOutSIMD	= new float[SIZE * SIZE];

    // Initialisation des données

    matrixInit(matrixA, SIZE, SIZE);
    matrixInit(matrixB, SIZE, SIZE);

	std::chrono::high_resolution_clock::time_point start, stop;
	std::chrono::duration<double, std::micro> total_time_std;

    //
    // Lancement du timer et des calculs
    //
	start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < NB_THROW; i++)
		matOpeAuto(matrixA, matrixB, matrixOutSIMD, SIZE, SIZE);

	stop = std::chrono::high_resolution_clock::now();
	total_time_std = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	printf("Compute matrix (std): %.3f microsec\n", total_time_std.count() / (double)NB_THROW);

    return 0;
}

