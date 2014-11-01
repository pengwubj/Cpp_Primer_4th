/*************************************************************************
    > File Name: static.cpp
    > Author: Peng Wu
    > Mail: pengwubj@gmail.com 
    > Created Time: 2014年10月31日 星期五 21时58分38秒
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
class Foo {
public:
	Foo(int a):f_int(a){}
	int get() {return f_int; }
private:
	int f_int;
};
class Bar {
public:
	static Foo FooVal()
	{
		CallsFooVal++;
		return b_foo ;
	}
	static int b_int;
	static Foo b_foo;
	static int CallsFooVal;
};

int Bar::CallsFooVal = 0;
int Bar::b_int =1;
Foo Bar::b_foo(2);

int main(){
	cout << Bar::CallsFooVal << endl;
	cout << Bar::b_foo.get() <<endl;
	cout << Bar::b_int << end
	return 0;
}
