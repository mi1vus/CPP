/*
Задача на программирование: двоичный поиск 

﻿

В первой строке даны целое число 1≤n≤105 и массив A[1…n] из n различных натуральных чисел, не превышающих 109, в порядке возрастания, во второй — целое число 1≤k≤105 и k натуральных чисел b1,…,bk, не превышающих 109. Для каждого i от 1 до k необходимо вывести индекс 1≤j≤n, для которого A[j]=bi, или −1, если такого j нет.
*/

#include <iostream>

using namespace std;

int main() {
  // put your code here
    int sizeA = 0, sizeTest = 0;
    
    cin >> sizeA;
    
    int * A = new int [sizeA];
    
    for (int i = 0; i < sizeA; ++i)
    {
        cin >> A[i];
    }
    
    cin >> sizeTest;
    
    for (int i = 0; i < sizeTest; ++i)
    {
        int l = 0, r = sizeA - 1, m = 0;
        int key = 0;
        cin  >> key;
        while (l <= r)
        {
            m = l + (r-l)/2;
            if (A[m] == key){
                cout << m + 1 << " ";
                break;
            }
            else if (A[m] > key)
                r = m - 1;
            else
                l = m + 1;                
        }
        if (l > r)
            cout << -1 << " ";    
    }
        
  return 0;
}
