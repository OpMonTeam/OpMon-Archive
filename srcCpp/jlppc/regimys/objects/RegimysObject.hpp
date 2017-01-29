
#ifndef REGIMYSOBJECT_HPP
#define REGIMYSOBJECT_HPP

class RegimysObject {
public:
	RegimysObject();
	virtual ~RegimysObject();
	virtual Class* getClass() = 0;

private:

};

#endif /* REGIMYSOBJECT_HPP */
