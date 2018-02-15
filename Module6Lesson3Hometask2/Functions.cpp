#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include "Header.h"
using namespace std;

void TaskNumber()
{
	setlocale(LC_ALL, "Rus");
	short int task;
	do
	{
		cout << "Введите номер задания - ";
		cin >> task;
			switch (task)
			{
				case 1:
				{
					/*1.	Даны первый член и знаменатель геометрической прогрессии.Написать рекурсивную функцию :
					a.нахождения n - го члена прогрессии
					b.нахождения суммы n первых членов прогрессии*/
					int b = 1, q = 2, n, count = 0;
					cout << "Введите n - ";
					cin >> n;
					int result = GeometryProgress(count, &b, &q, &n);
					cout << "result = " << result << endl;
				} break;

				case 2:
				{
					/*2.	Написать рекурсивную функцию для вычисления максимального элемента массива из n элементов*/
					int b = 1, q = 2, n, count = 0, sum = 0;
					cout << "Введите n - ";
					cin >> n;
					//int result = GeometryProgress(count, &b, &q, &n, &sum);
					int result = GeometryProgress(count, &b, &q, &n, &sum);
					cout << "result = " << result << endl;
				} break;

				case 3:
				{
					/*3.	Написать рекурсивную функцию для вычисления индекса максимального элемента массива из n элементов*/
					int arr[50], size;
					do
					{
						cout << "Введите размерность массива - ";
						cin >> size;
					} while (size < 10 || size > 50);
					arrFilling(arr, &size);
					arrPrint(arr, &size);
					int max = arr[0], count = 0;
					int result = RMaxElement(arr, &size, &max, count);
					cout << "MAX значение - " << result << endl;
				} break;

				case 4:
				{
					/*4.	Дан массив целых чисел A.Найти суммы положительных и отрицательных элементов массива, используя функцию определения суммы*/
					int arr[50], size;
					do
					{
						cout << "Введите размерность массива - ";
						cin >> size;
					} while (size < 10 || size > 50);
					arrFilling(arr, &size);
					arrPrint(arr, &size);
					int sumPlus = 0, sumMinus = 0;
					SumOfArrElements(arr, &size, &sumPlus, &sumMinus);
				} break;

				case 5:
				{
					/*5.	Даны два натуральных числа.Найти наименьшее общее кратное этих чисел, используя функцию реализующую алгоритм Евклида.*/
					int a, b;
					cout << "Введите два числа а и b - ";
					cin >> a >> b;
					NOD(&a, &b);

				} break;
			}
		} while (task > 0);
}


int GeometryProgress(int count, int *b, int *q, int *n)
{	
	
	if (count >= *n)
		return *b;
	count++;
	*b += count * *q;
	cout << "*b == " << *b << endl;
	*b = GeometryProgress(count, b, q, n);
	return *b;
}

int GeometryProgress(int count, int *b, int *q, int *n, int *sum)
{
	if (count >= *n)
		return *b;
	count++;
	*b += count * *q;
	*sum += *b;
	cout << "*sum == " << *sum << endl;
	*b = GeometryProgress(count, b, q, n, sum);
	return *sum;
}

int arrFilling(int *arr, int *size)
{
	srand(time(0));
	for (int i = 0; i < *size; i++)
	{
		arr[i] = -100 + rand() % 200;
	}
	return *arr;
}

void arrPrint(int *arr, int *size)
{
	for (int i = 0; i < *size; i++)
	{
		cout << arr[i] << endl;
	}
}

int RMaxElement(int *arr, int *size, int * max, int count)
{
	if (count == *size)
		return *max;
	if (arr[count] > *max)
		*max = arr[count];
	count++;
	*max = RMaxElement(arr, size, max, count);
	return *max;
}

void SumOfArrElements(int *arr, int *size, int*sumPlus, int *sumMinus)
{
	for (int i = 0; i < *size; i++)
	{
		if (arr[i] > 0)
			*sumPlus += arr[i];
		else
			*sumMinus += abs(arr[i]);
	}
	cout << "Сумма положительных чисел - " << *sumPlus << endl;
	cout << "Сумма отриц чисел - " << *sumMinus << endl;
}

void NOD(int *a, int*b)
{	
	int count, NOD = 0;
	if (*a > *b)
		count = *a;
	else
		count = *b;
	for (int i = 1; i <= count; i++)
	{
		if (*a % i == 0 && *b % i == 0)
			NOD = i;
	}
	cout << "Наибольший общий делитель для чисел " << *a << " & " << *b << " == " << NOD << endl;
}