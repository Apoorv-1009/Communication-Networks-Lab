#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    // int data[] = {1, 0, 0, 1, 1, 0, 1};
    // int length = sizeof(data) / sizeof(data[0]);
    int frame_length;
    int length;
    
    cout << "\n Enter length of array: ";
    cin >> length;

    cout << "\n Enter elements: \n";
    int data[length];
    for( int i=0; i<length; i++)
        cin >> data[i];

    frame_length = redundant_bit_calculator(length) + length;
    int frame[frame_length];
    int result[frame_length];

    // Initialize the whole frame initially as -5 and resultant as 0
    for(int i=0; i<frame_length; i++)
    {
        frame[i] = -5;
        result[i] = 0;
    }

    // cout << "\n Enter elements of array: \n";
    // for(int i=0; i<length; i++)
    //     cin >> data[i];
    
    cout << "\n Entered elements: ";
    for(int i=0; i<length; i++)
        cout << data[i] << "  ";
    cout << "\n";

    cout << "\n Frame size: " << frame_length;
    cout << "\n Number of redundant bits: " << redundant_bit_calculator(length);

    // Create frame without calculating parity value, leave parity position as -5
    int parity_pos = 0;
    int counter = 0; // to keep track of data position
    for(int i=0; i<frame_length; i++)
    {
        if(pow(2, parity_pos) == i+1)
            parity_pos += 1;
        else
        {
            frame[i] = data[counter];
            counter++;
        }
    }
    
    // cout << "\n Frame without parity: ";
    // for(int i=0; i<frame_length; i++)
    //     cout << frame[i] << "  ";
    //cout << "\n";   

    for(int i = 0; i < frame_length; i++)
    {
        if(frame[i] == -5)
        {
            // Find position of -5
            int pos = log2(i+1);
            //cout << "parity: "<< pos+1 << "   ";
            int binary = 0;
            // Iterate over the rest of the elements for parity calculation
            for(int j = i; j < frame_length; j++)
            {
                // Convert j to binary and get parity based element
                binary = binary_converter(j+1, pos);
                //cout << "j: " << j << " ";
                //cout << binary << "\n";

                // Check if it mataches condition for parity element
                if(binary == 1 && frame[j] !=-5) 
                {
                    //cout << "j: " << j+1 << " ";
                    //cout << frame[j] << "  ";
                    result[i] = result[i] ^ frame[j];
                }
            }
            //cout << "\n";
        }
        else
            result[i] = frame[i];
    }

    cout << "\n Final frame: ";
    // for(int i=frame_length-1; i>=0; i--)
    //     cout << result[i] << "  ";
    for(int i=0; i<frame_length; i++)
        cout << result[i] << ", ";
    cout << "\n";
    
    return 0;
}