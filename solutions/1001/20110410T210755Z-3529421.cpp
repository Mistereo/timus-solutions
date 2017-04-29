#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
        vector<double> v;
        double n;
        while(cin >> n) {
                v.push_back(n);
        }
        for(int i=v.size()-1; i>=0; i--)
                printf("%lf ",sqrt(v[i]));
        return 0;
}