//
// Created by josue on 8/29/2021.
//

#ifndef RADIOSTATION_RADIOSTATIONLOGIC_H
#define RADIOSTATION_RADIOSTATIONLOGIC_H

#include "MenuLogic.h"
#include "SongLogic.h"
#include "../model/dto/Song.h"
#include "../model/dto/List.h"

static const char *const WELCOME_MESSAGE = " ------------------------------------------------------------------------------  \n"
                                           " |         Estacion de Radio La Mejor De Todas Porque yo digo                 |  \n"
                                           " |                                   Por                                      |  \n"
                                           " |                       Josue Norberto Aguilar Islas                         |  \n"
                                           " |              Centro Universitario de Ciencias Exactas e Ingenierias        |  \n"
                                           " ------------------------------------------------------------------------------  \n";

static const char *const LINE = "------------------------------------------------------------------------------\n";

static const char *const CLOSE = "Salir \n";

static const char *const NEW_SONG = "Nueva cancion\n";

static const char *const SEE_SONGS = "Ver canciones\n";


static const int size = 25;

class RadioStationLogic {
private:
    List<Song> songList = List<Song>(size);
    SongLogic songLogic;
public:
    RadioStationLogic();

    void startProject();

    void optionHub(int option);

    void closeProgram();

    void newSong();

    void seeSongs();

    void init();
};


#endif //RADIOSTATION_RADIOSTATIONLOGIC_H
