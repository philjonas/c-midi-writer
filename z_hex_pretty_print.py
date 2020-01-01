def pretty_print(s):
    s = s.replace(' ','')
    hex_print = '0x'
    hex_print += ', 0x'.join(a+b for a, b in zip(s[::2], s[1::2]))

    return hex_print


if __name__ == "__main__":
    # print(pretty_print('00 FF 58 04 04 02 18 08'))
    print(pretty_print('00 FF 51 03 07 A1 20'))