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
int main(int argc, char const *argv[])
{
	multimap<string,string> writerBookSet;
	string author,work;
	do{
		cout << "INPUT the name of the author " << endl;
		cin >> author;
		if(!cin)
			break;
		cout << "the the corresponding book " << endl;
		while(cin >> work)
			writerBookSet.insert(make_pair(author,work));
		cin.clear();
	}while(cin);
	cin.clear();
	do{
		cout << "INPUT the name you are looking for :" <<endl;
		cin >> author;
		if(!cin)
			break;
		multimap<string,string>::iterator iter_b,iter_e;
		iter_b = writerBookSet.lower_bound (author);
		iter_e = writerBookSet.upper_bound (author);
		__typeof(writerBookSet.begin()) iter_first= writerBookSet.begin();
		cout << iter_first->first << iter_first -> second << endl;
		cout << "========================" << endl;
		while(iter_b != iter_e){
			cout << iter_b->second << endl;
			++iter_b;
		}
		cin.clear();
	}while(cin);
	return 0;
}