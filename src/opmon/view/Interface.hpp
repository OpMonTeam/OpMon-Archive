#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "../start/Core.hpp"

namespace OpMon{
  namespace View{
    class Interface {
    public:
      virtual GameStatus operator()() = 0;
      virtual ~Interface() = 0;

      virtual void initStrings() = 0;

      Interface* getNextInterface() const{
	return nextInterface;
      }

      void setNextInterface(Interface* next){
	nextInterface = next;
      }
      
      virtual void pause() = 0;
      virtual void play() = 0;

      bool isWait(){
	return wait;
      }
      
    protected:
      virtual void init() = 0;
      bool launched = false;
      Interface* nextInterface;
      bool wait = false;
    };
  }
}

#endif
