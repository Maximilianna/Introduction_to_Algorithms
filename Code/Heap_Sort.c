#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//ππΩ®∂—
void Build_max_heap(int* arr, int i, int s)
{
	int c, temp;
	if (i == 0)
		c = 1;
	else
		c = 2 * i + 1;
	temp = arr[i];
	if (c + 1 <= s && arr[c + 1] > arr[c])
		c++;
	if (arr[c] > temp)
	{
		arr[i] = arr[c];
		arr[c] = temp;
	}
}

//∂—≈≈–Ú
void Heap_sort(int* arr, int s)
{
	for (int i = 0; i <= s / 2; i++)
		Build_max_heap(arr, i, s);
}

int main()
{
	int arr[] = { 2,9,7,6,5,8 };
	Heap_sort(arr, 6);
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}