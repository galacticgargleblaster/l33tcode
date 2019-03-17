#include <vector>

class Solution {
public:
    int numPairsDivisibleBy60(std::vector<int>& time) {
		int i = 0;
		int j;
		int count = 0;
		while (i < (time.size() - 1))
		{
			j = i + 1;
			while (j < time.size())
			{
				if (((time[i] + time[j]) % 60) == 0)
					count++;
				j++;
			}	
			i++;
		}	
		return count;
    }
};


