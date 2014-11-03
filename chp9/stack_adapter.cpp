#include <stack>
#include <vector>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	const stack<int>::size_type	stk_size = 10;
	stack<int> intstack;
	int ix=0;
	while(intstack.size() != stk_size)
	{
		intstack.push(ix++);
	}
	int err_cnt =0;
	while(intstack.empty() == false){
		int value =intstack.top();
		if(value != --ix)
			cerr << "ERROR" << endl;
		intstack.pop();
		cout << intstack.size() << endl ;
	}

	return 0;
}