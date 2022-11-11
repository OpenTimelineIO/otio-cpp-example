# OpenTimelineIO C++ Example

This repository serves as a minimal example of using OpenTimelineIO in a C++ application.

Allowable use of the code in this repository includes copying and pasting portions into
your own projects without attribution.


# Getting started

To get started, use git to clone this repository:

```
git clone --recurse-submodules https://github.com/OpenTimelineIO/otio-cpp-example.git
cd otio-cpp-example
```

...then build it:

```
mkdir build
cd build
cmake ..
cmake --build .
```

...and run it:

```
./otio-cpp-example ../sample_timeline.otio
```

Please also consult with the OpenTimelineIO [documentation](https://opentimelineio.readthedocs.io/en/latest/index.html)
for more information about OpenTimelineIO in general.

Good luck and happy coding!


## Github Actions

A set of simple automation scripts are available in the `.github/workflows` folder.
* `ci.yaml` - builds and runs the example program on Linux, macOS, and Windows.


## Contributions

If you have any suggested changes to the template repository itself, 
please provide them via [pull request](../../pulls) or [create an issue](../../issues) as appropriate. 

All contributions back to the template repository must align with the contribution
[guidelines](https://opentimelineio.readthedocs.io/en/latest/tutorials/contributing.html) 
of the OpenTimelineIO project.

