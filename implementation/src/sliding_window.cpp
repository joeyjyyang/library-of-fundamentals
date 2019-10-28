#include <iostream>
#include <vector>

template <typename T>
T maxSumOfSubArrays(std::vector<T> &vec, int k)
{
	int max_sum = 0;
	int current_sum = 0;
	for (typename std::vector<T>::iterator it1 = vec.begin(); it1 != vec.end(); ++it1)
	{
		if (std::distance(vec.begin(), it1) < k) 
		{
			max_sum += *it1; //sum of first window of size k
			current_sum = max_sum;
		}
		else //compare sliding window subarray sum to update max sum 
		{
			typename std::vector<T>::iterator it2 = it1 - k;
			current_sum += *it1 - *it2;
			max_sum = std::max(max_sum, current_sum);
		}
	}
	return max_sum;
}

int main(int argc, char *argv[])
{
	std::vector<int> vec = {0, 2, 0, 4, 5, 6};
	int k = 3;
	std::cout << maxSumOfSubArrays(vec, k) << std::endl;
	return 0;
}

