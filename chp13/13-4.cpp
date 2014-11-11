#include <string>
#include <iostream>
using namespace std;
class NoName{
public:	
	NoName():sptr(new string),i(0),d(0.0) {
		cout << "default construct" << endl;
 	}
 	NoName(const string & s):sptr(new string(s)),i(0),d(0.0)
 	{
 		cout << "directly initialize " << endl;
 	}
	// NoName(const NoName & n):sptr(new string( *(n.sptr))),i(n.i),d(n.d){ 
	// 	cout << "indirectrly copy and construct " << endl;
	// }
	void show_string() const
	{
		cout << *sptr << endl;
	}
	NoName& operator= (const NoName&) ;
	string * sptr;	
private:
	// NoName(const NoName & n):sptr(new string( *(n.sptr))),i(n.i),d(n.d){ 
	// 	cout << "indirectrly copy and construct " << endl;
	// }

	// string * sptr;
	int i;
	double d;

};

NoName& 
NoName::operator= (const NoName &rhs){
	i = rhs.i;
	d = rhs.d;
	sptr = new string(*(rhs.sptr));
	cerr << "operator ovewload " << endl;
	return *this;

}

int main(int argc, char const *argv[])
{
	NoName n1;
	n1.show_string();
	cout << "===============" << endl;
	NoName n2= string("haha");
	n2.show_string();
	cout << "===============" << endl;
	NoName n3(n2);
	n3.show_string();
	cout << n2.sptr <<" " << n3.sptr << endl;   //synthesized copy constructor copy pty directly
	cout << "===============" << endl;
	NoName n4 = n3;
	n4.show_string();
	cout << "===============" << endl;
	NoName n5 ;
	n5 = n4;                                    //operator = overided 
	n5.show_string();
	cout << "===============" << endl;
	cout << n4.sptr << " "<< n5.sptr << endl;
	return 0;
}