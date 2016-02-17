/*
Задача на программирование: различные слагаемые

По данному числу 1≤n≤109 найдите максимальное число k, для которого n можно представить как сумму k различных натуральных слагаемых. Выведите в первой строке число k, во второй — k слагаемых.
*/

#include <iostream>

using namespace std;

int main() {
  // put your code here
    int num = 0;
    cin >> num;
    
    int sum = 0, count = 0;
    while (sum < num)
    {
        ++count;
        sum += count;
    }
    
    int exclude = 0;
    
    if (sum > num)
        exclude = sum - num;
    
    cout << ( (exclude == 0) ? (count) : (count - 1) ) << endl;
    for(int i = 0; i < count; ++i)
    {
        if (i + 1 != exclude)
            cout << i + 1 << " ";
    }

    return 0;
}
