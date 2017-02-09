#ifndef EVOLUTIONS_HPP_INCLUDED
#define EVOLUTIONS_HPP_INCLUDED

#include "Evolution.hpp"
#include <iostream>

using namespace std;

namespace Evolutions{

    const int Item = 7, Land = 6, Level = 5, Love = 4, Nope = 3, Trade = 2, TradeItem = 1;

    class E_Item: public Evolution {
public:
	E_Item(int evo, Item *forEvolve);
	bool checkEvolve(Pokemon  const& toCheck) const;
	bool itemEvolve(Item *forEvolve) const;
	 const int evolID = 7;

protected:
	Item *forEvolve;
};

class E_Land: public Evolution {
public:
	E_Land(int evo, string lieu);
	bool checkEvolve (Pokemon const& toCheck) const {return false;}//Il faudra tester si l'endroit ou se trouve le dresseur est le bon.
	 const int evolID = 6;
private:
	//Plan carteDuLieu;
};

class E_Level: public Evolution {
public:
	E_Level(int evo, int level);
	bool checkEvolve(Pokemon const& toCheck) const;
	 const int evolID = 5;
private:
	int level;
};

class E_Love: public Evolution {
public:
	E_Love(int evo) : Evolution(evo){}
	bool checkEvolve(Pokemon const& toCheck) const {return (toCheck.getStatLove() > 100);}
	 const int evolID = 4;
private:

};

class E_Nope {
public:
	E_Nope();
	bool checkEvolve(Pokemon const& toCheck) const;
	 const int evolID = 3;
};

class E_Trade: public Evolution {
public:
	E_Trade(int evo) : Evolution(evo){};
	bool checkEvolve(Pokemon const& toCheck) const {return true;}
	 const int evolID = 2;
};

class E_TradeItem: public E_Item {
public:
	E_TradeItem(int evo, Item *forEvolve, int ID) : E_Item(evo, forEvolve){};
	bool checkEvolve(Pokemon const& toCheck);
	 const int evolID = 1;
};

};

using namespace Evolutions;


#endif // EVOLUTIONS_HPP_INCLUDED
