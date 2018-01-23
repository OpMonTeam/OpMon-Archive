
#include <sys/types.h>
#include <sys/stat.h>
#include "ResourceLoader.hpp"


namespace OpMon{
  namespace Model{

    bool ResourceLoader::checkResourceFolderExists(){
      struct stat info;

      if(stat(RESSOURCES_PATH.c_str(), &info) != 0){
        return false; // Can't access to folder
      }
      if(!(info.st_mode & S_IFDIR)){
        return false; // Is not a folder
      }
      return true;
    }

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
