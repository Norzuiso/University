//
// Created by josue on 8/29/2021.
//

#include "Song.h"

const std::string &Song::getName() const {
    return name;
}

void Song::setName(const std::string &name) {
    Song::name = name;
}

const std::string &Song::getTitle() const {
    return title;
}

void Song::setTitle(const std::string &title) {
    Song::title = title;
}

const std::string &Song::getInterprete() const {
    return interprete;
}

void Song::setInterprete(const std::string &interprete) {
    Song::interprete = interprete;
}

Song::Song(const std::string &name, const std::string &title, const std::string &interprete) : name(name), title(title),
                                                                                               interprete(interprete) {}

Song::Song() {
}

std::string Song::toString() {
    return "name: " + name + "\n"
           + "title: " + title + "\n"
           + "interprete: " + interprete +
           "\n";
}