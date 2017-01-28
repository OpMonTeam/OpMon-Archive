/*
 * Item.hpp
 *
 *  Created on: 28 janv. 2017
 *      Author: Jlppc (session)
 */

#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_ITEM_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_ITEM_HPP_

class Item: public RegimysObject {
public:
	Item();
	static Class<Item> *classe = new Class<Item>("Item", 4984631);
};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_ITEM_HPP_ */
