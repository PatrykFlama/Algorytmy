#include<bits/stdc++.h>
using namespace std;


int main(){
	int exp, n;
	cout << "Wykladnik: ";
	cin >> exp;
	n = 1<<exp;
	for(int i = 0; i < n; i++){
		int liczbaGreya = (i >> 1)^i;
	    cout << bitset<10>(liczbaGreya).to_string() << '\n';
	    //i tu jeszcze trzeba znaleźć ktr liczbe zmieniasz i ja zmienic
	}
}
