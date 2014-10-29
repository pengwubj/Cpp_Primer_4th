/*************************************************************************
    > File Name: open_file.cpp
    > Author: Peng Wu
    > Mail: pengwubj@gmail.com 
    > Created Time: 2014年10月29日 星期三 22时13分55秒
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

istream & get(istream & in, vector<string> &cont){
	string ival;
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
		cont.push_back(ival);

	}
	in.clear();
	return in;
}
ifstream& open_file (const string filename,ifstream &in){
	in.close();
	in.clear();
	in.open(filename.c_str());
	if(!in)
		cerr << "CAN't OPEN FILE " <<endl;
	return in;
}

int main (){
	string fileName;
	cout << "INPut NAME: " << endl;
	cin >> fileName;
	ifstream file;
	open_file(fileName,file);
	vector<string> cont;
	get(file,cont);
	cout << "content in vector" << endl;
	for(vector<string>::iterator iter=cont.begin();iter!=cont.end();++iter)
		cout << *iter << endl;
	file.close();
	return 0;
}
