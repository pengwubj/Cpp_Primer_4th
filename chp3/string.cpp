/*************************************************************************
    > File Name: string.cpp
    > Author: Peng Wu
    > Mail: pengwubj@gmail.com 
    > Created Time: 2014年10月28日 星期二 22时18分08秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main() {
	string s1("Hello , World!!");
	string s2;
	string s3;
	string::size_type index;
	for(index=0;index<s1.size();++index){
		if(!ispunct(s1[index])) 
			s2 +=s1[index];
	}
	cout << s1 << "  size is " << s1.size() << endl;
	cout << s2 << "  size is " << s2.size() << endl;
	for(index=0;index < s2.size();++index)
		s2[index] = toupper(s2[index]);
	cout << s2 << "  size is " << s2.size() << endl;

	for(index=0;index < s2.size();++index)
		if(!isspace(s2[index]))
			s3 += s2[index];
	cout << s3 << "  size is " << s3.size() << endl;
	return 0;


}
