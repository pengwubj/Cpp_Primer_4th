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
		throw runtime_error("CANNOT OPEN FILE ");
	return in;
}
int main(int argc, char const *argv[])
{
	map<string,string> trans_map;
	string key,value;
	ifstream f1;
	ifstream f2;
	if(argc != 3)
		throw runtime_error("wrong number of argument");
	open_file(argv[1],f1);
	while(f1>>key >> value , !f1.eof())
		trans_map.insert(make_pair(key,value));
	open_file(argv[2],f2);
	string line;
	while(getline(f2,line)){
		istringstream stream(line);
		string word;
		bool firstWord = true;
		while(stream >> word){
			map<string,string>::iterator iter = trans_map.find(word);
			if(iter != trans_map.end())
				word = iter->second;
			if(firstWord)
				firstWord = false;
			else
				cout << " ";
			cout << word;
		}
		cout << endl;
	}

	return 0;
}