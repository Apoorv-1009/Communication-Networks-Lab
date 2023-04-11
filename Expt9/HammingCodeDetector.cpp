#include<iostream>
#include <bits/stdc++.h>
using namespace std;
 
int binary_converter(int n, int pos)
{
    // array to store binary number
    int binaryNum[32];
 
    // counter for binary array
    int i = 0;
    while (n > 0) 
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    return binaryNum[pos];
}

int redundant_bit_calculator(int l)
{
    int size;
    for(size=0; size<40 ; size++)
    {
        if(pow(2,size) >= l + size + 1)
            break;
    }

    return size;
}

int main() 
{
    int frame[] = {1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1};
    int frame_length = sizeof(frame) / sizeof(frame[0]);
    int pos, binary;

    int parity[frame_length];

    for(int i=0; i<frame_length; i++)
        parity[i] = 0;

    for(int i=0; i<frame_length; i++)
    {
        cout << "";
        for(int j=0; j<frame_length; j++)
        {
            binary = binary_converter(j+1, i);
            if(binary == 1)
            {
                //cout << "j: " << j << "  ";
                parity[i] = parity[i] ^ frame[j];
                //cout << "parity" << parity[i] << " ";
            }
        }
        //cout << "\n";
    }

    // cout << "parity elements: ";
    // for(int i=0; i<frame_length; i++)
    //     cout << parity[i] << "  ";

    int parity_sum = 0;
    for(int i=0; i<frame_length; i++)
        parity_sum += parity[i]*pow(2,i);

    if(parity_sum == 0)
        cout << "\n No error in received frame \n";

    else
    {
        cout << "\n Error at position: " << parity_sum << "\n";
        if(frame[parity_sum-1] == 0)
            frame[parity_sum-1] = 1;
        else 
            frame[parity_sum-1] = 0;

        cout <<"\n Corrected data: ";
        for(int i=0; i<frame_length; i++)
            cout << frame[i] << "  ";
    }
    cout <<"\n ";

    return 0;
}