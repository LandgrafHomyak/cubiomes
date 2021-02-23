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

print(cubiomes.BiomeType.Ocean)
print(cubiomes.BiomeType(8))
print(cubiomes.BiomeType("Mesa"))

print(cubiomes.Biome.ocean)
print(cubiomes.Biome(8))
print(cubiomes.Biome("badlands"))

print(cubiomes.BiomeTempCategory.Warm)
print(cubiomes.BiomeTempCategory(0))
print(cubiomes.BiomeTempCategory("Special"))

eit = iter(cubiomes.Biome)
print(eit)
print(*(val for val in eit))

# del cubiomes.initBiomeColours()[0]