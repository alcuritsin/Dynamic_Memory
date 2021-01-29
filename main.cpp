//TODO:
/*
В проект DynamicMemory добавить алгоритм добавления элемента в конец массива.
*/

#include<iostream>

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void push_back_mutable(int*& arr, int& n, int value);
void push_front_mutable(int*& arr, int& n, int value);

//#define HW_ADD_VALUE
#define CW_ADD_VALUE

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	std::cout << "Введите размер массива: "; std::cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	
	int value;
	std::cout << "Введите значение: "; std::cin >> value;

#ifdef HW_ADD_VALUE
	int* brr = new int[++n];
	for (int i = 0; i < n - 1; i++)
	{
		brr[i] = arr[i];
	}

	brr[n - 1] = value;
	delete[] arr;

	Print(brr, n);

	delete[] brr;
#endif // HW_ADD_VALUE
	
#ifdef CW_ADD_VALUE

	push_back_mutable(arr, n, value);
	Print(arr, n);

	std::cout << "Введите значение: "; std::cin >> value;
	push_front_mutable(arr, n, value);
	Print(arr, n);

	delete[] arr;

#endif // CW_ADD_VALUE





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

void push_back_mutable(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr; //Удалили указатель на массив.

	arr = buffer; //Присвоили бухерный массив старому указателю
	arr[n] = value; //В паследний индекс присваиваем новое значение.
	n++;

}
void push_front_mutable(int*& arr, int& n, int value)
{ //Добавляет значение в начало массива.
	//1. Создаём буферный массив
	int* buffer = new int[n + 1]{};
	//2. Копируем исходный массив в буферный массив со смещением.
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	//3. Удаляем исходный массив.
	delete[] arr;
	//4. Подменяем указатель на адрес нового массива.
	arr = buffer;
	//5. В начало массива добавляем значение.
	arr[0] = value;
	//6. Увеличиваем размер массива 'n'
	n++;
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