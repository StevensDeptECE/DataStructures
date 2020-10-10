#include <iostream>
#include<fstream>
#include<string>
#include "Algorithms.hh"

using namespace std;

int main (){
    int a, b, opt;
    char cont = 'C';
	
	ifstream myfile("input.txt");
	if (myfile.is_open()){
		myfile>>a>>b;
	}

	int *c = new int[a];
	int *randA = new int[a];

    for(int i=0;i<b;i++){
        for(int j=0; j<=a; j++){
            c[j]=randA[j]=rand()%a;
        }
    }

    while (cont == 'C' || cont == 'c'){
        cout << "====Welcome to Sorting==== \nPress 1 for Quicksort \nPress 2 for Heapsort \nPress 3 for Mergesort \nPress 4 for Bubblesort \nAnything else to Quit." << endl;
        cin >> opt;

        switch(opt){
        
            case 1:
                cout<<endl;	 
                printResult(randA, a);
                cout<<"Quicksort\n";
                quicksort(c,0,a-1);	
                printResult(c,a);	
                cout<<endl;	
                break;
            case 2: 
                cout<<endl;	 
                printResult(randA, a);
                cout<<"Heapsort\n";
		        heapsort(c,a);	
                printResult(c,a);	
                cout<<endl;	
                break;
            case 3: 
                cout<<endl;	 
                printResult(randA, a);
                cout<<"Mergesort\n";
		        mergeSort(c,a);	
                printResult(c,a);	
                cout<<endl;	
                break;
            case 4: 
                cout<<endl;	 
                printResult(randA, a);
                cout<<"BubbleSort\n";
		        bubblesort(c,a);	
                printResult(c,a);	
                cout<<endl;	
                break;
            default:
                exit(1);
        }
        cout << "To continue press C: ";
        cin >> cont;
    }

}