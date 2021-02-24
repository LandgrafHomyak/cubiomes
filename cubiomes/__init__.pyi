from typing import Iterable, Union, overload, NoReturn, Literal, Optional, Generic, TypeVar, Tuple

from pip._internal.utils.deprecation import deprecated

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


class __BiomeMeta(__enum['BiomeId']):
    none: BiomeID
    ocean: BiomeID
    plains: BiomeID
    desert: BiomeID
    mountains: BiomeID
    forest: BiomeID
    taiga: BiomeID
    swamp: BiomeID
    river: BiomeID
    nether_wastes: BiomeID
    the_end: BiomeID
    frozen_ocean: BiomeID
    frozen_river: BiomeID
    snowy_tundra: BiomeID
    snowy_mountains: BiomeID
    mushroom_fields: BiomeID
    mushroom_field_shore: BiomeID
    beach: BiomeID
    desert_hills: BiomeID
    wooded_hills: BiomeID
    taiga_hills: BiomeID
    mountain_edge: BiomeID
    jungle: BiomeID
    jungle_hills: BiomeID
    jungle_edge: BiomeID
    deep_ocean: BiomeID
    stone_shore: BiomeID
    snowy_beach: BiomeID
    birch_forest: BiomeID
    birch_forest_hills: BiomeID
    dark_forest: BiomeID
    snowy_taiga: BiomeID
    snowy_taiga_hills: BiomeID
    giant_tree_taiga: BiomeID
    giant_tree_taiga_hills: BiomeID
    wooded_mountains: BiomeID
    savanna: BiomeID
    savanna_plateau: BiomeID
    badlands: BiomeID
    wooded_badlands_plateau: BiomeID
    badlands_plateau: BiomeID
    small_end_islands: BiomeID
    end_midlands: BiomeID
    end_highlands: BiomeID
    end_barrens: BiomeID
    warm_ocean: BiomeID
    lukewarm_ocean: BiomeID
    cold_ocean: BiomeID
    deep_warm_ocean: BiomeID
    deep_lukewarm_ocean: BiomeID
    deep_cold_ocean: BiomeID
    deep_frozen_ocean: BiomeID
    the_void: BiomeID
    sunflower_plains: BiomeID
    desert_lakes: BiomeID
    gravelly_mountains: BiomeID
    flower_forest: BiomeID
    taiga_mountains: BiomeID
    swamp_hills: BiomeID
    ice_spikes: BiomeID
    modified_jungle: BiomeID
    modified_jungle_edge: BiomeID
    tall_birch_forest: BiomeID
    tall_birch_hills: BiomeID
    dark_forest_hills: BiomeID
    snowy_taiga_mountains: BiomeID
    giant_spruce_taiga: BiomeID
    giant_spruce_taiga_hills: BiomeID
    modified_gravelly_mountains: BiomeID
    shattered_savanna: BiomeID
    shattered_savanna_plateau: BiomeID
    eroded_badlands: BiomeID
    modified_wooded_badlands_plateau: BiomeID
    modified_badlands_plateau: BiomeID
    bamboo_jungle: BiomeID
    bamboo_jungle_hills: BiomeID
    soul_sand_valley: BiomeID
    crimson_forest: BiomeID
    warped_forest: BiomeID
    basalt_deltas: BiomeID
    extremeHills: BiomeID
    swampland: BiomeID
    hell: BiomeID
    sky: BiomeID
    frozenOcean: BiomeID
    frozenRiver: BiomeID
    icePlains: BiomeID
    iceMountains: BiomeID
    mushroomIsland: BiomeID
    mushroomIslandShore: BiomeID
    desertHills: BiomeID
    forestHills: BiomeID
    taigaHills: BiomeID
    extremeHillsEdge: BiomeID
    jungleHills: BiomeID
    jungleEdge: BiomeID
    deepOcean: BiomeID
    stoneBeach: BiomeID
    coldBeach: BiomeID
    birchForest: BiomeID
    birchForestHills: BiomeID
    roofedForest: BiomeID
    coldTaiga: BiomeID
    coldTaigaHills: BiomeID
    megaTaiga: BiomeID
    megaTaigaHills: BiomeID
    extremeHillsPlus: BiomeID
    savannaPlateau: BiomeID
    mesa: BiomeID
    mesaPlateau_F: BiomeID
    mesaPlateau: BiomeID
    warmOcean: BiomeID
    lukewarmOcean: BiomeID
    coldOcean: BiomeID
    warmDeepOcean: BiomeID
    lukewarmDeepOcean: BiomeID
    coldDeepOcean: BiomeID
    frozenDeepOcean: BiomeID

    @overload
    def __call__(self, id: int, /) -> BiomeID: ...

    @overload
    def __call__(self, name: str, /) -> BiomeID: ...


class BiomeID(metaclass=__BiomeMeta):
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


def initBiomes() -> NoReturn: ...


class Biome:
    id: BiomeID
    type: BiomeType
    height: float
    temp: float
    tempCat: BiomeTempCategory
    mutated: BiomeID
    name: str

    def __new__(
            self,
            id: int = ...,
            type: Union[int, str, BiomeType] = ...,
            height: float = ...,
            temp: float = ...,
            tempCat: Union[int, str, BiomeType] = ...,
            name: Optional[str] = ...
    ) -> __CustomBiome: ...

    def __init_subclass__(cls, **kwargs) -> NoReturn: ...


class __CustomBiome(Biome):
    id: int
    type: BiomeType
    height: float
    temp: float
    tempCat: BiomeTempCategory
    mutated: None
    name: str


class __biomes_tuple(tuple):
    def __new__(cls, *args, **kwargs) -> tuple: ...

    def __len__(self) -> Literal[256]: ...

    def __getitem__(self, item: Union[int, BiomeID]) -> Biome: ...


biomes: __biomes_tuple
