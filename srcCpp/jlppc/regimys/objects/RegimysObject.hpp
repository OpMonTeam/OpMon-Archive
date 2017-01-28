
#ifndef REGIMYSOBJECT_HPP
#define REGIMYSOBJECT_HPP

class RegimysObject {
public:
	RegimysObject();
	virtual ~RegimysObject();
	virtual Class* getClass(){return classe;};
	Class<RegimysObject> *classe = new Class<RegimysObject>("RegimysObject", 0000001);
	static Class* getClass(){return classe;};
};

#endif /* REGIMYSOBJECT_HPP */
