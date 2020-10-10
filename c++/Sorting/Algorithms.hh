#include <iostream>
using namespace std;

//Bubblesort
void bubblesort(int *a, int n) { //O(n^2)
  for (int j = n-1; j > 0; j--){ 
		for (int i = 0; i < j; i++){  
            if (a[i] > a[i+1]) {
                swap(a[i], a[i+1]);
            }
        }
    }
}

void bubblesort_Better(int *a, int n) { //O(n)
    bool done;
    for (int j = n-1; j > 0; j--){ 
        done = true;
		for (int i = 0; i < j; i++){  
            if (a[i] > a[i+1]) {
                swap(a[i], a[i+1]);
                done = false;
            }
        }
        if (done){
            return;
        }
    }
}

//Insertion sort
void insertsort(int x[], int n){
    for (int i=1; i < n; i++){
        if (x[i] < x[i-1]) {
            int temp = x[i];
            for (int j = i - 1; j >= 0; j--){
                if (temp < x[j] && j != 0) {
                    x[j+1] = x[j];
                }
                else if (temp < x[j] ){
                    x[j+1] = x[j];
                    x[j] = temp;
                }
                else {
                    x[j] = temp ;
                    break;
                }
            }
        }
    }
}

// Quicksort
void quicksort(int *x, int L, int R){
	int i = L;
	int j = R;
	int pivot = x[L + (rand() % R-L)];
	if (L >= R) 
		return;
	while (i <= j) {
		while (x[i] < pivot)
			i++;
		while (x[j] > pivot)
			j--;
		if (i <= j) {
			swap (x[i], x[j]);
			i++;
			j--;
		}
	}
	if (L < j)
		quicksort(x, L, j);
	if (i < R)
		quicksort(x, i, R);
}

// Heapsort
void makesubheap(int *arr, int i, int n){
	int root = n;
	int left = 2*n + 1; 
	int right = 2*n + 2;
  
	if (left < i && arr[left] > arr[root]){ //Left > root
   		root = left;
   	}
   	if (right < i && arr[right] > arr[root]){ // Right > root
   		root = right;
	}
   	if (root != n) //if the largest value is not the root keep swapping and recalling itself
    {
      swap(arr[n], arr[root]);
      makesubheap(arr, i, root);
    }
}

void makeheap (int *a, int n){
	for (int i = n/2; i >= 0; i--){
		makesubheap(a, n, i);
	}
}

void heapsort(int *a, int n){
	makeheap(a, n);
	for (int i = n-1; i >= 0; i--){
		swap(a[0], a[i]); // move to correct place
		makesubheap(a, i, 0); // heap gets smaller
	}
}

// Mergesort
void MergeSingle(int *A, int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;
    int *B = new int[high+1];
    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    while (i <= mid){
        B[k++] = A[i++];
    }
    while (j <= high){
        B[k++] = A[j++];
    }
    for (int i=low; i<=high; i++){
        A[i] = B[i];
    }
	delete [] B;
}

void mergeSort(int *A, int n){
	int p, l, h ,mid, i;
	for(p = 2; p<=n; p=p*2){
		for(i=0; i+p<=n; i=i+p){
			l = i;
			h = i+p-1;
			mid = (l+h)/2;
			MergeSingle(A,l,mid,h);
		}
	}
	if(p/2<n){
	    MergeSingle(A,0,p/2-1,n-1);
	}
} 

void printResult(int *B, int n){
	for (int i = 0; i<n; i++){
	    cout<<B[i]<<flush<<" ";
	}
	cout << endl;
}