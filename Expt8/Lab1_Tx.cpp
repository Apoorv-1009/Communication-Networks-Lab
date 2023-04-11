#include <iostream>
#include <cstring>
using namespace std;

void Checksum(int l, int a[100])
{
    int checksum = 0;
    int len;
    char str[20];
    int data[20];
    cout << "\n Enter length of data: ";
    cin >> len;
    cout << "\n Enter data: ";
    for(int i=0; i<len; i++)
        cin >> str[i];
    cout << "\n Data in str: " << str;

    // Convert str to int
    for(int i=0; i<len; i++)
    {
        if(str[i] == 'A')
            data[i] = 10;
        else if(str[i] == 'B')
            data[i] = 11;
        else if(str[i] == 'C')
            data[i] = 12;
        else if(str[i] == 'D')
            data[i] = 13;
        else if(str[i] == 'E')
            data[i] = 14;
        else if(str[i] == 'F')
            data[i] = 15;
        else 
            data[i] = str[i] - 48;
    }
    cout << "\n Data in integer: ";
    for(int i=0; i<len; i++)
        cout << data[i] << " ";

    for(int i=0; i<len; i++)
        checksum += data[i];

    cout << "\nDecimal Checksum value: " << checksum << endl;

    char chk[5];
    sprintf(chk, "%X", checksum);
    int size = strlen(chk);
     cout << "\nFinal Checksum value: ";
    for(int i=0; i<size; i++)
        cout << chk[i] << " ";

    cout << "\n Size: " << size;

    checksum = 0;
    if(size>1)
    {
        for(int i=0; i<size; i++)
        {
            if(chk[i] == 'A')
                checksum += 10;
            else if(chk[i] == 'B')
                checksum += 11;
            else if(chk[i] == 'C')
                checksum += 12;
            else if(str[i] == 'D')
                checksum += 13;
            else if(chk[i] == 'E')
                checksum += 14;
            else if(chk[i] == 'F')
                checksum += 15;
            else 
                checksum += chk[i] - 48;
        }
        cout << "\nDecimal adjusted Checksum value: " << checksum << endl;

        sprintf(chk, "%X", 15 - checksum);
        size = strlen(chk);
        cout << "\nFinal adjusted Checksum value: ";
        for(int i=0; i<size; i++)
        {
            cout << chk[i] << " ";
        }
    }
    cout << "\n Final frame: ";
    for(int i=0; i<len; i++)
        cout << str[i] << " ";
    cout << chk[0];

}

void CharachterCount(int l, int a[100])
{
    int len = 15;
    int k;
    // Fill rest of array with -1
    for(int i=l; i<len; i++)
        a[i] = -1;

    int num;
    cout << "\n Enter number of frames: ";
    cin >> num;
    int frame[num];

    for(int i=0; i<num; i++)
    {
        cout << "\n Enter size of frame " << i+1 << ": ";
        cin >> frame[i];
    }
    
    int counter = 0;
    int data[len][len];
    for(int i=0; i<len; i++)
        for(int j=0; j<len; j++)
            data[i][j] = -1;

    // cout << "\n Computed 1" << endl;
        
    // Main computation
    for(int i=0; i<len; i++)
    {
        data[i][0] = frame[i];
        for(int j=1; j<frame[i]; j++)
            data[i][j] = a[counter];
            counter ++;
    }

    //cout << "\n Computed 2" << endl;

    cout << "Final frame matrix: \n";
    for(int i=0; i<num; i++)
    {
        cout << "\n Frame " << i+1 << endl;
        for(int j=0; j<len; j++)
        {
            if(data[i][j] != -1)
                cout << data[i][j] << " ";
        }
        cout << "\n";
    }

}

void BitStuffing(int l, int a[100])
{
    // Check for 11111, append 0 to end of it
    int truth = 0;
    for(int i=0; i<l; i++)
    {
        if(a[i] == 1)
            truth++;
        else 
            truth = 0;
        
        if(truth == 5)
        {
            for(int j=l; j>i; j--)
                a[j+1] = a[j];
            l++;
            a[i+1] = 0;
            truth = 0;
        }
    }
    cout << "\n Adjusted output: ";
    for(int i=0; i<l; i++)
        cout << a[i] << " ";
}

void ByteStuffing(int l, int a[100])
{
    int len;
    int length = 20;
    cout << "\n Enter lenth of data:";
    cin >> len;
    char str[length];

    cout << "\n Enter data: ";
    for(int i=0; i<len; i++)
        cin >> str[i];

    cout << "\n Entered data: ";
    for(int i=0; i<len; i++)
        cout << str[i] << " ";

    // Check for AAAAA, append 0 to it
    int truth = 0;
    for(int i=0; i<len; i++)
    {
        if(str[i] == 'A')
            truth++;
        else
            truth = 0;

        if(truth == 5)
        {
            for(int j=len; j>i; j--)
                str[j+1] = str[j];
            len++;
            str[i+1] = '0';
            truth = 0;
        }
    }
    cout << "\n Adjusted data: ";
    for(int i=0; i<len; i++)
        cout << str[i] << " ";
}

int main()
{
    int length, array[100];
    cout << "\n Enter length of array: " << endl;
    cin >> length;

    cout << "Enter elements: " << endl;
    for(int i=0; i<length; i++)
        cin >> array[i];

    cout << "Entered elements: ";
    for(int i=0; i<length; i++)
        cout << array[i] << "  ";
    cout << endl;

    int choice;
    cout << "Enter 1 for Checksum" << endl;
    cout << "Enter 2 for Charachter count" << endl;
    cout << "Enter 3 for BitStuffing" << endl;
    cout << "Enter 4 for ByteStuffing" << endl;
    cin >> choice;

    switch(choice)
    {
        case 1: Checksum(length, array);
                break;

        case 2: CharachterCount(length, array);
                break;

        case 3: BitStuffing(length, array);
                break;

        case 4: ByteStuffing(length, array);
                break;
    }

    return 0;
}