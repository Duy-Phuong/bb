#include <iostream>
using namespace std;
#define MAX 100

typedef struct // C/C++
{
	double x;
	double y;
} Diem2D;

// Bài 1. Hàm nhập mảng a gồm n số thực
void Bai1(double a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> a[i];
	}
}

// Bài 2. Hàm nhập mảng a gồm n số nguyên dương
void Bai2(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		do
		{
			cout << "Nhap phan tu thu " << i + 1 << ": ";
			cin >> a[i];
		} while (!(a[i] > 0));
	}
}

// Bài 3.
// Hàm nhập 1 điểm trong mặt phẳng Oxy
void nhapDiem2D(Diem2D& p)
{
	cout << "Nhap hoanh do x: ";
	cin >> p.x;
	cout << "Nhap tung do y: ";
	cin >> p.y;
}

// Hàm nhập mảng a gồm n điểm trong mặt phẳng
void Bai3(Diem2D a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		nhapDiem2D(a[i]);
		//<=> cin >> a[i].x >> a[i].y;
	}
}

// Bài 4. Hàm xuất mảng a gồm n số thực
void Bai4(double a[], int n)
{
	cout << "Noi dung cua mang la: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

// Bài 5. Hàm xuất các số chẵn trong mảng a gồm n phần tử từ phải sang trái
void Bai5(int a[], int n)
{
	cout << "Cac mang so chan la: ";
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] % 2 == 0)
		{
			cout << a[i] << " ";
		}
	}
	cout << endl;
}

// Bài 6.
// Hàm xuất 1 điểm trong mặt phẳng Oxy
void xuatDiem2D(Diem2D p)
{
	cout << "(" << p.x << ", " << p.y << ") ";
}

// Hàm tính và trả về khoảng cách từ 1 điểm p bất kỳ đến gốc O
double tinhKCDenGocO(Diem2D p)
{
	return sqrt(p.x*p.x + p.y*p.y);
}

// Hàm xuất các điểm có trong a xa hơn điểm p cho trước
void Bai6(Diem2D a[], int n, Diem2D p)
{
	double kc = tinhKCDenGocO(p);

	cout << "Cac diem thoa yeu cau la: ";
	for (int i = 0; i < n; i++)
	{
		if (tinhKCDenGocO(a[i]) > kc)
		{
			xuatDiem2D(a[i]);
			//<=> cout << "(" << a[i].x << ", " << a[i].y << ") ";
		}
	}
	cout << endl;
}

// Bài 7.
// Hàm kiểm tra một số nguyên dương n cho trước có phải là số nguyên tố hay không
bool laSoNguyenTo(int n)
{
	int souoc = 0;

	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			souoc++;
		}
	}

	return (souoc == 2);
}

// Hàm đếm và trả về số lượng số nguyên tố có trong mảng a gồm n phần tử
int demSoLuongSoNguyenTo(int a[], int n)
{
	int soluong = 0;

	for (int i = 0; i < n; i++)
	{
		if (laSoNguyenTo(a[i]))
		{
			soluong++;
		}
	}

	return soluong;
}

// Bài 8. Hàm tính và trả về trung bình cộng các số chẵn có trong mảng a gồm n phần tử
double tinhTrungBinhCongSoChan(int a[], int n)
{
	int soluong, tong;

	soluong = 0;
	tong = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			soluong++;
			tong = tong + a[i];
		}
	}

	// Tính trung bình cộng
	double tbc = 0;

	if (soluong > 0)
	{
		tbc = tong / soluong;
	}

	return tbc;
}

// Bài 9. Hàm kiểm tra xem có phải là mảng toàn các số chẵn
bool Bai9(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (!(a[i] % 2 == 0))	// a[i] không chẵn
		{
			return false;		// kết luận không toàn số chẵn
		}
	}

	return true;				// kết luận toàn số chẵn
}

// Bài 10. Hàm kiểm tra xem có phải là mảng toàn số chẵn lớn hơn k cho trước
bool Bai10(int a[], int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		if (!(a[i] % 2 == 0 && a[i] > k))
		{
			return false;
		}
	}

	return true;
}

// Bài 11. Hàm kiểm tra xem có phải là mảng đối xứng
bool Bai11(int a[], int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		if (!(a[i] == a[n - 1 - i]))
		{
			return false;
		}
	}

	return true;
}

// Bài 12. Hàm kiểm tra xem có phải là mảng tăng dần
// a[0] < a[1] < a[2] < ... < a[n-1]
bool Bai12(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (!(a[i] < a[i + 1]))
		{
			return false;
		}
	}

	return true;
}

// Bài 13. Hàm kiểm tra xem có phải là mảng dạng sóng
bool Bai13(int a[], int n)
{
	for (int i = 1; i < n - 1; i++)
	{
		if (!((a[i] < a[i - 1] && a[i] < a[i + 1])		// cực tiểu
			|| (a[i] > a[i - 1] && a[i] > a[i + 1])))	// cực đại
		{
			return false;
		}
	}

	return true;
}

// Bài 14.
// Hàm hoán vị 2 số nguyên cho trước
void hoanVi(int& x, int& y)
{
	int t;
	t = x;
	x = y;
	y = t;
}

// Hàm đảo mảng a gồm n số nguyên cho trước
void Bai14(int a[], int n) // daoMang
{
	for (int i = 0; i < n / 2; i++)
	{
		hoanVi(a[i], a[n - 1 - i]);
	}
}

// Bài 15. Hàm tạo mảng b gồm các số dương có trong mảng a
void Bai15(int a[], int na, int b[], int& nb)
{
	nb = 0;
	for (int i = 0; i < na; i++)
	{
		if (a[i] > 0)
		{
			b[nb] = a[i];
			nb++;
		}
	}
}

// Hàm nối 2 mảng a và b cho trước thành mảng c
void Bai15(int a[], int na, int b[], int nb, int c[], int& nc)
{
	int i;
	nc = 0;
	for (i = 0; i < na; i++)
	{
		c[nc] = a[i];
		nc++;
	}

	for (i = 0; i < nb; i++)
	{
		c[nc] = b[i];
		nc++;
	}
}

// Bài 18. Hàm trộn 2 mảng tăng dần cho trước thành mảng cũng tăng dần nhưng không được sắp xếp
void Bai18(int a[], int na, int b[], int nb, int c[], int& nc)
{
	int i, j;
	nc = 0;

	i = 0;
	j = 0;
	while (i < na && j < nb)
	{
		if (a[i] < b[j])
		{
			c[nc] = a[i];
			i++;
		}
		else
		{
			c[nc] = b[j];
			j++;
		}

		nc++;
	}

	while (i < na)
	{
		c[nc] = a[i];
		i++;
		nc++;
	}

	while (j < nb)
	{
		c[nc] = b[j];
		j++;
		nc++;
	}
}

//ham chuyen tu nhị phan sang thap phan va nguoc lại
#include <math.h>
int chuyensangnhiphan(int n)
{
	int k = 1, s = 0;
	while (n > 0)
	{
		int x = n % 2;
		n = n / 2;
		s = s + k*x;
		k = k * 10;
	}
	return s;
}
int chuyensangthapphan(int n)
{
	int s = 0, i = 0;
	while (n > 0)
	{
		int x = n % 10;
		n = n / 10;
		s += x*pow((float)2, i);
		i++;
	}
	return s;
}
// Bài 19. Hàm tìm số lớn nhất trong mảng a gồm n số nguyên
int Bai19_Cach1(int a[], int n) // trả về giá trị
{
	int sln = a[0];

	for (int i = 1; i < n; i++)
	{
		if (a[i] > sln)
		{
			sln = a[i];
		}
	}

	return sln;
}

int Bai19_Cach2(int a[], int n) // trả về vị trí
{
	int vtsln = 0;

	for (int i = 1; i < n; i++)
	{
		if (a[i] > a[vtsln])
		{
			vtsln = i;
		}
	}

	return vtsln;
}

// Bài 20. Hàm tìm số âm lớn nhất trong mảng
// Cách 1. Tách số âm sang mảng b rồi tìm số lớn nhất trong mảng b (nếu nb > 0)
// Cách 2. Tìm số âm đầu tiên (hay cuối cùng) để gán cho số âm lớn nhất ban đầu, nếu còn số âm khác lớn hơn số này thì cập nhật lại
// Cách 3. Cài đặt như hàm tìm số lớn nhất bình thường (tổng quát nhưng phức tạp)
// Cách 4. Sắp xếp giảm dần rồi trả về số âm xuất hiện đầu tiên => chính là số âm lớn nhất (chú vị trí bị thay đổi) 
// Lưu ý: Nếu đề không nói rõ thì nên trả về vị trí sẽ dễ hơn trả về ngay giá trị
//        vì vị trí nếu không có sẽ bằng -1
//        còn giá trị nếu không có thì phải nghĩ ra 1 giá trị đặc biệt để trả về
int Bai20_Cach3a(int a[], int n) // trả về giá trị, cần phải nghĩ ra giá trị đặc biệt để trả về trong trường hợp không tìm được!
{
	int saln = a[0]; // giả sử đó là số đầu tiên!!!

	for (int i = 1; i < n; i++) // duyệt từ phần tử thứ 2 trở đi
	{
		if (a[i] < 0)
		{
			// nếu số hiện tại sai hoặc đúng nhưng còn số khác lớn hơn
			if (!(saln < 0) || (saln < 0 && a[i] > saln)) // có thể bỏ điều kiện saln < 0 trong bài này
			{
				saln = a[i];
			}
		}
	}

	if (!(saln < 0)) // nếu số âm lớn nhất lại không phải số âm!
	{
		saln = 0; // quy ước trả về 0 nghĩa là không có
	}

	return saln;
}

int Bai20_Cach3b(int a[], int n) // trả về vị trí, dễ làm hơn!
{
	int vtsaln = -1; // đầu tiên chưa có!!!

	for (int i = 0; i < n; i++) // duyệt toàn bộ mảng
	{
		if (a[i] < 0)
		{
			// nếu chưa có hoặc có rồi nhưng còn phần tử khác lớn hơn
			if (vtsaln == -1 || (vtsaln != -1 && a[i] > a[vtsaln]))
			{
				vtsaln = i;
			}
		}
	}

	return vtsaln; // -1 nghĩa là không có
}

// Bài 21. Hàm trả về VỊ TRÍ số thực nhỏ nhất khác 0
int Bai21_Cach3b(float a[], int n) // trả về vị trí
{
	int vtsnn = -1; // đầu tiên chưa có!!!

	for (int i = 0; i < n; i++) // duyệt toàn bộ mảng
	{
		if (a[i] != 0)
		{
			// nếu chưa có hoặc có rồi nhưng còn phần tử khác nhỏ hơn
			if (vtsnn == -1 || (vtsnn != -1 && a[i] < a[vtsnn]))
			{
				vtsnn = i;
			}
		}
	}

	return vtsnn; // -1 nghĩa là không có
}

// Bài 22. Hàm trả về khác VỊ TRÍ số khác 0 có trị tuyệt đối nhỏ nhất
int Bai22_Cach3b(int a[], int n)
{
	int vtsnn = -1; // đầu tiên chưa có!!!

	for (int i = 0; i < n; i++) // duyệt toàn bộ mảng
	{
		if (a[i] != 0)
		{
			// nếu chưa có hoặc có rồi nhưng còn phần tử khác có trị tuyệt đối nhỏ hơn
			if (vtsnn == -1 || (vtsnn != -1 && abs(a[i]) < abs(a[vtsnn])))
			{
				vtsnn = i;
			}
		}
	}

	return vtsnn; // -1 nghĩa là không có
}

// Bài 23. Hàm trả về VỊ TRÍ i sao cho |x - a[i]| nhỏ nhất (luôn có)
int Bai23(float a[], int n, float x)
{
	int vtsnn = 0; // giả sử đó là vị trí đầu tiên

	for (int i = 1; i < n; i++)
	{
		if (fabs(x - a[i]) < fabs(x - a[vtsnn]))
		{
			vtsnn = i;
		}
	}

	return vtsnn;
}

// Bài 24. Hàm trả về vị trí i sao cho a[i] gấp đôi tổng các phần tử còn lại
int Bai24(int a[], int n)
{
	int i, tong = 0;
	for (i = 0; i < n; i++)
	{
		tong = tong + a[i];
	}

	for (i = 0; i < n; i++)
	{
		if (a[i] == 2 * (tong - a[i]))
		{
			return i;
		}
	}

	return -1; // không tìm được
}

// Bài 25.
// Hàm trả về khoảng cách giữa 2 điểm p1 và p2
double tinhKC(Diem2D p1, Diem2D p2)
{
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	return sqrt(dx*dx + dy*dy);
}

// Hàm xuất 2 điểm khác nhau và gần nhau nhất ra màn hình
void Bai25(Diem2D a[], int n)
{
	if (n < 2)
	{
		cout << "Khong tim duoc!" << endl;
		return;
	}

	// n >= 2
	int vt1, vt2;
	int i, j;
	double kcnnht, kc;

	kcnnht = 0;
	vt1 = 0;
	vt2 = 0;

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			kc = tinhKC(a[i], a[j]);
			if (kc > 0)
			{
				if (kcnnht == 0 || (kcnnht > 0 && kc < kcnnht)) // có thể bỏ điều kiện kcnnht > 0 trong bài này!
				{
					vt1 = i;
					vt2 = j;
					kcnnht = kc;
				}
			}
		}
	}

	if (vt1 != vt2)
	{
		cout << "2 diem khac nhau va gan nhau nhat la: ";
		xuatDiem2D(a[vt1]);
		xuatDiem2D(a[vt2]);
	}
	else
	{
		cout << "Khong tim duoc!" << endl;
	}
}

// Bài 26. Sắp xếp mảng tăng dần
void Bai26(int a[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j]) // nếu giảm dần
			{
				hoanVi(a[i], a[j]); // thì hoán vị
			}
		}
	}
}

// Bài 27. Sắp xếp số chẵn tăng dần và giữ nguyên tính chất chẵn lẻ
void Bai27(int a[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			// nếu 2 số chẵn mà giảm dần thì hoán vị
			if (a[i] % 2 == 0 && a[j] % 2 == 0 && a[i] > a[j])
			{
				hoanVi(a[i], a[j]);
			}
		}
	}
}

// Bài 28. [dương giảm] [không dương tăng]
void Bai28(int a[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			// 1 trong 3 trường hợp sau thì hoán vị:
			// a. 2 số dương nhưng lại tăng
			// b. số không dương đứng trước số dương
			// c. 2 số không dương nhưng lại giảm
			if ((a[i] > 0 && a[j] > 0 && a[i] < a[j])
				|| (a[i] <= 0 && a[j] > 0)
				|| (a[i] <= 0 && a[j] <= 0 && a[i] > a[j]))
			{
				hoanVi(a[i], a[j]);
			}
		}
	}
}

// Bài 29. [dương giảm] [0] [âm tăng]
void Bai29(int a[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			// 1 trong 4 trường hợp sau thì hoán vị:
			// a. 2 số dương nhưng lại tăng
			// b. số 0 đứng trước số dương
			// c. số âm đứng trước số không âm 
			// d. 2 số âm nhưng lại giảm
			if ((a[i] > 0 && a[j] > 0 && a[i] < a[j])
				|| (a[i] == 0 && a[j] > 0)
				|| (a[i] < 0 && a[i] >= 0)
				|| (a[i] < 0 && a[j] < 0 && a[i] > a[j]))
			{
				hoanVi(a[i], a[j]);
			}
		}
	}
}

// Bài 30. Hàm chèn x vào mảng a tại vị trí vt
void Bai30(int a[], int& n, int x, int vt)
{
	if (vt >= 0 && vt <= n)
	{
		// Đẩy sang phải
		for (int i = n; i > vt; i--)
		{
			a[i] = a[i - 1];
		}

		// Gán
		a[vt] = x;

		// Tăng n
		n++;
	}
}

// Bài 31. Hàm chèn số 2 đằng sau mỗi số chẵn có trong mảng
void Bai31(int a[], int& n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] % 2 == 0)
		{
			Bai30(a, n, 2, i + 1); // Bai30 <=> hàm chèn, nếu đề bài là chèn đằng trước thì vị trí chỉ là i chứ không phải là i - 1
		}
	}
}

// Bài 32. Hàm xóa phần tử tại vị trí vt
void Bai32(int a[], int& n, int vt)
{
	if (vt >= 0 && vt < n)
	{
		// Kéo sang trái
		for (int i = vt; i < n - 1; i++)
		{
			a[i] = a[i + 1];
		}

		// Giảm n
		n--;
	}
}

// Bài 33. Hàm xóa tất cả số lẻ có trong mảng
void Bai33(int a[], int& n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] % 2 != 0)
		{
			Bai32(a, n, i); // Bai32 <=> hàm xóa
		}
	}
}

// Bài 34. Hàm xóa k phần tử bắt đầu tại vị trí vt
void Bai34(int a[], int& n, int vt, int k)
{
	// thực hiện hàm xóa (Bai32) k lần
	for (int i = 1; i <= k; i++)
	{
		Bai32(a, n, vt);
	}
}

// Bài 35a. Xuất mảng không dùng vòng lặp
void Bai35a(int a[], int n)
{
	if (n == 0)
	{
		return;
	}

	Bai35a(a, n - 1);
	cout << " " << a[n - 1];
}

// Bài 35b. Đảo mảng không dùng vòng lặp
void Bai35b(int a[], int vt1, int vt2)
{
	if (vt1 > vt2)
	{
		return;
	}

	hoanVi(a[vt1], a[vt2]);
	Bai35b(a, vt1 + 1, vt2 - 1);
}

void Bai35b(int a[], int n) // hàm gọi đơn giản cho người sử dụng
{
	Bai35b(a, 0, n - 1);
}

// Bài 35c. Hàm tính tổng mảng không dùng vòng lặp
int Bai35c(int a[], int n)
{
	if (n == 0)
	{
		return 0;
	}

	return Bai35c(a, n - 1) + a[n - 1];
}

// Bài 35d. Hàm tìm vị trí số lớn nhất không dùng vòng lặp
int Bai35d(int a[], int n)
{
	if (n == 1)
	{
		return 0;
	}

	int vtsln = Bai35d(a, n - 1);
	if (a[n - 1] > a[vtsln])
	{
		vtsln = n - 1;
	}

	return vtsln;
}

// Bài 35e. Hàm kiểm tra xem có phải là mảng toàn số dương
bool Bai35e(int a[], int n)
{
	if (n == 1)
	{
		return (a[0] > 0);
	}

	// n > 1
	// mảng toàn dương khi phần tử cuối cùng là số dương
	// và mảng gồm n - 1 phần tử trước đó cũng toàn dương
	return (a[n - 1] > 0 && Bai35e(a, n - 1));
}

// Bài 35f. Hàm sắp xếp mảng tăng dần không dùng vòng lặp
void Bai35f_Cach1(int a[], int n)
{
	if (n == 0)
	{
		return;
	}

	Bai35f_Cach1(a, n - 1);			// sắp xếp n - 1 phần tử đầu tiên
	if (a[n - 2] > a[n - 1])			// nếu chưa tăng toàn bộ n phần tử
	{
		hoanVi(a[n - 2], a[n - 1]);	// hoán vị phần tử lớn nhất về cuối
		Bai35f_Cach1(a, n - 1);		// sắp xếp lại n - 1 phần tử
	}
}

void Bai35f_Cach2(int a[], int n)
{
	if (n == 0)
	{
		return;
	}

	int vtsln = Bai35d(a, n);		// tìm vị trí số lớn nhất đã viết ở trên
	hoanVi(a[vtsln], a[n - 1]);		// đưa về cuối mảng
	Bai35f_Cach2(a, n - 1);			// thực hiện với mảng n - 1 phần tử còn lại
}

//ham liet ke lần xuat hien cua moi gia tri khac nhau trong mang
/*
nếu a[i] chưa xuất hiện trong mảng b => thêm vào mảng b[]  -----   (k tim thay trong mang b thi chua xuat hien)
nếu a[i] xuất hiện trong mảng b => k thêm vào mảng b[]
*/
int kiemtratontai(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (x == a[i])
		{
			return i;// neu co thi tra ve vi tri
		}
	}
	return -1;// neu k co thi tra ve -1
}

void lietke(int a[], int n, int b[], int c[], int &m)
{
	m = 0;
	for (int i = 0; i < n; i++)
	{
		int ketqua = kiemtratontai(b, m, a[i]);
		if (ketqua != -1)
		{
			c[ketqua]++;
		}
		else
		{
			b[m] = a[i];
			c[m] = 1;
			m++;
		}
	}

}

void xuat1(int b[], int c[], int &m)
{
	for (int i = 0; i < m; i++)
	{
		printf("so lan xuat hien cua phan tu %d la: %d", b[i], c[i]);
	}
}
//tim mang con co k phan tu so cho tong so phan tu max
// tinh tong k phan tu mot mang bat dau tu i
int tong(int a[], int n, int batdau, int k)
{
	int ketthuc = min(batdau + k, n);
	int s = 0;
	for (int i = batdau; i <= ketthuc; i++)
	{
		s += a[i];
	}
	return s;
}
void timmangconcotongmax(int a[], int n, int b[], int k)
{
	int smax = tong(a, n, 0, k);
	int imax = 0;
	for (int i = 0; i < n - k; i++)
	{
		int s = tong(a, n, i, k);
		if (s > smax);
		smax=s;
		imax=i;
		
	}
	int j = imax;
	for (int i = 0; i < k; i++)
	{
		b[i] = a[j];
		j++;
	}
}

//thuc hanh tuan 7


























