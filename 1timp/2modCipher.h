#pragma once
#include <string>
using namespace std;
class Cipher
{
	char** value;
	int m, n;
public:
	Cipher() = delete;
	Cipher(int key, const string& s);
	string encrypt(const std::string& open_text);
	string decrypt(const std::string& cipher_text);
	~Cipher();
};