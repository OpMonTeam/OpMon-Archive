/*!
 * \file Move.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \authors Navet56
 * \copyright GNU GPL v3.0
 */
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_

#include <filesystem>
#include <queue>

#include "Turn.hpp"
#include "src/opmon/core/Elements.hpp"
#include "src/utils/i18n/ATranslatable.hpp"

namespace OpMon {

    class OpMon;
    class Move;

    /*!
     * \brief This class is virtual and one has to be created for each move effect.
     */
    class MoveEffect {
      public:
        /*!
          \brief Applies the effect.
        */
        virtual int apply(Move & /*move*/, OpMon & /*attacker*/,
                          OpMon & /*defender*/,
                          std::queue<TurnAction> & /* turnQueue */) {
            return 0;
        }
        virtual ~MoveEffect() {}
    };

    /*!
     * \struct MoveData
     * \brief Contains all the necessary data to create an Move.
     * \details This structure is used in the class Move to link all the variables needed to the constructor in one variable. It represents the move in an abstract way, while Move represents an move owned by an OpMon.
     */
    struct MoveData {
        std::string
            nameKey; /*!< \brief The key (see Utils::StringKeys) used to get the move name in the right language.*/
        int power;   /*!< \brief  The power of the move.*/
        Type type;   /*!< \brief  The type of the move.*/
        int accuracy; /*!< \brief  The accuracy of the move*/
        bool
            special; /*!< \brief  If `true`, the move is a special move (uses the special stats). Else, the move is a physical move (uses the basic stats).*/
        bool
            status; /*!< \brief  If `true`, the move does not harm directly the opposite OpMon.*/
        int criticalRate; /*!< \brief  The critical rate of the move. It represents the denominator (one chance out of the value of the variable)*/
        bool neverFails;  /*!< \brief  If `true`, the move can't fail.*/
        int ppMax; /*!< \brief The maximum base PP (Power points) of the move.*/
        int priority; /*!< \brief The level of priority of the move.*/
        MoveEffect *preEffect =
            nullptr; /*!< \brief The move effect applied before the calculation of the damages.*/
        MoveEffect *postEffect =
            nullptr; /*!< \brief The move effect applied after the calculation of the damages.*/
        MoveEffect *ifFails =
            nullptr; /*!< \brief The move effect applied if the move fails.*/
        std::vector<TurnActionType>
            animationOrder; /*!< \brief The order in which the animations will occur.*/
        std::queue<Ui::Transformation>
            opAnimsAtk; /*!< \brief The animations linked to the attacking OpMon's sprite.*/
        std::queue<Ui::Transformation>
            opAnimsDef; /*!< \brief The animations linked to the attacked OpMon's sprite.*/
        std::queue<std::string>
            animations; /*!< \brief The animations played on the whole screen.*/
    };

    typedef struct MoveData MoveData;

    /*!
     * \class Move
     * \brief Describes an move.
     * \details This class describes an move owned by an OpMon, and not just an move in general (MoveData is used for this, the moves are stored in Move::moveList).
     * \todo Change the name to "move" to stick better with the original game.
     */
    class Move : public Utils::I18n::ATranslatable {
      public:
        virtual ~Move();
        /*!
         * \brief Creates an move with all the needed data.
         * \note To see the details of the parameters, see MoveData.
         */
        Move(std::string nameKey, int power, Type type, int accuracy,
             bool special, bool status, int criticalRate, bool neverFails,
             int ppMax, int priority,
             std::vector<TurnActionType> animationOrder,
             std::queue<Ui::Transformation> opAnimsAtk,
             std::queue<Ui::Transformation> opAnimsDef,
             std::queue<std::string> animations,
             MoveEffect *preEffect = nullptr, MoveEffect *postEffect = nullptr,
             MoveEffect *fails = nullptr);

        /*!
         * \brief Creates and move with all the data stored in the MoveData structure.
         */
        Move(MoveData const &data);

        /*!
         * \brief Returns a pointer to a new Move object created by using the parameter to access an MoveData object stored in Move::moveList.
         * \param name Key used to identify the wanted move in Move::moveList.
         */
        static Move *newMove(std::string name);
        /*!
         * \brief Initialises the moves and stores them in Move::moveList.
         * \param file The file containing the data to load (Json format).
         */
        static void initMoves(std::filesystem::directory_iterator dir);

        /*!
         * \brief Resets the current PP number to the maximum.
         */
        void healPP() { pp = ppMax; }

        Type getType() { return type; }

        int getPP() { return pp; }

        int getPPMax() { return ppMax; }

        /*!
         * \brief Causes a OpMon to move another one.
         * \param atk A reference to the OpMon using the move.
         * \param def A reference to the opposite OpMon.
         * \param turnQueue A reference to the action queue of the turn.
         * \param attacker If `true`, the OpMon attacking is the player's one (The one on the front of the screen.). Used to determine which health bar update.
         */
        int move(OpMon &atk, OpMon &def, std::queue<TurnAction> &turnQueue,
                 bool attacker);

        void setPP(int PP) { this->pp = PP; }

        void setPPMax(int PPMax) { this->ppMax = PPMax; }

        int getPriority() { return this->priority; }

        sf::String getName() { return name; }

        std::queue<Ui::Transformation> getOpAnimsAtk() const {
            return opAnimsAtk;
        }

        std::queue<Ui::Transformation> getOpAnimsDef() const {
            return opAnimsDef;
        }

        std::queue<std::string> getAnimations() const { return animations; }

        // methods used by pre and post Effects

        void setPower(int power) { this->power = power; }
        int getAccuracy() { return this->accuracy; }
        void setAccuracy(int accuracy) { this->accuracy = accuracy; }
        int getPart() { return part; }
        void setPart(int part) { this->part = part; }
        int getHpLost() { return this->hpLost; }

        void onLangChanged();

      protected:
        Utils::OpString
            nameKey; /*!<\brief The key (see Utils::StringKeys) used to get the move name in the right language.*/
        sf::String name; /*!<\brief The move name in the current language.*/
        int power;       /*!< \brief The power of the move.*/
        Type type;       /*!< \brief The type of the move.*/
        int accuracy;    /*!< \brief The accuracy of the move*/
        bool
            special; /*!< \brief If `true`, the move is a special move (uses the special stats). Else, the move is a physical move (uses the basic stats).*/
        bool
            status; /*!< \brief If `true`, the move does not harm directly the opposite OpMon.*/
        int criticalRate; /*!< \brief The critical rate of the move. It represents the denominator (one chance out of the value of the variable)*/
        bool neverFails;  /*!< \brief If `true`, the move can't fail.*/
        int pp;           /*!<\brief The current pp of the move.*/
        int ppMax; /*!< \brief The maximum base PP (Power points) of the move.*/
        int priority; /*!< \brief The level of priority of the move.*/
        MoveEffect *
            preEffect; /*!< \brief The move effect applied before the calculation of the damages.*/
        MoveEffect *
            postEffect; /*!< \brief The move effect applied after the calculation of the damages.*/
        MoveEffect *
            failEffect; /*!< \brief The move effect applied if the move fails.*/
        std::vector<TurnActionType>
            animationOrder; /*!< \brief The order in which the animations will occur.*/
        std::queue<Ui::Transformation>
            opAnimsAtk; /*!< \brief The animations linked to the attacking OpMon's sprite.*/
        std::queue<Ui::Transformation>
            opAnimsDef; /*!< \brief The animations linked to the attacked OpMon's sprite.*/
        std::queue<std::string>
            animations; /*!< \brief The animations played on the whole screen.*/

        /*!
         * \brief The number of HP lost by the opposite OpMon.
         */
        int hpLost = 0;
        /*!
         * \brief Used for moves in multiple turns.
         */
        int part = 0;

        /*!
         * \brief Map containing the data of all the available moves in the game.
         */
        static std::map<std::string, MoveData> moveList;

        /*!
         * \brief Generates the other version of the OpMon animations.
         * \details The OpMon animations are created to be used with the player's OpMon. This method generates opposite OpMon versions by creating a symmetry from the origin.
         */
        std::queue<Ui::Transformation> generateDefAnims(
            std::queue<Ui::Transformation> opAnims);
    };

} // namespace OpMon
#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_ */
