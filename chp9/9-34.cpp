#include <string>
#include <iostream>
#include <cctype>
using namespace std;
int main(int argc, char const *argv[])
{
	string s1("AbCdEfG");
	string s2 = s1;
	string s3 ("hello  world    ni hao !!");
	for(string::iterator ster=s1.begin();ster != s1.end();++ster){
		(*ster) = toupper(*ster);
	}
	cout << "s1: " << s1 << endl;

	for(string::iterator ster=s2.begin();ster != s2.end();++ster){
		if(isupper(*ster))
		{
			s2.erase(ster);
			--ster;
		}
	}
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;

	bool lastIsSpace = false;

	for(string::iterator ster=s3.begin();ster != s3.end();++ster){
		if(isspace(*ster) )
		{  
			if(lastIsSpace)
			{
				s3.erase(ster);
				--ster;
				//cout << "tag1" <<endl;
			}
			else{
					lastIsSpace = true;
					//cout << "tag2" <<endl;
				}
		}	
		else{	
				lastIsSpace = false;
				//cout << "tag3" <<endl;
			}
	}

	cout << "s3: " << s3 << endl;



	return 0;
}