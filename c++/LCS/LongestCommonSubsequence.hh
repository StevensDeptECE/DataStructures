/*
	Example: Longest Common Subsequence calculates the number of letters
	in common between two strings.

	This example is terrible because it is O(2**n). The key is to use
	dynamic programming for this problem or more efficiently, to create
	the array and fill it sequentially since it all must be done in any
	case. This placeholder is an example of how to contribute an
	algorithm, as a header file with a separate test code
	that demonstrates its use.

 */
int LCS(const char* a, const char* b) {
	if (*a == '\0' || *b == '\0')
		return 0;
	if (*a == *b)
		return 1 + LCS(a+1,b+1);
	return std::max(LCS(a+1,b), LCS(a, b+1));
}

int LCS_V2(const char a[], const char b[], int m, int n) {
	int memo[m+1][n+1];
	int i, j;
    for (i = 0; i < m; i++){ //0(m)
        memo[i][0] = 0;
    }
    for (j = 0; j < n; j++){ //O(n)
        memo[0][j] = 0;
    }
    for (i = 1; i < m + 1 ; i++){
        for (j = 1; j < n + 1; j++){
            if (a[i] == b[j]){
                memo[i][j] = 1 + memo[i-1][j-1];
            }
			else {
				memo[i][j] = std::max(memo[i][j-1], memo[i-1][j]);
			}
		}
	}
	return memo[m][n];
}

int LCS_Common(const char a[], const char b[], int m, int n){
	int memo2[m+1][n+1];
	int i, j;
    for (i = 0; i < m; i++){ //0(m)
        memo2[i][0] = 0;
    }
    for (j = 0; j < n; j++){ //O(n)
        memo2[0][j] = 0;
    }
    for (i = 1; i < m + 1 ; i++){
        for (j = 1; j < n + 1; j++){
            if (a[i] == b[j]){
                memo2[i][j] = 1 + memo2[i-1][j-1];
            }
			else {
				memo2[i][j] = std::max(memo2[i][j-1], memo2[i-1][j]);
			}
		}
	}

	int index = memo2[m][n];
   	char lcs[index+1];
   	lcs[index] = '\0';

	int x, y;
	x = m;
	y = n;
   	while (x > 0 && y > 0)
   	{
      	if (a[x-1] == b[y-1])
      	{
          lcs[index-1] = a[x-1]; 
          x--; 
		  y--; 
		  index--;
      	}
      	else if (memo2[x-1][y] > memo2[x][y-1])
        	 x--;
      	else
        	 y--;
   	}
	std::cout << lcs << std::endl;

	return 0;
}