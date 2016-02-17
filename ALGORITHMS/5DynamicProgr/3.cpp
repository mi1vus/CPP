/*
Задача на программирование: лестница

Даны число 1≤n≤102 ступенек лестницы и целые числа −104≤a1,…,an≤104, которыми помечены ступеньки. Найдите максимальную сумму, которую можно получить, идя по лестнице снизу вверх (от нулевой до n-й ступеньки), каждый раз поднимаясь на одну или две ступеньки.
*/

#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
	int n, cost;
    cin >> n;
    
	int* A = new int[n];
    for (int i = 0; i < n; ++i)
    {
		cin >> cost;
    	A[i] = cost;
    }
    
	int* D = new int[n+1];
	D[0] = 0;
	D[1] = A[0];

    for(int i = 2; i < n + 1; ++ i)
    {
		D[i] = max(D[i-1]+A[i-1],D[i-2]+A[i-1]);
    }
    
	cout << D[n];
	system("pause");
 	return 0;
}
