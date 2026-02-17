def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def modexp(base, exp, mod):
    res = 1
    base %= mod
    while exp:
        if exp & 1:
            res = (res * base) % mod
        base = (base * base) % mod
        exp >>= 1
    return res


def mod_inverse(e, phi):
    t, newt = 0, 1
    r, newr = phi, e

    while newr != 0:
        q = r // newr
        t, newt = newt, t - q * newt
        r, newr = newr, r - q * newr

    if r > 1:
        return -1
    if t < 0:
        t += phi
    return t


primeA = int(input("Provide prime number A: "))
primeB = int(input("Provide prime number B: "))
msg_val = int(input("Provide plaintext number (should be < modulus): "))

modulus = primeA * primeB
phi_n = (primeA - 1) * (primeB - 1)

pub_e = int(input("Provide public exponent (coprime with phi): "))

if gcd(pub_e, phi_n) != 1:
    print("Bad exponent: gcd(pub_e, phi) must equal 1")
    exit()

priv_d = mod_inverse(pub_e, phi_n)

print("\nPublic key [e, n]:", pub_e, modulus)
print("Private key d:", priv_d)

cipher = modexp(msg_val, pub_e, modulus)
print("Ciphertext:", cipher)    

recovered = modexp(cipher, priv_d, modulus)
print("Recovered plaintext:", recovered)