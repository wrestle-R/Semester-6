#include <iostream>
#include <vector>
using namespace std;

vector<int> computeLPS(string pattern)
{
    int n = pattern.length();

    vector<int> lps(n, 0);

    int len = 0;
    int i = 1;

    while(i < n)
    {
        if(pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

void KMP(string text, string pattern)
{
    vector<int> lps = computeLPS(pattern);

    int i = 0;
    int j = 0;

    while(i < text.length())
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if(j == pattern.length())
        {
            cout << "Pattern found at index: " << i - j << endl;
            j = lps[j - 1];
        }
        else if(i < text.length() && text[i] != pattern[j])
        {
            if(j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    cout << "LPS Array: ";

    for(int x : lps)
    {
        cout << x << " ";
    }

    cout << endl;
}

int main()
{
    string text, pattern;

    cin >> text;
    cin >> pattern;

    KMP(text, pattern);

    cout << "KMP is more efficient than brute-force because it avoids unnecessary comparisons using the LPS array.";

    return 0;
}