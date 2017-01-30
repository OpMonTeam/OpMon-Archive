
#ifndef REGIMYSOBJECT_HPP
#define REGIMYSOBJECT_HPP

class RegimysObject {
public:
	RegimysObject();
	virtual ~RegimysObject();
	virtual Class* getClass(){return classe;};

private:
	static Class<RegimysObject> classe;

};

#endif /* REGIMYSOBJECT_HPP */
