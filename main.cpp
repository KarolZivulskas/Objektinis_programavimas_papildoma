#include <sys/stat.h>

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "File.hpp"
#include "Print.hpp"
#include "String.hpp"
#include "Data.hpp"

#define SOURCE_FILE "Text.txt"

using namespace std;

void addWordToCollection(const string& word, map<string, WordData>& collection, int lineIndex) {
    if (word.empty()) {
        return;
    }

    auto itterator = collection.find(word);

    if (itterator == collection.end()) {
        collection.insert({ word, WordData(lineIndex) });
    }
    else {
        if (lineIndex != itterator->second.lineIndices.back()) {
            itterator->second.lineIndices.push_back(lineIndex);
        }

        itterator->second.count++;
    }
}

string promptForFilePath() {
    string filePath;
    cout << "Iveskite failo kelia (numatytasis " << SOURCE_FILE << "): ";
    getline(cin, filePath);

    return filePath.empty() ? SOURCE_FILE : filePath;
}

int main() {
    string filePath = promptForFilePath();
    if (!File::exists(filePath)) {
        cout << "Failas " << filePath << " neegzistuoja, nutraukiama" << endl;
        return 1;
    }

    int lineIndex = 0;
    string line;
    vector<string> urls;
    map<string, WordData> collection;

    stringstream buffer = File::getBuffer(filePath);

    while (getline(buffer, line)) {
        string word;
        istringstream iss(line);

        while (iss >> word) {
            if (String::isURL(word)) {
                urls.push_back(word);
            }
            else {
                word = String::removeNonWordCharacters(word);
                addWordToCollection(String::toLowerCase(word), collection, lineIndex);
            }
        }

        lineIndex++;
    }

    Print::crossReference(collection, lineIndex, "cross_reference.txt");
    Print::urls(urls, "urls.txt");
    Print::wordCound(collection, "word_count.txt");

    return 0;
}