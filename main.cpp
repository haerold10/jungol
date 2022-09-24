#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int N, M;
int arr[1000050];
long long anstree;
long long anstree1;
int mid;
int maxtree = -99999999;
int mintree = 0;
int bsearch(int minn, int maxx  , int target) {
    if(minn >= maxx) return minn;

    mid = (minn + maxx) / 2;
    anstree = anstree1 = 0;
    for(int i = 0; i < N; i++) {
        if(arr[i] > mid) {
            anstree += arr[i] - mid;
            if(anstree >= M) {
                break;
            }
        }
    }
    if(anstree >= M) {
        anstree1 = 0;
        for(int i = 0; i < N; i++) {
            if(arr[i] > mid + 1) {
                anstree1 += arr[i] - (mid + 1);
                if(anstree1 >= M) break;
            }
        }
        if(anstree1 < M) return mid;
        else return bsearch(mid + 1, maxx, M);
    }
    else return bsearch(minn, mid - 1, M);
    return 0;

}

int comp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(arr[0]), comp);
    maxtree = arr[0];
    printf("%d", bsearch(0, maxtree, M));
}
