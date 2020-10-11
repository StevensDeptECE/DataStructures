/*
    Golden Section Search
    http://fourier.eng.hmc.edu/e176/lectures/ch3/node3.html
    The golden section search algorithm can be used for finding a minimum (or maximum) 
    of a single-variable function f(x). If it is known that the function has a minimum between 
    some two points, then we can search for it iteratively, in a manner similar to the bisection 
    search for the root of an equation f(x)=0. 
*/
int goldenMeanSearch(int *data, int n){
    int L = 0, R = n-1, phi = 0.5, x, y;
    int s = (R - L) / phi; 

    while (R > L) {
        x = R - s, y = L + s;
        if (data[x] > data[y]){
            R = y;
            y = x;
            s = (R - L) / phi;
            x = R - s;
        }
        else {
            L = x;
            x = y;
            s = (R - L) / phi;
            y = L + s;
        }
    }
    return L;
}

int binarySearch(int *a, int target) { //O(log n)
    if (target < a[0] || target > a[a.size() -1]){
        return -1;
    }
	int L = 0, R = a.size()-1;
    while (R > L) {
		int guess = (L + R) / 2;
		if (a[guess] > target) {
			R = guess - 1;
		} 
        else if (a[guess] < target) {
			L = guess + 1;
		} 
        else {
			return guess;
		}
	}
	return -1; //not found
}

int binarySearch_V2(int *a, int L, int R, int target) { //O(log n)
    if (L > R){
        return -1;
    }
	int guess = (L + R) / 2;
	if (a[guess] > target) {
        return binarySearch_V2(a, L, guess - 1, target);
	} 
    else if (a[guess] < target) {
		returnn binarySearch_V2(a, guess + 1 , R, target);
	} 
    else {
		return guess;
	}
}

int linearSearch(int *a, int n, int target){ //O(n) 
    for (int i = 0; i < n; i++){
        if (array[i] == target){
            return i;
        }
    }
  return -1;
}