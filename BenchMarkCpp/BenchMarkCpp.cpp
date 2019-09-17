#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <chrono>
#include "BenchMarkCpp.h"
#include <ctime>

using namespace std;

void MatrixMultiplication(int size) {

	int i, j, k;
	int matrix[MAX_SIZE][MAX_SIZE] = { 0 };
	int resultantMatrix[MAX_SIZE][MAX_SIZE] = { 0 };

	PopulateMatrix(size, matrix);
	// PrintMatrix(size, matrix);
	
	// Multiplication
	auto wcts = std::chrono::system_clock::now();
	
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			for (k = 0; k < size; k++) {
				resultantMatrix[i][j] += matrix[i][k] * matrix[k][j];
			}
		}
	}

	std::chrono::duration<double> wctduration = (std::chrono::system_clock::now() - wcts);
	std::cout << "Time for matrix of int of size " << size << " " << (wctduration.count()) << " ms" << std::endl;
}

void PopulateMatrix(int size, int  matriz[MAX_SIZE][MAX_SIZE])
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matriz[i][j] = rand() % 10;
		}
	}
}

void PrintMatrix(int size, int  matriz[MAX_SIZE][MAX_SIZE])
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matriz[i][j];
			cout << " ";
		}
		cout << "\n";
	}
}


int main() 
{	
	for (size_t i = 50; i <= MAX_SIZE; i += 50)
	{
		MatrixMultiplication(i);
	}
}
