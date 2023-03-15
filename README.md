# rlCppPythonPlugin
Sample project for setting up a C++ plugin for Python


### CPython and PyBind11 plugin (C++, VS2022)

Solution file in rlCppPlugin contains 3 projects:

- **rlMathCalc**
	- Defines some trigonometric functions
	
- **rlCppPlugin**
	- Exposes functions in **rlMathCalc** to a dll using CPython
	
- **rlCppPlugin2**
	- Exposes functions in **rlMathCalc** to a dll using PyBind11
	- Simpler than CPython

Remarks:
	
- All projects in solutions builds to `/output` folder
- Additional Python library directories and includes are hardcoded (to Python libs)
- Dll extensions are set to `.pyd` in vs configuration properties
- Post build events copies resulting `.pyd` to Python source directory

### Python rlCppPythonPlugin module

`rlCppPythonPlugin.py` imports functions from the above mentioned plugins
and test their perfomance.

Example results with `N = 50e6`:

| Method                          | Time [S]      |
| ------------------------------- | ------------- |
| `N` calls to Python tanh        | `21.911s`     |
| `N` calls to CPython tanh       | ` 5.096s`     |
| `N` calls to PyBind11 tanh      | `15.088s`     |
| CPython calling tanh `N` times  | ` 0.512s`     |
| PyBind11 calling tanh `N` times | ` 0.524s`     |


PyBind11 simplifies the definitions of the functions and module to be 
exposed to Python from C++. However, has some overhead for each function calls.
Haven't digged into it, but probably some work arounds for that.
When doing large calculations in single functions, there's isn't any difference
in perfomance between the two.



