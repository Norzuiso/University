//
// Created by josue on 8/29/2021.
//

#ifndef RADIOSTATION_SONGLOGIC_H
#define RADIOSTATION_SONGLOGIC_H


#include "../model/dto/Song.h"
#include "MenuLogic.h"
#include "utils/Utils.h"

class SongLogic {

public:
    Song createNewSong();

    void showSong(Song song);
};


#endif //RADIOSTATION_SONGLOGIC_H
