﻿#include<iostream>

int** Allocate(const int m, const int n);

void FillRand(int arr[], const int n, int minRand =0, int maxRand =100);
void FillRand(int** arr, const int m, const int n);
void Print(int arr[], const int n);
void Print(int** arr, const int m, const int n);
void PrintArithmetic(int** arr, const int m, const int n); //Выводит двумерный динамический массив на экран используя арифметику указателей и оператор разыменования

void Push_back_mutable(int*& arr, int& n, int value);
void Push_front_mutable(int*& arr, int& n, int value);

void Push_row_back(int**& arr, int& m, const int n); //Добавляет строку в конец двумерного динамического массива
void Push_row_back_opt(int**& arr, int& m, const int n); //Добавляет строку в конец двумерного динамического массива
void Push_row_front(int**& arr, int& m, const int n); //Добавляет строку в начало двумерного динамического массива
void Push_row_front_opt(int**& arr, int& m, const int n); //Добавляет строку в начало двумерного динамического массива
void Push_col_back(int**& arr, const int m, int& n); //Добавляет столбик в конец двумерного динамического массива
void Push_col_back_opt(int**& arr, const int m, int& n); //Добавляет столбик в конец двумерного динамического массива
void Push_col_front(int**& arr, const int m, int& n); //Добавляет столбик в начало двумерного динамического массива
void Push_col_front_opt(int**& arr, const int m, int& n); //Добавляет столбик в начало двумерного динамического массива


void Insert_mutable(int*& arr, int& n, int value, int index); //Вставляет значение в массив по указанному индексу;
void Insert_row(int**& arr, int& m, int n, int index); //Вставляет строку в массив по указанному индексу;
void Insert_row_opt(int**& arr, int& m, int n, int index); //Вставляет строку в массив по указанному индексу;
void Insert_col(int**& arr, const int m, int& n, int index); //Вставляет столвик в массив по указанному индексу;
void Insert_col_opt(int**& arr, const int m, int& n, int index); //Вставляет столвик в массив по указанному индексу;

void Pop_back_mutable(int*& arr, int& n); //Удаляет значение с конца массива
void Pop_front_mutable(int*& arr, int& n); //Удаляет значение с начала массива

void Pop_row_back(int**& arr, int& m, const int n); //Удаляет строку в конеце двумерного динамического массива
void Pop_row_back_opt(int**& arr, int& m, const int n); //Удаляет строку в конеце двумерного динамического массива
void Pop_row_front(int**& arr, int& m, const int n); //Удаляет строку в начале двумерного динамического массива
void Pop_row_front_opt(int**& arr, int& m, const int n); //Удаляет строку в начале двумерного динамического массива
void Pop_col_back(int**& arr, const int m, int& n); //Удаляет столбик в конеце двумерного динамического массива
void Pop_col_back_opt(int**& arr, const int m, int& n); //Удаляет столбик в конеце двумерного динамического массива
void Pop_col_front(int**& arr, const int m, int& n); //Удаляет столбик в начале двумерного динамического массива
void Pop_col_front_opt(int**& arr, const int m, int& n); //Удаляет столбик в начале двумерного динамического массива

void Erase_mutable(int*& arr, int& n, int index); //Удаляет значение из массива по указанному индексу
void Erase_row(int**& arr, int& m, const int n, int index); //Удаляет строку из двумерного динамического массива по указанному индексу
void Erase_row_opt(int**& arr, int& m, const int n, int index); //Удаляет строку из двумерного динамического массива по указанному индексу
void Erase_col(int**& arr, const int m, int& n, int index); //Удаляет столбик из двумерного динамического массива по указанному индексу
void Erase_col_opt(int**& arr, const int m, int& n, int index); //Удаляет столбик из двумерного динамического массива по указанному индексу

void Clear(int** arr, const int m); // Удаляет двумерный динамический массив

#define DELIMETR std::cout <<"==============================================\n"

//#define HW_ADD_VALUE
//DONE:
/*
В проект DynamicMemory добавить алгоритм добавления элемента в конец массива.
*/

//#define CW_ADD_VALUE

//#define HW_ADD_INSERT //Вставляет значение в массив по указанному индексу;
//#define HW_ADD_POP_BACK //Удаляет значение с конца массива
//#define HW_ADD_POP_FRONT //Удаляет значение с начала массива
//#define HW_ADD_ERASE //Удаляет значение из массива по указанному индексу
//DONE:
/*
В проект DynamicMemory добавить функции:
void insert();	//Вставляет значение в массив по указанному индексу;
void pop_back();//Удаляет значение с конца массива
void pop_front();//Удаляет значение с начала массива
void erase();	//Удаляет значение из массива по указанному индексу
*/

//#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2

//#define HW_ADD_2021_02_03 //DONE
/*
1. Вывести двумерный динамический массив на экран используя арифметику указателей и оператор разыменования;
2. Код, выделяющий память под массив вынести в функцию ??? Allocate(???);
3. Код, удаляющий двумерный массив вынести в функцию ??? Clear(???);
4. Написать функцию ??? push_row_back(???), которая добавляет строку в конец двумерного динамического массива;
5. Написать функцию ??? push_row_front(???), которая добавляет строку в начало двумерного динамического массива;
6. Написать функцию ??? insert_row(???), которая вставляет строку в двумерный динамического массив по указанному индексу;
*/
#define HW_ADD_2021_02_05 //DONE
/*
7. Написать функцию ??? push_col_back(???), которая добавляет столбик в конец двумерного динамического массива;
8. Написать функцию ??? push_col_front(???), которая добавляет столбик в начало двумерного динамического массива;
9. Написать функцию ??? insert_col(???), которая вставляет столбик в двумерный динамического массив по указанному индексу;
10. Написать функцию ??? pop_row_back(???), которая удаляет строку в конеце двумерного динамического массива;
11. Написать функцию ??? pop_row_front(???), которая удаляет строку в начале двумерного динамического массива;
12. Написать функцию ??? erase_row(???), которая удаляет строку из двумерного динамического массива по указанному индексу;
13. Написать функцию ??? pop_col_back(???), которая удаляет столбик в конеце двумерного динамического массива;
14. Написать функцию ??? pop_col_front(???), которая удаляет столбик в начале двумерного динамического массива;
15. Написать функцию ??? erase_col(???), которая удаляет столбик из двумерного динамического массива по указанному индексу;
*/

//#define IZDEVATELSTVO

void main()
{
	setlocale(LC_ALL, "Russian");

	int m=20000;//Количество строк 
	int n=25000;//Количество столбцов(элементов строки)
	int index = 1;//Индекс для произведения мутаций массива

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

#ifdef HW_ADD_2021_02_03

	//std::cout << "Введите количество строк: "; std::cin >> m;
	//std::cout << "Введите количество элементов строки: "; std::cin >> n;

	//1. Создаём массив указателей и выделяем память для строк двумерного динамического массива:
	int** arr = Allocate(m, n);
	//std::cout << "Memory allocated" << std::endl;

	//2. Работа с двумерным динамическим массивом:
	FillRand(arr, m, n); //Заполнение массива
	std::cout << "Array filled" << std::endl;

	Print(arr, m, n); //Вывод массива в консоль
	DELIMETR;

	std::cout << "Массив выведен с использованием арифметики указателей и оператор разыменования:\n";
	PrintArithmetic(arr, m, n); //Вывод с использованием арифметики указателей и оператор разыменования
	DELIMETR;

	//std::cout << "Appending row..." << endl;
	Push_row_back_opt(arr, m, n); //Добавление строки в конец двумерного динамического массива
	std::cout << "Добавляена строка в конец двумерного динамического массива:\n";
	//std::cout << "Row appended" << std::endl;
	Print(arr, m, n); //Вывод массива в консоль
	DELIMETR;

	//std::cout << "Appending row..." << endl;
	Push_row_front_opt(arr, m, n); //Добавление строки в начоло двумерного динамического массива
	std::cout << "Добавляена строка в начало двумерного динамического массива:\n";
	//std::cout << "Row appended" << std::endl;
	Print(arr, m, n); //Вывод массива в консоль
	DELIMETR;

	do
	{//Проверка выхода за пределы массива
		if (index < 0 || index > m) std::cout << "Error. Выход за пределы масива. Повторите ввод." << std::endl; //Выход за пределы!!!
		std::cout << "Вставить строку по индексу: "; std::cin >> index; //Запросить индекс для добавления строки
	} while (index < 0 || index > m);
	//std::cout << "Insert row..." << endl;
	Insert_row_opt(arr, m, n, index); //Добавление строки по индексу в двумерный динамический массив
	std::cout << "Добавляена строка по индексу в двумерный динамический массив:\n";
	//std::cout << "Row appended" << std::endl;
	Print(arr, m, n); //Вывод массива в консоль
	DELIMETR;

	//4. Удаление двумерного динамического массива
	Clear(arr, m);
	delete[] arr;
#endif // HW_ADD_2021_02_03

#ifdef HW_ADD_2021_02_05

	//std::cout << "Введите количество строк: "; std::cin >> m;
	//std::cout << "Введите количество элементов строки: "; std::cin >> n;
	//1. Создаём массив указателей и выделяем память для строк двумерного динамического массива:
	int** arr = Allocate(m, n);
	std::cout << "Memory allocated" << std::endl;

	std::cout << "Filling array... ";
	FillRand(arr, m, n);
	std::cout << "Array fill" << std::endl;

	std::cout << "Appending col back... --opt\t";
	Push_col_back_opt(arr, m, n);
	std::cout << "Col back append. --opt" << std::endl;

	std::cout << "Appending col front... --opt\t";
	Push_col_front_opt(arr, m, n);
	std::cout << "Col front append. --opt" << std::endl;

	DELIMETR;
	//Print(arr, m, n);
	do
	{//Проверка выхода за пределы массива
		//std::cout << "Вставить столбец по индексу (0 - "<<n<<"): "; std::cin >> index; //Запросить индекс
		if (index < 0 || index > n) std::cout << "Error. Выход за пределы масива. Повторите ввод." << std::endl; //Выход за пределы!!!
	} while (index < 0 || index > n);
	std::cout << "Insert col of index... --opt\t";
	Insert_col_opt(arr, m, n, index);
	std::cout << "Col of index insert --opt" << std::endl;

	DELIMETR;
	//Print(arr, m, n);

	std::cout << "Poping row back... --opt\t";
	Pop_row_back_opt(arr, m, n);
	std::cout << "Row back pop --opt" << std::endl;

	std::cout << "Poping row front... --opt\t";
	Pop_row_front_opt(arr, m, n);
	std::cout << "Row front pop --opt" << std::endl;

	DELIMETR;
	//Print(arr, m, n);
	do
	{//Проверка выхода за пределы массива
		//std::cout << "Удалить строку по индексу (0 - " << m - 1 << "): "; std::cin >> index; //Запросить индекс
		if (index < 0 || index >= m) std::cout << "Error. Выход за пределы масива. Повторите ввод." << std::endl; //Выход за пределы!!!
	} while (index < 0 || index >= m);
	std::cout << "Erasing row of index... --opt\t";
	Erase_row_opt(arr, m, n, index);
	std::cout << "Row of index erase --opt" << std::endl;

	std::cout << "Poping col back... --opt\t";
	Pop_col_back_opt(arr, m, n);
	std::cout << "Col back pop --opt" << std::endl;

	std::cout << "Poping col front... --opt\t";
	Pop_col_front_opt(arr, m, n);
	std::cout << "Col front pop --opt" << std::endl;

	DELIMETR;
	//Print(arr, m, n);
	do
	{//Проверка выхода за пределы массива
		//std::cout << "Удалить колонку по индексу (0 - " << n - 1 << "): "; std::cin >> index; //Запросить индекс
		if (index < 0 || index >= n) std::cout << "Error. Выход за пределы масива. Повторите ввод." << std::endl; //Выход за пределы!!!
	} while (index < 0 || index >= n);
	std::cout << "Erasing col of index... --opt\t";
	Erase_col_opt(arr, m, n, index);
	std::cout << "Col of index erase --opt" << std::endl;

	DELIMETR;
	//Print(arr, m, n);

	//Очищаем память.
	Clear(arr, m);
	delete[] arr;

#endif //HW_ADD_2021_02_05

#ifdef IZDEVATELSTVO

	int** arr = Allocate(m, n);
	std::cout << "Memory allocated." << std::endl;
	std::cout << "Loading data..." << std::endl;
	FillRand(arr, m, n);
	Print(arr, m, n);
	std::cout << "Data loaded." << std::endl;
	std::wcout << "Appending row down..." << std::endl;
	Push_row_back_opt(arr, m, n);
	FillRand(arr[m - 1], n);
	Print(arr, m, n);
	std::cout << "Appending comlete!" << std::endl;
	Clear(arr, m);
	delete[] arr;
#endif // IZDEVATELSTVO

	std::cout << "\nПрограмма завершена.\n";
}

int** Allocate(const int m, const int n)
{
	//1. Создаём массив указателей:
	int** arr = new int* [m];
	//2. Выделяем память для строк двумерного динамического массива:
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}
	return arr;
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(int** arr, const int m, const int n)
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
void Print(int** arr, const int m, const int n)
{//Выводит двумерный динамический массив на экран используя индекс
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
void PrintArithmetic(int** arr, const int m, const int n)
{//Выводит двумерный динамический массив на экран используя арифметику указателей и оператор разыменования
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout.width(3);
			std::cout << *(*(arr+i)+j) << "  ";
		}
		std::wcout << "\n";
	}
}

void Push_back_mutable(int*& arr, int& n, int value)
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
void Push_front_mutable(int*& arr, int& n, int value)
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
void Push_row_back(int**& arr, int& m, const int n)
{//Добавляет строку в конец двумерного динамического массива
	//1. Создаём буферный массив
	int** buffer = Allocate(++m, n);

	//2. Копируем исходный массив в буферный массив, последнюю строчку заполняем нулями.
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			(i < m - 1) ? buffer[i][j] = arr[i][j]: buffer[i][j] = 0;
		}
	}

	//3. Удаляем исходный массив.
	Clear (arr,m - 1);
	delete[] arr;

	//4. Подменяем указатель на адрес нового массива.
	arr = buffer;
}
void Push_row_back_opt(int**& arr, int& m, const int n)
{//Добавляет строку в конец двумерного динамического массива
	int** buffer = new int* [++m];
	
	for (int i = 0; i < m -1; i++)
	{
			buffer[i] = arr[i];
	}

	delete[] arr;

	arr = buffer;

	buffer[m-1] = new int [n] {};
}
void Push_row_front(int**& arr, int& m, const int n)
{//Добавляет строку в начало двумерного динамического массива
	//1. Создаём буферный массив
	int** buffer = Allocate(++m, n);

	//2. Копируем со сдвигом исходный массив в буферный массив, первую строку заполняем нолями.
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			(i == 0) ? buffer[i][j] = 0 : buffer[i][j] = arr[i - 1][j];
		}
	}

	//3. Удаляем исходный массив.
	Clear(arr, m - 1);
	delete[] arr;

	//4. Подменяем указатель на адрес нового массива.
	arr = buffer;
}
void Push_row_front_opt(int**& arr, int& m, const int n)
{//Добавляет строку в начало двумерного динамического массива
	int** buffer = new int* [++m];

	for (int i = 0; i < m - 1; i++)
	{
		buffer[i + 1] = arr[i];
	}

	delete[] arr;

	arr = buffer;

	buffer[0] = new int [n] {};
}
void Push_col_back(int**& arr, const int m, int& n)
{//Добавляет столбик в конец двумерного динамического массива
	//1. Создаём буферный массив
	int** buffer = Allocate(m, ++n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			(j == n - 1) ? buffer[i][j] = 0 : buffer[i][j] = arr[i][j];
		}
	}

	//3. Удаляем исходный массив.
	Clear(arr, m);
	delete[] arr;

	//4. Подменяем указатель на адрес нового массива.
	arr = buffer;
}
void Push_col_back_opt(int**& arr, const int m, int& n)
{//Добавляет столбик в конец двумерного динамического массива
	n++;
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n]{};
		for (int j = 0; j < n - 1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
}
void Push_col_front(int**& arr, const int m, int& n)
{//Добавляет столбик в начало двумерного динамического массива
	int** buffer = Allocate(m, ++n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			(j == 0) ? buffer[i][j] = 0 : buffer[i][j] = arr[i][j-1];
		}
	}

	//3. Удаляем исходный массив.
	Clear(arr, m);
	delete[] arr;

	//4. Подменяем указатель на адрес нового массива.
	arr = buffer;
}
void Push_col_front_opt(int**& arr, const int m, int& n)
{//Добавляет столбик в начало двумерного динамического массива
	n++;
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n] {};
		for (int j = 0; j < n - 1; j++)
		{
			buffer[j+1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}

}

void Insert_mutable(int*& arr, int& n, int value, int index)
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
void Insert_row(int**& arr, int& m, int n, int index)
{//Вставляет строку в массив по указанному индексу;
	if (index > m)return;
	//1. Создаём буферный массив
	int** buffer = Allocate(++m, n);

	//2. Копируем со сдвигом исходный массив в буферный массив, первую строку заполняем нолями.
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < index) //До индекса обычное копирование
			{
				buffer[i][j] = arr[i][j];
			}
			else if (i == index) //При индексе заполняем нолями
			{
				buffer[i][j] = 0;
			}
			else //После индекса копирование со сдвигом
			{
				buffer[i][j] = arr[i - 1][j];
			}
		}
	}

	//3. Удаляем исходный массив.
	Clear(arr, m - 1);
	delete[] arr;

	//4. Подменяем указатель на адрес нового массива.
	arr = buffer;
}
void Insert_row_opt(int**& arr, int& m, int n, int index)
{//Вставляет строку в массив по указанному индексу;
	if (index > m)return;
	int** buffer = new int* [++m]{};

	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < m-1; i++)
	{
		buffer[i + 1] = arr[i];
	}

	delete[] arr;

	arr = buffer;
	arr[index] = new int[n] {};
}
void Insert_col(int**& arr, const int m, int& n, int index)
{//Вставляет столвик в массив по указанному индексу;
	//1. Создаём буферный массив
	int** buffer = Allocate(m, ++n);

	//2. Копируем со сдвигом исходный массив в буферный массив, первый столбик заполняем нолями.
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j < index) //До индекса обычное копирование
			{
				buffer[i][j] = arr[i][j];
			}
			else if (j == index) //При индексе заполняем нолями
			{
				buffer[i][j] = 0;
			}
			else //После индекса копирование со сдвигом
			{
				buffer[i][j] = arr[i][j-1];
			}
		}
	}

	//3. Удаляем исходный массив.
	Clear(arr, m);
	delete[] arr;

	//4. Подменяем указатель на адрес нового массива.
	arr = buffer;
}
void Insert_col_opt(int**& arr, const int m, int& n, int index)
{//Вставляет столвик в массив по указанному индексу;
	
	if (index >= n)return;
	n++;

	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n] {};
		for(int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < n - 1; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
}

void Pop_back_mutable(int*& arr, int& n)
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
void Pop_front_mutable(int*& arr, int& n)
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

void Pop_row_back(int**& arr, int & m, const int n)
{//Удаляет строку в конеце двумерного динамического массива
	if (m <= 0)return; //Слишком маленький массив для уменьшения

	int** buffer = Allocate(--m, n);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}

	//3. Удаляем исходный массив.
	Clear(arr, m + 1);
	delete[] arr;

	//4. Подменяем указатель на адрес нового массива.
	arr = buffer;
}
void Pop_row_back_opt(int**& arr, int& m, const int n)
{//Удаляет строку в конеце двумерного динамического массива
	int** buffer = new int* [--m];

	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	//delete[] arr[m]; //На всякий случай.
	delete[] arr;

	arr = buffer;
}
void Pop_row_front(int**& arr, int& m, const int n)
{//Удаляет строку в начале двумерного динамического массива
	if (m <= 0)return; //Слишком маленький массив для уменьшения

	int** buffer = Allocate(--m, n);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i + 1][j];
		}
	}

	//3. Удаляем исходный массив.
	Clear(arr, m + 1);
	delete[] arr;

	//4. Подменяем указатель на адрес нового массива.
	arr = buffer;
}
void Pop_row_front_opt(int**& arr, int& m, const int n)
{//Удаляет строку в начале двумерного динамического массива
	int** buffer = new int* [--m];

	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i + 1];
	}
	//delete[] arr[0]; //На всякий случай.
	delete[] arr;

	arr = buffer;
}

void Pop_col_back(int**& arr, const int m, int& n)
{//Удаляет столбик в конеце двумерного динамического массива
	if (n <= 0)return; //Слишком маленький массив для уменьшения

	int** buffer = Allocate(m, --n);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}

	//3. Удаляем исходный массив.
	Clear(arr, m);
	delete[] arr;

	//4. Подменяем указатель на адрес нового массива.
	arr = buffer;
}
void Pop_col_back_opt(int**& arr, const int m, int& n)
{//Удаляет столбик в конеце двумерного динамического массива
	n--;
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n] {};
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
}
void Pop_col_front(int**& arr, const int m, int& n)
{//Удаляет столбик в начале двумерного динамического массива
	if (n <= 0)return; //Слишком маленький массив для уменьшения

	int** buffer = Allocate(m, --n);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j + 1];
		}
	}

	//3. Удаляем исходный массив.
	Clear(arr, m);
	delete[] arr;

	//4. Подменяем указатель на адрес нового массива.
	arr = buffer;

}
void Pop_col_front_opt(int**& arr, const int m, int& n)
{//Удаляет столбик в начале двумерного динамического массива
	n--;
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n] {};
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j+ 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
}

void Erase_mutable(int*& arr, int& n, int index)
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

void Erase_row(int**& arr, int& m, const int n, int index)
{//Удаляет строку из двумерного динамического массива по указанному индексу
	if (m <= 0)return; //Слишком маленький массив для уменьшения

	int** buffer = Allocate(--m, n);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < index)
			{
				buffer[i][j] = arr[i][j];
			}
			else if (i >= index)
			{
				buffer[i][j] = arr[i + 1][j];
			}
		}
	}

	//3. Удаляем исходный массив.
	Clear(arr, m + 1);
	delete[] arr;

	//4. Подменяем указатель на адрес нового массива.
	arr = buffer;
}
void Erase_row_opt(int**& arr, int& m, const int n, int index)
{//Удаляет строку из двумерного динамического массива по указанному индексу
	if (index < 0 || index>m)return;

	int** buffer = new int* [--m];

	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < m; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
}
void Erase_col(int**& arr, const int m, int& n, int index)
{//Удаляет столбик из двумерного динамического массива по указанному индексу
	if (n <= 0)return; //Слишком маленький массив для уменьшения

	int** buffer = Allocate(m, --n);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j < index)
			{
				buffer[i][j] = arr[i][j];
			}
			else if (j >= index)
			{
				buffer[i][j] = arr[i][j + 1];
			}
		}
	}

	//3. Удаляем исходный массив.
	Clear(arr, m);
	delete[] arr;

	//4. Подменяем указатель на адрес нового массива.
	arr = buffer;
}
void Erase_col_opt(int**& arr, const int m, int& n, int index)
{//Удаляет столбик из двумерного динамического массива по указанному индексу
	if (index<0 || index>n)return;
	n--;
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int [n] {};
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < n; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
}

void Clear(int** arr, const int m)
{// Удаляет двумерный динамический массив
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
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