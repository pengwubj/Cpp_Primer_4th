/*************************************************************************
    > File Name: enum.cpp
    > Author: Peng Wu
    > Mail: pengwubj@gmail.com 
    > Created Time: 2014年10月28日 星期二 21时56分27秒
 ************************************************************************/
#include<iostream>
using namespace std;
int main(){
	//enum open_modes {input,output,append};
	enum open_modes {input=3,output,append};
	open_modes x1 = input;
	open_modes x2 = output;
	open_modes x3 = append;
	cout << x1 <<" "<< x2 <<" "<<x3 <<endl;
	return 0;
}
