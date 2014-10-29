/*************************************************************************
    > File Name: bitset.cpp
    > Author: Peng Wu
    > Mail: pengwubj@gmail.com 
    > Created Time: 2014年10月29日 星期三 20时52分10秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<bitset>
using namespace std;
int main(){
	bitset<32> ibit;
	int x =0;
	int y =1;
	int z=x+y;
	while(z <= 21 ){
		ibit.set(z);
		x=y;
		y=z;
		z=x+y;
	}
	cout << ibit <<endl;
	return 0;
}
