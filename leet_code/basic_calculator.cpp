#/* 
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com
 * Runtime: 8 ms - Beats 99.31% of submissions
 * Memory: 11.3 MB - Beats 42.86% of submissions
 */

include <iostream>
#include <vector>
#include <string>

int calculate(std::string);

int main(int argc, char *argv[])
{
	std::string expression = "3 +10*2 - 5 /2";
	int result = calculate(expression);
	std::cout << "Expression: 3 +10*2 - 5 /2" << std::endl;
	std::cout << "Correct result: "  << 3 + 10 * 2 - 5 / 2 << std::endl;
	std::cout << "Actual result: " << result << std::endl;

	return 0;
}

int calculate(std::string s) 
{
	std::vector<int> vec;
        int temp;
        int result = 0;
        int str_index = 0;
        int vec_index = 0;
        char sign;

        if (!s.empty()) vec.push_back(0); 
	//accumulate number and stop at first sign
        while (isdigit(s[str_index]) || isspace (s[str_index]))
	{
		if (isdigit(s[str_index]))
		{
			//accumulate into first vector element
	 		vec[vec_index] = vec[vec_index] * 10 + (s[str_index] - '0');
        	}
		str_index++;
	}
	
	//traverse through string expression starting from first sign
        while (s[str_index])
        {
		sign = s[str_index];
		str_index++; //go to digit after sign
		temp = 0; //accumulator
		while (isdigit(s[str_index]) || isspace(s[str_index]))
		{
			if (isdigit(s[str_index])) 
			{
				temp = temp * 10 + (s[str_index] - '0'); //accumulate number after sign
			}
			str_index++;
		}
		switch (sign)
		{
			case '+':
				vec.push_back(temp);
				vec_index++;
				break;
			case '-':
				vec.push_back(-temp);
				vec_index++;
				break;
			case '*':
				vec[vec_index] = vec[vec_index] * temp;
				break;
			case '/':
				vec[vec_index] = vec[vec_index] / temp;
				break;
			default:
				break;
		}
	}
	
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		result += *it;
	}
		
	return result;
}

