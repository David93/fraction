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
		bool operator==(const Fraction& b);
		bool operator!=(const Fraction& b);
		//reduce/simplify func
		void reduce();
		//display function
		void display(){cout<<num<<"/"<<dem<<endl;}	
};
void Fraction::reduce(){
	int h=HCF(abs(num),abs(dem));
	num/=h;
	dem/=h;
}
Fraction Fraction::operator+(const Fraction& b){
	int n1=(this->num)*(b.dem);
	int n2=(this->dem)*(b.num);
	int d=(this->dem)*(b.dem);
	Fraction res(n1+n2,d);
	res.reduce();
	return res;
}
Fraction Fraction::operator-(const Fraction& b){
	int n1=(this->num)*(b.dem);
	int n2=(this->dem)*(b.num);
	int d=(this->dem)*(b.dem);
	Fraction res(n1-n2,d);
	res.reduce();
	return res;
}
Fraction Fraction::operator*(const Fraction& b){
	int n=(this->num)*(b.num);
	int d=(this->dem)*(b.dem);
	Fraction res(n,d);
	res.reduce();
	return res;
}
Fraction Fraction::operator/(const Fraction& b){
	return (*this)*(Fraction(b.dem,b.num));
}
int main(){
	cout<<"Fraction Testbench"<<endl;
	Fraction a(1,4);
	Fraction b(1,2);
	Fraction t=a/b;
	t.display();
	return 0;
}