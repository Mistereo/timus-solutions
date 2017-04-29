#include <iostream>
using namespace std;

int main() {
    int _10, _50, _100, _500, _1000, _5000, cost;
    cin >> _10 >> _50 >> _100 >> _500 >> _1000 >> _5000 >> cost;

 int minCoup;
 if(_10 != 0)
        minCoup = 10;
    else if(_50 != 0)
        minCoup = 50;
    else if(_100 != 0)
        minCoup = 100;
    else if(_500 != 0)
        minCoup = 500;
    else if(_1000 != 0)
        minCoup = 1000;
    else if(_5000 != 0)
        minCoup = 5000;

    int sumOfAll = _10*10 + _50*50 + _100*100 + _500 *500 + _1000*1000 + _5000*5000 - minCoup;

    int count0 = 0;
    while(sumOfAll >= cost){
        sumOfAll -= cost;
        count0++;
    }

    minCoup += sumOfAll;

    int count1 = 0;
    while(minCoup >= cost){
        minCoup -= cost;
        count1++;
    }
    cout << count1 << '\n';
    for(int i = 1; i <= count1; ++i)
        cout << count0 + i << ' ';
}