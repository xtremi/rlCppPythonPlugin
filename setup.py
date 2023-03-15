import setuptools

setuptools.setup(
    name="rlCppPythonPlugin",
    version="1.0.0",
    description="Sample project for a Python C++ extension/plugin",
    pacakges=setuptools.find_packages('src'),
    package_dir={'':'src'}
)