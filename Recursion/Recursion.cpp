#include <iostream>


int c(int n, int k) {
    if (n == k)
        return 1;
    else if (k == 1)
        return n;
    else
        return c(n - 1, k) + c(n - 1, k - 1);
}

int main() {
    std::cout << c(4,2) << std::endl;
    return 0;
}
