#include<iostream>
template<typename T>	T** Allocate(const int m, const int n)
{
	//1. Создаём массив указателей:
	T** arr = new T * [m];
	//2. Выделяем память для строк двумерного динамического массива:
	for (int i = 0; i < m; i++)
	{
		arr[i] = new T[n];
	}
	return arr;
}

template<typename T>	void Random(T& variable)
{
	if (typeid(variable) == typeid(int))
	{
		variable = rand() % 100;
	}
	else if (typeid(variable) == typeid(float) || typeid(variable) == typeid(double))
	{
		variable = double(rand() % 10000) / 100;
	}
	else if (typeid(variable) == typeid(char))
	{
		variable = rand();
	}
	else
	{
		variable = T();
	}
}

template<typename T>	void FillRand(T arr[], const int n, int minRand, int maxRand)
	{
		for (int i = 0; i < n; i++)
		{
			Random(arr[i]);
			//arr[i] = RandomInt(minRand,maxRand);
		}
	}

template<typename T>	void FillRand(T * *arr, const int m, const int n, int minRand, int maxRand)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				Random(arr[i][j]);
				//arr[i][j] = RandomInt(minRand, maxRand);
			}
		}
	}

template<typename T>	void Print(T arr[], const int n)
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << arr[i] << "  ";
		}
		std::cout << std::endl << std::endl;
	}
template<typename T>	void Print(T * *arr, const int m, const int n)
	{//Выводит двумерный динамический массив на экран используя индекс
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				//std::cout.width(3);
				std::cout << arr[i][j] << "  ";
			}
			std::wcout << "\n";
		}
	}
template<typename T>	void PrintArithmetic(T * *arr, const int m, const int n)
	{//Выводит двумерный динамический массив на экран используя арифметику указателей и оператор разыменования
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				//std::cout.width(3);
				std::cout << *(*(arr + i) + j) << "  ";
			}
			std::wcout << "\n";
		}
	}

template<typename T>	void Push_back_mutable(T * &arr, int& n, T value)
	{
		T* buffer = new T[n + 1]{};
		for (int i = 0; i < n; i++)
		{
			buffer[i] = arr[i];
		}

		delete[] arr; //Удалили указатель на массив.

		arr = buffer; //Присвоили буферный массив старому указателю
		arr[n] = value; //В паследний индекс присваиваем новое значение.
		n++;
	}
template<typename T>	void Push_front_mutable(T * &arr, int& n, T value)
	{ //Добавляет значение в начало массива.
		//1. Создаём буферный массив
		T* buffer = new T[n + 1]{};
		//2. Копируем исходный массив в буферный массив со смещением.
		for (int i = 0; i < n; i++)
		{
			buffer[i + 1] = arr[i];
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
template<typename T>	void Push_row_back_opt(T * *&arr, int& m, const int n)
	{//Добавляет строку в конец двумерного динамического массива
		T** buffer = new T * [++m];

		for (int i = 0; i < m - 1; i++)
		{
			buffer[i] = arr[i];
		}

		delete[] arr;

		arr = buffer;

		buffer[m - 1] = new T[n]{};
	}
template<typename T>	void Push_row_front_opt(T * *&arr, int& m, const int n)
	{//Добавляет строку в начало двумерного динамического массива
		T** buffer = new T * [++m];

		for (int i = 0; i < m - 1; i++)
		{
			buffer[i + 1] = arr[i];
		}

		delete[] arr;

		arr = buffer;

		buffer[0] = new T[n]{};
	}
template<typename T>	void Push_col_back_opt(T * *&arr, const int m, int& n)
	{//Добавляет столбик в конец двумерного динамического массива
		n++;
		for (int i = 0; i < m; i++)
		{
			T* buffer = new T[n]{};
			for (int j = 0; j < n - 1; j++)
			{
				buffer[j] = arr[i][j];
			}
			delete[] arr[i];
			arr[i] = buffer;
		}
	}
template<typename T>	void Push_col_front_opt(T * *&arr, const int m, int& n)
	{//Добавляет столбик в начало двумерного динамического массива
		n++;
		for (int i = 0; i < m; i++)
		{
			T* buffer = new T[n]{};
			for (int j = 0; j < n - 1; j++)
			{
				buffer[j + 1] = arr[i][j];
			}
			delete[] arr[i];
			arr[i] = buffer;
		}

	}

template<typename T>	void Insert_mutable(T * &arr, int& n, T value, int index)
	{//Вставляет значение в массив по указанному индексу;
		//1. Создаём буферный массив.
		T* buffer = new T[++n]{};
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
template<typename T>	void Insert_row_opt(T * *&arr, int& m, int n, int index)
	{//Вставляет строку в массив по указанному индексу;
		if (index > m)return;
		T** buffer = new T * [++m]{};

		for (int i = 0; i < index; i++)
		{
			buffer[i] = arr[i];
		}
		for (int i = index; i < m - 1; i++)
		{
			buffer[i + 1] = arr[i];
		}

		delete[] arr;

		arr = buffer;
		arr[index] = new T[n]{};
	}
template<typename T>	void Insert_col_opt(T * *&arr, const int m, int& n, int index)
	{//Вставляет столвик в массив по указанному индексу;

		if (index >= n)return;
		n++;

		for (int i = 0; i < m; i++)
		{
			T* buffer = new T[n]{};
			for (int j = 0; j < index; j++)
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

template<typename T>	void Pop_back_mutable(T * &arr, int& n)
	{//Удаляет значение с конца массива
		//1. Создаём буферный массив.
		T* buffer = new T[--n]{};
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
template<typename T>	void Pop_front_mutable(T * &arr, int& n)
	{//Удаляет значение с начала массива
		//1. Создаём буферный массив.
		T* buffer = new T[--n]{};
		//2. Копируем исходный массив в буферный массив со сдвигом.
		for (int i = 0; i < n; i++)
		{
			buffer[i] = arr[i + 1];
		}
		//3. Удаляем исходный массив.
		delete[] arr;
		//4. Подменяем указатель на адрес нового массива.
		arr = buffer;
	}

template<typename T>	void Pop_row_back_opt(T * *&arr, int& m, const int n)
	{//Удаляет строку в конеце двумерного динамического массива
		T** buffer = new T * [--m];

		for (int i = 0; i < m; i++)
		{
			buffer[i] = arr[i];
		}
		delete[] arr[m]; //Удаляем последнюю строку из памяти
		delete[] arr; //Удаляем массив указателей.

		arr = buffer; //Подменяем на новый массив указателей
	}
template<typename T>	void Pop_row_front_opt(T * *&arr, int& m, const int n)
	{//Удаляет строку в начале двумерного динамического массива
		T** buffer = new T * [--m];

		for (int i = 0; i < m; i++)
		{
			buffer[i] = arr[i + 1];
		}
		delete[] arr[0]; //На всякий случай.
		delete[] arr;

		arr = buffer;
	}

template<typename T>	void Pop_col_back_opt(T * *&arr, const int m, int& n)
	{//Удаляет столбик в конеце двумерного динамического массива
		n--;
		for (int i = 0; i < m; i++)
		{
			T* buffer = new T[n]{};
			for (int j = 0; j < n; j++)
			{
				buffer[j] = arr[i][j];
			}
			delete[] arr[i];
			arr[i] = buffer;
		}
	}
template<typename T>	void Pop_col_front_opt(T * *&arr, const int m, int& n)
	{//Удаляет столбик в начале двумерного динамического массива
		n--;
		for (int i = 0; i < m; i++)
		{
			T* buffer = new T[n]{};
			for (int j = 0; j < n; j++)
			{
				buffer[j] = arr[i][j + 1];
			}
			delete[] arr[i];
			arr[i] = buffer;
		}
	}

template<typename T>	void Erase_mutable(T * &arr, int& n, int index)
	{//Удаляет значение из массива по указанному индексу
		//1. Создаём буферный массив.
		T* buffer = new T[n - 1]{};
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

template<typename T>	void Erase_row_opt(T * *&arr, int& m, const int n, int index)
	{//Удаляет строку из двумерного динамического массива по указанному индексу
		if (index < 0 || index>m)return;

		T** buffer = new T * [--m];

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
template<typename T>	void Erase_col_opt(T * *&arr, const int m, int& n, int index)
	{//Удаляет столбик из двумерного динамического массива по указанному индексу
		if (index<0 || index>n)return;
		n--;
		for (int i = 0; i < m; i++)
		{
			T* buffer = new T[n]{};
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

template<typename T>	void Clear(T * *arr, const int m)
	{// Удаляет двумерный динамический массив
		for (int i = 0; i < m; i++)
		{
			delete[] arr[i];
		}
	}
