#include "Header.h"

int main() {

    setlocale(LC_ALL, "Rus");

    std::cout << "Обработка исключения при инициализации объекта:\n";

    Track track1 = Track("Song1", "Pop", -3); 

    std::cout << "После ввода отрицательной продолжительности она устанавливается в 0:\n";

    track1.printToConsole();

    std::cout << "Обработка исключения при использовании сеттера:\n";
    Album album;

   
    album.setYear(-2022);
   

    Track trackArray[2];
    Playlist playlistArray[2][2];

    std::cout << "\nодномерный массив треков:\n";
    for (int i = 0; i < 2; ++i) {
        trackArray[i].readFromConsole();
    }

    std::cout << "\nСозданный одномерный массив треков:\n";
    for (auto& track : trackArray) {
        track.printToConsole();
    }

    std::cout << "\nдвумерный массив плейлистов\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            playlistArray[i][j].readFromConsole();
        }
    }

    std::cout << "\nСозданный двумерный массив плейлистов:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            playlistArray[i][j].printToConsole();
        }
    }

    return 0;
}