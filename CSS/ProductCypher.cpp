#include <iostream>
#include <string>

using namespace std;

int main()
{
    string plaintext = "affinecipher";
    string key = "xmcklqwertyu";

    if (plaintext.length() != key.length())
    {
        cout << "Key length must match plaintext length" << endl;
        return 0;
    }

    string cipher;


    for (int i = 0; i < plaintext.length(); i++)
    {
        char c = plaintext[i] ^ key[i];
        cipher += c;
    }

    cout << "Cipher Text (OTP): ";
    for (unsigned char c : cipher)
        cout << (int)c << " ";
    cout << endl;


    string decrypted;
    for (int i = 0; i < cipher.length(); i++)
    {
        char p = cipher[i] ^ key[i];
        decrypted += p;
    }

    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}

