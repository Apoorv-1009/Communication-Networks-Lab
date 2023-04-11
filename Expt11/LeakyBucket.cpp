#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int length;
    cout << "\n Enter number of data bursts: ";
    cin >> length;
    int input_rate_time[length], input_rate[length];
    int area = 0;

    for(int i=0; i<length; i++)
    {
        cout << "Enter burst " << i+1 << " data rate: ";
        cin >> input_rate[i];
        cout << "Enter burst " << i+1 << " duration: ";
        cin >> input_rate_time[i];
        area = input_rate[i] * input_rate_time[i] + area;
    }
    int desired_flow_rate;
    cout << "Enter desired flow rate: ";
    cin >> desired_flow_rate;
    int duration = area / desired_flow_rate;
    cout << "Calculated time for desired flow rate: " << duration << endl;
    return 0;
}