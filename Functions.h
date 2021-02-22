#pragma once
#include<iostream>
#include "Functions.cpp"

template<typename T>	T** Allocate(const int m, const int n);

template<typename T>	void Random(T& variable);

template<typename T>	void FillRand(T arr[], const int n, int minRand = 0, int maxRand = 100); //ƒл€ int одномерного массива...

template<typename T>	void FillRand(T** arr, const int m, const int n, int minRand = 0, int maxRand = 100);	//ƒл€ int двумерного массива...

template<typename T>	void Print(T arr[], const int n);
template<typename T>	void Print(T** arr, const int m, const int n);
template<typename T>	void PrintArithmetic(T** arr, const int m, const int n); //¬ыводит двумерный динамический массив на экран использу€ арифметику указателей и оператор разыменовани€

template<typename T>	void Push_back_mutable(T*& arr, int& n, T value);
template<typename T>	void Push_front_mutable(T*& arr, int& n, T value);

template<typename T>	void Push_row_back_opt(T**& arr, int& m, const int n); //ƒобавл€ет строку в конец двумерного динамического массива
template<typename T>	void Push_row_front_opt(T**& arr, int& m, const int n); //ƒобавл€ет строку в начало двумерного динамического массива
template<typename T>	void Push_col_back_opt(T**& arr, const int m, int& n); //ƒобавл€ет столбик в конец двумерного динамического массива
template<typename T>	void Push_col_front_opt(T**& arr, const int m, int& n); //ƒобавл€ет столбик в начало двумерного динамического массива

template<typename T>	void Insert_mutable(T*& arr, int& n, T value, int index); //¬ставл€ет значение в массив по указанному индексу;
template<typename T>	void Insert_row_opt(T**& arr, int& m, int n, int index); //¬ставл€ет строку в массив по указанному индексу;
template<typename T>	void Insert_col_opt(T**& arr, const int m, int& n, int index); //¬ставл€ет столвик в массив по указанному индексу;

template<typename T>	void Pop_back_mutable(T*& arr, int& n); //”дал€ет значение с конца массива
template<typename T>	void Pop_front_mutable(T*& arr, int& n); //”дал€ет значение с начала массива

template<typename T>	void Pop_row_back_opt(T**& arr, int& m, const int n); //”дал€ет строку в конеце двумерного динамического массива
template<typename T>	void Pop_row_front_opt(T**& arr, int& m, const int n); //”дал€ет строку в начале двумерного динамического массива
template<typename T>	void Pop_col_back_opt(T**& arr, const int m, int& n); //”дал€ет столбик в конеце двумерного динамического массива
template<typename T>	void Pop_col_front_opt(T**& arr, const int m, int& n); //”дал€ет столбик в начале двумерного динамического массива

template<typename T>	void Erase_mutable(T*& arr, int& n, int index); //”дал€ет значение из массива по указанному индексу
template<typename T>	void Erase_row_opt(T**& arr, int& m, const int n, int index); //”дал€ет строку из двумерного динамического массива по указанному индексу
template<typename T>	void Erase_col_opt(T**& arr, const int m, int& n, int index); //”дал€ет столбик из двумерного динамического массива по указанному индексу

template<typename T>	void Clear(T** arr, const int m); // ”дал€ет двумерный динамический массив
