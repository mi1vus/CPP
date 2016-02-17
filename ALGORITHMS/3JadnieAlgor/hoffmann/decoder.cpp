/*
Задача на программирование: декодирование Хаффмана



Восстановите строку по её коду и беспрефиксному коду символов. 

В первой строке входного файла заданы два целых числа k и l через пробел — количество различных букв, встречающихся в строке, и размер получившейся закодированной строки, соответственно. В следующих k строках записаны коды букв в формате "letter: code". Ни один код не является префиксом другого. Буквы могут быть перечислены в любом порядке. В качестве букв могут встречаться лишь строчные буквы латинского алфавита; каждая из этих букв встречается в строке хотя бы один раз. Наконец, в последней строке записана закодированная строка. Исходная строка и коды всех букв непусты. Заданный код таков, что закодированная строка имеет минимальный возможный размер.


В первой строке выходного файла выведите строку s. Она должна состоять из строчных букв латинского алфавита. Гарантируется, что длина правильного ответа не превосходит 104 символов.
*/

#include <iostream>
#include <cstring> //strlen
#include <string>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int letSize = 0, codeSize = 0;
	string code;
	cin >> letSize >> codeSize;

	map<char,string>& dict  = *(new map<char,string>());
	
	for (int i = 0; i < letSize; ++i)
	{
		string line1;
		string line2;
		cin >> line1 >> line2;
		dict.insert(make_pair((char)line1[0],line2));
	}

	cin >> code;
	
	map<char,string>::iterator cur;

	int startLetPos = 0;
	for (int i = 1; i < codeSize + 1; i++){
		string findLine = code.substr(startLetPos,i - startLetPos);
		for (cur=dict.begin();cur!=dict.end();cur++)
		{
			if (findLine.compare((*cur).second) == 0)
			{
				cout << (*cur).first;
				startLetPos = i;
				break;
			}
		}
	}
//	system("pause");
	return 0;
}
