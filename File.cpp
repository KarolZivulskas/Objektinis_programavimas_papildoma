#include "File.hpp"

bool File::exists(const string& filePath) {
    ifstream file(filePath);
    return file.good();
}

stringstream File::getBuffer(const string& filePath) {
    ifstream file;
    file.open(filePath);

    if (!file) {
        throw std::runtime_error("Klaida: failas \"" + filePath + "\" negali buti atidarytas");
    }

    stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return buffer;
}

void File::saveBuffer(const string& filePath, stringstream& buffer) {
    std::ofstream file;
    file.open(filePath);

    if (!file) {
        throw std::runtime_error("Klaida: failas \"" + filePath + "\" negali buti atidarytas");
    }

    file << buffer.str();
    file.close();
}