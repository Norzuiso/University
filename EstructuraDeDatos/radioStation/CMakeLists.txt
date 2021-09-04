cmake_minimum_required(VERSION 3.19)
project(radioStation)

set(CMAKE_CXX_STANDARD 14)

file(GLOB ImageFeatureDetector_SRC *.h *.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "builder")

add_executable(radioStation

        model/dto/List.h
        model/dto/Song.cpp
        model/dto/Song.h

        exceptions/ListException.h

        model/dto/Menu.cpp
        model/dto/Menu.h

        logic/utils/Utils.cpp
        logic/utils/Utils.h

        logic/MenuLogic.cpp
        logic/MenuLogic.h

        logic/RadioStationLogic.cpp
        logic/RadioStationLogic.h

        logic/SongLogic.cpp
        logic/SongLogic.h

        main.cpp
        )