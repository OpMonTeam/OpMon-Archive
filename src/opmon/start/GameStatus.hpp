/**
  GameStatus.hpp
  Author : BAKfr
  File under GNU GPL v3.0 license
*/
#pragma once

namespace OpMon {

    enum class GameStatus {
        CONTINUE,
        STOP,
        NEXT,
        PREVIOUS,
	NEXT_NLS, //NLS stands for No Loading Screen
	PREVIOUS_NLS
    };
}
