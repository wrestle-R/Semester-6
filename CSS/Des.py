# DES Key Generation in Python (Hex Output)

PC1 = [
    57, 49, 41, 33, 25, 17, 9,
    1, 58, 50, 42, 34, 26, 18,
    10, 2, 59, 51, 43, 35, 27,
    19, 11, 3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
    14, 6, 61, 53, 45, 37, 29,
    21, 13, 5, 28, 20, 12, 4
]

PC2 = [
    14, 17, 11, 24, 1, 5,
    3, 28, 15, 6, 21, 10,
    23, 19, 12, 4, 26, 8,
    16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
]

SHIFT_TABLE = [
    1, 1, 2, 2, 2, 2, 2, 2,
    1, 2, 2, 2, 2, 2, 2, 1
]


def hex_to_bin(hex_str):
    return bin(int(hex_str, 16))[2:].zfill(64)


def bin_to_hex(bin_str):
    return hex(int(bin_str, 2))[2:].upper().zfill(12)
    # 48 bits → 12 hex characters


def permute(key, table):
    return ''.join([key[i - 1] for i in table])


def shift_left(bits, shifts):
    return bits[shifts:] + bits[:shifts]


def generate_keys(key_hex):
    key_bin = hex_to_bin(key_hex)

    key_pc1 = permute(key_bin, PC1)

    left = key_pc1[:28]
    right = key_pc1[28:]

    round_keys = []

    for i in range(16):
        left = shift_left(left, SHIFT_TABLE[i])
        right = shift_left(right, SHIFT_TABLE[i])

        combined = left + right

        round_key_bin = permute(combined, PC2)

        round_key_hex = bin_to_hex(round_key_bin)

        round_keys.append(round_key_hex)

    return round_keys


# Example
key = "133457799BBCDFF1"
keys = generate_keys(key)

for i, k in enumerate(keys):
    print(f"Round {i+1} Key : {k}")