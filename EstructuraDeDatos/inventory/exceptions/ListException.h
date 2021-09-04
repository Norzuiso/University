//
// Created by josue on 8/29/2021.
//

#ifndef RADIOSTATION_LISTEXCEPTION_H
#define RADIOSTATION_LISTEXCEPTION_H


#include <exception>
#include <string>

class ListException : public std::exception {
private:
    std::string msg;
public:
    explicit ListException(const char *message) : msg(message) {}

    explicit ListException(const std::string message) : msg(message) {}

    virtual ~ListException() throw() {}

    virtual const char *what() const throw() {
        return msg.c_str();
    }
};


#endif //RADIOSTATION_LISTEXCEPTION_H
