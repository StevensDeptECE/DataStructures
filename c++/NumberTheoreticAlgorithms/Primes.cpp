#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int n) { //O(sqrt n)
	for (int i = 2; i <= sqrt(n); i++) { 
		if (n % i == 0)
			return false; // not prime
	}
	return true; // prime
}

void Erathosthenes(int num){
    int count = 0;
    bool* sieve = new bool [num];

    for (int i = 2; i <= num; i++){ //O(num)
        sieve[i] = 1;
    }

// remove even 
    for (int j = 4; j <=num; j+=2){ //O(num)
     sieve[j] = 0;
    }

    for (int k = 3; k <= num; k += 2){ //O(num)
        if (sieve[k] == 1){
            for (int l = k*k; l <= num; l = l + 2*k){
            sieve[l] = 0;
            }
        }
    }

    vector <int> list;
  // counter of primes
    for(int m = 2; m <=num; m++){
        if (sieve[m] == 1){
            list.push_back(m);
            count++;
        }
    }
    cout << count << "\n" << "List of Primes: ";

    // if (list.empty()){
    //     cout << "No Primes.";
    // }

    for (int n = 0; n <list.size(); n++){
        cout << list.at(n) << " ";
    }

    cout << endl;
}

int main() {

    int N;
    cout << "Give me any number: ";
    cin >> N;

    if (isPrime(N) == 0){
        cout << "Number of prime: "; 
        Erathosthenes(N);
    }
    else {
        cout << N << " is prime." <<endl;
    }

    return 0;
}
