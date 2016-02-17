/*
Задача на программирование: очередь с приоритетами



Первая строка входа содержит число операций 1≤n≤105. Каждая из последующих n строк задают операцию одного из следующих двух типов:

Insert x, где 0≤x≤109 — целое число;
ExtractMax.
Первая операция добавляет число x в очередь с приоритетами, вторая — извлекает максимальное число и выводит его.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

#include <cstddef>
#include <cstring>

struct BinaryHeap {
    
    BinaryHeap(size_t size)
	{
        arr_ = new int [size];
        maxSize_ = size;
        size_ = 0;
    }
    
    BinaryHeap(int* A, size_t size)
	{
        arr_ = A;
		size_ = size;
		for (int i = size/2; i>0;i--)
			SiftDownMin(i);

    }


    ~BinaryHeap()
	{        
        delete[] arr_;
     }

    size_t Size()
	{
        return size_;
    }

    int At(size_t idx){
        return arr_[idx];
    }
    
    void Swap(int ind1, int ind2){
        int tmp = arr_[ind1];
		arr_[ind1] = arr_[ind2];
		arr_[ind2] = tmp;
    }

	int MaxElementIndex(int ind1, int ind2)
	{
		return (arr_[ind1] > arr_[ind2]) ? ind1:ind2;
	}
	
	int MinElementIndex(int ind1, int ind2)
	{
		return (arr_[ind1] < arr_[ind2]) ? ind1:ind2;
	}

    void SiftUp(int ind)
    {
        if (size_ <= 1)
            return;
        int parentInd = ind; 

		while (parentInd > 1)
		{
			parentInd = parentInd/2;

			if (arr_[ind-1] > arr_[parentInd-1])
			{
				Swap(ind-1,parentInd-1);
				ind = parentInd;
			} else
			{
				break;
			}
		}
    }

	void SiftDown(int ind)
    {
        if (size_ < 1)
            return;

		int childIndex = ind;
		while (childIndex < size_+1)
		{
			int left = childIndex*2; 
			int right = childIndex*2+1;
			if(left > size_ && right > size_)
				break;
			else if (left > size_ )
				childIndex = right;
			else if (right > size_ )
				childIndex = left;
			else
				childIndex = MaxElementIndex(left-1,right-1)+1;

			if (arr_[ind-1] < arr_[childIndex-1])
			{
				Swap(ind-1,childIndex-1);
				ind = childIndex;
			} else
			{
				break;
			}
		}
    }

	int Extract()
	{
		if (size_ > 0)
		{
			int result = At(0);
			Swap(0, size_-1);
			size_--;

			SiftDown(1);
			return result;
		}
		return 0;
	}

    void Insert(int val) 
	{
        arr_[size_] = val;
        size_++;
        
		SiftUp(size_);
	}

	void SiftUpMin(int ind)
    {
        if (size_ <= 1)
            return;
        int parentInd = ind; 

		while (parentInd > 1)
		{
			parentInd = parentInd/2;

			if (arr_[ind-1] < arr_[parentInd-1])
			{
				Swap(ind-1,parentInd-1);
				ind = parentInd;
			} else
			{
				break;
			}
		}
    }

	void SiftDownMin(int ind)
    {
        if (size_ < 1)
            return;

		int childIndex = ind;
		while (childIndex < size_+1)
		{
			int left = childIndex*2; 
			int right = childIndex*2+1;
			if(left > size_ && right > size_)
				break;
			else if (left > size_ )
				childIndex = right;
			else if (right > size_ )
				childIndex = left;
			else
				childIndex = MinElementIndex(left-1,right-1)+1;

			if (arr_[ind-1] > arr_[childIndex-1])
			{
				Swap(ind-1,childIndex-1);
				ind = childIndex;
			} else
			{
				break;
			}
		}
    }

	int ExtractMin()
	{
		if (size_ > 0)
		{
			int result = At(0);
			Swap(0, size_-1);
			size_--;

			SiftDownMin(1);
			return result;
		}
		return 0;
	}

    void InsertMin(int val) 
	{
        arr_[size_] = val;
        size_++;
        
		SiftUpMin(size_);
	}


    size_t size_;
    size_t maxSize_;
    int *arr_;
};

int main()
{

    int n=100000;
    
    size_t size=0;           
    cin >> size;
    
    BinaryHeap heap(size);
	int counter = 0;

    while (counter < size)
    {
		counter++;
        char str[200] = "";
		cin >> str;

        int num = 0;

        if (strcmp(str,"Insert") == 0)
		{
            cin >> num;
			heap.Insert(num);
		}
        else 
        if (strcmp(str,"ExtractMax") == 0)
        {
			cout << heap.Extract() << endl;
            continue;
        }
	}

/*
    size_t size=0;           
    cin >> size;
    
	int * arr = new int [size];
	for (int i = 0; i < size; i++){
		int val = 0;
		cin >> val;
		arr[i] = val;
	}

    BinaryHeap heap(arr, size);

	for (int i = 0; i < size; i++){
		cout << heap.ExtractMin() << " ";
	}
	cout << endl;
*/

//	system("pause");
    return 0;
}
