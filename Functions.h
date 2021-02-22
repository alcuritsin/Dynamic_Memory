#pragma once
#include<iostream>
#include "Functions.cpp"

template<typename T>	T** Allocate(const int m, const int n);

template<typename T>	void Random(T& variable);

template<typename T>	void FillRand(T arr[], const int n, int minRand = 0, int maxRand = 100); //��� int ����������� �������...

template<typename T>	void FillRand(T** arr, const int m, const int n, int minRand = 0, int maxRand = 100);	//��� int ���������� �������...

template<typename T>	void Print(T arr[], const int n);
template<typename T>	void Print(T** arr, const int m, const int n);
template<typename T>	void PrintArithmetic(T** arr, const int m, const int n); //������� ��������� ������������ ������ �� ����� ��������� ���������� ���������� � �������� �������������

template<typename T>	void Push_back_mutable(T*& arr, int& n, T value);
template<typename T>	void Push_front_mutable(T*& arr, int& n, T value);

template<typename T>	void Push_row_back_opt(T**& arr, int& m, const int n); //��������� ������ � ����� ���������� ������������� �������
template<typename T>	void Push_row_front_opt(T**& arr, int& m, const int n); //��������� ������ � ������ ���������� ������������� �������
template<typename T>	void Push_col_back_opt(T**& arr, const int m, int& n); //��������� ������� � ����� ���������� ������������� �������
template<typename T>	void Push_col_front_opt(T**& arr, const int m, int& n); //��������� ������� � ������ ���������� ������������� �������

template<typename T>	void Insert_mutable(T*& arr, int& n, T value, int index); //��������� �������� � ������ �� ���������� �������;
template<typename T>	void Insert_row_opt(T**& arr, int& m, int n, int index); //��������� ������ � ������ �� ���������� �������;
template<typename T>	void Insert_col_opt(T**& arr, const int m, int& n, int index); //��������� ������� � ������ �� ���������� �������;

template<typename T>	void Pop_back_mutable(T*& arr, int& n); //������� �������� � ����� �������
template<typename T>	void Pop_front_mutable(T*& arr, int& n); //������� �������� � ������ �������

template<typename T>	void Pop_row_back_opt(T**& arr, int& m, const int n); //������� ������ � ������ ���������� ������������� �������
template<typename T>	void Pop_row_front_opt(T**& arr, int& m, const int n); //������� ������ � ������ ���������� ������������� �������
template<typename T>	void Pop_col_back_opt(T**& arr, const int m, int& n); //������� ������� � ������ ���������� ������������� �������
template<typename T>	void Pop_col_front_opt(T**& arr, const int m, int& n); //������� ������� � ������ ���������� ������������� �������

template<typename T>	void Erase_mutable(T*& arr, int& n, int index); //������� �������� �� ������� �� ���������� �������
template<typename T>	void Erase_row_opt(T**& arr, int& m, const int n, int index); //������� ������ �� ���������� ������������� ������� �� ���������� �������
template<typename T>	void Erase_col_opt(T**& arr, const int m, int& n, int index); //������� ������� �� ���������� ������������� ������� �� ���������� �������

template<typename T>	void Clear(T** arr, const int m); // ������� ��������� ������������ ������
