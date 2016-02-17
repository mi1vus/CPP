/*
Задача на программирование: непрерывный рюкзак



Первая строка содержит количество предметов 1≤n≤103 и вместимость рюкзака 0≤W≤2⋅106. Каждая из следующих n строк задаёт стоимость 0≤ci≤2⋅106 и объём 0<wi≤2⋅106 предмета (n, W, ci, wi — целые числа). Выведите максимальную стоимость частей предметов (от каждого предмета можно отделить любую часть, стоимость и объём при этом пропорционально уменьшатся), помещающихся в данный рюкзак, с точностью не менее трёх знаков после запятой.
*/

#include <iostream>
#include <cstdlib> // содержит srand() и rand()
#include <stdio.h>
#include <iomanip>

int main() {
  // put your code here
    long size = 0, bag = 0;
    std::cin >> size >> bag;
  
    long first=0,last=0;
    long items[2][size];
    
    double cost[size];
    double res = 0;
    
    for (long i = 0; i<size; ++i)
    {
        std::cin >> first >> last;
/*		first = rand()%100; // запись случайного числа, которое вернет rand()
		last  = rand()%100;
		while(first > last)
		{
			first = rand()%100; // запись случайного числа, которое вернет rand()
			last  = rand()%100;
		}
*/      items[0][i] = first; items[1][i] = last;
        cost[i] = ((double) first) / ((double)last);
//        std::cout << first << " " << last << std::endl;
    }
    
    for (long i = 0; i<size; ++i)
    {
    	for (long j = 0; j<size-1-i; ++j)
    	{
    		if (cost[j] < cost[j+1])
    		{
    			long t1 = items[0][j];
    			long t2 = items[1][j];
                double t3 = cost[j];
    			items[0][j] = items[0][j + 1];
    			items[1][j] = items[1][j + 1];
                cost[j] = cost[j + 1];
                items[0][j + 1] = t1;
    			items[1][j + 1] = t2;
                cost [j + 1] = t3;
    		}
    	}
    }

//    for (int i = 0; i<size; ++i)
//    {
//    	std::cout << otr[i*2] << " " << otr[i*2 + 1] << std::endl;
//    }

    
    if (size != 0)
    {
        long itemInd = 0;
        while (bag > 0)
        {
	    	if (items[1][itemInd] <= bag)
	    	{
			    bag -= items[1][itemInd];
                res += items[0][itemInd];
                ++itemInd;
	    	}
            else
            {
                double k = ((double)bag) / ((double)items[1][itemInd]);
                bag = 0;
                res += k * ((double)items[0][itemInd]);
            }
	    }
    }
    
    std::cout << std::fixed;
  	std::cout << std::setprecision(3) << res;

	//printf ("%1.4f", res);
    /*
    for (int i = 0; i<resSize; ++i)
    {
    	std::cout << res[i] << " ";
    }
    */
    return 0;
}
