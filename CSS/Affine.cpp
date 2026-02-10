#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int modInverse(int a)
{
    for (int i = 0; i < 26; i++)
    {
        if ((a * i) % 26 == 1)
            return i;
    }
    return -1;
}

int main()
{
    string s = "affinecipher";
    char k1 = 'f';
    char k2 = 'b';
    int key = 4;

    string o;
    char t;

    int a = k1 - 'a';
    int b = k2 - 'a';

    
    for (char x : s)
    {
        t = ((x - 'a') * a + b) % 26 + 'a';
        o += t;
    }

    printf("Affine Output: %s", o.c_str());


    int r = o.size() / key;
    string output;

    for (int c = 0; c < key; c++)
    {
        for (int row = 0; row < r; row++)
        {
            int i = row * key + c;
            output += o[i];
        }
    }

    printf("\nFinal Output (Affine + Transposition): %s", output.c_str());


    string transDecrypt(o.size(), ' ');
    int idx = 0;

    for (int c = 0; c < key; c++)
    {
        for (int row = 0; row < r; row++)
        {
            int i = row * key + c;
            transDecrypt[i] = output[idx++];
        }
    }

    printf("\nAfter Transposition Decryption: %s", transDecrypt.c_str());

    
    int a_inv = modInverse(a);
    string finalPlain;

    for (char y : transDecrypt)
    {
        int val = y - 'a';
        int decrypted = (a_inv * (val - b + 26)) % 26;
        finalPlain += decrypted + 'a';
    }

    printf("\nFinal Decrypted Plaintext: %s", finalPlain.c_str());

    return 0;
}