/*
Задача на программирование: покрыть отрезки точками



По данным n отрезкам необходимо найти множество точек минимального размера, для которого каждый из отрезков содержит хотя бы одну из точек.

В первой строке дано число 1≤n≤100 отрезков. Каждая из последующих n строк содержит по два числа 0≤l≤r≤109, задающих начало и конец отрезка. Выведите оптимальное число m точек и сами m точек. Если таких множеств точек несколько, выведите любое из них.
*/

#include <iostream>

int main() {
  // put your code here
    int size = 0;
    std::cin >> size;
  
    int first=0,last=0;
    int otr[size*2];
    
    int res[size*2];
    int resSize = 0;
    
    for (int i = 0; i<size; ++i)
    {
        std::cin >> first >> last;
        otr[i*2] = first; otr[i*2+1] = last; 
    }
    
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j<size-1-i; ++j)
        {
    		if (otr[j*2+1] > otr[j*2+3])
    		{
    			int t1 = otr[j*2];
    			int t2 = otr[j*2+1];
    			otr[j*2] = otr[j*2+2];
    			otr[j*2+1] = otr[j*2+3];
    			otr[j*2+2] = t1;
    			otr[j*2+3] = t2;
    		}
    	}
    }
    
    if (size > 0)
    {
    	res[resSize] = otr[1];
    	++resSize;
	    for (int i = 0; i<size; ++i)
	    {
	    	if (otr[i*2] > res[resSize-1])
	    	{
			    res[resSize] = otr[i*2+1];
		    	++resSize;
	    	}
	    }
    }
    
    std::cout << resSize << std::endl;
    
    for (int i = 0; i<resSize; ++i)
    {
    	std::cout << res[i] << " ";
    }
    
    return 0;
}
