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

ifstream& open_file (const string filename,ifstream &in){
	in.close();
	in.clear();
	in.open(filename.c_str());
	if(!in)
		cerr << "CAN't OPEN FILE " <<endl;
	return in;
}
void getoff_punct(string &s){
	for(string::iterator iter = s.begin();iter !=s.end();++iter)
	{
		if(ispunct(*iter))
		{
			s.erase(iter);
			iter--;
		}	
	}
}
int main(int argc, char const *argv[])
{
	ifstream	f1;
	string fileName("text1");
	string s1;
	std::map<string, int> wordCount;
	open_file(fileName,f1);
	while( f1 >> s1 ,!f1.eof())
	{
		getoff_punct(s1);
		++wordCount[s1];
		// cout << wordCount[s1] << endl;
	}
	for(map<string,int>::iterator iter = wordCount.begin();iter != wordCount.end();iter++)
		 cout << iter->first << "\t\t" << iter->second << endl;
	cout << "INPUT STRING TO CHECK :" << endl;
	while(cin >> s1){
		map<string,int>::iterator iter = wordCount.find(s1);
		if(iter !=wordCount.end())
		 cout << iter->first << "\t\t" << iter->second << endl;
		 else
		 cout <<"CANNOT find the pair "<< endl;			
	}

	return 0;
}