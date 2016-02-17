/*
Задача на программирование: число инверсий

﻿

Первая строка содержит число 1≤n≤105, вторая — массив A[1…n], содержащий натуральные числа, не превосходящие 109. Необходимо посчитать число пар индексов 1≤i<j≤n, для которых A[i]>A[j]. (Такая пара элементов называется инверсией массива. Количество инверсий в массиве является в некотором смысле его мерой неупорядоченности: например, в упорядоченном по неубыванию массиве инверсий нет вообще, а в массиве, упорядоченном по убыванию, инверсию образуют каждые два элемента.)
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

long long counter1 = 0;
long long counter2 = 0;
long long counter3 = 0;
long long counter4 = 0;
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
				counter1++;
			}
			else{
				result->push_back(i2[c2]);
				counter2 += i1.size() - c1;
				++c2;
			}
		}
		else if (c1 >= i1.size())
		{				
			result->push_back(i2[c2]);
			++c2;
			counter3++;
		}
		else if (c2 >= i2.size())
		{				
			result->push_back(i1[c1]);
			++c1;
			counter4++;
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

int isPow2(int a) {
  return !(a&(a-1));
}

int main() {
  // put your code here
	long long sizeDat=0;
	long long val = 0;
	std::cin >> sizeDat;
	
vector<long long>* source = new vector<long long>();

for (long long i = 0; i < sizeDat; i++)
{
	std::cin >> val;
	source->push_back(val);
}
	while(!isPow2(source->size()))
	{
		source->push_back(999999999999);
	}

	vector<long long>* sorted = Sort(source);

//	std::cout << counter1 << " " << counter2 << " " << counter3 << " " << counter4 << std::endl;

for (long long i = 0; i < sizeDat; i++)
{
//	std::cout << (*sorted)[i] << " ";
}

	std::cout  <<  counter2;


  return 0;
}
