#include <stdio.h>

int DivideAndConquer(int list[], int left, int right)
{
	int MaxLeftSum, MaxRightSum;	//存放两边最大子列和
	int MaxLeftBorderSum = 0, MaxRightBorderSum = 0;	//存放跨分界线最大子列和
	int LeftBorderSum = 0, RightBorderSum = 0;
	int center;	//存放中分点
	//递归的终止条件
	if (left == right)
	{
		//当数组中只有一个元素时，结束递归
		if (list[left] > 0)
			return list[left];
		//并判断当前元素是否大于0，如果大于0则返回当前元素，否则返回0
		return 0;
	}

	//1.找到中分点
	center = (left + right) / 2;

	//2.递归求得两边子列和
	MaxLeftSum = DivideAndConquer(list, left, center);
	MaxRightSum = DivideAndConquer(list, center + 1, right);

	//3.求跨分界线的最大子列和
	for (int i = center; i >= left; i--)
	{//从中线向左扫描
		LeftBorderSum += list[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}//左面扫描结束

	for (int i = center + 1; i <= right; i++)
	{//从中线向右扫描
		RightBorderSum += list[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}//右面扫描结束

	//返回结果
	int Max = 0;
	if (MaxLeftSum > MaxRightSum)
	{
		if (MaxLeftSum > MaxLeftBorderSum + MaxRightBorderSum)
			Max = MaxLeftSum;
		else
			Max = MaxLeftBorderSum + MaxRightBorderSum;
	}
	else
	{
		if (MaxRightSum > MaxLeftBorderSum + MaxRightBorderSum)
			Max = MaxRightSum;
		else
			Max = MaxLeftBorderSum + MaxRightBorderSum;
	}
	return Max;
}

int main()
{
	int arr[] = { -2,11,-4,13,-5,-2 };
	int c = DivideAndConquer(arr, 0, sizeof(arr) / sizeof(int));
	printf("最大子列和为：%d", c);
	return 0;
}