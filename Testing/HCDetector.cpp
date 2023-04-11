#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int BinaryConverter(int n, int pos)
{
    int num[10];
    int i = 0;
    while(n > 0)
    {
        num[i] = n%2;
        n = n/2;
        i++;
    }
    return num[pos];
}

int main()
{
    // int frame[] = {0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1};
    int frame[] = {0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1};
    int len = sizeof(frame) / sizeof(frame[0]);

    int parity[len];
    for(int i=0; i<len; i++)
        parity[i] = 0;

    int lsb;
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            lsb = BinaryConverter(j+1, i);
            if(lsb == 1)
                parity[i] = parity[i] ^ frame[j];
        }
    }

    int parity_sum = 0;
    for(int i=0; i<len; i++)
        parity_sum += pow(2,i)*parity[i];

    if(parity_sum == 0)
        cout << "\n No error in Tx";
    
    else 
    {
        cout << "\n Error in Tx";
        cout << "\n Error  at: " << parity_sum;
    }
}