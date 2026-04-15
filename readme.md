## PyTermui

Python binding for [TermUI](https://github.com/josh-orio/termui) library.

These binds are written entirely by Claude or Ollama models because I'm not porting 30+ header files by hand. I check the output and if CI passes that's "good enough".

[![CI](https://github.com/josh-orio/pytermui/actions/workflows/build.yml/badge.svg)](https://github.com/josh-orio/pytermui/actions/workflows/build.yml)


### Get Started

> This project is designed to work with [uv](https://docs.astral.sh/uv/).

There are multiple ways to use this binding:

1. The easiest way is ```uv add termuipy```, 'pytermui' was sadly taken.

2. Alternatively, you may need to build your own:

    ```bash
    gh repo clone josh-orio/pytermui
    cd pytermui
    uv build
    ```

    uv will build the project and leave a .whl in dist/

    To use this wheel, you will need a layout like so:
    ```
    |- pytermui/
    |  |- __init__.py
    |  |- *.whl
    |- main.py
    ```

    The init file will need to match [this one.](pytermui/__init__.py)

The installed library is imported using ```import pytermui```.

### Usage

The API for PyTermui tries to replicate the CPP version as close as possible.

To learn more, visit the [docs](https://github.com/josh-orio/termui/tree/main/docs/).
