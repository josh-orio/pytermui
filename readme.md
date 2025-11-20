## PyTermui

Python binding for TermUI library.

[Original TermUI](https://github.com/josh-orio/termui)

### Get Started

To build and install the library, run ```make install```.

Then in python, import using:
```python3
import pytermui
```

To simply get a feel of the library, you can run ```make test```. Note that a path is added in bind_test.py, this is the location in the build dir where the library is stored, it is not available systemwide.

### Usage

The API for PyTermui is very similar to the CPP version. Methods that return ptrs and smart ptrs are not pybound at present.

To understand which interfaces and elements are shipped with TermUI, visit the [docs](https://github.com/josh-orio/termui).
