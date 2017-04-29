#include <iostream>
using namespace std;

void main () {
	int n,count=0;
	cin >> n;
	bool x=false;
	for(int i=0; i*i<=n; i++){
		for(int i2=0; i2*i2<=n; i2++){
			for(int i3=0; i3*i3<=n; i3++){
				for(int i4=0; i4*i4<=n; i4++){
					if((i*i)+(i2*i2)+(i3*i3)+(i4*i4)==n){
						if(i!=0)
							count++;
						if(i2!=0)
							count++;
						if(i3!=0)
							count++;
						if(i4!=0)
							count++;
						x=true;
						break;
					}
				}
				if(x)
					break;
			}
			if(x)
				break;
		}
		if(x)
			break;
	}
	cout << count << endl;
	system("pause");
}