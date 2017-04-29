#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main() {
	srand(time(0));
	char c;
	for(int i=0; i<1000000; i++) {
		c = rand() % 26 + 'a';
		printf("%c",c);
	}
	system("pause");
	return 0;
}