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
bool isShorter(const string &s1 ,const string & s2){
	return s1.size() < s2.size();
}
bool GT5(const string &s1){
	return s1.size() > 5;
}

int main(int argc, char const *argv[])
{
	ifstream f1;
	if(argc != 2 || !open_file(argv[1],f1))
		cerr << "WRONG ARG" << endl;
	string each_line;
	std::vector<string> words;
	while(getline(f1,each_line)){
		istringstream line(each_line);
		string each_word;
		while(line >> each_word )
			words.push_back(each_word);
	} 
	std::vector<string>::iterator unique_end = unique(words.begin(),words.end());
	words.erase(unique_end,words.end());
	// sort(words.begin(),words.end());
	sort(words.begin(),words.end(),isShorter);
	std::vector<string>::size_type wc =count_if(words.begin(),words.end(),GT5);
	cout << wc << " " << "word(s)" ;

	return 0;
}
