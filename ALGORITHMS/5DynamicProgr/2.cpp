/*
Задача на программирование повышенной сложности: наибольшая невозрастающая подпоследовательность



Дано целое число 1≤n≤105и массив A[1…n], содержащий неотрицательные целые числа, не превосходящие 109. Найдите наибольшую невозрастающую подпоследовательность в A. В первой строке выведите её длину k, во второй — её индексы 1≤i1<i2<…<ik≤n (таким образом, A[i1]≥A[i2]≥…≥A[in]).

*/


#include <algorithm>
#include <cstddef>
#include <climits>
#include <iostream>
#include <vector>

int BinSearchFirstHigher(std::vector<int> * arr_, int l, int r, int val)
{
	if (l>r)
		return r + 1;

	int mid =  (l+r)/2;

	if ((*arr_)[mid] > val)
		return BinSearchFirstHigher(arr_,l,mid-1,val);
	else
		return BinSearchFirstHigher(arr_,mid + 1, r,val);
}
int BinSearchFirstNum(std::vector<int> * arr_, int l, int r, int val)
{
	if (l>r)
		return r + 1;

	int mid =  (l+r)/2;

	if ((*arr_)[mid] > val)
		return BinSearchFirstHigher(arr_,l,mid-1,val);
	else
		return BinSearchFirstHigher(arr_,mid + 1, r,val);
}
int BinSearchFirstLower(std::vector<int> * arr_, int l, int r, int val)
{
	if (l>r)
		return r;

	int mid =  (l+r)/2;

	if ((*arr_)[mid] < val)
		return BinSearchFirstLower(arr_,mid + 1, r,val);
	else
		return BinSearchFirstLower(arr_,l,mid-1,val);
}

int get_length_of_longest_divisible_subsequence1(const std::vector<int> &numbers) {
  // TODO optimize this function
  int result = 0;

  std::vector<int>* D = new std::vector<int>(numbers.size() + 3);
  std::vector<int>* Prev = new std::vector<int>(numbers.size() + 3);
  std::vector<int>* indPrev = new std::vector<int>(numbers.size() + 3);

  (*D)[0] = INT_MIN;
  for (int i = 1; i < numbers.size() + 3; ++i){
	  (*D)[i] = INT_MAX;
  }

  for (int i = 0; i < numbers.size(); ++i){
	  int j = int (std::upper_bound (D->begin(), D->end(), numbers[i]) - D->begin());
//		int j = BinSearchFirstHigher(D,0,numbers.size(),numbers[i]);
		if ((*D)[j-1] <= numbers[i] && numbers[i] < (*D)[j]){
			(*D)[j] = numbers[i];
			(*indPrev)[j] = i;
			(*Prev)[i] = (*D)[j-1] == INT_MIN ? INT_MIN : (*indPrev)[j-1];
		}
  }
  int last = 0;
  for (int i = 0; i < D->size(); ++i)
	  if ((*D)[i] < INT_MAX /*&& (*D)[result] >= (*D)[i]*/){
		  result = i;
		  last = (*indPrev)[i];
	  }

	std::cout << result << std::endl;

	while (last >= 0)
	{
		//std::cout << numbers[last]  << " ";
        std::cout << numbers.size() - last << " ";
		last = (*Prev)[last];
	}

  return result;
}

int main(void) {
  size_t number_count = 100000;
  std::cin >> number_count;
    size_t number = 0;
  std::vector<int> numbers(number_count);
  for (int i = number_count; i > 0; --i) {
	//number = std::rand();
	std::cin >> number;
    numbers[i-1] = number;
  }
  get_length_of_longest_divisible_subsequence1(numbers);
  //std::cout << get_length_of_longest_divisible_subsequence1(numbers) << std::endl;
  //std::cout << BinSearchFirstHigher(&numbers, 0, numbers.size(), 4) << std::endl;
  //std::cout << std::endl;
  //system("pause");
}
