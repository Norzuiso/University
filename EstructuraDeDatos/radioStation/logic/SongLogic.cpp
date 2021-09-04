//
// Created by josue on 8/29/2021.
//

#include "SongLogic.h"

void SongLogic::showSong(Song song) {
    MenuLogic::print(song.toString());
}

Song SongLogic::createNewSong() {
    const string &title = Utils::getStringValue("Cancion: ");
    const string &name = Utils::getStringValue("Autor:");
    const string &interprete = Utils::getStringValue("Interprete:");
    const Song &song = Song(name, title, interprete);
    return song;
}
