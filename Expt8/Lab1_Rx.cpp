#include <iostream>
#include <cstring>
using namespace std;

void Checksum(int l, int a[100])
{
    char str[20];
    int len;
    cout << "\n Enter length of frame: ";
    cin >> len;

    cout << "\n Enter data:";
    for(int i=0; i<len; i++)
        cin >> str[i];
    
    cout << "\n Entered data: " << str;

    int checksum = 0;
    for(int i=0; i<len; i++)
    {
        if(str[i] == 'A')
            checksum += 10;
        else if(str[i] == 'B')
            checksum += 11;
        else if(str[i] == 'C')
            checksum += 12;
        else if(str[i] == 'D')
            checksum += 13;
        else if(str[i] == 'E')
            checksum += 14;
        else if(str[i] == 'F')
            checksum += 15;
        else
            checksum += str[i] - 48;
    }

    cout << "\n Checksum: " <<  checksum;
    char hexck[5];
    sprintf(hexck, "%X", checksum);
    cout << "\n Checksum in hex: " <<  hexck;

    int size = strlen(hexck);
    if(size > 1)
    {
        checksum = 0;
        for(int i=0; i<size; i++)
        {
            if(hexck[i] == 'A')
                checksum += 10;
            else if(hexck[i] == 'B')
                checksum += 11;
            else if(hexck[i] == 'C')
                checksum += 12;
            else if(hexck[i] == 'D')
                checksum += 13;
            else if(hexck[i] == 'E')
                checksum += 14;
            else if(hexck[i] == 'F')
                checksum += 15;
            else
                checksum += hexck[i] - 48;
        }
        sprintf(hexck, "%X", checksum);
        cout << "\n Adjusted checksum value: " << checksum;
        cout << "\n Adjusted checksum value in hex: " << hexck;
    }

    if(hexck[0] == 'F')
        cout << "\n Data correctly received";
    else    
        cout << "\n Incorrect data received";


}

void CharachterCount(int l, int a[100])
{
    // Replace rest of the array with -1
    for(int i=l; i<100; i++)
        a[i] = -1;
    
    int counter = 0;
    for(int i=0; i<l; )
    {
        cout << "\n Frame " << i << ": ";
        for(int j=0; j<a[i]; j++)
        {
            cout << a[counter] << " ";
            counter++;
        }
        i = counter;
    }

}

void BitStuffing(int l, int a[100])
{
    int truth = 0;
    for(int i=0; i<l; i++)
    {
        if(a[i] == 1)
            truth++;
        else 
            truth = 0;

        if(truth == 5)
        {
            for(int j=i+1; j<l; j++)
                a[j] = a[j+1];
            l--;
            truth = 0;
        }
    }
    cout << "\n Adjusted data: ";
    for(int i=0; i<l; i++)
        cout << a[i] << " ";
}

void ByteStuffing(int l, int a[100])
{
    int len = 20;
    char str[len];
    cout << "\n Enter len of data: " << endl;
    cin >> len;
    cout << "Enter data: ";
    for(int i=0; i<len; i++)
        cin >> str[i];
    
    int truth = 0;
    for(int i=0; i<len; i++)
    {
        if(str[i] == 'A')
            truth++;
        else 
            truth = 0;

        if(truth == 5)
        {
            for(int j=i+1; j<len; j++)
                str[j] = str[j+1];
            len--;
            truth = 0;
        }
    }
    cout << "\n Adjusted data: ";
    for(int i=0; i<len; i++)
        cout << str[i];
}


int main()
{
    int len;
    int data[100];
    cout <<"\n Enter data length: ";
    cin >> len;

    cout << "\n Enter data: ";
    for(int i=0; i<len; i++)
        cin >> data[i];

    int choice;
    cout << "Enter 1 for Checksum" << endl;
    cout << "Enter 2 for Charachter count" << endl;
    cout << "Enter 3 for BitStuffing" << endl;
    cout << "Enter 4 for ByteStuffing" << endl;
    cin >> choice;

    switch(choice)
    {
        case 1: Checksum(len, data);
                break;

        case 2: CharachterCount(len, data);
                break;

        case 3: BitStuffing(len, data);
                break;

        case 4: ByteStuffing(len, data);
                break;
    }

    
    return 0;
}