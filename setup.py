from distutils.core import Extension, setup

from generate_enums import main as generate_enums, EnumData

generate_enums(
    "./python/_enums.c",
    [
        EnumData.from_list(
            "BiomeType",
            "PyBiomeTypeObject",
            (
                "Void",
                "Ocean",
                "Plains",
                "Desert",
                "Hills",
                "Forest",
                "Taiga",
                "Swamp",
                "River",
                "Nether",
                "Sky",
                "Snow",
                "MushroomIsland",
                "Beach",
                "Jungle",
                "StoneBeach",
                "Savanna",
                "Mesa"
            ),
            lambda s: {"id": s, "name": f"\"{s}\""}
        ),
        EnumData.from_list(
            "BiomeID",
            "PyBiomeIDObject",
            (
                "none",
                "ocean",
                "plains",
                "desert",
                "mountains",
                "forest",
                "taiga",
                "swamp",
                "river",
                "nether_wastes",
                "the_end",
                "frozen_ocean",
                "frozen_river",
                "snowy_tundra",
                "snowy_mountains",
                "mushroom_fields",
                "mushroom_field_shore",
                "beach",
                "desert_hills",
                "wooded_hills",
                "taiga_hills",
                "mountain_edge",
                "jungle",
                "jungle_hills",
                "jungle_edge",
                "deep_ocean",
                "stone_shore",
                "snowy_beach",
                "birch_forest",
                "birch_forest_hills",
                "dark_forest",
                "snowy_taiga",
                "snowy_taiga_hills",
                "giant_tree_taiga",
                "giant_tree_taiga_hills",
                "wooded_mountains",
                "savanna",
                "savanna_plateau",
                "badlands",
                "wooded_badlands_plateau",
                "badlands_plateau",
                "small_end_islands",
                "end_midlands",
                "end_highlands",
                "end_barrens",
                "warm_ocean",
                "lukewarm_ocean",
                "cold_ocean",
                "deep_warm_ocean",
                "deep_lukewarm_ocean",
                "deep_cold_ocean",
                "deep_frozen_ocean",

                "the_void",

                "sunflower_plains",
                "desert_lakes",
                "gravelly_mountains",
                "flower_forest",
                "taiga_mountains",
                "swamp_hills",
                "ice_spikes",
                "modified_jungle",
                "modified_jungle_edge",
                "tall_birch_forest",
                "tall_birch_hills",
                "dark_forest_hills",
                "snowy_taiga_mountains",
                "giant_spruce_taiga",
                "giant_spruce_taiga_hills",
                "modified_gravelly_mountains",
                "shattered_savanna",
                "shattered_savanna_plateau",
                "eroded_badlands",
                "modified_wooded_badlands_plateau",
                "modified_badlands_plateau",
                "bamboo_jungle",
                "bamboo_jungle_hills",
                "soul_sand_valley",
                "crimson_forest",
                "warped_forest",
                "basalt_deltas"
            ),
            lambda s: {"id": s, "name": f"\"{s}\"", "alternative_name": "NULL"},
            {
                "extremeHills": "mountains",
                "swampland": "swamp",
                "hell": "nether_wastes",
                "sky": "the_end",
                "frozenOcean": "frozen_ocean",
                "frozenRiver": "frozen_river",
                "icePlains": "snowy_tundra",
                "iceMountains": "snowy_mountains",
                "mushroomIsland": "mushroom_fields",
                "mushroomIslandShore": "mushroom_field_shore",
                "desertHills": "desert_hills",
                "forestHills": "wooded_hills",
                "taigaHills": "taiga_hills",
                "extremeHillsEdge": "mountain_edge",
                "jungleHills": "jungle_hills",
                "jungleEdge": "jungle_edge",
                "deepOcean": "deep_ocean",
                "stoneBeach": "stone_shore",
                "coldBeach": "snowy_beach",
                "birchForest": "birch_forest",
                "birchForestHills": "birch_forest_hills",
                "roofedForest": "dark_forest",
                "coldTaiga": "snowy_taiga",
                "coldTaigaHills": "snowy_taiga_hills",
                "megaTaiga": "giant_tree_taiga",
                "megaTaigaHills": "giant_tree_taiga_hills",
                "extremeHillsPlus": "wooded_mountains",
                "savannaPlateau": "savanna_plateau",
                "mesa": "badlands",
                "mesaPlateau_F": "wooded_badlands_plateau",
                "mesaPlateau": "badlands_plateau",
                "warmOcean": "warm_ocean",
                "lukewarmOcean": "lukewarm_ocean",
                "coldOcean": "cold_ocean",
                "warmDeepOcean": "deep_warm_ocean",
                "lukewarmDeepOcean": "deep_lukewarm_ocean",
                "coldDeepOcean": "deep_cold_ocean",
                "frozenDeepOcean": "deep_frozen_ocean",
            }
        ),
        EnumData.from_list(
            "BiomeTempCategory",
            "PyBiomeTempCategoryObject",
            (
                "Oceanic",
                "Warm",
                "Lush",
                "Cold",
                "Freezing",
                "Special"
            ),
            lambda s: {"id": s, "name": f"\"{s}\""},

        )
    ]
)

ext = Extension(
    name="cubiomes",
    sources=[
        "./finders.c",
        "./generator.c",
        "./layers.c",
        "./util.c",
        "./python_module.c",
        "./python/_enums.c",
        "./python/enums.c",
        "./python/biome_colours.c",
        "./python/biome.c",
    ]
)
setup(
    name="cubiomes",
    ext_modules=[
        ext
    ],
    packages=["cubiomes"],
    package_data={"cubiomes": ["py.typed", "__init__.pyi"]}
)
