#include <iostream>
#include "algorithms.hh"
using namespace std;

int main(int argc, char *argv[]){

	int a[argc];

	cout<<"You have entered: "<<argc-1<<" numbers"<<'\n';
	for (int i = 0; i<argc; i++){
		a[i] = atoi(argv[i]); 
	}

	cout<<"GCD: "<< gcd(a[1], a[2]) << endl;
	cout<<"LCM: "<< lcm(a[1], a[2]) << endl;
    cout <<"Power: " << power(a[1], a[2])<< endl;
	cout<<"PowerMod: "<< powermod(a[1], a[2], a[3]) << endl;
    cout <<"Fermat: " << fermat(a[1], a[2])<< endl;

    if (fermat2(a[1], a[2]) == 0){
        cout << "Not prime." << endl;
    }
    else {
        cout << "Is prime." <<endl;
    }

}