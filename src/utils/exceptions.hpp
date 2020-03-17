/*!
 * \file exceptions.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <exception>
#include <string>

namespace Utils {

    /*!
     * \brief Base class for exceptions containing some data.
     *
     * This class inherits from the standard std::exception class, but also takes some data useful to treat the exception. It also defines a function to return the error in std::string format, and makes what() return desc().c_str().
     */
    class Exception : public std::exception {
    public:
        /*!
         * \brief Returns a description of the exception.
         */
        virtual const std::string desc() const noexcept = 0;
        /*!
         * \brief Returns desc().c_str().
         */
        const char* what() const noexcept {return desc().c_str();}
        Exception(bool fatal, int returnId);
        /*!
         * \brief If the exception is fatal or not.
         *
         * This variable should be set to `true` if the problem prevents the program from executing normally.
         */
        const bool fatal;
        /*!
         * \brief The value returned by the program when closed by this exception.
         *
         * This variable should be set for every inherited class.
         */
        const int returnId;
    };

    /*!
     * \brief Exception representing a loading error.
     *
     * Return code: 2
     */
    class LoadingException : public Exception {
    public:
        const std::string desc() const noexcept;
        LoadingException(std::string path, bool fatal = false);
        /*!
         * \brief The path of the file the program failed to load.
         */
        const std::string path;
    };

    /*!
     * \brief Exception thrown when a pointer unexpectedly have the value `nullptr`.
     *
     * Return code: 3
     */
    class NullptrException : public Exception {
    public:
        const std::string desc() const noexcept;
        NullptrException(std::string info, bool fatal = true);
        /*!
         * \brief Some information about the error.
         */
        const std::string info;
    };

    /*!
     * \brief Exception thrown when a variable have an unexpected value that can't be handled.
     *
     * Return code: 4
     */
    class UnexpectedValueException : public Exception {
    public:
        const std::string desc() const noexcept;
        UnexpectedValueException(std::string value, std::string expected, bool fatal = true);
        /*!
         * \brief The unexpected value that caused the error.
         */
        const std::string value;
        /*!
         * \brief The description of the expected values.
         */
        const std::string expected;
    };
}
