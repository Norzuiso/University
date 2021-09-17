//
// Created by josue on 9/5/2021.
//

#ifndef ACTIVIDAD04_PILAYCOLA_PILAEXCEPTION_H
#define ACTIVIDAD04_PILAYCOLA_PILAEXCEPTION_H

#include <exception>
#include <string>

class Exception : public std::exception {
private:
    std::string msg;
public:
    explicit Exception(const char *message) : msg(message) {}

    explicit Exception(const std::string &message) : msg(message) {}

    virtual ~Exception() throw() {}

    virtual const char *what() const throw() {
        return msg.c_str();
    }
};


#endif //ACTIVIDAD04_PILAYCOLA_PILAEXCEPTION_H
