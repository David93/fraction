#include <iostream>
#include <string>
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
		//constructors
		Fraction(int n, int d):num(n),dem(d){reduce();}
		Fraction(int n):num(n),dem(1){}
		Fraction(double n){
			string s=to_string(n);
			int dot=s.find(".");
			int a=stoi(s.substr(0,dot));
			int b=stoi(s.substr(dot+1,s.size()-dot));
			while(b%10==0)
				b/=10;
			dem=1;
			num=stoi(to_string(a)+to_string(b));
			while(b)
			{	b/=10;dem*=10;}
			reduce();
		}
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
		//display functions
		void display(){cout<<num<<"/"<<dem<<endl;}
		//overload for <<, declared as friend to use private elems	
		friend ostream& operator<<(ostream& os, const Fraction& f);  
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
bool Fraction::operator<(const Fraction& b){
	int n1=(this->num)*(b.dem);
	int n2=(this->dem)*(b.num);
	if(n1<n2)
		return true;
	return false;
}
bool Fraction::operator>(const Fraction& b){
	int n1=(this->num)*(b.dem);
	int n2=(this->dem)*(b.num);
	if(n1>n2)
		return true;
	return false;
}
bool Fraction::operator==(const Fraction& b){
	int n1=(this->num)*(b.dem);
	int n2=(this->dem)*(b.num);
	int d=(this->dem)*(b.dem);
	if(n1==n2)
		return true;
	return false;
}
bool Fraction::operator!=(const Fraction& b){
	return !(*this==b);
}
//<< overload body
ostream& operator<<(ostream& os, const Fraction& f)  
{  
    os<<f.num<<'/'<<f.dem;  
    return os;  
}  
int main(){
	cout<<"Fraction Testbench"<<endl;
	Fraction a(3,4);
	Fraction b=a*1.25;
	cout<<b<<endl;
	return 0;
}