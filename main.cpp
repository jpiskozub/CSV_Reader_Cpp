#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>

//using namespace std;

const int MAX_COLS = 15;
const int MAX_ROWS = 500000;


void read_csv(std::string filename){

    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Nie udało się otworzyć pliku CSV." << std::endl;
    }
    else{
        std::cout << "Plik CSV otwarty - odczytuje" << std::endl;
    }
    
    std::vector<std::array<std::string, MAX_COLS>> matrix(MAX_ROWS);
    std::string line, word;
    //std::array<std::string,
    int row = 0;

    while (std::getline(file, line)) {

        std::stringstream ss(line);
        std::array<std::string, MAX_COLS> rowData;

         std::string token;
        int col = 0;

        while (std::getline(ss, token, ',') && col < MAX_COLS) {
            rowData[col++] = token;
        }

        matrix[row++] = rowData;
    }
    
    for (const auto& row : matrix) {

        for (const auto& value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    file.close();
    
}   

int main(int, char**){

    std::string filename="/home/kuba/Ubuntu_repos/CSV_Reader_Cpp/gestures.csv";
    //std::cin >> filename;

    read_csv(filename);

}
