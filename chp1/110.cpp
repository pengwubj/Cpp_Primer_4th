/*************************************************************************
    > File Name: 110.cpp
    > Author: Peng Wu
    > Mail: pengwubj@gmail.com 
    > Created Time: 2014年10月28日 星期二 15时21分18秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int v1,v2;
	cout<< "INPUT TWO NUMBER :" << endl ;
	while(cin >> v1 >> v2 ){
		cout << "v1 = " << v1 << "v2" << v2 << endl;
		if(v1 <= v2 ){
			for(int v3 = v1;v3 <= v2 ;v3++){
				if( ((v3-v1) % 10) == 0) cout << endl;
				cout << v3 << "\t";
			}
			cout << endl;
			cout << "@END"<<endl;
		}
		else{
			for(int v3 = v2;v3 <= v1 ;v3++){
				if( ((v3-v2) % 10) == 0) cout << endl;
				cout << v3 << "\t" ;
			}
			cout << endl;
			cout << "@END"<<endl;
		}

	}
	cout << "ILEGAL INPUT END " << endl;
	return 0;

}
