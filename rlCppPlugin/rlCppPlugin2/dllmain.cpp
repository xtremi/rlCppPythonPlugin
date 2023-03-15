#ifdef _DEBUG
    #undef _DEBUG
    #include <pybind11/pybind11.h>
    #define _DEBUG
#else
    #include <pybind11/pybind11.h>
#endif
#include "trig.h"

namespace py = pybind11;


PYBIND11_MODULE(rlCppPlugin2, m) {
    m.def("fast_tanh2", &rl::Math::tanh, R"pbdoc(Compute a hyperbolic tangent of a single argument expressed in radians.)pbdoc");
    m.def("multi_fast_tanh_test2", &rl::Math::multiTanhTest, R"pbdoc(Calls fast_tanh2 N times. Used to test performance.)pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}