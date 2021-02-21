import cubiomes

s = cubiomes.BiomesPalette([(1, 2, 3)] * 256)

p = cubiomes.BiomesPalette()
print(p[0])
for value in (1, (0, 0, 2), b"\0\0\x03", (b"\0", b"\0", b"\x04"), p[0].unbound(), p[0]):
    p[0] = value
    print(p[0])

p[0].red = 100
print(p[0])
c = p[0].unbound()
c.green = 500
print(c)

# print(s)
# e = s[62]
# print(e)
# print(e.unbound())
