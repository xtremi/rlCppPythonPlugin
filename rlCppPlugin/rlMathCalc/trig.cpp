#define _USE_MATH_DEFINES
#include <cmath>
#include "trig.h"

using namespace rl;
using namespace Math;

const double rl::Math::e = 2.7182818284590452353602874713527;

double rl::Math::sinh(double x) {
    return (1 - pow(e, (-2 * x))) / (2 * pow(e, -x));
}

double rl::Math::cosh(double x) {
    return (1 + pow(e, (-2 * x))) / (2 * pow(e, -x));
}

double rl::Math::tanh(double x) {
    return rl::Math::sinh(x) / rl::Math::cosh(x);
}


bool rl::Math::multiTanhTest(int nRuns) {

    double xmin = -2 * M_PI;
    double xmax = 2 * M_PI;

    for (int i = 0; i < nRuns; i++) {
        double x = ((double)rand() / (RAND_MAX)) + 1.0;
        double y = rl::Math::tanh(x);
    }
    return true;
}
