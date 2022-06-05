#include "String.hpp"

#define NON_WORD_PATTERN "[-.%,?!/;:\"'()\\]\\[*0-9]"
#define URL_PATTERN "(((http|https)://)?www\\.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)"

bool String::isURL(const string& word) {
    return (regex_match(word, regex(URL_PATTERN)));
}

string String::removeNonWordCharacters(const string& word) {
    return regex_replace(word, regex(NON_WORD_PATTERN), "");
}

string String::toLowerCase(string& word) {
    for_each(word.begin(), word.end(), [](char& c) {
        c = ::tolower(c);
        });

    return word;
}
