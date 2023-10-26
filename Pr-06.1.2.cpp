#include <iostream>
#include <iomanip>

using namespace std;

void Create(int* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}
void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i];
	cout << endl;
}

int sum(int* a, const int size, int i) {
	if (i < size)
	{
		if (a[i] < 0 || a[i] % 2 == 1)
		{
			return a[i] + sum(a, size, i + 1);
		}
		else {
			return sum(a, size, i + 1);
		}
	}
	else {
		return 0;
	}

}
int count(int* a, const int size, int i)
{
	if (i < size)
	{
		if (a[i] < 0 || a[i] % 2 == 1)
		{
			return 1 + count(a, size, i + 1);
		}
		else {
			return count(a, size, i + 1);
		}
	}
	else {
		return 0;
	}
}
void replace(int* a, const int size, int i)
{

	if (i < size)
	{
		if (a[i] < 0 || a[i] % 2 == 1)
		{
			a[i] = 0;

		}
		replace(a, size, i + 1);
	}

}
int main()
{
	srand(time(0));
	int arr[24];
	int size = 24;
	Create(arr, size, -50, 15);
	Print(arr, size);

	cout << "sum of negative or odd numbers " << sum(arr, size, 0) << endl;
	cout << "amount of negative or odd numbers " << count(arr, size, 0) << endl;
	replace(arr, size, 0);
	Print(arr, size);
	return 0;
}

