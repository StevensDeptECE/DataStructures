#include<iostream>
#include<fstream>
#include<string>
#include"LongestCommonSubsequence.hh"

using namespace std;

int main () {
    
    int m,n;
    
    // Reading Text files 
    string mytext, mysecondtext;
    ifstream myfile("text1.txt"); 
	getline(myfile,mytext);

	ifstream myfile2("text2.txt"); 
    getline(myfile2,mysecondtext);

    m = int(mytext.length());
    n = int(mysecondtext.length());
    cout << "String 1: " << m << endl;
	cout << "String 2: " << n << endl;

	cout <<"LCS: "<< LCS_V2(mytext.c_str(), mysecondtext.c_str(), m, n) << endl;
    cout <<"Print LCS: " << LCS_Common(mytext.c_str(), mysecondtext.c_str(), m, n) << endl;
    
    return 0;
}