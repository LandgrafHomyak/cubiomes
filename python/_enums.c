/* This file is auto-generated */

#include <stdio.h>
#include <python.h>
#include <structmember.h>
#include "_enums.h"
#include "enums.h"

static PyMemberDef PyCEnum_BiomeType_members[] = {
    {"Void", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 0, READONLY},
    {"Ocean", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 1, READONLY},
    {"Plains", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 2, READONLY},
    {"Desert", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 3, READONLY},
    {"Hills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 4, READONLY},
    {"Forest", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 5, READONLY},
    {"Taiga", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 6, READONLY},
    {"Swamp", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 7, READONLY},
    {"River", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 8, READONLY},
    {"Nether", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 9, READONLY},
    {"Sky", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 10, READONLY},
    {"Snow", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 11, READONLY},
    {"MushroomIsland", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 12, READONLY},
    {"Beach", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 13, READONLY},
    {"Jungle", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 14, READONLY},
    {"StoneBeach", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 15, READONLY},
    {"Savanna", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 16, READONLY},
    {"Mesa", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 17, READONLY},
    {NULL}
};

static PyBiomeTypeObject PyCEnum_BiomeType_values[] = {
    {
    PyObject_HEAD_INIT(NULL)
    .id = Void,
    .name = "Void"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = Ocean,
    .name = "Ocean"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = Plains,
    .name = "Plains"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = Desert,
    .name = "Desert"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = Hills,
    .name = "Hills"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = Forest,
    .name = "Forest"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = Taiga,
    .name = "Taiga"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = Swamp,
    .name = "Swamp"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = River,
    .name = "River"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = Nether,
    .name = "Nether"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = Sky,
    .name = "Sky"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = Snow,
    .name = "Snow"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = MushroomIsland,
    .name = "MushroomIsland"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = Beach,
    .name = "Beach"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = Jungle,
    .name = "Jungle"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = StoneBeach,
    .name = "StoneBeach"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = Savanna,
    .name = "Savanna"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = Mesa,
    .name = "Mesa"
  }
};

static PyTypeObject PyBiomeType_MetaType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "cubiomes.BiomeType",
    .tp_doc = "",
    .tp_basicsize = sizeof(PyCEnumMetaObject) - sizeof(PyObject *),
    .tp_itemsize = sizeof(PyObject *),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_TYPE_SUBCLASS,
    .tp_dealloc = (destructor)PyCEnumMeta_Dealloc,
    .tp_members = PyCEnum_BiomeType_members,
    .tp_call = (ternaryfunc)PyBiomeType_Call
};

static struct {
    PyTypeObject base;
    PyObject *values[18];
} _PyBiomeType_Type = {
    .values = {
        (PyObject *)&(PyCEnum_BiomeType_values[0]),
        (PyObject *)&(PyCEnum_BiomeType_values[1]),
        (PyObject *)&(PyCEnum_BiomeType_values[2]),
        (PyObject *)&(PyCEnum_BiomeType_values[3]),
        (PyObject *)&(PyCEnum_BiomeType_values[4]),
        (PyObject *)&(PyCEnum_BiomeType_values[5]),
        (PyObject *)&(PyCEnum_BiomeType_values[6]),
        (PyObject *)&(PyCEnum_BiomeType_values[7]),
        (PyObject *)&(PyCEnum_BiomeType_values[8]),
        (PyObject *)&(PyCEnum_BiomeType_values[9]),
        (PyObject *)&(PyCEnum_BiomeType_values[10]),
        (PyObject *)&(PyCEnum_BiomeType_values[11]),
        (PyObject *)&(PyCEnum_BiomeType_values[12]),
        (PyObject *)&(PyCEnum_BiomeType_values[13]),
        (PyObject *)&(PyCEnum_BiomeType_values[14]),
        (PyObject *)&(PyCEnum_BiomeType_values[15]),
        (PyObject *)&(PyCEnum_BiomeType_values[16]),
        (PyObject *)&(PyCEnum_BiomeType_values[17])
    }
};

PyCEnumMetaObject *PyBiomeType_TypePtr = (PyCEnumMetaObject *)&_PyBiomeType_Type;
    
static PyMemberDef PyCEnum_BiomeID_members[] = {
    {"none", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 0, READONLY},
    {"ocean", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 1, READONLY},
    {"plains", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 2, READONLY},
    {"desert", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 3, READONLY},
    {"mountains", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 4, READONLY},
    {"forest", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 5, READONLY},
    {"taiga", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 6, READONLY},
    {"swamp", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 7, READONLY},
    {"river", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 8, READONLY},
    {"nether_wastes", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 9, READONLY},
    {"the_end", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 10, READONLY},
    {"frozen_ocean", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 11, READONLY},
    {"frozen_river", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 12, READONLY},
    {"snowy_tundra", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 13, READONLY},
    {"snowy_mountains", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 14, READONLY},
    {"mushroom_fields", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 15, READONLY},
    {"mushroom_field_shore", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 16, READONLY},
    {"beach", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 17, READONLY},
    {"desert_hills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 18, READONLY},
    {"wooded_hills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 19, READONLY},
    {"taiga_hills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 20, READONLY},
    {"mountain_edge", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 21, READONLY},
    {"jungle", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 22, READONLY},
    {"jungle_hills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 23, READONLY},
    {"jungle_edge", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 24, READONLY},
    {"deep_ocean", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 25, READONLY},
    {"stone_shore", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 26, READONLY},
    {"snowy_beach", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 27, READONLY},
    {"birch_forest", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 28, READONLY},
    {"birch_forest_hills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 29, READONLY},
    {"dark_forest", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 30, READONLY},
    {"snowy_taiga", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 31, READONLY},
    {"snowy_taiga_hills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 32, READONLY},
    {"giant_tree_taiga", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 33, READONLY},
    {"giant_tree_taiga_hills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 34, READONLY},
    {"wooded_mountains", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 35, READONLY},
    {"savanna", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 36, READONLY},
    {"savanna_plateau", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 37, READONLY},
    {"badlands", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 38, READONLY},
    {"wooded_badlands_plateau", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 39, READONLY},
    {"badlands_plateau", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 40, READONLY},
    {"small_end_islands", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 41, READONLY},
    {"end_midlands", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 42, READONLY},
    {"end_highlands", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 43, READONLY},
    {"end_barrens", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 44, READONLY},
    {"warm_ocean", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 45, READONLY},
    {"lukewarm_ocean", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 46, READONLY},
    {"cold_ocean", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 47, READONLY},
    {"deep_warm_ocean", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 48, READONLY},
    {"deep_lukewarm_ocean", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 49, READONLY},
    {"deep_cold_ocean", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 50, READONLY},
    {"deep_frozen_ocean", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 51, READONLY},
    {"the_void", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 52, READONLY},
    {"sunflower_plains", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 53, READONLY},
    {"desert_lakes", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 54, READONLY},
    {"gravelly_mountains", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 55, READONLY},
    {"flower_forest", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 56, READONLY},
    {"taiga_mountains", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 57, READONLY},
    {"swamp_hills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 58, READONLY},
    {"ice_spikes", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 59, READONLY},
    {"modified_jungle", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 60, READONLY},
    {"modified_jungle_edge", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 61, READONLY},
    {"tall_birch_forest", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 62, READONLY},
    {"tall_birch_hills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 63, READONLY},
    {"dark_forest_hills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 64, READONLY},
    {"snowy_taiga_mountains", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 65, READONLY},
    {"giant_spruce_taiga", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 66, READONLY},
    {"giant_spruce_taiga_hills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 67, READONLY},
    {"modified_gravelly_mountains", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 68, READONLY},
    {"shattered_savanna", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 69, READONLY},
    {"shattered_savanna_plateau", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 70, READONLY},
    {"eroded_badlands", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 71, READONLY},
    {"modified_wooded_badlands_plateau", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 72, READONLY},
    {"modified_badlands_plateau", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 73, READONLY},
    {"bamboo_jungle", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 74, READONLY},
    {"bamboo_jungle_hills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 75, READONLY},
    {"soul_sand_valley", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 76, READONLY},
    {"crimson_forest", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 77, READONLY},
    {"warped_forest", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 78, READONLY},
    {"basalt_deltas", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 79, READONLY},
    {"extremeHills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 4, READONLY},
    {"swampland", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 7, READONLY},
    {"hell", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 9, READONLY},
    {"sky", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 10, READONLY},
    {"frozenOcean", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 11, READONLY},
    {"frozenRiver", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 12, READONLY},
    {"icePlains", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 13, READONLY},
    {"iceMountains", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 14, READONLY},
    {"mushroomIsland", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 15, READONLY},
    {"mushroomIslandShore", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 16, READONLY},
    {"desertHills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 18, READONLY},
    {"forestHills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 19, READONLY},
    {"taigaHills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 20, READONLY},
    {"extremeHillsEdge", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 21, READONLY},
    {"jungleHills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 23, READONLY},
    {"jungleEdge", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 24, READONLY},
    {"deepOcean", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 25, READONLY},
    {"stoneBeach", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 26, READONLY},
    {"coldBeach", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 27, READONLY},
    {"birchForest", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 28, READONLY},
    {"birchForestHills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 29, READONLY},
    {"roofedForest", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 30, READONLY},
    {"coldTaiga", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 31, READONLY},
    {"coldTaigaHills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 32, READONLY},
    {"megaTaiga", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 33, READONLY},
    {"megaTaigaHills", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 34, READONLY},
    {"extremeHillsPlus", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 35, READONLY},
    {"savannaPlateau", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 37, READONLY},
    {"mesa", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 38, READONLY},
    {"mesaPlateau_F", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 39, READONLY},
    {"mesaPlateau", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 40, READONLY},
    {"warmOcean", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 45, READONLY},
    {"lukewarmOcean", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 46, READONLY},
    {"coldOcean", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 47, READONLY},
    {"warmDeepOcean", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 48, READONLY},
    {"lukewarmDeepOcean", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 49, READONLY},
    {"coldDeepOcean", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 50, READONLY},
    {"frozenDeepOcean", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 51, READONLY},
    {NULL}
};

static PyBiomeIDObject PyCEnum_BiomeID_values[] = {
    {
    PyObject_HEAD_INIT(NULL)
    .id = none,
    .name = "none",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = ocean,
    .name = "ocean",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = plains,
    .name = "plains",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = desert,
    .name = "desert",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = mountains,
    .name = "mountains",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = forest,
    .name = "forest",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = taiga,
    .name = "taiga",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = swamp,
    .name = "swamp",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = river,
    .name = "river",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = nether_wastes,
    .name = "nether_wastes",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = the_end,
    .name = "the_end",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = frozen_ocean,
    .name = "frozen_ocean",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = frozen_river,
    .name = "frozen_river",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = snowy_tundra,
    .name = "snowy_tundra",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = snowy_mountains,
    .name = "snowy_mountains",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = mushroom_fields,
    .name = "mushroom_fields",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = mushroom_field_shore,
    .name = "mushroom_field_shore",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = beach,
    .name = "beach",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = desert_hills,
    .name = "desert_hills",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = wooded_hills,
    .name = "wooded_hills",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = taiga_hills,
    .name = "taiga_hills",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = mountain_edge,
    .name = "mountain_edge",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = jungle,
    .name = "jungle",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = jungle_hills,
    .name = "jungle_hills",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = jungle_edge,
    .name = "jungle_edge",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = deep_ocean,
    .name = "deep_ocean",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = stone_shore,
    .name = "stone_shore",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = snowy_beach,
    .name = "snowy_beach",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = birch_forest,
    .name = "birch_forest",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = birch_forest_hills,
    .name = "birch_forest_hills",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = dark_forest,
    .name = "dark_forest",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = snowy_taiga,
    .name = "snowy_taiga",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = snowy_taiga_hills,
    .name = "snowy_taiga_hills",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = giant_tree_taiga,
    .name = "giant_tree_taiga",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = giant_tree_taiga_hills,
    .name = "giant_tree_taiga_hills",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = wooded_mountains,
    .name = "wooded_mountains",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = savanna,
    .name = "savanna",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = savanna_plateau,
    .name = "savanna_plateau",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = badlands,
    .name = "badlands",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = wooded_badlands_plateau,
    .name = "wooded_badlands_plateau",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = badlands_plateau,
    .name = "badlands_plateau",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = small_end_islands,
    .name = "small_end_islands",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = end_midlands,
    .name = "end_midlands",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = end_highlands,
    .name = "end_highlands",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = end_barrens,
    .name = "end_barrens",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = warm_ocean,
    .name = "warm_ocean",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = lukewarm_ocean,
    .name = "lukewarm_ocean",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = cold_ocean,
    .name = "cold_ocean",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = deep_warm_ocean,
    .name = "deep_warm_ocean",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = deep_lukewarm_ocean,
    .name = "deep_lukewarm_ocean",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = deep_cold_ocean,
    .name = "deep_cold_ocean",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = deep_frozen_ocean,
    .name = "deep_frozen_ocean",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = the_void,
    .name = "the_void",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = sunflower_plains,
    .name = "sunflower_plains",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = desert_lakes,
    .name = "desert_lakes",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = gravelly_mountains,
    .name = "gravelly_mountains",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = flower_forest,
    .name = "flower_forest",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = taiga_mountains,
    .name = "taiga_mountains",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = swamp_hills,
    .name = "swamp_hills",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = ice_spikes,
    .name = "ice_spikes",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = modified_jungle,
    .name = "modified_jungle",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = modified_jungle_edge,
    .name = "modified_jungle_edge",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = tall_birch_forest,
    .name = "tall_birch_forest",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = tall_birch_hills,
    .name = "tall_birch_hills",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = dark_forest_hills,
    .name = "dark_forest_hills",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = snowy_taiga_mountains,
    .name = "snowy_taiga_mountains",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = giant_spruce_taiga,
    .name = "giant_spruce_taiga",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = giant_spruce_taiga_hills,
    .name = "giant_spruce_taiga_hills",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = modified_gravelly_mountains,
    .name = "modified_gravelly_mountains",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = shattered_savanna,
    .name = "shattered_savanna",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = shattered_savanna_plateau,
    .name = "shattered_savanna_plateau",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = eroded_badlands,
    .name = "eroded_badlands",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = modified_wooded_badlands_plateau,
    .name = "modified_wooded_badlands_plateau",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = modified_badlands_plateau,
    .name = "modified_badlands_plateau",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = bamboo_jungle,
    .name = "bamboo_jungle",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = bamboo_jungle_hills,
    .name = "bamboo_jungle_hills",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = soul_sand_valley,
    .name = "soul_sand_valley",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = crimson_forest,
    .name = "crimson_forest",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = warped_forest,
    .name = "warped_forest",
    .alternative_name = NULL
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = basalt_deltas,
    .name = "basalt_deltas",
    .alternative_name = NULL
  }
};

static PyTypeObject PyBiomeID_MetaType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "cubiomes.BiomeID",
    .tp_doc = "",
    .tp_basicsize = sizeof(PyCEnumMetaObject) - sizeof(PyObject *),
    .tp_itemsize = sizeof(PyObject *),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_TYPE_SUBCLASS,
    .tp_dealloc = (destructor)PyCEnumMeta_Dealloc,
    .tp_members = PyCEnum_BiomeID_members,
    .tp_call = (ternaryfunc)PyBiomeID_Call
};

static struct {
    PyTypeObject base;
    PyObject *values[80];
} _PyBiomeID_Type = {
    .values = {
        (PyObject *)&(PyCEnum_BiomeID_values[0]),
        (PyObject *)&(PyCEnum_BiomeID_values[1]),
        (PyObject *)&(PyCEnum_BiomeID_values[2]),
        (PyObject *)&(PyCEnum_BiomeID_values[3]),
        (PyObject *)&(PyCEnum_BiomeID_values[4]),
        (PyObject *)&(PyCEnum_BiomeID_values[5]),
        (PyObject *)&(PyCEnum_BiomeID_values[6]),
        (PyObject *)&(PyCEnum_BiomeID_values[7]),
        (PyObject *)&(PyCEnum_BiomeID_values[8]),
        (PyObject *)&(PyCEnum_BiomeID_values[9]),
        (PyObject *)&(PyCEnum_BiomeID_values[10]),
        (PyObject *)&(PyCEnum_BiomeID_values[11]),
        (PyObject *)&(PyCEnum_BiomeID_values[12]),
        (PyObject *)&(PyCEnum_BiomeID_values[13]),
        (PyObject *)&(PyCEnum_BiomeID_values[14]),
        (PyObject *)&(PyCEnum_BiomeID_values[15]),
        (PyObject *)&(PyCEnum_BiomeID_values[16]),
        (PyObject *)&(PyCEnum_BiomeID_values[17]),
        (PyObject *)&(PyCEnum_BiomeID_values[18]),
        (PyObject *)&(PyCEnum_BiomeID_values[19]),
        (PyObject *)&(PyCEnum_BiomeID_values[20]),
        (PyObject *)&(PyCEnum_BiomeID_values[21]),
        (PyObject *)&(PyCEnum_BiomeID_values[22]),
        (PyObject *)&(PyCEnum_BiomeID_values[23]),
        (PyObject *)&(PyCEnum_BiomeID_values[24]),
        (PyObject *)&(PyCEnum_BiomeID_values[25]),
        (PyObject *)&(PyCEnum_BiomeID_values[26]),
        (PyObject *)&(PyCEnum_BiomeID_values[27]),
        (PyObject *)&(PyCEnum_BiomeID_values[28]),
        (PyObject *)&(PyCEnum_BiomeID_values[29]),
        (PyObject *)&(PyCEnum_BiomeID_values[30]),
        (PyObject *)&(PyCEnum_BiomeID_values[31]),
        (PyObject *)&(PyCEnum_BiomeID_values[32]),
        (PyObject *)&(PyCEnum_BiomeID_values[33]),
        (PyObject *)&(PyCEnum_BiomeID_values[34]),
        (PyObject *)&(PyCEnum_BiomeID_values[35]),
        (PyObject *)&(PyCEnum_BiomeID_values[36]),
        (PyObject *)&(PyCEnum_BiomeID_values[37]),
        (PyObject *)&(PyCEnum_BiomeID_values[38]),
        (PyObject *)&(PyCEnum_BiomeID_values[39]),
        (PyObject *)&(PyCEnum_BiomeID_values[40]),
        (PyObject *)&(PyCEnum_BiomeID_values[41]),
        (PyObject *)&(PyCEnum_BiomeID_values[42]),
        (PyObject *)&(PyCEnum_BiomeID_values[43]),
        (PyObject *)&(PyCEnum_BiomeID_values[44]),
        (PyObject *)&(PyCEnum_BiomeID_values[45]),
        (PyObject *)&(PyCEnum_BiomeID_values[46]),
        (PyObject *)&(PyCEnum_BiomeID_values[47]),
        (PyObject *)&(PyCEnum_BiomeID_values[48]),
        (PyObject *)&(PyCEnum_BiomeID_values[49]),
        (PyObject *)&(PyCEnum_BiomeID_values[50]),
        (PyObject *)&(PyCEnum_BiomeID_values[51]),
        (PyObject *)&(PyCEnum_BiomeID_values[52]),
        (PyObject *)&(PyCEnum_BiomeID_values[53]),
        (PyObject *)&(PyCEnum_BiomeID_values[54]),
        (PyObject *)&(PyCEnum_BiomeID_values[55]),
        (PyObject *)&(PyCEnum_BiomeID_values[56]),
        (PyObject *)&(PyCEnum_BiomeID_values[57]),
        (PyObject *)&(PyCEnum_BiomeID_values[58]),
        (PyObject *)&(PyCEnum_BiomeID_values[59]),
        (PyObject *)&(PyCEnum_BiomeID_values[60]),
        (PyObject *)&(PyCEnum_BiomeID_values[61]),
        (PyObject *)&(PyCEnum_BiomeID_values[62]),
        (PyObject *)&(PyCEnum_BiomeID_values[63]),
        (PyObject *)&(PyCEnum_BiomeID_values[64]),
        (PyObject *)&(PyCEnum_BiomeID_values[65]),
        (PyObject *)&(PyCEnum_BiomeID_values[66]),
        (PyObject *)&(PyCEnum_BiomeID_values[67]),
        (PyObject *)&(PyCEnum_BiomeID_values[68]),
        (PyObject *)&(PyCEnum_BiomeID_values[69]),
        (PyObject *)&(PyCEnum_BiomeID_values[70]),
        (PyObject *)&(PyCEnum_BiomeID_values[71]),
        (PyObject *)&(PyCEnum_BiomeID_values[72]),
        (PyObject *)&(PyCEnum_BiomeID_values[73]),
        (PyObject *)&(PyCEnum_BiomeID_values[74]),
        (PyObject *)&(PyCEnum_BiomeID_values[75]),
        (PyObject *)&(PyCEnum_BiomeID_values[76]),
        (PyObject *)&(PyCEnum_BiomeID_values[77]),
        (PyObject *)&(PyCEnum_BiomeID_values[78]),
        (PyObject *)&(PyCEnum_BiomeID_values[79])
    }
};

PyCEnumMetaObject *PyBiomeID_TypePtr = (PyCEnumMetaObject *)&_PyBiomeID_Type;
    
static PyMemberDef PyCEnum_BiomeTempCategory_members[] = {
    {"Oceanic", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 0, READONLY},
    {"Warm", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 1, READONLY},
    {"Lush", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 2, READONLY},
    {"Cold", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 3, READONLY},
    {"Freezing", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 4, READONLY},
    {"Special", T_OBJECT_EX, offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * 5, READONLY},
    {NULL}
};

static PyBiomeTempCategoryObject PyCEnum_BiomeTempCategory_values[] = {
    {
    PyObject_HEAD_INIT(NULL)
    .id = Oceanic,
    .name = "Oceanic"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = Warm,
    .name = "Warm"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = Lush,
    .name = "Lush"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = Cold,
    .name = "Cold"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = Freezing,
    .name = "Freezing"
  },
    {
    PyObject_HEAD_INIT(NULL)
    .id = Special,
    .name = "Special"
  }
};

static PyTypeObject PyBiomeTempCategory_MetaType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "cubiomes.BiomeTempCategory",
    .tp_doc = "",
    .tp_basicsize = sizeof(PyCEnumMetaObject) - sizeof(PyObject *),
    .tp_itemsize = sizeof(PyObject *),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_TYPE_SUBCLASS,
    .tp_dealloc = (destructor)PyCEnumMeta_Dealloc,
    .tp_members = PyCEnum_BiomeTempCategory_members,
    .tp_call = (ternaryfunc)PyBiomeTempCategory_Call
};

static struct {
    PyTypeObject base;
    PyObject *values[6];
} _PyBiomeTempCategory_Type = {
    .values = {
        (PyObject *)&(PyCEnum_BiomeTempCategory_values[0]),
        (PyObject *)&(PyCEnum_BiomeTempCategory_values[1]),
        (PyObject *)&(PyCEnum_BiomeTempCategory_values[2]),
        (PyObject *)&(PyCEnum_BiomeTempCategory_values[3]),
        (PyObject *)&(PyCEnum_BiomeTempCategory_values[4]),
        (PyObject *)&(PyCEnum_BiomeTempCategory_values[5])
    }
};

PyCEnumMetaObject *PyBiomeTempCategory_TypePtr = (PyCEnumMetaObject *)&_PyBiomeTempCategory_Type;
    
int PyCEnum_InitAll( void )
{
    Py_ssize_t i;
    /* typeof(PyTypeObject) */ long flags = PyCEnumMeta_Type.tp_flags;
    PyCEnumMeta_Type.tp_flags = PyCEnumMeta_Type.tp_flags | Py_TPFLAGS_BASETYPE;
    PyCEnumMeta_Type.tp_base = &PyType_Type;
    
    PyBiomeType_MetaType.tp_base = &PyCEnumMeta_Type;
    if (PyType_Ready(&PyBiomeType_MetaType))
    {
        return -1;
    }
    
    _PyBiomeType_Type.base = PyBiomeType_TypeBase;
    Py_TYPE(PyBiomeType_TypePtr) = &PyBiomeType_MetaType;
    Py_SIZE(PyBiomeType_TypePtr) = 18;
    
    if (PyType_Ready((PyTypeObject *)PyBiomeType_TypePtr))
    {
        return -1;
    }
    
    for (i = 0; i < 18; i++)
    {
        Py_TYPE(&(PyCEnum_BiomeType_values[i])) = (PyTypeObject *)PyBiomeType_TypePtr;
    }




    PyBiomeID_MetaType.tp_base = &PyCEnumMeta_Type;
    if (PyType_Ready(&PyBiomeID_MetaType))
    {
        return -1;
    }
    
    _PyBiomeID_Type.base = PyBiomeID_TypeBase;
    Py_TYPE(PyBiomeID_TypePtr) = &PyBiomeID_MetaType;
    Py_SIZE(PyBiomeID_TypePtr) = 80;
    
    if (PyType_Ready((PyTypeObject *)PyBiomeID_TypePtr))
    {
        return -1;
    }
    
    for (i = 0; i < 80; i++)
    {
        Py_TYPE(&(PyCEnum_BiomeID_values[i])) = (PyTypeObject *)PyBiomeID_TypePtr;
    }




    PyBiomeTempCategory_MetaType.tp_base = &PyCEnumMeta_Type;
    if (PyType_Ready(&PyBiomeTempCategory_MetaType))
    {
        return -1;
    }
    
    _PyBiomeTempCategory_Type.base = PyBiomeTempCategory_TypeBase;
    Py_TYPE(PyBiomeTempCategory_TypePtr) = &PyBiomeTempCategory_MetaType;
    Py_SIZE(PyBiomeTempCategory_TypePtr) = 6;
    
    if (PyType_Ready((PyTypeObject *)PyBiomeTempCategory_TypePtr))
    {
        return -1;
    }
    
    for (i = 0; i < 6; i++)
    {
        Py_TYPE(&(PyCEnum_BiomeTempCategory_values[i])) = (PyTypeObject *)PyBiomeTempCategory_TypePtr;
    }



  
    PyCEnumMeta_Type.tp_flags = flags;
    
    if (PyType_Ready(&PyCEnumMeta_Type))
    {
        return -1;
    }
    if (PyType_Ready(&PyCEnumIterator_Type))
    {
        return -1;
    }
    
    return 0;
}

