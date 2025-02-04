import math
import random

def rand_e(totient):
    e = random.randint(1, totient)
    while math.gcd(e, totient) != 1:
        e = random.randint(1, totient)
    return e

p = 10894450533789807236752183082582039506656699359680740323408248679047758588429686776977426972576133642175120211928372835177366064411495615508313404903424669
q = 12658413478697605728885154615230336197961975942639038208290096302503254434667936247442634579296863931509922590389713912295021376339694185908552735417570047
n = p * q
totient = (p-1)*(q-1)
e = 65537#rand_e(totient)
d = pow(e, -1, totient)
print("Public key: (e={}, n={})".format(e, n))
print("Private key: d={}".format(d))
exit()
ciph = 513256
plain = str(pow(ciph, d, n))
print(f"Decimal plaintext: {plain}")
print(f"ASCII Plaintext = {''.join(chr(int(x)) for x in plain.split("00"))}")