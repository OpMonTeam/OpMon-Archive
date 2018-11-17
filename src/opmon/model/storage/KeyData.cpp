/*
  OptionsMenuData.cpp
  Author : Cyrion
  File under GNU GPL v3.0 license
*/
#include "KeyData.hpp"

namespace OpMon {
    namespace Model {
        const std::string& KeyData::findNameKeyCode(sf::Keyboard::Key searchKeyCode)
        {
            for(auto it = std::cbegin(Model::KeyData::keysMap); it != std::cend(Model::KeyData::keysMap); ++it )
            {
                if (it->second == searchKeyCode)
                    return it->first;
            }

            return std::cbegin(Model::KeyData::keysMap)->first;
        }

#define ADDMAP(key) {(#key), sf::Keyboard::key}
        const std::unordered_map<std::string, sf::Keyboard::Key> KeyData::keysMap = {
                ADDMAP(Unknown),
                ADDMAP(A), ADDMAP(Z), ADDMAP(E), ADDMAP(R), ADDMAP(T),
                ADDMAP(Y), ADDMAP(U), ADDMAP(I), ADDMAP(O), ADDMAP(P),
                ADDMAP(Q), ADDMAP(S), ADDMAP(D), ADDMAP(F), ADDMAP(G),
                ADDMAP(H), ADDMAP(J), ADDMAP(K), ADDMAP(L), ADDMAP(M),
                ADDMAP(W), ADDMAP(X), ADDMAP(C), ADDMAP(V), ADDMAP(B),
                ADDMAP(N),
                ADDMAP(Num1), ADDMAP(Num2), ADDMAP(Num3), ADDMAP(Num4), ADDMAP(Num5),
                ADDMAP(Num6), ADDMAP(Num7), ADDMAP(Num8), ADDMAP(Num9), ADDMAP(Num0),
                ADDMAP(LControl), ADDMAP(RControl), ADDMAP(LShift), ADDMAP(RShift), ADDMAP(LAlt),
                ADDMAP(RAlt), ADDMAP(Space), ADDMAP(Return), ADDMAP(BackSpace), ADDMAP(Tab),
                ADDMAP(Up), ADDMAP(Left), ADDMAP(Right), ADDMAP(Down),
                ADDMAP(Numpad1), ADDMAP(Numpad2), ADDMAP(Numpad3), ADDMAP(Numpad4), ADDMAP(Numpad5),
                ADDMAP(Numpad6), ADDMAP(Numpad7), ADDMAP(Numpad8), ADDMAP(Numpad9), ADDMAP(Numpad0)
            };
#undef ADDMAP
    } // namespace Model
} // namespace OpMon
