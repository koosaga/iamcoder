#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <queue>
#include <algorithm>
#include <string.h>
#include <stack>
#include <map>

#define INF 987654321
typedef long long ll;

using namespace std;

vector<int> diff(vector<int> data) {
    vector<int> ret;
    for (int i = 0; i < data.size() - 1; i++) {
        ret.push_back(data[i + 1] - data[i]);
    }
    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> data;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            data.push_back(num);
        }
        if (n <= 4) {
            puts("YES");
        }
        else {
            for (int i = 0; i < 3; i++) {
                data = diff(data);
            }
            bool isSame = true;
            for (int i = 0; i < data.size() - 1; i++){
                if (data[i] != data[i + 1]) {
                    isSame = false;
                    break;
                }
            }
            if (isSame) {
                puts("YES");
            }
            else
                puts("NO");
        }
    }
}
