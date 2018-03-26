# Author: Hao CHENG
# Date: 24th Mar 2018
# Description: RSA with artificially small parameters

import math
import random


def Gcd(a, b):
    if a > b:
        a, b = b, a
    while a != 0:
        a, b = b % a, a
    return b


def Is_Prime(num):
    i = 2
    while (i < math.sqrt(num) + 1):
        if num % i == 0:
            return 0
        i += 1
    return 1


def Mod_Inverse(a, m):
    u1, u2, u3 = 1, 0, a
    v1, v2, v3 = 0, 1, m
    while v3 != 0:
        q = u3 // v3
        v1, v2, v3, u1, u2, u3 = (u1 - q * v1), (u2 - q * v2), (u3 - q * v3), v1, v2, v3
    return (u1 % m)


def Key_Generation(length):
    e, p, q = 3, 4, 4
    while(Is_Prime(p) == 0):
        p = random.randint(2 ** (length - 1), 2 ** length)
    while(Is_Prime(q) == 0):
        q = random.randint(2 ** (length - 1), 2 ** length)
    fi = (p - 1) * (q - 1)
    for e in [3, 5, 7, 11, 13, 17, 19]:
        if Gcd(e, fi) == 1:
            break
    d = Mod_Inverse(e, fi)
    n = p * q
    return p, q, e, d, n


def RSA_Encryption(m, e, n):
    e_bin = bin(e)
    c = 1
    for i in range(2, len(e_bin)):
        c = (c * c) % n
        if e_bin[i] == '1':
            c = (c * m) % n
    return c


if __name__ == '__main__':
    p, q, e, d, n = Key_Generation(30)
    m = int(input("\nPlease input the plaintext:\n"))
    c = RSA_Encryption(m, e, n)
    t = RSA_Encryption(c, d, n)

    print ('\nPublic Key(e, n) is:\n(', e, ', ', n, ')')
    print ('\nPrivate Key(p, q, d) is:\n(', p, ', ', q, ', ', d, ')')
    print ('\nCiphertext is:\n', c)
    print ('\nPlaintext is:\n', t)
