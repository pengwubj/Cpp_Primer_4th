/*************************************************************************
    > File Name: switch.cpp
    > Author: Peng Wu
    > Mail: pengwubj@gmail.com 
    > Created Time: 2014年10月31日 星期五 00时30分38秒
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

ifstream& open_file (const string filename,ifstream &in){
	in.close();
	in.clear();
	in.open(filename.c_str());
	if(!in)
		cerr << "CAN't OPEN FILE " <<endl;
	return in;
}

int main(){

	ifstream file;
	string fileName("target");
	open_file(fileName.c_str(),file);

	char pre_char ='\0';
	char cur_char;
	int ff_cnt=0;
	int fl_cnt=0;
	int fi_cnt=0;

	while(file.get(cur_char)){
		if(pre_char == 'f')
			switch(cur_char){
				case 'f': 
					ff_cnt++;
					break;
				case 'l':
					fl_cnt++;
					break;
				case 'i':
					fi_cnt++;
					break;
			}
		pre_char = cur_char;
	}
	cout << "THE NUMBER  OF ff is " << ff_cnt  << endl
     	 <<	"THE NUMBER  OF fl is " << fl_cnt  << endl
     	 <<	"THE NUMBER  OF fi is " << fi_cnt  << endl;
	return 0;

}





