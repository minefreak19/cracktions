#include "./fraction.hh"

int main() {
    using namespace std;
    using namespace Cracktions;

    Fraction a(14, 3);
    Fraction b(4, 1);

    cout << 2 * (3 - (1 + (1 / b))) << endl;

    return 0;
}
