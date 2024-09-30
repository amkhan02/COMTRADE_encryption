import math
import random

p = 52667
q = 56911
n = p * q
totient = (p-1)*(q-1)
e = random.randint(1, totient)
while math.gcd(e, totient) != 1:
    e = random.randint(1, totient)

d = pow(e, -1, totient)

print("Public key: (e={}, n={})".format(e, n))
print("Private key: d={}".format(d))