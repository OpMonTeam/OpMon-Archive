#include "exceptions.hpp"

namespace Utils {
    Exception::Exception(bool fatal, int returnId)
        : fatal(fatal), returnId(returnId) {}

    LoadingException::LoadingException(std::string path, bool fatal)
        : Exception(fatal, 2), path(path) {}

    const std::string LoadingException::desc() const noexcept {
        return "LoadingException: can't load " + path;
    }

    NullptrException::NullptrException(std::string info, bool fatal)
        : Exception(fatal, 3), info(info) {}

    const std::string NullptrException::desc() const noexcept {
        return "NullptrException : " + info;
    }

    UnexpectedValueException::UnexpectedValueException(std::string value,
                                                       std::string expected,
                                                       bool fatal)
        : Exception(fatal, 4), value(value), expected(expected) {}

    const std::string UnexpectedValueException::desc() const noexcept {
        return "UnexpectedValueException : unexpected value \"" + value +
               "\" but expected " + expected;
    }

    UnloadedResourceException::UnloadedResourceException(std::string resource,
                                                         std::string location,
                                                         bool fatal)
        : Exception(fatal, 5), resource(resource), location(location) {}

    const std::string UnloadedResourceException::desc() const noexcept {
        return "UnloadedResourceException : Resource \"" + resource +
               "\" has never been loaded in " + location;
    }
} // namespace Utils
