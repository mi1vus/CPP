/*
Задача на программирование: рюкзак

﻿

Первая строка входа содержит целые числа 1≤W≤104 и 1≤n≤300 — вместимость рюкзака и число золотых слитков. Следующая строка содержит n целых чисел 0≤w1,…,wn≤105, задающих веса слитков. Найдите максимальный вес золота, который можно унести в рюкзаке.
*/


#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
	int W,n,cost;
    cin>>W;
    cin>>n;
    
	int* A = new int[n];
    for (int i = 0; i < n; ++i)
    {
		cin >> cost;
    	A[i] = cost;
    }
    
	int** D = new int*[2];
	D[0] = new int[W+1];
	D[1] = new int[W+1];

	int currRow = 0;
    for (int i = 0; i < W + 1; ++i)
    {
    	D[currRow][i] = 0;
    }

    for(int i = 1; i < n + 1; ++ i)
    {
        currRow = (currRow + 1) % 2;
    	D[currRow][0] = 0;
	    for (int w = 1; w < W + 1; ++w)
	    {
			D[currRow][w] = D[(currRow + 1) % 2][w];
			if (A[i-1] <= w)
				D[currRow][w] = max(
						D[currRow][w],
						D[(currRow + 1) % 2][w - A[i-1]] + A[i-1]
					);
	    }
    }
    
	cout << D[currRow][W];
	system("pause");
 	return 0;
}
