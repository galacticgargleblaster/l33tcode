class Solution {
	public:
		int shipWithinDays(vector<int>& weights, int D) {
			int sum = 0;
			int capacity = 0;
			int days;
			int i = 0;
			for (int i = 0; i < weights.size(); i++)
				capacity = (capacity > weights[i] ? capacity : weights[i]);
			capacity--;
			do {
				capacity++;
				i = 0;
				days = 0;
				while ((days < D))
				{
					sum = 0;
					while (i < weights.size() && (sum + weights[i] <= capacity))
					{
						sum += weights[i];
						i++;
					}
					days++;
				}
			} while (i != weights.size() );
			return (capacity);
		}
};
