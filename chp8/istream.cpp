/*************************************************************************
    > File Name: istream.cpp
    > Author: Peng Wu
    > Mail: pengwubj@gmail.com 
    > Created Time: 2014年10月29日 星期三 21时19分22秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<bitset>
#include<stdexcept>
using namespace std;
istream & get(istream & in){
	int ival;
	while(in>>ival ,!in.eof()){
		if(in.bad())
			throw runtime_error("IO stream corrupted");
		if(in.fail()){
			cerr << "BAD DATA. TRY AGAIN" <<endl;
			in.clear();
			in.ignore(200,'\n');
			continue;
		}
		cout << ival << " ";

	}
	in.clear();
	return in;
}

int main (){
	int ival;
	get(cin);
	cout << "BACK" <<endl;
	return 0;
}


