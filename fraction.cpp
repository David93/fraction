#include <iostream>
using namespace std;
//HCF func
int HCF(int a, int b){
	if(a==b)
		return a;
	if(a<b)
		return HCF(b,a);
	int res=1;
	for(int i=2;i<=b;i++){
		if(a%i==0 && b%i==0)
			res=i;
	}
	return res;
}
class Fraction{
	private:
		int num, dem;
	public:
		//constructor
		Fraction(int n, int d):num(n),dem(d){reduce();}
		//overloaded ops
		Fraction operator+(const Fraction& b);
		Fraction operator-(const Fraction& b);
		Fraction operator*(const Fraction& b);
		Fraction operator/(const Fraction& b);
		bool operator>(const Fraction& b);
		bool operator<(const Fraction& b);
		//reduce/simplify func
		void reduce();
		//display function
		void display(){cout<<num<<"/"<<dem<<endl;}	
};
void Fraction::reduce(){
	int h=HCF(num,dem);
	num/=h;
	dem/=h;

}
int main(){
	cout<<"Fraction Testbench"<<endl;
	Fraction t(5,95);
	t.display();
	return 0;
}