/*************************************************************************
    > File Name: vector.cpp
    > Author: Peng Wu
    > Mail: pengwubj@gmail.com 
    > Created Time: 2014年10月28日 星期二 22时37分56秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cctype>
#include<vector>
using namespace std;

int main () {
//3-13
/*	vector<int> ivec;
	int v1;
	cout << "INPUT AN ARRAY OF NUMBER"  << endl;
	while( cin >> v1 )
		ivec.push_back(v1);
	for(vector<int>::size_type index=0;index != ((ivec.size())/2) ; ++index)
		cout << "SUM of the" << index << "st and the " << (ivec.size()-1-index) << "st is " << ivec[index] + ivec[(ivec.size()-1-index)] << endl;

//3-14
	vector<string> svec;
	string s1;
	cout << "INPUT Text"<<endl;
	while(cin >>s1 )
		svec.push_back(s1);
	for(vector<string>::size_type index=0;index != svec.size();++index)
		for(string::size_type s_index =0;s_index !=svec[index].size();++s_index)
			svec[index][s_index]= toupper(svec[index][s_index]);

	for(vector<string>::size_type index=0;index != svec.size();++index){
		if(index%8 == 0)
			cout<<endl;
		cout << svec[index] << " ";
	}
*/
//3-17
	vector<string> svec;
	string s1;
	cout << "INPUT Text"<<endl;
	while(cin >>s1 )
		svec.push_back(s1);
	for(vector<string>::iterator iter=svec.begin();iter!=svec.end();++iter)
		for(string::size_type s_index =0;s_index !=(*iter).size();++s_index)
			(*iter)[s_index]= toupper((*iter)[s_index]);
		
	for(vector<string>::iterator iter = svec.begin(); iter != svec.end();++iter){
		cout << *iter << " ";
	}

	return 0;



}
