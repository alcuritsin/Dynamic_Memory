//TODO:
/*
В проект DynamicMemory добавить алгоритм добавления элемента в конец массива.
*/

#include<iostream>

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	std::cout << "Введите размер массива: "; std::cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	
	int value;
	std::cout << "Введите размер значение: "; std::cin >> value;
	
	int* brr = new int[++n];
	for (int i = 0; i < n - 1; i++)
	{
		brr[i] = arr[i];
	}

	brr[n - 1] = value;
	delete[] arr;

	Print(brr, n);

	delete[] brr;

	std::cout << "Программа завершена.";
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand()%100;
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

//Исполнитель
/*
-----------------------------------------------------
|                                                   |
|   "Компьютерная академия ШАГ"                     |
|   Курс: БД011                                     |
|   Предмет: Основы програмvирования на языке C++   |
|                                                   |
|   Исполнитель: Курицын Алексей                    |
|   Преподаватель: Ковтун Олег                      |
|                                                   |
|   Екатеринбург - 2021                             |
|                                                   |
-----------------------------------------------------*/