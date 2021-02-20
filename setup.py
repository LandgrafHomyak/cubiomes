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
    name="markup_language_parser",
    ext_modules=[
        ext
    ],
    # ext_package="markup_language_parser",
    # packages=["markup_language_parser"],
    # package_data={"markup_language_parser": ["py.typed", "__init__.pyi", "_utils.pyi"]}
)
