/*************************************************************************
    > File Name: istringstream.cpp
    > Author: Peng Wu
    > Mail: pengwubj@gmail.com 
    > Created Time: 2014年10月29日 星期三 23时00分12秒
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

ifstream& open_file (const string & filename,ifstream &in){
	in.close();
	in.clear();
	in.open(filename.c_str()) ;
	if(!in)
		cerr << "CAN't OPEN FILE " <<endl;
	return in;
}

ofstream& open_file_w (const string & filename,ofstream &in){
	in.close();
	in.clear();
	in.open(filename.c_str(), ofstream::out | ofstream::ate )  ;
	if(!in)
		cerr << "CAN't OPEN FILE " <<endl;
	return in;
}
int main (){
	string fileName;
	string file_line;
	cout << "INPUT NAME " << endl;
	cin >> fileName;
	ifstream file_s;
	ofstream file_t;
	open_file("badgetc",file_s);
	open_file_w(fileName,file_t);
	while(getline(file_s,file_line)){
		istringstream eachLine(file_line);
		string eachWord;
		while(eachLine >> eachWord)
			file_t << eachWord  << endl;
	}
	return 0;
}












