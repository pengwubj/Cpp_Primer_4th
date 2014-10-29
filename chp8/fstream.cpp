/*************************************************************************
    > File Name: fstream.cpp
    > Author: Peng Wu
    > Mail: pengwubj@gmail.com 
    > Created Time: 2014年10月29日 星期三 23时51分52秒
 ************************************************************************/

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

fstream& open_file (const string filename,fstream &in){
	in.close();
	in.clear();
	in.open(filename.c_str(),fstream::in | fstream::out | fstream::app);
	if(!in)
		cerr << "CAN't OPEN FILE " <<endl;
	return in;
}
int main () {
	string fileName("target");
	vector<string> svec;
	fstream f1;
	fstream f2;
	open_file("target",f1);
	open_file("badgetc",f2);
	string line;
	while(getline(f1,line))
		svec.push_back(line);
	for(vector<string>::iterator iter=svec.begin();iter!=svec.end();++iter)
		f2 << *iter << endl;
	f1.close();
	f2.close();
	return 1;
}
