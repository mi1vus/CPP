/*
Задача на программирование: калькулятор



У вас есть примитивный калькулятор, который умеет выполнять всего три операции с текущим числом x: заменить x на 2x, 3x или x+1. По данному целому числу 1≤n≤105 определите минимальное число операций k, необходимое, чтобы получить n из 1. Выведите k и последовательность промежуточных чисел.
*/


#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <vector>
#include <stdexcept>      // std::invalid_argument
#include <string>
#include <sstream>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
	(std::ostringstream() << std::dec << x)).str()

using namespace std;

int main()
{
	int W;
	cin >> W;

	//if (W > 10){
	//	std::string s = SSTR(W);
	//	throw new invalid_argument(s.c_str());
	//}

	if (W == 1)
	{
		cout << 0 << endl << 1 << endl;
		system("pause");
		return 0;
	}
	int** D = new int*[W + 2];
	
	int currRow = 0;
	D[0] = new int[W + 1];
	for (int i = 0; i < W + 1; ++i)
	{
		D[0][i] = INT_MAX;
	}
	D[0][0] = 0;
	D[0][1] = 0;
	++currRow;

	for (int i = 1; i < W; ++i)
	{
		D[i] = new int[W + 1];
		for (int j = i; j < W + 1; ++j)
		{
			D[i][j] = INT_MAX;
		}
		D[i][i] = 0;

		for (int j = i; j < W + 1; ++j)
		{
			if (D[i-1][j] != INT_MAX)
			{
				D[i][j] = j;
				if (j * 2 <= W){
					D[i][j * 2] = j;
				}
				if (j * 3 <= W){
					D[i][j * 3] = j;
				}
				if (j + 1 <= W){
					D[i][j + 1] = j;
				}
			}
		}

		if (D[i][W] != INT_MAX){

			cout << i << endl;
			vector<int> answer;
			while (W != 0){
				answer.push_back(W);
				W = D[i][W];
				--i;
			}
			for (i = answer.size(); i > 0; --i)
				cout << answer[i - 1] << " ";

			cout << endl;
			system("pause");
			return 0;
		}
	}
	return 0;
}
