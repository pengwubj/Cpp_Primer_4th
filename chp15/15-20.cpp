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
class Iterm_base{
public:
	Iterm_base(const string &book ="",double sales_price =0.0):
	isbn(book),price(sales_price)
	{
		cout << "Iterm_base(const std::string &,double)" << endl;

	}
	Iterm_base(const Iterm_base & ib):isbn(ib.isbn),price(ib.price)
	{
		cout << "Iterm_base(cosnt Iterm_base & ib )" << endl ;
	}
	Iterm_base & operator=(const Iterm_base & rhs)
	{
		isbn  = rhs.isbn;
		price = rhs.price;
		cout << "Iterm_base& operator=" << endl;
		return *this; 
	}
	virtual ~Iterm_base()
	{
		cout << "~Iterm_base" << endl;
	}
	string book()const
	{
		return isbn;
	}
	virtual double net_price(size_t n) const
	{
		return n * price;
	}

private:
	string isbn;
protected:
	double price;
};
class Bulk_iterm: public Iterm_base
{
public:
	Bulk_iterm(const string & book ="",double sales_price =0.0,size_t qty =0,double disc_rate = 0.0):
	Iterm_base(book,sales_price),min_qty(qty),discount(disc_rate)
	{
		cout << "Bulk_iterm(const string & book,double sales_price,size_t qty,double disc_rate )" << endl;
	}
	Bulk_iterm(const Bulk_iterm &b):
	Iterm_base(b),min_qty(b.min_qty),discount(b.discount)
	{
		cout << "Bulk_iterm(const Bulk_iterm &b)" << endl;
	}
	Bulk_iterm& operator=(const Bulk_iterm & rhs)
	{
		if(this != &rhs)
		{
			Iterm_base::operator=(rhs);
			min_qty =rhs.min_qty;
			discount=rhs.discount;
		}
			cout << "Bulk_iterm& operator" << endl;
			return *this;
	}
	double	 net_price(size_t cnt ) const
	{
		if(cnt >= min_qty)
			return cnt* (1 - discount)* price;
		else
			return cnt * price;
	}
	~Bulk_iterm()
	{
		cout << "~Bulk_iterm" << endl;
	}
private:
	size_t min_qty;
	double discount;
};
void foo1(Iterm_base obj){}
void foo2(Iterm_base &obj){}
Iterm_base foo3()
{
	Iterm_base obj;
	return obj;
}

int main(int argc, char const *argv[])
{
	/* code */
	cout << "\n ==================1===================== \n" << endl;
	Iterm_base iobj; //default constructor of Iterm_base
	cout << "\n ==================2===================== \n" << endl;
	foo1(iobj); //copy & delete 
	cout << "\n ==================3===================== \n" << endl;
	foo2(iobj); //need not to copy and delete
	cout << "\n ==================4===================== \n" << endl;
	iobj = foo3(); //default constructer of local obj and copy by = then delete 
	cout << "\n ==================5===================== \n" << endl;
	Iterm_base *p = new Iterm_base; // default constructor and need not to copy
	cout << "\n ==================6===================== \n" << endl;
	delete p;  //~
	cout << "\n ==================7===================== \n" << endl;
	Bulk_iterm bobj;  // build base and drived 
	cout << "\n ==================8===================== \n" << endl;
	foo1(bobj); //implicitly translate Bclass to Iclass and build Iclass the copy then delete;
	cout << "\n ==================9===================== \n" << endl;
	foo2(bobj); //implicitly translate
	cout << "\n ==================10==================== \n" << endl;
	Bulk_iterm *q = new Bulk_iterm;
	cout << "\n ==================11===================== \n" << endl;
	delete q;   
	std::vector<Iterm_base*> ivec;
	string book;
	double	sales_price;
	double  disc_rate;
	size_t qty;
	cout  <<  "Input book\tsale_price\tdisc_rate\tqty :" << endl;	
	while(cin>>book>>sales_price>>disc_rate>>qty)
	{
		Bulk_iterm* bptr = new Bulk_iterm(book,sales_price,qty,disc_rate);
		ivec.push_back(bptr);
	}
	double sum=0.0;
	for(std::vector<Iterm_base*>::iterator iter=ivec.begin();iter != ivec.end();++iter)
	{
		sum +=(*iter)->net_price(100);
	}
	cout << "NET PRICE IS " << sum << endl;
	for(std::vector<Iterm_base*>::iterator iter=ivec.begin();iter != ivec.end();++iter)
	{
		delete (*iter);
	}

	return 0;
}