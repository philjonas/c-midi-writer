import z_hex_pretty_print
with open('c4.mid', 'rb') as f:
    d = f.read().hex()
    hex_print = z_hex_pretty_print.pretty_print(d)
print(hex_print)
