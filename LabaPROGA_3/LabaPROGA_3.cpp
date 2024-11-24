#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool isValidForHeader(const string& header) {
    regex forRegex(R"(^for\s*\(\s*[^;]*;\s*[^;]*;\s*[^;]*\s*\)\s*$)");


    if (!regex_match(header, forRegex)) {
        return false;
    }

    size_t openParen = header.find('(');
    size_t closeParen = header.find(')');
    if (openParen == string::npos || closeParen == string::npos) {
        return false;
    }

    string body = header.substr(openParen + 1, closeParen - openParen - 1);
    size_t firstSemicolon = body.find(';');
    size_t secondSemicolon = body.find(';', firstSemicolon + 1);

    if (firstSemicolon == string::npos || secondSemicolon == string::npos) {
        return false; 
    }

    string init = body.substr(0, firstSemicolon);
    string condition = body.substr(firstSemicolon + 1, secondSemicolon - firstSemicolon - 1);
    string update = body.substr(secondSemicolon + 1);

    // Дополнительные проверки (по желанию, можно усложнить)
    if (init.empty() || condition.empty() || update.empty()) {
        return false; 
    }

    return true;
}

int main() {
    string header;

    setlocale(LC_ALL, "ru");

    cout << "Введите заголовок цикла for: ";
    getline(cin, header);

    if (isValidForHeader(header)) {
        cout << "Заголовок цикла for корректен." << endl;
    }
    else {
        cout << "Заголовок цикла for некорректен." << endl;
    }

    return 0;
}