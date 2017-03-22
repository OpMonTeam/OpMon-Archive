#include "Overworld.hpp"

namespace MainFrame {
    namespace Overworld {

        bool continuer = true;
        long ancientTick = 0;
        bool joypressed = false;
        Plan *actuel = NULL;

        void initVars() {}
        void verifVars() {}
        void deleteVars() {}
        void overworld() {
            initVars();
            verifVars();

            boucle();
        }

        int boucle() {
            while(continuer) {
                while (continuer) {
                    if ((SDL_GetTicks() - ancientTick) >= FPS_TICKS) {

                        ancientTick = SDL_GetTicks();

                        SDL_PollEvent(&events);

                        switch (events.type) {
                            QUIT
                        case SDL_KEYDOWN:
                            switch (events.key.keysym.sym) {
                                ECHAP
                            }
                            break;

                        case SDL_JOYBUTTONDOWN:
                            if (!joypressed) {
                                joypressed = true;
                                switch (events.jbutton.button)
                                    JOYQUIT
                                }
                            }
                            break;

                            /*case SDL_WINDOWEVENT:
                                switch (events.window.event) {
                                    case SDL_WINDOWEVENT_RESIZED:
                                        break;
                                }
                                break;*/

                    } else {
                        SDL_Delay(FPS_TICKS - (SDL_GetTicks() - ancientTick));
                    }
                }
            }
        }
    }
}
