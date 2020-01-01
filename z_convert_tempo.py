import z_hex_pretty_print

minute_in_microsecs = 60 * 1000 * 1000


def bpm_2_microsecs(bpm):
    return int(minute_in_microsecs / bpm)


def int_to_byte_array(n):
    s = hex(n)
    s = s.replace('0x', '')
    if len(s) % 2 == 1:
        s = '0' + s
    return z_hex_pretty_print.pretty_print(s)


if __name__ == "__main__":
    d = bpm_2_microsecs(120)
    h = hex(d)
    print(d, 'in hex is', h)

    s = int_to_byte_array(d)
    print('Byte array form:')
    print(s)
