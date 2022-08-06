#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

#include "StrExtra.h"

using namespace nlohmann;

int main() {
    nlohmann::json entry;
    entry["Name"]           = "Habemus Papam";
    entry["ReleaseYear"]    = 2011;
    entry["Countries"]      = split_str("Italy, France");
    entry["Directors"]      = split_str("Nanni Moretti");
    entry["Studios"]        = split_str("Backup Films, Canal+ [fr], Coficup, Eurimages, Le Pacte, Rai Cinema, Sacher Film");
    entry["Screenwriters"]  = split_str("Nanni Moretti, Francesco Piccolo, Federica Pontremoli, Tom King");
    entry["Producers"]      = split_str("Jean Labadie, Nanni Moretti, Domenico Procacci");
    entry["Actors"]         = json({{"Michel Piccoli", "Papa"}, {"Jerzy Stuhr", "portavoce"}, {"Renato Scarpa", "Cardinal Gregori"}, {"Franco Graziosi", "Cardinal Bollati"}}); // actor name - role

    std::ofstream ofile("movie_record.json");
    if (ofile.is_open()) {
        ofile << entry.dump(1, '\t');
        ofile.close();
    } else {
        std::cout << "Could not create file 'movie_record.json'.";
        return 0;
    }

    std::ifstream ifile("movie_record.json");
    std::string buf;
    while (ifile >> buf) std::cout << buf << std::endl;
}
