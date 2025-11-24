## PyTermui

Python binding for [TermUI](https://github.com/josh-orio/termui) library.

### Get Started

There are multiple ways to use this binding:

1. Check [Releases](https://github.com/josh-orio/pytermui/releases), there may already be a compiled wheel for your system/pyversion.

    You'll be able to "pip install ${WHL_URL}" or add the URL to a requirements.txt.

2. Build a wheel yourself.

    ```bash
    pip install --upgrade build
    python -m build
    ```

    Will build a wheel and leave it in dist/, which you can then install or distribute yourself.

The installed library is imported using ```import pytermui```.

### Usage

The API for PyTermui is very similar to the CPP version. Methods that return ptrs and smart ptrs are not pybound at present.

In addition constructors and functions that would have optional arguments in the C++ library, are currently all mandatory.

To understand which interfaces and elements are shipped with TermUI, visit the [docs](https://github.com/josh-orio/termui).
