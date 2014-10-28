/*************************************************************************
    > File Name: char_signed.cpp
    > Author: Peng Wu
    > Mail: pengwubj@gmail.com 
    > Created Time: 2014年10月28日 星期二 15时51分23秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	unsigned char v1 = 1;
	if(v1 >=0 && ~v1 >=0)
		cout << v1 << ~v1<< "char in this compiler&machine is unsigned" << endl;
	else 
		cout << "char in this compiler&machine is signed" << endl;
	return 0;

}
