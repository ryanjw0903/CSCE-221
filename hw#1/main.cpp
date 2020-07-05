#include <iostream>
#include <vector>
using  namespace std;
template <typename T>
T binarySearch(T arr[], int l, int r, T x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
int main() {
    vector<T> v1 {2,4,6,8,2};
    binarySearch(v1,0,v1.size(),8);
}

