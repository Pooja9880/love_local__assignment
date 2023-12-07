#include <iostream>

using namespace std;

int countDigitOne(int n) {
    int count = 0;
    for (long long i = 1; i <= n; i *= 10) {
        long long divider = i * 10;
        count += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
    }
    return count;
}

int main() {
    int n = 13;
    int result = countDigitOne(n);

    cout << "Output: " << result << endl;

    return 0;
}
