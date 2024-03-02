#include <stdio.h>

int DivideAndConquer(int list[], int left, int right)
{
	int MaxLeftSum, MaxRightSum;	//�������������к�
	int MaxLeftBorderSum = 0, MaxRightBorderSum = 0;	//��ſ�ֽ���������к�
	int LeftBorderSum = 0, RightBorderSum = 0;
	int center;	//����зֵ�
	//�ݹ����ֹ����
	if (left == right)
	{
		//��������ֻ��һ��Ԫ��ʱ�������ݹ�
		if (list[left] > 0)
			return list[left];
		//���жϵ�ǰԪ���Ƿ����0���������0�򷵻ص�ǰԪ�أ����򷵻�0
		return 0;
	}

	//1.�ҵ��зֵ�
	center = (left + right) / 2;

	//2.�ݹ�����������к�
	MaxLeftSum = DivideAndConquer(list, left, center);
	MaxRightSum = DivideAndConquer(list, center + 1, right);

	//3.���ֽ��ߵ�������к�
	for (int i = center; i >= left; i--)
	{//����������ɨ��
		LeftBorderSum += list[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}//����ɨ�����

	for (int i = center + 1; i <= right; i++)
	{//����������ɨ��
		RightBorderSum += list[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}//����ɨ�����

	//���ؽ��
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
	printf("������к�Ϊ��%d", c);
	return 0;
}