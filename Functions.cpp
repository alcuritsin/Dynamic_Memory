#include<iostream>
template<typename T>	T** Allocate(const int m, const int n)
{
	//1. ������ ������ ����������:
	T** arr = new T * [m];
	//2. �������� ������ ��� ����� ���������� ������������� �������:
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
	{//������� ��������� ������������ ������ �� ����� ��������� ������
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
	{//������� ��������� ������������ ������ �� ����� ��������� ���������� ���������� � �������� �������������
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

		delete[] arr; //������� ��������� �� ������.

		arr = buffer; //��������� �������� ������ ������� ���������
		arr[n] = value; //� ��������� ������ ����������� ����� ��������.
		n++;
	}
template<typename T>	void Push_front_mutable(T * &arr, int& n, T value)
	{ //��������� �������� � ������ �������.
		//1. ������ �������� ������
		T* buffer = new T[n + 1]{};
		//2. �������� �������� ������ � �������� ������ �� ���������.
		for (int i = 0; i < n; i++)
		{
			buffer[i + 1] = arr[i];
		}
		//3. ������� �������� ������.
		delete[] arr;
		//4. ��������� ��������� �� ����� ������ �������.
		arr = buffer;
		//5. � ������ ������� ��������� ��������.
		arr[0] = value;
		//6. ����������� ������ ������� 'n'
		n++;
	}
template<typename T>	void Push_row_back_opt(T * *&arr, int& m, const int n)
	{//��������� ������ � ����� ���������� ������������� �������
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
	{//��������� ������ � ������ ���������� ������������� �������
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
	{//��������� ������� � ����� ���������� ������������� �������
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
	{//��������� ������� � ������ ���������� ������������� �������
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
	{//��������� �������� � ������ �� ���������� �������;
		//1. ������ �������� ������.
		T* buffer = new T[++n]{};
		//2. �������� �������� ������ � �������� ������ � ����� ��������� ������� �� �������.
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

		//3. ������� �������� ������.
		delete[] arr;
		//4. ��������� ��������� �� ����� ������ �������.
		arr = buffer;
		//5. ����������� ������ ������� 'n'
	}
template<typename T>	void Insert_row_opt(T * *&arr, int& m, int n, int index)
	{//��������� ������ � ������ �� ���������� �������;
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
	{//��������� ������� � ������ �� ���������� �������;

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
	{//������� �������� � ����� �������
		//1. ������ �������� ������.
		T* buffer = new T[--n]{};
		//2. �������� �������� ������ � �������� ������. �������� ��������� �������.
		for (int i = 0; i < n; i++)
		{
			buffer[i] = arr[i];
		}
		//3. ������� �������� ������.
		delete[] arr;
		//4. ��������� ��������� �� ����� ������ �������.
		arr = buffer;
	}
template<typename T>	void Pop_front_mutable(T * &arr, int& n)
	{//������� �������� � ������ �������
		//1. ������ �������� ������.
		T* buffer = new T[--n]{};
		//2. �������� �������� ������ � �������� ������ �� �������.
		for (int i = 0; i < n; i++)
		{
			buffer[i] = arr[i + 1];
		}
		//3. ������� �������� ������.
		delete[] arr;
		//4. ��������� ��������� �� ����� ������ �������.
		arr = buffer;
	}

template<typename T>	void Pop_row_back_opt(T * *&arr, int& m, const int n)
	{//������� ������ � ������ ���������� ������������� �������
		T** buffer = new T * [--m];

		for (int i = 0; i < m; i++)
		{
			buffer[i] = arr[i];
		}
		delete[] arr[m]; //������� ��������� ������ �� ������
		delete[] arr; //������� ������ ����������.

		arr = buffer; //��������� �� ����� ������ ����������
	}
template<typename T>	void Pop_row_front_opt(T * *&arr, int& m, const int n)
	{//������� ������ � ������ ���������� ������������� �������
		T** buffer = new T * [--m];

		for (int i = 0; i < m; i++)
		{
			buffer[i] = arr[i + 1];
		}
		delete[] arr[0]; //�� ������ ������.
		delete[] arr;

		arr = buffer;
	}

template<typename T>	void Pop_col_back_opt(T * *&arr, const int m, int& n)
	{//������� ������� � ������ ���������� ������������� �������
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
	{//������� ������� � ������ ���������� ������������� �������
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
	{//������� �������� �� ������� �� ���������� �������
		//1. ������ �������� ������.
		T* buffer = new T[n - 1]{};
		//2. �������� �������� ������ � �������� ������ � ����� ��������� ������� �� �������.
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
		//3. ������� �������� ������.
		delete[] arr;
		//4. ��������� ��������� �� ����� ������ �������.
		arr = buffer;
		//5. ����������� ������ ������� 'n'
		n--;
	}

template<typename T>	void Erase_row_opt(T * *&arr, int& m, const int n, int index)
	{//������� ������ �� ���������� ������������� ������� �� ���������� �������
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
	{//������� ������� �� ���������� ������������� ������� �� ���������� �������
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
	{// ������� ��������� ������������ ������
		for (int i = 0; i < m; i++)
		{
			delete[] arr[i];
		}
	}
