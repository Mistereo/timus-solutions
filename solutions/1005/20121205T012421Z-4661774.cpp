#include <cstdio>
#define rep(i, n) for(int i=0; i<n; i++)

int main (int argc, const char * argv[])
{
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    //--------------------------------------
    
    int n;
    scanf("%d", &n);
    int *A = new int[n];
    rep(i, n) scanf("%d", A+i);
    
    int n1 = n/2;
    int *H = new int[1<<n1];
    int n2 = n - n1;
    rep(m, (1<<n1)) {
        H[m] = 0;
        rep(i, n1) {
            if (m & (1 << i)) H[m] += A[i];
            else H[m] -= A[i];
        }
    }
    int ans = 1000000000;
    rep(m, (1<<n2)) {
        int S = 0;
        rep(i, n2) {
            if (m&(1<<i)) S+= A[n1+i];
            else S -= A[n1+i];
        }
        rep(i, (1<<n1)) {
            if ((S+H[i] < 0 && -(S+H[i]) < ans) || (S+H[i] >=0 && S+H[i] < ans)) {
                ans = S+H[i] > 0 ? S+H[i] : -(S+H[i]);
            }
        }
    }
    printf("%d\n", ans);
    //--------------------------------------
#ifdef MISTMAC
	fclose(stdout);
	fclose(stdin);
#endif
    return 0;
}