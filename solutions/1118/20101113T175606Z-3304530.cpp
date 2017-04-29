#include <time.h>
#include <iostream>
using namespace std;
#define N 1000001
float trivial(int x) {
	int sum=1;
	for(int i=2; i+i<=x; i++)
		if(x%i==0)
			sum+=i;
	return (float)sum/x;
}
int main()
{

	/**
	float duration;
	clock_t start, finish;
	start = clock(); //**/

	// Begin.

	//Primes
	bool *primes = new bool[N];
	memset(primes,true,N);
	memset(primes,false,2);
	for(int i=2; i*i<N; i++)
		if(primes[i])
			for(int j=i*i; j<N; j+=i)
				primes[j] = false;
	//******
	int a,b;
	bool foo = false;
	cin >> a >> b;
	if (a==1)
		cout << 1 << endl;
	else {
		for(int i=b; i>=a; i--) {
			if (primes[i]){
				cout << i << endl;
				foo = true;
				break;
			}
		}
		if (!foo) {
			float temp;
			float min = trivial(a);
			int answer = a;
			for(int i=a+1; i<=b; i++){
				temp = trivial(i);
				if(temp < min) {
					min=temp;
					answer = i;
				}
			}
			cout << answer << endl;
		}
	}
	//End.

	/**
	finish = clock(); 
	duration = (float)(finish - start) / CLOCKS_PER_SEC; 
	cout << duration <<  endl; //**/
	system("pause");

}