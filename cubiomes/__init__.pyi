from typing import Iterable, Union, overload, NoReturn, Literal

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
