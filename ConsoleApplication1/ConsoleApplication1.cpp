#include "Header.h"

int main() {

    setlocale(LC_ALL, "Rus");

    Track track1("Track 1", "Genre 1", 180);
    Track track2("Track 2", "Genre 2", 240);
    Track track3("Track 3", "Genre 3", 300);

    /*использование "this" в некоторых сеттерах класса трек*/
    /*Дружественная функция - printTrackDetails выводит информацию о треке */
    std::cout << "Демонстрация использования this. Set-метод не добавил пустую строку в название трека:" << std::endl;
    track1.setName("");
    printTrackDetails(track1);

    std::cout << "\nSet-метод добавил не пустую строку в название трека:" << std::endl;
    track1.setName("SongName");
    printTrackDetails(track1);
    std::cout << "Информация о треке выведена дружественной функцией" << std::endl;

    std::cout <<"\nИспользование статистического метода для получения количества созданных треков(является статистическим полем) "<< Track::getTrackCount() << std::endl;

    Track track4 = track1 + track2;
    std::cout << "\nДемонстрация работы перегрузки +" << std::endl << "Первый трек:" << std::endl;
    track1.printToConsole();
    std::cout << "\nВторой трек" << std::endl;
    track2.printToConsole();

    std::cout << "\ntrack1+track2:" << std::endl;

    printTrackDetails(track4);

    std::cout << "\nДемонстрация работы перегрузки постфиксного инкремента" << std::endl << "трек:" << std::endl;
    track2.printToConsole();

    std::cout << "\nПосле выполнения" << std::endl;

    printTrackDetails(track2++);

    std::cout << "\nДемонстрация работы перегрузки префиксного инкремента" << std::endl << "трек:" << std::endl;
    track2.printToConsole();

    track4 = ++track2;
    std::cout << "Трек, который вернулся после выполнения ++track" << std::endl;

    printTrackDetails(track4);
    std::cout << "\nСамо значение track" << std::endl;
    printTrackDetails(track2);

    
    std::vector<Track> tracks = { track1,track2,track3};

    //Указатель
    std::vector<Track>* tracksByGenrePointer = Track::findTracksByGenrePointer(tracks, "Genre 2");
    std::cout << "\nВозврат значения из статистического метода через указатель(массив треков определённого жанра)" << std::endl;
    for (const auto& track : *tracksByGenrePointer) {
        track.printToConsole();
    }

    // Ссылка
    std::cout << "\nВозврат значения из статистического метода по ссылке(массив треков определённого жанра)" << std::endl;
    std::vector<Track> tracksByGenreReference;
    Track::findTracksByGenreReference(tracks, "Genre 1", tracksByGenreReference);
    for (const auto& track : tracksByGenreReference) {
        track.printToConsole();
    }

    delete tracksByGenrePointer;


    return 0;
}