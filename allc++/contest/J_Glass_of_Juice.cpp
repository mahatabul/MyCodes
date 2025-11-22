/*
C makes it easy to shoot yourself in the foot; C++ makes it harder, but when you do, it blows your whole leg off.
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;

bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int factorial(int n){
if (n == 0)
{
return 1;}
int m = factorial(n - 1);int k = n * m;
return k;
}

#define PI 3.14159265358979323846


int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        double r1, r2, h, p;
        cin >> r1 >> r2 >> h >> p;

        // Calculate the radius at the top of the truncated cone
        double r3 = r2 + (r1 - r2) * (p / h);

        // Calculate the volume of the truncated cone using the formula:
        // V = (1/3) * π * h * (R1^2 + R1 * R2 + R2^2)
        // where R1 is the radius at the bottom, R2 is the radius at the top, and h is the height
        double volume = (3.14159265358979323846 * p / 3) * (r2 * r2 + r2 * r3 + r3 * r3);

        // Print the result
        cout << "Case " << t << ": " << fixed << setprecision(9) << volume << endl;
    }

    return 0;
}

