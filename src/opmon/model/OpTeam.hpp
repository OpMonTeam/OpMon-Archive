/*!
 * \file OpTeam.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */
#ifndef SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_
#define SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_

#include <string>
#include <vector>

#include "OpMon.hpp"

namespace OpMon {

    class OpMon;

    /*!
     * \brief Defines an OpMon team, used by the player and trainers.
     */
    class OpTeam {
      public:
        ~OpTeam();
        OpTeam(std::string const &name);
        std::string getName() const { return name; }
        std::vector<OpMon *> getOpTeam() { return opteam; }
        /*!
         * \brief Heals all the OpMon.
         */
        void heal();
        /*!
         * \brief Adds an OpMon to the team.
         * \returns `false` if the team is full and the OpMon is not added.
         * \param toAdd A pointer to the OpMon to add. The OpMon will be deleted at the destruction of the OpTeam.
         */
        bool addOpMon(OpMon *toAdd);
        /*!
         * \brief Removes an OpMon from the team without deleting the object.
         * \returns A pointer to the removed OpMon.
         * \param number The index of the OpMon in the team.
         */
        OpMon *removeOp(int number);
        /*!
         * \brief Returns the OpMon at the specified index.
         */
        OpMon *operator[](int id) const;

        /*!
         * \copydoc operator[]
         * \details Equivalent to OpTeam::operator[]
         */
        OpMon *getOp(int id) const { return (*this)[id]; }
        /**
         * \brief Returns `true` if all the OpMon on the team are K.O.
         */
        bool isKo() const;
        int getSize() const;
        void save();

      private:
        /*!
         * \brief The array containing the team.
         */
        std::vector<OpMon *> opteam;
        /*!
         * \brief The name of the team.
         */
        std::string name;
        OpTeam(OpTeam const &) = delete;
    };

} // namespace OpMon

#endif /* SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_ */
