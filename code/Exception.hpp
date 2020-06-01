#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>

class BadRequest : public std::exception {
    public:
    const char* what() const noexcept;
};

class NotFound : public std::exception {
    public:
    const char* what() const noexcept;
};

class PermissionDenied : public std::exception {
    public:
    const char* what() const noexcept;
};

class EmptyList : public std::exception {
    public:
    const char* what() const noexcept;
};

class NotEnoughCredit : public std::exception {
    public:
    const char* what() const noexcept;
};

class NotEnoughRoom : public std::exception {
    public:
    const char* what() const noexcept;
};

class NoRating : public std::exception {
    public:
    const char* what() const noexcept;
};

#endif
