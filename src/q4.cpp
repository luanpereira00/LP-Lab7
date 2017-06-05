#include <iostream>
using std::cout;
using std::endl;

#include <vector> 
using std::vector; 

#include <algorithm>
using std::find_if;

#include <set> 
using std::set; 
 
#include "templateSTL.h"

bool isPrime(int i){
	int j=2;
	while(j<=i/2){
		if(i%j==0) return false;
		j++;
	}
	return true;
}

int main() {    
	vector<int> v;
	set<int> y;
	int n = 50, i=2;
	while(i<n) {
		 v.push_back(i);
		i++;
	}   

	print_elements(v);
	auto it = v.begin();
	while(it!=v.end()){
		y.insert(*(find_if(it, v.end(), isPrime)));
		it++;
	}  
	print_elements(y);
	return 0; 
}
