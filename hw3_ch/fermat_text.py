# Author: Hao CHENG
# Date: 26th Mar 2018
# Description: Fermat Primality Test

import sys
import random

test_num = int(sys.argv[1])
t = 100


def fermat_test(n):
    for i in range(1, t + 1):
        a = random.randint(2, n - 2)
        r = a ** (n - 1) % n
        if r != 1:
            return "composite"
    return "prime"


if __name__ == '__main__':
    print (fermat_test(test_num))
