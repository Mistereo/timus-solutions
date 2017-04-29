#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int a,b,c;
	scanf("%d%d",&a,&b);
	__asm {
		mov eax, a
		mov ebx, b
		add eax, ebx
		mov c, eax
	}
	printf("%d",c);
	return 0;
}