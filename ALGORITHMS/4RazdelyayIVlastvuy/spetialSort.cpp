/* 
Задача на программирование: сортировка подсчётом 



Первая строка содержит число 1≤n≤104, вторая — n натуральных чисел, не превышающих 10. Выведите упорядоченную по неубыванию последовательность этих чисел.
*/

#include <iostream>

using namespace std;

int main() {
  // put your code here
    
    int size = 0;
    cin >> size;
        
    int mas[11];
    for (int i = 0; i < 11; ++i)
    {
        mas[i] = 0;
    }    
    for (int i = 0; i < size; ++i)
    {
        int ind = 0;
        cin >> ind;
        ++mas[ind];
    }

    for (int i = 0; i < 11; ++i)
        while (mas[i] > 0){
            cout << i << " ";
            --mas[i];
        }
    
    return 0;
}
