/*!
 * \file OpMonData.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <unordered_map>
#include <vector>

#include "Species.hpp"
#include "src/opmon/core/GameData.hpp"

namespace OpMon {

    class OpMonData {
      private:
        /*!
         * \brief The sprites for each OpMon species.
         */
        std::vector<std::vector<sf::Texture>> opSprites;
        /*!
         * \brief The list OpMon species.
         */
        std::map<unsigned int, Species *> listOp;
        /*!
         * \brief The logos for each type.
         */
        std::unordered_map<Type, sf::Texture> typesTextures;

      public:
        OpMonData(GameData *gamedata);
        virtual ~OpMonData();

        /*!
         * \brief Gets a texture of an OpMon.
         * \param id The identifier of the Species of the OpMon.
         * \param face If `true`, returns the face texture, if `false`, the back texture.
         */
        sf::Texture &getOpSprite(unsigned int id, bool face) {
            return opSprites[id][(unsigned int)face];
        }
        /*!
         * \brief Gets a pointer to a Species object.
         */
        Species *getOp(unsigned int id) { return listOp.at(id); }
        /*!
         * \brief Gets the texture of a type.
         */
        sf::Texture &getTypeTexture(Type type) { return typesTextures[type]; }
    };

} /* namespace OpMon */
