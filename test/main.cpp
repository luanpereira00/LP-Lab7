#include <iostream>
using std::cout;
using std::endl;

#include <vector> 
using std::vector; 
 
#include "templateSTL.h"

int main() {    
	vector<int> v { 1, 2, 3, 30, 40, 50, 15, 84, 75, 23, 2, 5, 8, 26, 25, 1 };    
	auto result = closest2mean(v.begin(), v.end());    
	cout << (*result) << endl;    
	return 0; 
}
