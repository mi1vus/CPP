/*
Задача на программирование: точки и отрезки

﻿

В первой строке задано два целых числа 1≤n≤50000 и 1≤m≤50000 — количество отрезков и точек на прямой, соответственно. Следующие n строк содержат по два целых числа ai и bi (ai≤bi) — координаты концов отрезков. Последняя строка содержит m целых чисел — координаты точек. Все координаты не превышают 108 по модулю. Точка считается принадлежащей отрезку, если она находится внутри него или на границе. Для каждой точки в порядке появления во вводе выведите, скольким отрезкам она принадлежит.


*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include <cstddef>
#include <cstring>

#include <iostream>
#include <queue>
#include <vector>


using namespace std;

vector<long long>* Merge(vector<long long>* in1, vector<long long>* in2)
{
	vector<long long> i1 = *in1;
	vector<long long> i2 = *in2;
	long long c1 = 0, c2 = 0;
	vector<long long>* result = new vector<long long>();

	for (long long i = 0; i< i1.size() + i2.size(); ++i)
	{
		if (c1 < i1.size() && c2 < i2.size()){

			if (i1[c1] <= i2[c2]){
				result->push_back(i1[c1]);
				++c1;
			}
			else{
				result->push_back(i2[c2]);
				++c2;
			}
		}
		else if (c1 >= i1.size())
		{				
			result->push_back(i2[c2]);
			++c2;
		}
		else if (c2 >= i2.size())
		{				
			result->push_back(i1[c1]);
			++c1;
		}
	}
	return result;
}

vector<long long>* Sort(vector<long long>* data)
{
	if (data->size() < 2)
		return data;
	
	int m = data->size()/2;
	
	vector<long long>* l = new vector<long long>();
	for (int i = 0; i < m; ++i){
		l->push_back((*data)[i]);
	}
	vector<long long>* r = new vector<long long>();
	for (int i = m; i < data->size(); ++i){
		r->push_back((*data)[i]);
	}
	return Merge(Sort(l),Sort(r));
}





int BinSearch1(vector<long long> * arr_, int l, int r, long long val)
{
	if (l>r)
		return r;

	int mid =  (l+r)/2;

	if ((*arr_)[mid - 1] > val)
		return BinSearch1(arr_,l,mid-1,val);
	else
		return BinSearch1(arr_,mid + 1, r,val);
}

int main()
{
//	srand (time(NULL));

    size_t numSegment=0;
	size_t numPoint=0; 
    cin >> numSegment;
    cin >> numPoint;

//	int * x1Points = new int[numSegment];
//	int * x2Points = new int[numSegment];
	vector<long long>* x1PointsV = new vector<long long>();
	vector<long long>* x2PointsV = new vector<long long>();
	for(int i = 0; i < numSegment; i++)
	{

//		int x1 = rand(), x2 = rand();

		int x1 = 0, x2 = 0;
		cin >> x1 >> x2;

		x1PointsV->push_back(x1);
		x2PointsV->push_back(x2+1);
	}
	
	vector<long long>* sorted1 = Sort(x1PointsV);
	vector<long long>* sorted2 = Sort(x2PointsV);

    for (int i = 0; i < numPoint; i++)
    {
		int point = 0;
		cin >> point;
		int begSegm = BinSearch1(sorted1, 1, numSegment, point);
		int endSegm = BinSearch1(sorted2, 1, numSegment, point);

		cout << (begSegm - endSegm) << " ";
	}

//	system("pause");

    return 0;
}
