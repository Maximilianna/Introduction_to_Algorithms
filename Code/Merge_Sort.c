#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void merge(int list[], int Left[], int Right[], int l, int r)
{
	int i = 0, j = 0, k = 0;
	while (l > i && r > j)
	{
		if (Left[i] <= Right[j])
			list[k++] = Left[i++];
		else
			list[k++] = Right[j++];
	}
	while (l > i)
		list[k++] = Left[i++];
	while (r > j)
		list[k++] = Right[j++];
}

void merge_sort(int list[], int n)
{
	//数组中元素至少大于1，才进行排序
	if (n > 1)
	{
		//找到中间点
		int mid = n / 2;
		//建立两个左右子数组
		int* Left = (int*)malloc(sizeof(int) * mid);
		int* Right = (int*)malloc(sizeof(int) * (n - mid));
		//将原数组中的内容放入左右子数组
		for (int i = 0; i < mid; i++)
			Left[i] = list[i];
		for (int i = mid; i < n; i++)
			Right[i - mid] = list[i];
		merge_sort(Left, mid);
		merge_sort(Right, n - mid);
		merge(list, Left, Right, mid, n - mid);
		free(Left);
		free(Right);
	}
}

int main()
{
	int arr[] = { 5,4,6,33,12,19,3,21,18,9 };
	merge_sort(arr, sizeof(arr) / sizeof(int));
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}