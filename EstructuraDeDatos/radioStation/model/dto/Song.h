//
// Created by josue on 8/29/2021.
//

#ifndef RADIOSTATION_SONG_H
#define RADIOSTATION_SONG_H

#include <iostream>

class Song {
private:
    std::string name;
    std::string title;
    std::string interprete;
public:
    Song();

    Song(const std::string &name, const std::string &title, const std::string &interprete);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    const std::string &getInterprete() const;

    void setInterprete(const std::string &interprete);

    std::string toString();
};


#endif //RADIOSTATION_SONG_H
