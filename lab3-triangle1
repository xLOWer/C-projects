#include <math.h>


class __TRIANG{
	public: double a, b, c;
	
	double _perimeter()
	{
		return a + b + c;
	}
	
	double _square()
	{
		double p = _perimeter() / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	
	bool __triangle(){
		if(a + b > c && a + c > b && b + c > a){return true ;}else{return false;}
	}

};
