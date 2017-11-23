//1.sap xep mang 1 chieu n pt theo chieu tang dan
//nhap so nguyen x chen x vao mang sao cho k lm thay doi thu tu cua mang
//2.tim mang con dai nhat trong mang 1 chieu n pt
//3.nhap mang 2 chieu m dong n cot
//tim cac phan tu min tren moi dong
//4.


void chengiuthutu(int a[], int &n, int x)
{
	sapxep(a, n);
	int vt = 0;
	while (vt < n && a[vt] < x)
	{
		vt++;
	}
	chen(a, n, x, vt);

}
int timmax(int a[], int n, int &vtmax)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i] == max)
		{
			vtmax = i;
			break;
		}
	}
	return max;
}
void timmangcon(int a[], int n, int b[100][100], int dong[])
{
	int i1 = 0;
	int  j1 = 0;
	int a1 = 0;
	int b1 = 0;
	int dem = 0;
	int x = 0;
	int vitritang[100];
	int vt = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < a[i + 1])
		{
			b[i1][j1++] = a[i];
			x++;
			if (x == 1)
				vitritang[vt++] = i;
		}
		if (a[i] > a[i + 1])
		{
			b[i1][j1++] = a[i];
			x++;
			dong[a1++] = x;
			x = 0;
			j1 = 0;
			i1++;
			dem++;
		}
	}
	int vtdong;
	int max = timmax(dong, dem, vtdong);
	cout << "chuoi co chieu dai max la: " << max << endl;
	for (int i = 0; i < max; i++)
	{
		cout << b[vtdong][i] << " ";
	}
}



int main()
{
	int a[] = { 0, 1, 0, 1, 3, 6, -5, 1, 2, -1, 1, 2, 3, 4, 5, 6, -5, -9 };
	int n = 18;
	int b[100][100];
	int dong[100];
	timmangcon(a, n, b, dong);
	return 0;
}


 for (int i = 0; i < k; i++)
 {
	 for (int j = 0; j < lmax; j++)
	 {
		 b[i][j] = a[c[i] + j];
			 //c[i] la vt bat dau cong j truy ra cac vtxq
	 }	
}

//bai3 
 void MaxDong(int a[][100], int d, int c, int b[], int& k) {
	 int max;
	 k = 0;
	 for (int i = 0; i < d; i++) {
		 max = a[i][0];
		 for (int j = 0; j < c; j++) {
			 if (a[i][j] > max)
				 max = a[i][j];
		 }
		 b[k++] = max;
	 }
 }
 void MaxCot(int a[][100], int d, int c, int b[], int& k) {
	 int max;
	 k = 0;
	 for (int j = 0; j < c; j++) {
		 max = a[0][j];
		 for (int i = 0; i < d; i++) {
			 if (a[i][j] > max)
				 max = a[i][j];
		 }
		 b[k++] = max;
	 }
 }
 void xuat1(int b[], int k)
 {
	 for (int i = 0; i < k; i++)
	 {
		 printf("%d\t", b[i]);
	 }
 }
//bai 4: tim pt tu lon nhat tren cot va min tren dong
 void timphantunndong(int a[100][100], int m, int n, int b[], int k)
 {
	 int ib = 0;
	// k = 0;
	 for (int i = 0; i < m; i++)
	 {
		 int min_dong = a[i][0]; 
		 int jmin = 0; 
		 int imin = 0;
		 for (int j = 0; j < n; j++)
		 {
			 if (a[i][j] < min_dong)
			 {
				 min_dong = a[i][j];
				 jmin = j; imin = i;
			 }

		 }
		 //tim pt min tren dong roi tim max cot
		 int kt = 1;
		 for (int k = 0; k < m; k++)
		 {
			 if(a[k][jmin]>min_dong)
			 {
				 kt = 0;
			 }
			
		 }
		 if (kt == 1)
		 {
			 b[ib] = min_dong;
			 ib++;
		 }
	 }
 }







 