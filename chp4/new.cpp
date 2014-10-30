/*************************************************************************
    > File Name: charVSstring.cpp
    > Author: Peng Wu
    > Mail: pengwubj@gmail.com 
    > Created Time: 2014年10月30日 星期四 22时48分58秒
 ************************************************************************/

#include <cmath>    
#include <cstddef>  
#include <cstdlib>  
#include <string>   
#include <vector>   
#include <list>     
#include <map>      
#include <set>      
#include <utility>  
#include <iostream> 
#include <fstream>  
#include <sstream>  
#include <algorithm>
#include <numeric>  
#include <iterator> 
#include <stdexcept> 
using namespace std;
int main(){
	vector<int> ivec;
	int ival;
	cout << "INPUT INTS" << endl;
	while(cin>> ival)
		ivec.push_back(ival);
	vector<int>::size_type ivecSize = ivec.size();
	int * aPtr = new int[ivecSize];
	int * a_bak = aPtr;
	for(vector<int>::size_type ix=0;ix != ivecSize;++ix)
		*(aPtr++) = ivec[ix];
	for(int ix =0 ; ix != ivecSize; ix++)
		cout << a_bak[ix] <<endl;
	delete [] a_bak;
	return 0;
}
