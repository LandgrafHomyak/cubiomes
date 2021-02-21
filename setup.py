from distutils.core import Extension, setup

ext = Extension(
    name="cubiomes",
    sources=[
        "./finders.c",
        "./generator.c",
        "./layers.c",
        "./util.c",
        "./python_module.c",
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
