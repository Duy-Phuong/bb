#include <stdio.h>
#include <math.h>

// Bài 01: S(n) = 1 + 2 + 3 + ... + n
//         S(n) = S(n-1) + n
int Bai01(int n)
{
	if (n == 0)
	{
		return 0;
	}

	return Bai01(n - 1) + n;
}

// Bài 02: S(n) = 1 + 2^2 + 3^2 + ... + n^2
int Bai02(int n)
{
	if (n == 0)
	{
		return 0;
	}

	return Bai02(n - 1) + n * n;
}

// Bài 03: S(n) = 1 + 1/2 + 1/3 + ... + 1/n
double Bai03(int n)
{
	if (n == 0)
	{
		return 0;
	}

	return Bai03(n - 1) + 1.0 / n;
}

// Bài 04: S(n) = 1/2 + 1/4 + 1/6 + ... + 1/(2n)
double Bai04(int n)
{
	if (n == 0)
	{
		return 0;
	}

	return Bai04(n - 1) + 1.0 / (2 * n);
}

// Bài 05: S(n) = 1/(2*0+1) + 1/3 + 1/5 + ... + 1/(2n+1)
double Bai05(int n)
{
	if (n == -1)
	{
		return 0;
	}

	return Bai05(n - 1) + 1.0 / (2 * n + 1);
}

// Bài 06: S(n) = 1/(1*2) + 1/(2*3) + 1/(3*4) + ... + 1/(n*(n+1))
double Bai06(int n)
{
	if (n == 0)
	{
		return 0;
	}

	return Bai06(n - 1) + 1.0 / (n * (n + 1));
}

// Bài 07: S(n) = 1/2 + 2/3 + 3/4 + ... + n/(n+1)
double Bai07(int n)
{
	if (n == 0)
	{
		return 0;
	}

	return Bai07(n - 1) + (double)n / (n + 1);
}

// Bài 08: S(n) = 1/2 + 3/4 + 5/6 + ... + (2n+1)/(2n+2)
double Bai08(int n)
{
	if (n == -1)
	{
		return 0;
	}

	return Bai08(n - 1) + (double)(2 * n + 1) / (2 * n + 2);
}

// Bài 09: P(n) = 1*2*3*...*n
int Bai09(int n)
{
	if (n == 0)
	{
		return 1;
	}

	return Bai09(n - 1) * n;
}

// Bài 10: S(n) = x^n (n >= 0)
int Bai10(double x, int n)
{
	if (n == 0)
	{
		return 1;
	}

	return Bai10(x, n - 1) * x;
}

// Bài 11: S(n) = 1 + 1*2 + 1*2*3 + ... + 1*2*3*...*n
int Bai11(int n)
{
	if (n == 0)
	{
		return 0;
	}

	return Bai11(n - 1) + Bai09(n); // Bai09(n) <=> n!
}

// Bài 12: S(n) = x + x^2 + x^3 + ... + x^n
int Bai12(double x, int n)
{
	if (n == 0)
	{
		return 0;
	}

	return Bai12(x, n - 1) + Bai10(x, n); // Bai10(x, n) <=> x^n
}

// Bài 13: S(n) = x^2 + x^4 + x^6 + ... + x^2n
int Bai13(double x, int n)
{
	if (n == 0)
	{
		return 0;
	}

	return Bai13(x, n - 1) + Bai10(x, 2 * n); // Bai10(x, 2 * n) <=> x^2n
}

// Bài 14: S(n) = x^1 + x^3 + x^5 + ... + x^(2n+1)
int Bai14(double x, int n)
{
	if (n == -1)
	{
		return 0;
	}

	return Bai14(x, n - 1) + Bai10(x, 2 * n + 1); // Bai10(x, 2*n+1) <=> x^(2n+1)
}

// Bài 15: S(n) = 1 + 1/(1+2) + 1/(1+2+3) + ... + 1/(1+2+3+...+n)
double Bai15(int n)
{
	if (n == 0)
	{
		return 0;
	}

	return Bai15(n - 1) + 1.0 / Bai01(n); // Bai01(n) <=> 1+2+3+...+n 
}

// Bài 16: S(n) = x + x^2/2! + x^3/3! + ... + x^n/n!
double Bai16(double x, int n)
{
	if (n == 0)
	{
		return 0;
	}

	return Bai16(x, n - 1) + (double)Bai10(x, n) / Bai09(n); // Bai10(x, n) <=> x^n, Bai09(n) <=> n! 
}

// Bài 17: S(n) = 1 + x^2/2! + x^4/4! + ... + x^2n/2n!
double Bai17(double x, int n)
{
	if (n == -1)
	{
		return 0;
	}

	return Bai17(x, n - 1) + (double)Bai10(x, 2 * n) / Bai09(2 * n); // Bai10(x, 2 * n) <=> x^(2n), Bai09(2 * n) <=> (2n)! 
}

// Bài 18: S(n) = sqrt(2 + sqrt(2 + sqrt(2 + ... + sqrt(2))))
double Bai18(int n)
{
	if (n == 0)
	{
		return 0;
	}

	return sqrt(2 + Bai18(n - 1));
}

// Bài 19: S(n) = sqrt(n + sqrt(n-1 + sqrt(n-2 + ... + sqrt(1))))
double Bai19(int n)
{
	if (n == 0)
	{
		return 0;
	}

	return sqrt(n + Bai19(n - 1));
}

// Bài 20: S(n) = sqrt(1 + sqrt(2 + sqrt(3 + ... + sqrt(n))))
double Bai20(int n, int start)	// Lần đầu tiên gọi start = n 
{
	if (n == 0)
	{
		return 0;
	}

	return sqrt((start - n + 1) + Bai20(n - 1, start));
}

// Bài 21: S(n) = 1 + 1/(1 + 1/(1 + ...1/(1+1)))
double Bai21(int n)
{
	if (n == 0)
	{
		return 0;
	}

	return 1 + 1 / (1 + Bai21(n - 1));
}

// Bài 22: Ước số lẻ lớn nhất của số nguyên dương n
int Bai22(int n)
{
	if (n % 2 != 0) // n lẻ
	{
		return n;
	}

	return Bai22(n / 2);
}

// Bài 23: Số lượng chữ số của số nguyên dương n
// n = ab...z
int Bai23(int n)
{
	if (n < 10)		// n chỉ có 1 chữ số
	{
		return 1;
	}

	return 1 + Bai23(n / 10);
}

// Bài 24: Tổng các chữ số của số nguyên dương n
int Bai24(int n)
{
	if (n < 10)
	{
		return n;
	}

	return Bai24(n / 10) + (n % 10);
}

// Bài 25: Tích các chữ số của số nguyên dương n
int Bai25(int n)
{
	if (n < 10) // n chỉ có 1 chữ số
	{
		return n;
	}

	return Bai25(n / 10) * (n % 10);
}

// Bài 26: Số lượng chữ số lẻ của số nguyên dương n
int Bai26(int n)
{
	// Cách 1
	if (n == 0)
	{
		return 0;
	}

	// n từ 1 chữ số trở lên
	int dv = n % 10;
	if (dv % 2 != 0) // đơn vị là số lẻ
	{
		return Bai26(n / 10) + 1;
	}
	else
	{
		return Bai26(n / 10);
	}

	// Cách 2
	// if (n == 0) return 0;
	// return (Bai23(n/10) + (n % 2));
}

// Bài 27: Tổng các số chẵn của số nguyên dương n
int Bai27(int n)
{
	if (n == 0)
	{
		return 0;
	}

	// n từ 1 chữ số trở lên
	int dv = n % 10;
	if (dv % 2 == 0) // đơn vị là số chẵn
	{
		return Bai27(n / 10) + dv;
	}
	else
	{
		return Bai27(n / 10);
	}
}

// Bài 28: Tích các chữ số lẻ của số nguyên dương n
int Bai28(int n)
{
	if (n < 10) // n chỉ có 1 chữ số
	{
		if (n % 2 != 0) // n là số lẻ
		{
			return n;
		}
		else
		{
			return 1;
		}
	}

	// n nhiều hơn 1 chữ số
	int dv = n % 10;
	if (dv % 2 != 0) // đơn vị là số lẻ
	{
		return Bai28(n / 10) * dv;
	}
	else
	{
		return Bai28(n / 10);
	}
}

// Bài 29: Tìm chữ số lẻ đầu tiên của số nguyên dương n
int Bai29(int n)
{
	if (n < 10) // n chỉ có 1 chữ số
	{
		if (n % 2 != 0) // n là số lẻ
		{
			return n; // đây là chữ số lẻ đầu tiên
		}
		else
		{
			return 0; // không có chữ số lẻ nào
		}
	}

	// n nhiều hơn 1 chữ số
	int dv = n % 10;
	int tam = Bai29(n / 10); // tìm chữ số lẻ đầu tiên của phần trước

	if (tam > 0) // tìm được chữ số lẻ đầu tiên của phần trước
	{
		return tam;
	}
	else // không tìm được chữ số lẻ đầu tiên của phần trước
	{
		if (dv % 2 != 0)// nếu đơn vị là số lẻ
		{
			return dv;	// thì trả về đơn vị
		}
		else
		{
			return 0;	// ngược lại kết luận không có chữ số lẻ nào
		}
	}
}

// Bài 30: Xuất số đảo ngược của số nguyên dương n
// n = (abcd) => d(abc)
void Bai30(int n)
{
	if (n < 10)
	{
		printf("%d", n);
	}
	else
	{
		printf("%d", n % 10);
		Bai30(n / 10);
	}
}

// Bài 31: Tìm chữ số lớn nhất của số nguyên dương n
int Bai31(int n)
{
	if (n < 10) // n chỉ có 1 chữ số
	{
		return n;
	}

	// n nhiều hơn 1 chữ số
	int dv = n % 10;
	int sln = Bai31(n / 10);

	if (dv > sln)
	{
		sln = dv;
	}

	return sln;
}

// Bài 32: Kiểm tra xem số nguyên dương n có phải toàn chữ số lẻ
int Bai32(int n)
{
	if (n < 10) // n chỉ có 1 chữ số
	{
		if (n % 2 != 0) // n là số lẻ
		{
			return 1;	// toàn lẻ
		}
		else
		{
			return 0;	// không toàn lẻ
		}
	}

	// n nhiều hơn 1 chữ số
	int dv = n % 10;
	if (dv % 2 != 0 && Bai32(n / 10) == 1) // đơn vị là số lẻ và phần trước cũng toàn lẻ
	{
		return 1;
	}
	else
	{
		return 0;
	}

	// <=> return (dv % 2 != 0 && Bai32(n / 10) == 1);
}

// Bài 33: Tìm USCLN của 2 số nguyên dương a và b
int Bai33(int a, int b)
{
	if (a == b)
	{
		return a;
	}

	if (a > b)
	{
		return Bai33(a - b, b);
	}
	else
	{
		return Bai33(b - a, a);
	}
}

// Bài 33: Tìm giá trị phần tử tại dòng d, cột c của tam giác Pascal
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// ...

int Bai34(int d, int c)
{
	if (c == 0 || d == c)
	{
		return 1;
	}

	return Bai34(d - 1, c - 1) + Bai34(d - 1, c);
}

// Bài 35: Tính C(n , k) = k!/(n!*(n-k)!)
int Bai35(int n, int k)
{
	if (k == 0 || k == n)
	{
		return 1;
	}

	if (k > n)
	{
		return 0;
	}

	return Bai35(n - 1, k - 1) + Bai35(n - 1, k);
}

// Bài 36: Xuất số nguyên dương n ở hệ thập phân sang hệ k
void Bai36(int n, int k)
{
	if (n == 0)
	{
		return;
	}

	int thuong = n / k;
	int sodu = n % k;

	Bai36(thuong, k);
	printf("%d", sodu);
}

// Bài 37: Xuất nội dung của mảng 1 chiều
void Bai37(int a[], int n)
{
	// Cách 1
	if (n == 0)
	{
		return;
	}

	Bai37(a, n - 1);
	printf(" %d", a[n - 1]);

	// Cach 2
	/*
	if (n == 1)
	{
	printf("%d", a[0]);
	}
	else
	{
	Bai37(a, n - 1);
	printf(" %d", a[n - 1]);
	}
	*/
}

// Bài 38: Tính tổng các phần tử trong mảng
int Bai38(int a[], int n)
{
	if (n == 0)
	{
		return 0;
	}

	return Bai38(a, n - 1) + a[n - 1];
}

// Bài 39: Tìm số nhỏ nhất trong mảng
int Bai39(int a[], int n)
{
	if (n == 1)
	{
		return a[0];
	}

	int snn = Bai39(a, n - 1);

	if (snn < a[n - 1])
	{
		return snn;
	}
	else
	{
		return a[n - 1];
	}
}

// Bài 40: Kiểm tra xem có phải là mảng toàn số dương
int Bai40(int a[], int n)
{
	if (n == 0)
	{
		return 0;
	}

	if (n == 1) // nếu chỉ có 1 phần tử
	{
		if (a[0] > 0) // và phần tử này dương
		{
			return 1; // thì mảng toàn dương
		}
		else
		{
			return 0; // ngược lại mảng không toàn dương
		}
	}

	// n > 0
	if (a[n - 1] > 0) // nếu phần tử cuối mảng là số dương
	{
		return Bai40(a, n - 1); // thì kết quả phụ thuộc và n - 1 phần tử trước đó
	}
	else
	{
		return 0; // ngược lại kết luận mảng không toàn dương
	}
}

void main()
{
}