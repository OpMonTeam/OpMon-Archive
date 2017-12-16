#ifndef INTERFACE_HPP
#define INTERFACE_HPP

namespace OpMon{
  namespace View{
    class Interface {
    public:
      virtual GameStatus operator()() = 0;
      virtual ~Interface() = 0;

      virtual void initStrings() = 0;

      Interface* getNextPanel(){
	return nextPanel;
      }

      virtual void pause() = 0;
      virtual void play() = 0;
      
    protected:
      void init() = 0;
      bool launched = false;
      Interface* nextPanel;
    };
  }
}

#endif
