from typing import Iterable, Union, overload, NoReturn, Literal, Optional, Generic, TypeVar

_RGB_COMPONENT_TYPE = Union[int, bytes]


class Color:
    red: int
    green: int
    blue: int

    def __init__(
            self,
            red: _RGB_COMPONENT_TYPE = ...,
            green: _RGB_COMPONENT_TYPE = ...,
            blue: _RGB_COMPONENT_TYPE = ...
    ) -> NoReturn: ...


class ColorPointer(Color):
    red: int
    green: int
    blue: int
    index: int
    palette: BiomesPalette

    def unbound(self) -> Color: ...


_RGB_TYPE = Union[int, bytes, Iterable[_RGB_COMPONENT_TYPE], Color, ColorPointer]


class BiomesPalette:
    @overload
    def __init(self, array: Union[bytes, Iterable[_RGB_TYPE]]) -> NoReturn: ...

    @overload
    def __init__(self, *args: Iterable[_RGB_TYPE]) -> NoReturn: ...

    def __getitem__(self, index: int) -> ColorPointer: ...

    def __setitem__(self, index: int, value: _RGB_TYPE) -> NoReturn: ...

    def __len__(self) -> int: ...

    @overload
    def __contains__(self, item: ColorPointer) -> bool: ...

    @overload
    def __contains__(self, item: Color) -> Literal[False]: ...


def initBiomeColours(palette: BiomesPalette = ..., /): ...


def initBiomeTypeColours(palette: BiomesPalette = ..., /): ...


_IV = TypeVar("_IV")


class __enum_iterator(Generic[_IV]):
    def __next__(self) -> _IV: ...

    def __iter__(self) -> __enum_iterator[_IV]: ...


class __enum(type, Generic[_IV]):
    __name__: str

    def __iter__(self) -> __enum_iterator[_IV]: ...


class __BiomeTypeMeta(__enum['BiomeType']):
    Void: BiomeType
    Ocean: BiomeType
    Plains: BiomeType
    Desert: BiomeType
    Hills: BiomeType
    Forest: BiomeType
    Taiga: BiomeType
    Swamp: BiomeType
    River: BiomeType
    Nether: BiomeType
    Sky: BiomeType
    Snow: BiomeType
    MushroomIsland: BiomeType
    Beach: BiomeType
    Jungle: BiomeType
    StoneBeach: BiomeType
    Savanna: BiomeType
    Mesa: BiomeType

    @overload
    def __call__(self, id: int, /) -> BiomeType: ...

    @overload
    def __call__(self, name: str, /) -> BiomeType: ...


class BiomeType(metaclass=__BiomeTypeMeta):
    id: int
    name: str


class __BiomeMeta(__enum['Biome']):
    none: Biome
    ocean: Biome
    plains: Biome
    desert: Biome
    mountains: Biome
    forest: Biome
    taiga: Biome
    swamp: Biome
    river: Biome
    nether_wastes: Biome
    the_end: Biome
    frozen_ocean: Biome
    frozen_river: Biome
    snowy_tundra: Biome
    snowy_mountains: Biome
    mushroom_fields: Biome
    mushroom_field_shore: Biome
    beach: Biome
    desert_hills: Biome
    wooded_hills: Biome
    taiga_hills: Biome
    mountain_edge: Biome
    jungle: Biome
    jungle_hills: Biome
    jungle_edge: Biome
    deep_ocean: Biome
    stone_shore: Biome
    snowy_beach: Biome
    birch_forest: Biome
    birch_forest_hills: Biome
    dark_forest: Biome
    snowy_taiga: Biome
    snowy_taiga_hills: Biome
    giant_tree_taiga: Biome
    giant_tree_taiga_hills: Biome
    wooded_mountains: Biome
    savanna: Biome
    savanna_plateau: Biome
    badlands: Biome
    wooded_badlands_plateau: Biome
    badlands_plateau: Biome
    small_end_islands: Biome
    end_midlands: Biome
    end_highlands: Biome
    end_barrens: Biome
    warm_ocean: Biome
    lukewarm_ocean: Biome
    cold_ocean: Biome
    deep_warm_ocean: Biome
    deep_lukewarm_ocean: Biome
    deep_cold_ocean: Biome
    deep_frozen_ocean: Biome
    the_void: Biome
    sunflower_plains: Biome
    desert_lakes: Biome
    gravelly_mountains: Biome
    flower_forest: Biome
    taiga_mountains: Biome
    swamp_hills: Biome
    ice_spikes: Biome
    modified_jungle: Biome
    modified_jungle_edge: Biome
    tall_birch_forest: Biome
    tall_birch_hills: Biome
    dark_forest_hills: Biome
    snowy_taiga_mountains: Biome
    giant_spruce_taiga: Biome
    giant_spruce_taiga_hills: Biome
    modified_gravelly_mountains: Biome
    shattered_savanna: Biome
    shattered_savanna_plateau: Biome
    eroded_badlands: Biome
    modified_wooded_badlands_plateau: Biome
    modified_badlands_plateau: Biome
    bamboo_jungle: Biome
    bamboo_jungle_hills: Biome
    soul_sand_valley: Biome
    crimson_forest: Biome
    warped_forest: Biome
    basalt_deltas: Biome
    extremeHills: Biome
    swampland: Biome
    hell: Biome
    sky: Biome
    frozenOcean: Biome
    frozenRiver: Biome
    icePlains: Biome
    iceMountains: Biome
    mushroomIsland: Biome
    mushroomIslandShore: Biome
    desertHills: Biome
    forestHills: Biome
    taigaHills: Biome
    extremeHillsEdge: Biome
    jungleHills: Biome
    jungleEdge: Biome
    deepOcean: Biome
    stoneBeach: Biome
    coldBeach: Biome
    birchForest: Biome
    birchForestHills: Biome
    roofedForest: Biome
    coldTaiga: Biome
    coldTaigaHills: Biome
    megaTaiga: Biome
    megaTaigaHills: Biome
    extremeHillsPlus: Biome
    savannaPlateau: Biome
    mesa: Biome
    mesaPlateau_F: Biome
    mesaPlateau: Biome
    warmOcean: Biome
    lukewarmOcean: Biome
    coldOcean: Biome
    warmDeepOcean: Biome
    lukewarmDeepOcean: Biome
    coldDeepOcean: Biome
    frozenDeepOcean: Biome

    @overload
    def __call__(self, id: int, /) -> Biome: ...

    @overload
    def __call__(self, name: str, /) -> Biome: ...


class Biome(metaclass=__BiomeMeta):
    id: int
    name: str
    alternative_name: Optional[str]


class __BiomeTempCategoryMeta(__enum['BiomeTempCategory']):
    Oceanic: BiomeTempCategory
    Warm: BiomeTempCategory
    Lush: BiomeTempCategory
    Cold: BiomeTempCategory
    Freezing: BiomeTempCategory
    Special: BiomeTempCategory

    @overload
    def __call__(self, id: int, /) -> BiomeTempCategory: ...

    @overload
    def __call__(self, name: str, /) -> BiomeTempCategory: ...


class BiomeTempCategory(metaclass=__BiomeTempCategoryMeta):
    id: int
    name: str
