#include <iostream>
using namespace std;

string xorfun(string data, string crc)
{
    int datalen = data.length();
    int crclen = crc.length();
    for(int i=0; i <= datalen - crclen; )
    {
        for(int j=0; j<crclen; j++)
        {
            data[i+j] = data[i+j] == crc[j] ? '0' : '1';
        }
        if(i < datalen && data[i] != '1')
            i++;
    }
    return data;
}


int main()
{
    string data, crc, encoded;
    cout << "\n Enter data bits: ";
    cin >> data;
    cout << "\n Enter generator: ";
    cin >>crc;
    encoded += data;

    int crclen = crc.length();
    int datalen = data.length();
    
    for(int i=0; i<crclen-1; i++)
        encoded += '0';

    // cout << "\n Divisor: " << encoded;
    string remainder = xorfun(data, crc);
    remainder = remainder.substr(datalen - crclen + 1);
    cout << "\n Remainder: " << remainder;

    string frame = data + remainder;
    cout << "\n Final frame to be transmitted: " << frame << endl;

    return 0;
}