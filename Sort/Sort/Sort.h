#pragma once
#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include "Stack.h"

void PrintArray(int* a, int n);

//÷±Ω”≤Â»Î≈≈–Ú
void InsertSort(int* a, int n);

//œ£∂˚≈≈–Ú
void ShellSort(int* a, int n);

//÷±Ω”—°‘Ò≈≈–Ú
void SelectSort(int* a, int n);

//∂—≈≈–Ú
void HeapSort(int* a, int n);

//√∞≈›≈≈–Ú
void BubbleSort(int* a, int n);

//øÏÀŸ≈≈–Ú
void QuickSort(int* a, int left, int right);

