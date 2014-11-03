#include <vector>
#include <list>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int ia[]={0,1,1,2,3,5,8,13,21,55,89};
	std::vector<int>  ivec(ia,ia+11);
	std::list<int> ilist(ia,ia+11);
	for(std::vector<int>::iterator iter=ivec.begin();iter != ivec.end();++iter)
	{
		if(*iter % 2 != 0){
			ivec.erase(iter);
			--iter;
		}
	}
	for(std::vector<int>::iterator iter=ivec.begin();iter != ivec.end();++iter)
	{
		cout << *iter <<endl;
	}
	return 0;
}