with open('c4.mid', 'rb') as f:
    d = f.read().hex()
    hex_print = '0x'
    hex_print += ', 0x'.join(a+b for a,b in zip(d[::2], d[1::2]))
print(hex_print)