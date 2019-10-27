/*
 * Author: Joey Yang
 * Email: joeyyang.ai@gmail.com	
 * Runtime: Time Limit Exceeded - O(n*k) runtime complexity
 */

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int unique = 0;
        std::set<int> set;
        for (std::vector<int>::iterator it1 = A.begin(); it1 != A.end(); ++it1)
        {
            for (std::vector<int>::iterator it2 = it1; it2 != A.end(); ++it2)
            {
                if (set.find(*it2) == set.end()) //not found - is unique
                {
                    set.insert(*it2);
                    if (set.size() < K)
                    {
                        ;
                    }
                    else if (set.size() == K)
                    {
                        unique++;
                    }
                    else if (set.size() > K)
                    {
                        set.clear();
                        break;
                    }
                }
                else //is found - not unique
                {
                    if (set.size() < K)
                    {
                        ;
                    }
                    else if (set.size() >= K)
                    {
                        unique++;
                    }
                }

            }
            set.clear();
        }
        return unique;     
    }
};


