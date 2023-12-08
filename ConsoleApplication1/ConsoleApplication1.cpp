#include "Header.h"
#include <algorithm>

int main() {

    setlocale(LC_ALL, "Rus");

    Track tr = Track("DS", "Rock", 202);
    Track etr = ExtendedTrack("EDS", "KPOP", 300, 9);
    Track tr1 = Track("Mill", "Bambam", 20);
    Track etr1 = ExtendedTrack("Akka", "Wow", 303, 9);

    std::vector<Track> tracks = { tr,etr, tr1,etr1 };

    std::cout << "Сортировка треков по названию:\n";
    sort(tracks.begin(), tracks.end(), [](const Track& a, const Track& b) {
        return a.getName() < b.getName();
        });

    for (const auto& tr : tracks) {
        tr.printToConsole();
    }
    std::cout << "\nСортировка треков по продолжительности:\n";
    sort(tracks.begin(), tracks.end(), [](const Track& a, const Track& b) {
        return a.getDuration() < b.getDuration();
        });
    for (const auto& tr : tracks) {
        tr.printToConsole();
    }

    std::cout << "\n Поиск треков по жанру Rock:\n";
    std::string genreToSearch = "Rock";

    // Используем std::copy_if для копирования найденных треков в новый вектор
    std::vector<Track> foundTracks;
    copy_if(tracks.begin(), tracks.end(), std::back_inserter(foundTracks), [genreToSearch](const Track& track) {
        return track.getGenre() == genreToSearch;
        });

    for (const auto& foundTrack : foundTracks) {
        std::cout << foundTrack << "\n";
    }
}