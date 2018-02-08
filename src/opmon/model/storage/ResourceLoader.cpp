
#include "ResourceLoader.hpp"
#include "../../../utils/path.hpp"

namespace OpMon {
	namespace Model {

		const std::string &ResourceLoader::getResourcePath() {
			static const std::string &path = Utils::Path::getResourcePath();

			return path;
		}

		bool ResourceLoader::checkResourceFolderExists() {
			//getResourcePath() already check if the folder exists.
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

		sf::Music *ResourceLoader::loadMusic(const char *path) {
			auto *music = new sf::Music();
			if(!music->openFromFile(getResourcePath() + path)) {
				handleError(std::string("Failed to load music: ") + path, false);
			}
			return music;
		}

		std::ifstream ResourceLoader::loadKeysFile(const char *path) {
			std::ifstream file(getResourcePath() + path);
			if(!file) {
				handleError(std::string("Keys initialization error: ") + path, true);
			}
			return file;
		}

	} // namespace Model
} // namespace OpMon
