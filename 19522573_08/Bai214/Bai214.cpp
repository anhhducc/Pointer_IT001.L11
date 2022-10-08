#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

struct diem
{
	float x;
	float y;
};
typedef struct diem DIEM;

struct duongtron
{
	DIEM I;
	float R;
};
typedef struct duongtron DUONGTRON;

void Nhap(DUONGTRON&);
void Nhap(DUONGTRON[], int&);
void Nhap(DIEM&);
void Xuat(DUONGTRON);
void Xuat(DUONGTRON[], int);
void Xuat(DIEM);
float KhoangCachGoc(DUONGTRON);
DUONGTRON GanGocNhat(DUONGTRON[], int);


int main()
{
	DUONGTRON b[100];
	int k;

	Nhap(b, k);
	cout << "\nMang ban dau: " << endl;
	Xuat(b, k);
	cout << "\nDuong tron gan goc toa do nhat: ";
	Xuat(GanGocNhat(b, k));
	return 1;
}

void Nhap(DIEM& P)
{
	cout << "Nhap x: ";
	cin >> P.x;
	cout << "Nhap y: ";
	cin >> P.y;
}

void Nhap(DUONGTRON& c)
{
	cout << endl;
	cout << "Nhap tam: \n";
	Nhap(c.I);
	cout << "Nhap ban kinh: ";
	cin >> c.R;
}

void Nhap(DUONGTRON a[], int& n)
{
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "Nhap a[" << i << "]: ";
		Nhap(a[i]);
	}
}

void Xuat(DIEM P)
{
	cout << "\nx: " << P.x;
	cout << "\ny: " << P.y;
}

void Xuat(DUONGTRON c)
{
	cout << "\nTam: ";
	Xuat(c.I);
	cout << "\nBan kinh: " << c.R << endl;
}


void Xuat(DUONGTRON a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nDuong tron a[" << i << "]:";
		Xuat(a[i]);
	}

}

float KhoangCachGoc(DIEM p)
{
	return sqrt(p.x * p.x + p.y * p.y);
}

float KhoangCachGoc(DUONGTRON c)
{
	float kc = KhoangCachGoc(c.I);
	return abs(kc - c.R);
}

DUONGTRON GanGocNhat(DUONGTRON a[], int n)
{
	DUONGTRON lc = a[0];
	for (int i = 0; i < n; i++)
		if (KhoangCachGoc(a[i]) < KhoangCachGoc(lc))
			lc = a[i];
	return lc;
}
