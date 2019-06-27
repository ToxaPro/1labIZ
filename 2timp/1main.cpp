#include <iostream>
#include <cctype>
#include <codecvt>
#include <locale>
#include "modAlphaCipher.h"
using namespace std;
void check(const string& Text, const string& key, const
           bool destructCipherText=false)
{
    try {
        locale loc("ru_RU.UTF-8");
        wstring_convert<codecvt_utf8<wchar_t>, wchar_t>
        codec;
        
        string cipherText;
        string decryptedText;
        modAlphaCipher cipher(key);
        cipherText = cipher.encrypt(Text);
        cipherText = cipher.encrypt(Text);
        if (destructCipherText) {
            wstring ws = cipher.towstr(cipherText);
            ws.front() = tolower(ws.front(),loc);
            cipherText = cipher.fromwstr(ws);
        }
        decryptedText = cipher.decrypt(cipherText);
        cout<<"key="<<key<<endl;
        cout<<Text<<endl;
        cout<<cipherText<<endl;
        cout<<decryptedText<<endl;
    } catch (const cipher_error & e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
}
int main(int argc, char **argv)
{
    check("АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ","Лежааать");
    check("АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ","");
    check("АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ","ААА");
    check("Ку привет здарова хай","Бум");
    check("123","Абвг");
    
    check("АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ","Ничего",true
         );
    return 0;
}