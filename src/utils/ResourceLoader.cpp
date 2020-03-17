/*
  ResourceLoader.cpp
  Author : BAKFR
  File under GNU GPL v3.0 license
*/
#include "ResourceLoader.hpp"

#include <cstdio>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <algorithm>

namespace Utils {

    std::string ResourceLoader::resourcePath = "";

    std::string ResourceLoader::getResourcePath(){
        return resourcePath;
    }

    void ResourceLoader::setResourcePath(std::string path){
        resourcePath = path;
    }

    bool ResourceLoader::checkResourceFolderExists() {
        return !getResourcePath().empty();
    }

    void ResourceLoader::loadTextureArray(sf::Texture container[], const char *path, size_t nb_frame, size_t path_offset) {
        for(size_t i = 0; i < nb_frame; ++i) {
            char buffer[2048];

            container[i] = sf::Texture();
            snprintf(buffer, 2048, path, i + path_offset);
            ResourceLoader::load(container[i], buffer);
        }
    }

    void ResourceLoader::loadTextureArray(std::vector<sf::Texture> &container, const char *path, size_t nb_frame, size_t path_offset) {
        for(size_t i = 0; i < nb_frame; ++i) {
            char buffer[2048];

            container.emplace_back();
            snprintf(buffer, 2048, path, i + path_offset);
            ResourceLoader::load(container[i], buffer);
        }
    }

    std::unique_ptr<sf::Music> ResourceLoader::loadMusic(const char *path) {
        auto music = std::make_unique<sf::Music>();
        if(!music->openFromFile(ResourceLoader::getResourcePath() + path)) {
            throw LoadingException(path);
        }
        return music;
    }


} // namespace Utils
