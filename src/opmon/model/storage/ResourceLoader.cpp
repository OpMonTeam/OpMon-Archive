
#include "ResourceLoader.hpp"

namespace OpMon{
  namespace Model{

    void ResourceLoader::loadTextureArray(sf::Texture container[], const char *path, size_t nb_frame, size_t path_offset){
      for(size_t i = 0; i < nb_frame; ++i) {
        char buffer[2048];

        container[i] = sf::Texture();
        snprintf(buffer, 2048, path, i + path_offset);
        ResourceLoader::load(container[i], buffer);
      }
    }


    void ResourceLoader::loadTextureArray(std::vector<sf::Texture> &container, const char *path, size_t nb_frame, size_t path_offset){
      for(size_t i = 0; i < nb_frame; ++i) {
        char buffer[2048];

        container.emplace_back();
        snprintf(buffer, 2048, path, i + path_offset);
        ResourceLoader::load(container[i], buffer);
      }
    }

  }
}
