#include <stdio.h>
#include <math.h>
void nhap(int a[][100], int &d, int &c)
{
	printf("nhap so dong: ");
	scanf("%d", &d);
	printf("nhap so cot: ");
	scanf("%d", &c);
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("nhap phan tu a[%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);

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

void hoanvi(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void domang1chieusangmang2chieu(int a[][100], int d, int c, int b[], int k)
{
	k = 0;
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			a[i][j] = b[k];
			k++;
		}
	}
}
void domang2chieusangmang1chieu(int a[][100], int d, int c, int b[], int &k)
{
	k = 0;
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			b[k] = a[i][j];
			k++;
		}
	}
}
void sapxepmang1chieu(int b[], int k)
{
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (b[i] > b[j])
			{
				hoanvi(b[i], b[j]);
			}
		}
	}
}
//sap xep khong can dung mang phu
void sapxep(int a[][100], int d, int c)
{
	int n = d * c;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i / c][i % c] > a[j / c][j % c])
			{
				hoanvi(a[i / c][i % c], a[j / c][j % c]);
			}
		}
	}
}

//diem cuc tri la diem lon hon hoac nho hon cac diem xung quanh


/*
1.khai báo cau truc diem va duong tron trong khong gian 2d
nhap 1 điểm va 1 đuong tron(C)
đém xem có bao nhiu điểm nằm trong (C)
2. khai bao cau truc da thuc f bac n co dang  f(x)=a0+a1*x+..+an*x
nhap 1 so thuc x
a) tinh gia tri da thuc f tai x
b)tinh dao ham bac 1 cua f tai x

*/

typedef struct
{
	int x, y;
}diem2d;
struct duongtron
{
	diem2d tam;
	int bankinh;
};
void nhap1diem(diem2d &a)
{
	printf("nhap x: ");
	scanf("%d", &a.x);
	printf("nhap y: ");
	scanf("%d", &a.y);
}
void nhapndiem(diem2d a[], int &n)
{
	printf("nhap n: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		nhap1diem(a[i]);
	}

}
void nhapduongtron(duongtron &c)
{
	printf("nhap tam: ");
	nhap1diem(c.tam);
	printf("nhap ban kinh: ");
	scanf("%d", &c.bankinh);

}

float tinhkc(diem2d a, diem2d b)
{
	return sqrt(float((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)));
}

int kiemtra(duongtron c, diem2d a)
{
	return(tinhkc(c.tam, a) < c.bankinh);
}
int dem(duongtron c, diem2d a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (kiemtra(c, a[i]))
		{
			dem++;
		}
	}
	return dem;
}

//bai2
//2. khai bao cau truc da thuc f bac n co dang  f(x) = a0 + a1*x + .. + an*x
//nhap 1 so thuc x
//a) tinh gia tri da thuc f tai x
//b)tinh dao ham bac 1 cua f tai x
struct dathuc
{
	float a[100];
	int n;
};

void nhapdiem(dathuc &f)
{
	printf("nhap bac da thuc");
	scanf("%f", &f.n);
	for (int i = 0; i < f.n + 1; i++)
	{
		printf("nhap he so thu %d", i);
		scanf("%f", &f.a[i]);
	}
}

float tinhgiatri(dathuc f, float x)
{
	float gt = f.a[0], lt = 1;
	for (int i = 1; i < f.n + 1; i++)
	{
		lt = lt*x;
		gt = gt + f.a[i] * lt;
	}
	return gt;
}

dathuc timdathucdaoham(dathuc f)
{
	dathuc daoham;
	if (f.n == 0)
	{
		daoham.n = 0;
		daoham.a[0] = 0;
		return daoham;
	}
	daoham.n = f.n - 1;
	for (int i = 0; i < daoham.n + 1; i++)
	{
		daoham.a[i] = f.a[i + 1] * (i + 1);
	}
	return daoham;
}

float tinhdaoham(dathuc f, float x)
{
	dathuc g = timdathucdaoham(f);
	return tinhgiatri(g, x);
}


// sap xep thao dong, cot ma tran
//theo dong
void SapXepDong(int a[][100], int d, int c)
{
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c - 1; j++)
		{
			for (int k = j + 1; k < c; k++)
			{
				if (a[i][j]>a[i][k]);
				{
					hoanvi(a[i][j], a[i][k]);
				}
			}
		}
	}
}
//theo cot
void SapXepCot(int a[][100], int d, int c)
{
	for (int j = 0; j < c; j++)
	{
		for (int i = 0; i < d - 1; i++)
		{
			for (int k = i + 1; k < d; k++)
			{
				if (a[i][j]>a[k][j]);
				{
					hoanvi(a[i][j], a[k][j]);
				}
			}
		}
	}
}















