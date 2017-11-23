#include <stdio.h>
void nhap(int a[][100], int &d, int &c)
{
	printf("nhap so dong: ");
	scanf_s("%d", &d);
	printf("nhap so cot: ");
	scanf_s("%d", &c);
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("nhap phan tu a[%d][%d]: ", i, j);
			scanf_s("%d", &a[i][j]);

		}
	}
}
void xuat(int a[][100], int d, int c)
{
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}
void timphantunndong(int a[100][100], int d, int c, int min[], int &n)
{
	
	for (int i = 0; i < d; i++)
	{
		int min_dong = a[i][0];
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] < min_dong)
			{
				min_dong = a[i][j];
			}
			min[n] = min_dong;
			n++;
		}
	}
}
void xuat1(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
}

void main()
{
	int a[100][100], d, c, min[100], n;
	nhap(a, d, c);
	xuat(a, d, c);
	timphantunndong(a, d, c, min, n);
	xuat1(min, d);

}