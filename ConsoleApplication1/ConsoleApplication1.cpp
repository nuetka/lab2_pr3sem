#include "Header.h"

int main() {

    setlocale(LC_ALL, "Rus");

    ExtendedTrack ext_track = ExtendedTrack();
    ext_track.readFromConsole();
    std::cout << "Произвольный класс ExtendedTrack(protected):\n";
    ext_track.printProtectedFields();
    std::cout << "\nПерегрузка метода базового класса с вызовом метода базовоо класса:\n";
    ext_track.printToConsole(false);//перегрузку метода базового класса в производном классе с вызовом метода базового класса,
    std::cout << "\nПосле вызова конструктора базового класса в конструкторе производного класса с параметрами\n";
    ExtendedTrack ext_track1 = ExtendedTrack("Song1", "Pop", 380,9);
    ext_track1.printToConsole(false);
    std::cout << "\nПрисваивание объекта базового класса объекту производного класса\nВывод с помощью операции <<\nОбъект базового класса:\n";
    Track baseTrack("BaseSong", "Pop", 200);
    std::cout << baseTrack;
    ExtendedTrack extendedTrack;
   // Присваивание объекта базового класса объекту производного класса
    extendedTrack = baseTrack;
    extendedTrack.setRating(4);
    std::cout << "\nОбъект производного класса:\n";
    std::cout << extendedTrack;
    std::cout << "\n Вызываем виртуальную функцию через не виртуальную функцию базового класса\n";
   
    Track::printTrack(baseTrack);          

    // Создаем объекты динамически
    Track* baseTrackPtr = new Track("DS", "Rock", 202);
    Track* extendedTrackPtr = new ExtendedTrack("EDS", "KPOP", 300,9);

    std::cout << "\nВызываем виртуальную функцию через указатели на динамические объекты базового и производного классов:\n";
    baseTrackPtr->printDetails();      
    extendedTrackPtr->printDetails();  

    std::cout << "\nИзменение работы программы если функция не виртуальная/вывод только из базового класаа\n";
    baseTrackPtr->printDetailsNV();
    extendedTrackPtr->printDetailsNV();

    // Освобождаем выделенную память
    delete baseTrackPtr;
    delete extendedTrackPtr;

    Movie movie = Movie("Title");

    std::cout << "\nИспользование абстрактного класса\n";
    std::cout << baseTrack.getMediaType()<<"   " << movie.getMediaType();

    std::cout << "\nСинглтон\n";
    // Получаем экземпляр синглтона
    Library& myLibrary = Library::getInstance();
  
    Album album1("Альбом 1");
    Album album2("Альбом 2");

    Playlist playlist1("Плейлист 1");
    Playlist playlist2("Плейлист 2");

    // Добавляем альбомы в вектор
    std::vector<Album> albums = { album1, album2 };

    // Добавляем плейлисты в вектор
    std::vector<Playlist> playlists = { playlist1, playlist2 };

    // Устанавливаем альбомы и плейлисты в библиотеку
    myLibrary.setAlbums(albums);
    myLibrary.setPlaylists(playlists);

    myLibrary.printToConsole();
    return 0;
}