#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (is_prime(number)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    return 0;
}
// Output
// Enter a number: 7
// 7 is a prime number.
// Enter a number: 10
// 10 is not a prime number.
// Enter a number: 13
// 13 is a prime number.
// Enter a number: 20
// 20 is not a prime number.
// Enter a number: 23
// 23 is a prime number.
// Enter a number: 30
// 30 is not a prime number.
// Enter a number: 31
// 31 is a prime number.
// Enter a number: 40
// 40 is not a prime number.
// Enter a number: 47
// 47 is a prime number.
// Enter a number: 50
// 50 is not a prime number.
// Enter a number: 53
// 53 is a prime number.
// Enter a number: 60
// 60 is not a prime number.
// Enter a number: 61
// 61 is a prime number.
// Enter a number: 70
// 70 is not a prime number.
// Enter a number: 73
// 73 is a prime number.
// Enter a number: 80
// 80 is not a prime number.
// Enter a number: 83
// 83 is a prime number.
// Enter a number: 90
// 90 is not a prime number.
// Enter a number: 97
// 97 is a prime number.
// Enter a number: 100
// 100 is not a prime number.
// Enter a number: 101
// 101 is a prime number.
// Enter a number: 110
// 110 is not a prime number.
// Enter a number: 113
// 113 is a prime number.
// Enter a number: 120
// 120 is not a prime number.
// Enter a number: 127
// 127 is a prime number.
// Enter a number: 130
// 130 is not a prime number.
// Enter a number: 131
// 131 is a prime number.
// Enter a number: 140
// 140 is not a prime number.
// Enter a number: 137
// 137 is a prime number.
// Enter a number: 150
// 150 is not a prime number.
//