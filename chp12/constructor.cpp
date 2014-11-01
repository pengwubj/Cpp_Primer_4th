/*************************************************************************
    > File Name: constructor.cpp
    > Author: Peng Wu
    > Mail: pengwubj@gmail.com 
    > Created Time: 2014年10月31日 星期五 21时14分19秒
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
class ctest {	
public:
	ctest(const string& str,int cnt ,double* dptr,ifstream& f1):
		c_str(str),c_int(cnt),c_ptr(dptr),c_if(f1)
	{ 
		cout << "constructor 1 "<< endl;
	}
	ctest(int cnt ,double* dptr,ifstream& f1):
		c_str("HElLO"),c_int(cnt),c_ptr(dptr),c_if(f1)
	{ 
		cout << "constructor 2"<< endl;
	}
	const string c_str;
	int c_int;
	double * c_ptr;
	ifstream& c_if;
};

int main(){
	double a =1.0;
	ifstream f1;
	ctest c1("hello",1,&a,f1);
	ctest c2(1,&a,f1);
	return 0;

}
