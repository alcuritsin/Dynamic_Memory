//TODO
/*
В проект DynamicMemory добавить функции:
void insert();	//Вставляет значение в массив по указанному индексу;
void pop_back();//Удаляет значение с конца массива
void pop_front();//Удаляет значение с начала массива
void erase();	//Удаляет значение из массива по указанному индексу
*/

//DONE:
/*
В проект DynamicMemory добавить алгоритм добавления элемента в конец массива.
*/

#include<iostream>

void FillRand(int arr[], const int n);
void FillRand(int ** arr, const int m, const int n);
void Print(int arr[], const int n);
void Print(int ** arr, const int m, const int n);

void push_back_mutable(int*& arr, int& n, int value);
void push_front_mutable(int*& arr, int& n, int value);

void insert_mutable(int*& arr, int& n, int value, int index); //Вставляет значение в массив по указанному индексу;

void pop_back_mutable(int*& arr, int& n); //Удаляет значение с конца массива
void pop_front_mutable(int*& arr, int& n); //Удаляет значение с начала массива

void erase_mutable(int*& arr, int& n, int index); //Удаляет значение из массива по указанному индексу

#define DELIMETR std::cout <<"==============================================\n"

//#define HW_ADD_VALUE

//#define CW_ADD_VALUE

//#define HW_ADD_INSERT //Вставляет значение в массив по указанному индексу;
//#define HW_ADD_POP_BACK //Удаляет значение с конца массива
//#define HW_ADD_POP_FRONT //Удаляет значение с начала массива
//#define HW_ADD_ERASE //Удаляет значение из массива по указанному индексу

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef DYNAMIC_MEMORY_1
	int n;
	std::cout << "Введите размер массива: "; std::cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value; //Значение для передачи в массив
	int index = 0; //Индекс для передачи в массив

	//std::cout << "Введите значение: "; std::cin >> value;

#ifdef HW_ADD_VALUE
	int* brr = new int[++n];
	for (int i = 0; i < n - 1; i++)
	{
		brr[i] = arr[i];
	}

	brr[n - 1] = value;

	Print(brr, n);

	delete[] brr;
#endif // HW_ADD_VALUE

#ifdef CW_ADD_VALUE
	std::cout << "Введите значение: "; std::cin >> value;

	push_back_mutable(arr, n, value);
	Print(arr, n);

	std::cout << "Введите значение: "; std::cin >> value;
	push_front_mutable(arr, n, value);
	Print(arr, n);

#endif // CW_ADD_VALUE

#ifdef HW_ADD_INSERT //Вставляет значение в массив по указанному индексу;

	std::cout << "INSERT_mutable\n";
	std::cout << "Вставляет значение в массив по указанному индексу.\n";
	DELIMETR;

	std::cout << "Введите значение: "; std::cin >> value;
	do
	{
		std::cout << "Введите индекс: "; std::cin >> index;
		if (index <= n && index < 0) std::cout << "Error: Введён некорректный индекс. Повторите ввод.\n";
	} while (index <= n && index < 0); //Проверка на корректность индекса (чтобы он не выходил за пределы массива)

	insert_mutable(arr, n, value, index);

	Print(arr, n);

#endif // HW_ADD_INSERT

#ifdef HW_ADD_POP_BACK //Удаляет значение с конца массива

	std::cout << "POP_BACK_mutable\n";
	std::cout << "Удаляет значение с конца массива.\n";
	DELIMETR;

	pop_back_mutable(arr, n);

	Print(arr, n);

#endif // HW_ADD_POP_BACK

#ifdef HW_ADD_POP_FRONT //Удаляет значение с начала массива

	std::cout << "POP_FRONT_mutable\n";
	std::cout << "Удаляет значение с начала массива.\n";
	DELIMETR;

	pop_front_mutable(arr, n);

	Print(arr, n);

#endif // HW_ADD_POP_FRONT

#ifdef HW_ADD_ERASE //Удаляет значение из массива по указанному индексу

	std::cout << "ERASE_mutable\n";
	std::cout << "Удаляет значение из массива по указанному индексу.\n";
	DELIMETR;

	do
	{
		std::cout << "Введите индекс: "; std::cin >> index;
		if (index <= n && index < 0) std::cout << "Error: Введён некорректный индекс. Повторите ввод.\n";
	} while (index <= n && index < 0); //Проверка на корректность индекса (чтобы он не выходил за пределы массива)

	erase_mutable(arr, n, index);

	Print(arr, n);

#endif // HW_ADD_ERASE

	//Удалили указатель на массив.
	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2

	int m=0;//Количество строк
	int n=0;//Количество столбцов(элементов строки)

	std::cout << "Введите количество строк: "; std::cin >> m;
	std::cout << "Введите количество элементов строки: "; std::cin >> n;
	//1. Создаём массив указателей:
	int** arr = new int* [m];
	//2. Выделяем память для строк двумерного динамического массива:
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}
	//3. Работа с двумерным динамическим массивом:
	FillRand(arr, m, n);

	Print(arr, m,n);

	//4. Удаление двумерного динамического массива
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

#endif // DYNAMIC_MEMORY_2


	std::cout << "Программа завершена.";
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand()%100;
	}
}

void FillRand(int ** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
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

void Print(int ** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout.width(3);
			std::cout << arr[i][j] << "  ";
		}
		std::wcout << "\n";
	}
}

void push_back_mutable(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr; //Удалили указатель на массив.

	arr = buffer; //Присвоили буферный массив старому указателю
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

void insert_mutable(int*& arr, int& n, int value, int index)
{//Вставляет значение в массив по указанному индексу;
	//1. Создаём буферный массив.
	int* buffer = new int[++n]{};
	//2. Копируем исходный массив в буферный массив и сразу вставляем элемент по индексу.
			//buffer[index] = value;
	//for (int i = 0; i < n; i++)
	//{
	//	if (i < index)
	//	{
	//		buffer[i] = arr[i];
	//	}
	//	else if (i>index)
	//	{
	//		buffer[i] = arr[i-1];
	//	}
	//}

	for (int i = 0; i < n; i++)
	{
		buffer[i] = i < index ? arr[i] : i>index ? arr[i - 1] : value;
	}

	//3. Удаляем исходный массив.
	delete[] arr;
	//4. Подменяем указатель на адрес нового массива.
	arr = buffer;
	//5. Увеличиваем размер массива 'n'
}

void pop_back_mutable(int*& arr, int& n)
{//Удаляет значение с конца массива
	//1. Создаём буферный массив.
	int* buffer = new int[--n]{};
	//2. Копируем исходный массив в буферный массив. Исключая последний элемент.
	for (int i = 0; i < n; i++)
	{
			buffer[i] = arr[i];
	}
	//3. Удаляем исходный массив.
	delete[] arr;
	//4. Подменяем указатель на адрес нового массива.
	arr = buffer;
}

void pop_front_mutable(int*& arr, int& n)
{//Удаляет значение с начала массива
	//1. Создаём буферный массив.
	int* buffer = new int[--n]{};
	//2. Копируем исходный массив в буферный массив со сдвигом.
	for (int i = 0; i < n; i++)
	{
			buffer[i] = arr[i+1];
	}
	//3. Удаляем исходный массив.
	delete[] arr;
	//4. Подменяем указатель на адрес нового массива.
	arr = buffer;
}

void erase_mutable(int*& arr, int& n, int index)
{//Удаляет значение из массива по указанному индексу
	//1. Создаём буферный массив.
	int* buffer = new int[n - 1]{};
	//2. Копируем исходный массив в буферный массив и сразу вставляем элемент по индексу.
	for (int i = 0; i < n - 1; i++)
	{
		if (i < index)
		{
			buffer[i] = arr[i];
		}
		else
		{
			buffer[i] = arr[i + 1];
		}
	}
	//3. Удаляем исходный массив.
	delete[] arr;
	//4. Подменяем указатель на адрес нового массива.
	arr = buffer;
	//5. Увеличиваем размер массива 'n'
	n--;
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