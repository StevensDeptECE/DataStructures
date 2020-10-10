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
	return max(LCS(a+1,b), LCS(a, b+1));
}
	
