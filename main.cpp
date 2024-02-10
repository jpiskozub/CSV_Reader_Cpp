#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>

//using namespace std;


void read_csv(std::string filename){

    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Nie udało się otworzyć pliku CSV." << std::endl;
    }
    else{
        std::cerr << "Plik CSV otwarty - odczytuje" << std::endl;
    }
    
    std::vector<std::string> row;
    std::string line, word, temp;
    //std::array<std::string,

    while (std::getline(file, line)) {

        std::stringstream ss(line);
        while (std::getline(ss, word,',')) {
            row.push_back(word);
        }
    }

    for (const auto& value : row) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    file.close();

}   

int main(int, char**){

    std::string filename="/home/kuba/Ubuntu_repos/CSV_Reader_Cpp/gestures.csv";
    //std::cin >> filename;

    read_csv(filename);

}
