cmake_minimum_required(VERSION 3.19)
project(Actividad04_PilaYCola)

set(CMAKE_CXX_STANDARD 14)

add_executable(Actividad04_PilaYCola
        logic/utils/Execeptions/Exception.h

        Logic/utils/Utils.cpp
        Logic/utils/Utils.h

        Logic/MenuLogic.cpp
        Logic/MenuLogic.h

        model/dto/Cola.h
        model/dto/Menu.h
        model/dto/Menu.cpp
        model/dto/Pila.h

        main.cpp)