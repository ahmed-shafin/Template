/**
 * Author: Name here
 * Date: 2018-07-06
 * License: CC0
 * Description: Ternary serach for finding minima/maxima of a unimodal continuous function\\
 * 200-300 iterations are sufficient
 * Time: O(logn)
 * Usage: If necessary
 */
double ternary_search(double l, double r) {
    double eps = 1e-9;              //set the error limit here
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);                    //return the maximum of f(x) in [l, r]
}
