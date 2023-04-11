#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int redundant_bit_calculator(int l)
{
    for(int i=0; i<100; i++)
        if(pow(2, i) >= l+i+1)
            return i;
}

int binaryconverter(int n, int pos)
{
    int binary[10];
    int i = 0;
    while(n>0)
    {
        binary[i] = n%2;
        n = n/2;
        i++;
    }
    return binary[pos];

}

int main()
{
    //int l;
    // cout << "\n Enter data length:";
    // cin >> l;

    // int data[l];
    // cout << "\n Enter data: ";
    // for(int i=0; i<l; i++)
    //     cin >> data[i];

    int data[] = {1, 0, 0, 1, 1, 0, 1};
    //int data[] = {1, 0, 1, 1, 0, 0, 1};
    int l = sizeof(data) / sizeof(data[0]);

    cout << "\n Entered data: ";
    for(int i=0; i<l; i++)
        cout << data[i] << " ";

    int rb = redundant_bit_calculator(l);
    // cout << "\n Number of redundant bits: " << rb;

    int len = l + rb;
    int frame[len], result[len];
    for(int i=0; i<len; i++)
    {
        frame[i] = -1;
        result[i] = 0;
    }

    int paritypos = 0;
    int counter = 0;
    for(int i=0; i<len; i++)
    {
        if(pow(2, paritypos) == i+1)
            paritypos ++;
        else
        {
            frame[i] = data[counter];
            counter++;
        }
    }    

    cout << "\n Edited frame: ";
    for(int i=0; i<len; i++)
        cout << frame[i] << " ";
    int poslsb;
    // Parity computation
    for(int i=0; i<len; i++)
    {
        // Check if it is parity position
        if(frame[i] == -1)
        {
            for(int j=i; j<len; j++)
            {
                poslsb = binaryconverter(j+1, log2(i+1));
                if(poslsb == 1 && frame[j]!=-1)
                    result[i] = result[i] ^ frame[j];
            }
        }
        else 
            result[i] = frame[i];
    } 

    cout << "\n Final frame: ";
    for(int i=0; i<len; i++)
        cout << result[i] << " ";

    return 0;
}