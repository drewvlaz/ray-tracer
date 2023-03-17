#ifndef GEOMETRY_H
#define GEOMETRY_H

class Tuple {
public:
    double x;
    double y;
    double z;
    double w;  // w = 0 denotes vector, w = 1 denotes point

    Tuple();
    Tuple(double x, double y, double z, double w);

    Tuple operator+(const Tuple& v);
    Tuple operator-(const Tuple& v);
    Tuple operator-();
    Tuple operator*(const double& s);
    Tuple operator/(const double& s);
    bool operator==(const Tuple& v);

    double magnitude();
    double squareMagnitude();
    Tuple normalize();
    double dot(const Tuple& v);
    Tuple cross(const Tuple& v);

private:
    // Fast inverse square root (with the original comments from Quake III Arena)
    // https://en.wikipedia.org/wiki/Fast_inverse_square_root
    double fastInverseSqrt(double x) {
        long i;
        float x2, y;
        const float threehalfs = 1.5F;

        x2 = x * 0.5F;
        y  = x;
        i  = * ( long * ) &y;                       // evil floating point bit level hacking
        i  = 0x5f3759df - ( i >> 1 );               // what the fuck? 
        y  = * ( float * ) &i;
        y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
        //	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

        return y;
    }
};

#endif

