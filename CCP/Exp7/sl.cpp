#include <iostream>
#include <vector>
using namespace std;

unsigned int reverseBits(unsigned int n)
{
    unsigned int rev = 0;

    for(int i = 0; i < 32; i++)
    {
        rev = (rev << 1) | (n & 1);
        n = n >> 1;
    }

    return rev;
}

int countSetBits(unsigned int n)
{
    int count = 0;

    while(n)
    {
        count += (n & 1);
        n = n >> 1;
    }

    return count;
}

int findUnique(vector<int>& arr)
{
    int x = 0;

    for(int num : arr)
    {
        x ^= num;
    }

    return x;
}

void generateSubsets(vector<int>& arr)
{
    int n = arr.size();
    int total = 1 << n;

    for(int mask = 0; mask < total; mask++)
    {
        cout << "{ ";

        for(int i = 0; i < n; i++)
        {
            if(mask & (1 << i))
            {
                cout << arr[i] << " ";
            }
        }

        cout << "}" << endl;
    }
}

int main()
{
    unsigned int n;

    cin >> n;

    cout << "Original Number: " << n << endl;
    cout << "Reversed Bits Number: " << reverseBits(n) << endl;
    cout << "Set Bits Count: " << countSetBits(n) << endl;

    vector<int> arr = {2, 3, 4, 3, 2};
    cout << "Unique Element using XOR: " << findUnique(arr) << endl;

    vector<int> subsetArr = {1, 2, 3};

    cout << "Subsets using Bit Masking:" << endl;
    generateSubsets(subsetArr);

    return 0;
}