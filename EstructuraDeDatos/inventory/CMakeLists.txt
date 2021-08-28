cmake_minimum_required(VERSION 3.19)
project(inventory)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "builder")

add_executable(inventory main.cpp
        model/dto/Date.cpp
        model/dto/Menu.cpp
        model/dto/Product.cpp

        model/include/Date.h
        model/include/Menu.h
        model/include/Product.h

        logic/InventoryLogic.cpp
        logic/InventoryLogic.h
        logic/MenuLogic.cpp
        logic/MenuLogic.h
        logic/ProductLogic.cpp
        logic/ProductLogic.h

        logic/utils/Utils.cpp
        logic/utils/Utils.h
        )