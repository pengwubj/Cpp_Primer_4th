/*************************************************************************
    > File Name: 2_27.cpp
    > Author: Peng Wu
    > Mail: pengwubj@gmail.com 
    > Created Time: 2014年10月28日 星期二 21时52分07秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int i;
	const int j = 7;
	const int & rj =j;
	int &ri = i;
	i=5;
	cout << i <<" "<<ri<<endl;
	cout << j <<" "<<rj<<endl;
	ri =10;
//	rj = 5;
	cout << i <<" "<<ri<<endl;
	cout << j <<" "<<rj<<endl;
	return 0;
}
