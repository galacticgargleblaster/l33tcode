#include <cstdio>

class Solution {
public:
    int bitwiseComplement(int N) {
		int result = 0;
		int bits = 0;

		while (N)
		{
			result = result + ((!(N & 0b1)) << bits);
			bits++;
			N = N >> 1;
		}
        return result; 
    }
};



int main()
{
	Solution s;

	printf("%d\n", s.bitwiseComplement(5));
	printf("%d\n", s.bitwiseComplement(7));
	printf("%d\n", s.bitwiseComplement(10));
	return (0);
}
