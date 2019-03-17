#include <vector>

class Solution {
public:
    int numPairsDivisibleBy60(std::vector<int>& time) {
		int i = 0;
		int j;
		int count = 0;
		int size = time.size();
		int itime = 0;
		while (i < (size - 1))
		{
			j = i + 1;
			itime = time[i];
			while (j < size)
			{
				if (((itime + time[j]) % 60) == 0)
					count++;
				j++;
			}	
			i++;
		}	
		return count;
    }
};


