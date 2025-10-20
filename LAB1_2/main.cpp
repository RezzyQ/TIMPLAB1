#include <iostream>  
#include <locale>  
#include <string>  
#include "module.h"  

int main() {  
    std::locale::global(std::locale(""));  
    std::wcout.imbue(std::locale());  
    std::wcin.imbue(std::locale());  

    int key;  
    std::wcout << L"кол-во столбцов: ";  
    std::wcin >> key;  
    std::wcin.ignore();  

    RouteCipher cipher(key);  

    while (true) {  
        std::wcout << L"\n1 Шифровать\n2 Дешифровать\n3 Выход\n";  
        int choice;  
        std::wcin >> choice;  
        std::wcin.ignore();  

        if (choice == 3) break;

        if (choice != 1 && choice != 2) continue;

        std::wstring text;
        std::wcout << L"Введите текст: ";
        std::getline(std::wcin, text);

        if (text.empty()) continue;

        if (choice == 1) {
            std::wstring encrypted = cipher.encrypt(text);
            std::wcout << L"Зашифровано: " << encrypted << std::endl;
        } else {
            std::wstring decrypted = cipher.decrypt(text);
            std::wcout << L"Расшифровано: " << decrypted << std::endl;
        }
    }
    return 0;
}
