#include<iostream>
#include<ctime>

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 10;
	int arr[n];

	std::cout << time(NULL) << std::endl;

	srand(time(NULL));
	FillRand(arr, n);
	Print(arr, n);

	int even_count = 0;
	int odd_count = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even_count++;
		}
		else
		{
			odd_count++;
		}
	}

	int* even_values = new int [even_count] {};
	int* odd_values = new int [odd_count] {};

	for (int i = 0, i_even = 0, i_odd = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even_values[i_even++] = arr[i];
		}
		else
		{
			odd_values[i_odd++] = arr[i];
		}
	}

	std::cout << "Массив ЧЕТНЫХ значений:\n";
	Print(even_values, even_count);

	std::cout << "Массив НЕ ЧЕТНЫХ значений:\n";
	Print(odd_values, odd_count);

	delete[]even_values;
	delete[]odd_values;

	std::cout << "Программа завершена.\n";
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << "  ";
	}
	std::cout << std::endl << std::endl;
}