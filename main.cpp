﻿#include "Functions.h"
//#include "Functions.cpp"

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

typedef char data_type; //Псевдоним для типа

void main()
{
	setlocale(LC_ALL, "Russian");

	int m=6;//Количество строк 
	int n=5;//Количество столбцов(элементов строки)
	int index = 1;//Индекс для произведения мутаций массива

	//std::cout << "Старт тестирования одномерного массива:\n";
	//std::cout << "Тестирование одномерного массива:\n";




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
	data_type** arr = new int* [m];
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
	data_type** arr = Allocate<data_type>(m, n);
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
	data_type** arr = Allocate<data_type>(m, n);
	std::cout << "Memory allocated" << std::endl;

	std::cout << "Filling array... ";
	FillRand(arr, m, n, 33, 250);
	std::cout << "Array fill" << std::endl;
	Print(arr, m, n);

	std::cout << "Appending row back... --opt\t";
	Push_row_back_opt(arr, m, n);
	std::cout << "Row back append. --opt" << std::endl;

	std::cout << "Appending row back... --opt\t";
	Push_row_front_opt(arr, m, n);
	std::cout << "Row back append. --opt" << std::endl;

	std::cout << "Appending col back... --opt\t";
	Push_col_back_opt(arr, m, n);
	std::cout << "Col back append. --opt" << std::endl;

	std::cout << "Appending col front... --opt\t";
	Push_col_front_opt(arr, m, n);
	std::cout << "Col front append. --opt" << std::endl;

	DELIMETR;
	Print(arr, m, n);
	do
	{//Проверка выхода за пределы массива
		//std::cout << "Вставить столбец по индексу (0 - "<<n<<"): "; std::cin >> index; //Запросить индекс
		if (index < 0 || index > n) std::cout << "Error. Выход за пределы масива. Повторите ввод." << std::endl; //Выход за пределы!!!
	} while (index < 0 || index > n);
	std::cout << "Insert col of index... --opt\t";
	Insert_col_opt(arr, m, n, index);
	std::cout << "Col of index insert --opt" << std::endl;

	DELIMETR;
	Print(arr, m, n);

	std::cout << "Poping row back... --opt\t";
	Pop_row_back_opt(arr, m, n);
	std::cout << "Row back pop --opt" << std::endl;

	std::cout << "Poping row front... --opt\t";
	Pop_row_front_opt(arr, m, n);
	std::cout << "Row front pop --opt" << std::endl;

	DELIMETR;
	Print(arr, m, n);
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
	Print(arr, m, n);
	do
	{//Проверка выхода за пределы массива
		//std::cout << "Удалить колонку по индексу (0 - " << n - 1 << "): "; std::cin >> index; //Запросить индекс
		if (index < 0 || index >= n) std::cout << "Error. Выход за пределы масива. Повторите ввод." << std::endl; //Выход за пределы!!!
	} while (index < 0 || index >= n);
	std::cout << "Erasing col of index... --opt\t";
	Erase_col_opt(arr, m, n, index);
	std::cout << "Col of index erase --opt" << std::endl;

	DELIMETR;
	Print(arr, m, n);

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