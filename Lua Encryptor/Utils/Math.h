#pragma once

namespace Utils {
    static double Lerp(double a, double b, double t)
    {
        return a + t * (b - a);
    }
}
