class Solution {
public:
int numTrees(int n) {
	if( n <= 2 )
		return n;

	int numbers[n+1];
	numbers[0] = 1;
	numbers[1] = 1;

	int i,j;
	for( i = 2; i <= n; i++)
		numbers[i] = 0;
	for( i = 2; i <= n; i++ )
	{

		for( j = i - 1 ; j >=0; j-- )
		{
			numbers[i] += numbers[j] * numbers[i - j - 1];
		}
	}
    return numbers[n];
}
};