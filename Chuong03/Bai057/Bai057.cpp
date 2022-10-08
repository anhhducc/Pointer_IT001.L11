#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
void Nhap(int[], int&);
void Xuat(int[], int);
int DemChan(int[], int);
int DemLe(int[], int);
int TuongQuan(int[], int);

int main()
{
	int b[100];
	int k;
	Nhap(b, k);
	cout << "\nMang ban dau: ";
	Xuat(b, k);
	cout << "\nSu tuong quan giua so luong so chan va le: ";
	int kq = TuongQuan(b, k);
	cout << kq;
	return 1;
}

void Nhap(int a[], int& n)
{
	cout << "Nhap n: ";
	cin >> n;
	srand(std::time(nullptr));
	for (int i = 0; i < n; i++)
		a[i] = rand() % (200 + 1) - 100;
}

void Xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << setw(6) << a[i];
	}
}

int DemChan(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i <= n - 1; i++)
		if (a[i] % 2 == 0)
			dem++;
	return dem;
}

int DemLe(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i <= n - 1; i++)
		if (a[i] % 2 != 0)
			dem++;
	return dem;
}

int TuongQuan(int a[], int n)
{
	int x = DemChan(a, n);
	int y = DemLe(a, n);
	if (x > y)
		return -1;
	if (x < y)
		return 1;
	return 0;
}

