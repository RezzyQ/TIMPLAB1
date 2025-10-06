#include "modAlphaCipher.h"

modAlphaCipher::modAlphaCipher(const wstring &skey) {
    // Добавляем все символы включая пробел в алфавит
    for(unsigned i=0; i<numAlpha.size(); i++) {
        alphaNum[numAlpha[i]]=i;
    }
    key=convert(skey);
}

inline vector <int> modAlphaCipher::convert(const wstring &s) {
    vector <int> result;
    for(auto c:s) {
        result.push_back(alphaNum[c]); // ПРОБЕЛ ТЕПЕРЬ ИМЕЕТ СВОЙ ИНДЕКС
    }
    return result;
}

inline wstring modAlphaCipher::convert(const vector <int> &v) {
    wstring result;
    for(auto i:v) {
        result.push_back(numAlpha[i]); // АВТОМАТИЧЕСКИ ВОССТАНАВЛИВАЕТ ПРОБЕЛ
    }
    return result;
}

wstring modAlphaCipher::encrypt(const wstring &open_text) {
    vector <int> work=convert(open_text);
    for(unsigned i=0; i<work.size(); i++) {
        // ШИФРУЕМ ВСЕ СИМВОЛЫ ВКЛЮЧАЯ ПРОБЕЛ
        work[i]=(work[i]+key[i%key.size()])%alphaNum.size();
    }
    return convert(work);
}

wstring modAlphaCipher::decrypt(const wstring &cipher_text) {
    vector <int> work=convert(cipher_text);
    for(unsigned i=0; i<work.size(); i++) {
        // ДЕШИФРУЕМ ВСЕ СИМВОЛЫ ВКЛЮЧАЯ ПРОБЕЛ
        work[i]=(work[i]+alphaNum.size()-key[i%key.size()])%alphaNum.size();
    }
    return convert(work);
}
