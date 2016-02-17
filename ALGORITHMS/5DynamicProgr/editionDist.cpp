/*
Задача на программирование: расстояние редактирования



Вычислите расстояние редактирования двух данных непустых строк длины не более 102, содержащих строчные буквы латинского алфавита.
*/

#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    string in, out;
    cin>>in;
    cin>>out;
    
    const int n = in.size(), m = out.size();
    
	int** D = new int*[2];
	D[0] = new int[n+1];
	D[1] = new int[n+1];
	int currRow = 0;
    int absRowCount = 1;
    for (int i = 0; i < n + 1; ++i)
    {
    	D[currRow][i] = i;
    }

    for(int i = 1; i < m + 1; ++ i)
    {
        currRow = (currRow + 1) % 2;
    	D[currRow][0] = i;
	    for (int j = 1; j < n + 1; ++j)
	    {
	    	D[currRow][j] = min(
	    		D[(currRow + 1) % 2][j] + 1,
	    		min(
	    			D[currRow][j - 1] + 1,
	    			D[(currRow + 1) % 2][j-1] + (int)(in[j-1] != out[i-1])
	    			)
	    		);
	    }
    }
    
	cout << D[currRow][n];
	system("pause");
 	return 0;
}
