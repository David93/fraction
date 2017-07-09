#include <iostream>
using namespace std;
class Fraction{
	private:
	int num, dem;
	public:
	Fraction(int n, int d):num(n),dem(d){}
	void display(){cout<<num<<"/"<<dem<<endl;}	
};
int main(){
	cout<<"Fraction Testbench"<<endl;
	Fraction t(1,2);
	t.display();
	return 0;
}