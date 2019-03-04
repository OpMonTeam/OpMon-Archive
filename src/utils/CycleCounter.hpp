#pragma once

namespace Utils {
    
    class CycleCounter {
    private:
	int value = 0;

	int limitDown;
	int limitUp;
	int range;
	
    public:
	CycleCounter(int limitUp, int limitDown = 0, int value = 0) :
	    value(value),
	    limitDown(limitDown),
	    limitUp(limitUp),
	    range(limitUp - limitDown) {}

	CycleCounter operator+(int number) {return CycleCounter(limitUp, limitDown, ((range + ((value + number) - limitDown)) % range) + limitDown);}
	CycleCounter operator-(int number) {return CycleCounter(limitUp, limitDown, ((range + ((value - number) - limitDown)) % range) + limitDown);}
	CycleCounter operator*(int number) {return CycleCounter(limitUp, limitDown, ((range + ((value * number) - limitDown)) % range) + limitDown);}
	CycleCounter operator/(int number) {return CycleCounter(limitUp, limitDown, ((range + ((value / number) - limitDown)) % range) + limitDown);}

	void operator++(int) {value = (*this + 1).value;}
	void operator--(int) {value = (*this - 1).value;}

	void operator+=(int number) {value = (*this + number).value;}
	void operator-=(int number) {value = (*this - number).value;}
	void operator*=(int number) {value = (*this * number).value;}
	void operator/=(int number) {value = (*this / number).value;}

	int getValue() {return value;}
	
    };
}
