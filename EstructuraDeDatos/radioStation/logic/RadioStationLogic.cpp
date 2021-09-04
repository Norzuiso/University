//
// Created by josue on 8/29/2021.
//

#include "RadioStationLogic.h"

RadioStationLogic::RadioStationLogic() {}

void RadioStationLogic::init() {
    songLogic = SongLogic();
}

void RadioStationLogic::startProject() {
    init();
    int option;
    do {
        MenuLogic::showWelcomeMenssage(WELCOME_MESSAGE);
        option = MenuLogic::showMenu({
                                             NEW_SONG,
                                             SEE_SONGS,
                                             CLOSE});
        optionHub(option);

    } while (option != 2);
}

void RadioStationLogic::optionHub(int option) {
    switch (option) {
        case 0:
            newSong();
            break;
        case 1:
            seeSongs();
            break;
        case 2:
            closeProgram();
            break;
        default:
            Utils::throwErrorMsg("Opcion erronea, intentalo de nuevo");
            break;
    }
}

void RadioStationLogic::closeProgram() {
    MenuLogic::print("Gracias por usar :D");
}

void RadioStationLogic::newSong() {
    MenuLogic::print(LINE);
    MenuLogic::print(NEW_SONG);
    MenuLogic::print(LINE);

    const Song &song = songLogic.createNewSong();
    songList.insertData(song);
    MenuLogic::print(LINE);
}

void RadioStationLogic::seeSongs() {
    MenuLogic::print(LINE);
    MenuLogic::print(SEE_SONGS);
    MenuLogic::print(LINE);

    int i(0);
    while (i < songList.getLast()) {
        const Song &song = songList.getValueFromPosition(i);
        songLogic.showSong(song);
        i++;
        MenuLogic::print(LINE);
    }

}
