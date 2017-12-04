#ifndef INTERFACE_HPP
#define INTERFACE_HPP

namespace OpMon{
  namespace View{
    class Interface {
    public:
      GameStatus operator()() = 0;
      void del() = 0;
    protected:
      void init() = 0;
      bool launched = false;
    };
  }
}

#endif
