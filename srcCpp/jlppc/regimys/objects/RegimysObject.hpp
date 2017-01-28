/*
 * RegimysObject.hpp
 *
 *  Created on: 28 janv. 2017
 *      Author: Jlppc (session)
 */

#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_REGIMYSOBJECT_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_REGIMYSOBJECT_HPP_

class RegimysObject {
public:
	RegimysObject();
	virtual ~RegimysObject();
	virtual Class* getClass(){return classe;};
	virtual static Class<RegimysObject> *classe = new Class<RegimysObject>("RegimysObject", 0000001);
};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_REGIMYSOBJECT_HPP_ */
