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
void getoff_punct(string &s);

class TextQuery
{
public:
	typedef std::vector<string>::size_type line_no;
	void read_file(std::ifstream &is);
	set<line_no> run_query (const std::string &);
	string text_line(line_no) const;
private:
	void store_file(ifstream &);
	void build_map();
	std::map<string, set<line_no> > word_map;
	std::vector<string> lines_of_text;
};
void TextQuery::read_file(std::ifstream &is){
	store_file(is);
	build_map();
}
void TextQuery::store_file (ifstream &is){
	if(!is)
		cerr << "CAN't OPEN FILE " <<endl;
	string each_line;
	while(getline(is,each_line)){
		lines_of_text.push_back(each_line);
	}
}
void TextQuery::build_map (){
	for(line_no index=0;index !=lines_of_text.size();++index){
		string each_word;
		istringstream line (lines_of_text[index]);
		while(line >> each_word){
			getoff_punct(each_word);
			word_map[each_word].insert(index);
		}
	}
}
set<TextQuery::line_no>  TextQuery::run_query(const string &s){
	map< string,set<line_no> > :: const_iterator loc = word_map.find(s);
	if(loc == word_map.end())
		return set<line_no>();
	else 
		return loc->second;
}

string TextQuery::text_line (line_no index) const {
	if(index < lines_of_text.size())
		return lines_of_text[index];
	throw out_of_range("line number out of range ");
}

ifstream& open_file (const string filename,ifstream &in){
	in.close();
	in.clear();
	in.open(filename.c_str());
	if(!in)
		cerr << "CAN't OPEN FILE " <<endl;
	return in;
}
void print_result(const set<TextQuery::line_no> l ,const string &s,const TextQuery &t){
	typedef set< TextQuery::line_no> line_set;
	line_set::size_type times = l.size();
	cout << "element" << s << "occures " << times << "time(s)" << endl;
	line_set::iterator iter = l.begin();
	while(iter != l.end()){
		cout << "\t" << (*iter )+ 1  << "\t" << t.text_line(*iter) << endl; 
		++iter;
	}
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
	ifstream infile;
	if(argc != 2 || !open_file(argv[1],infile)){
		cerr << "NO FILE OPEN" << endl;
		return EXIT_FAILURE;
	}
	TextQuery t1;
	t1.read_file(infile);
	while(true){
		cout << "enter word you look for : or q to quit  " << endl;
		string s;
		cin >>s;
		if(!cin || s == "q") break;
		set<TextQuery::line_no> locs  =t1.run_query(s);
		print_result(locs,s,t1);
		cin.clear();
	}

	return 0;
}