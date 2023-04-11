#include <iostream>
using namespace std;

string xorfun(string data, string  crc)
{
    int datalen = data.length();
    int crclen = crc.length();
    for(int i=0; i <= datalen - crclen;)
    {
        for(int j=0; j<crclen; j++)
            data[i+j] = data[i+j] == crc[j] ? '0' : '1';

        if(i<datalen && data[i] !='1')
            i++;
    }
    return data;
}

int main()
{
    string data, crc, encoded;
    cout << "\n Enter data: ";
    cin >> data;
    cout << "\n Enter generator: ";
    cin >> crc;    encoded += data;
    // for(int i=0; i)

    int crclen = crc.length();
    int datalen = data.length();

    string remainder = xorfun(data, crc);
    //cout << "\n Remainder: " << remainder;

    int k=0;
    for(int i=0; i<datalen; i++)
    {
        if(remainder[i] != '0')
        {
            cout << "\n Error in transmission";
            k = 1;
            return 0;
        }
    }

    if(k == 0)
        cout << "\n No error in transmission";

    return 0;
}