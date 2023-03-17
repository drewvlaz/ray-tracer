#include <iostream>

#include "Geometry.h"

int main() {
    Tuple v1(1, 2, -3, 1);
    Tuple v2(4.5, 5, 6, 1);

    Tuple v3 = v1 + v2;
    std::cout << v3.x << ", " << v3.y << ", " << v3.z << ", " << v3.w << std::endl;

    Tuple v4 = v1 - v2;
    std::cout << v4.x << ", " << v4.y << ", " << v4.z << ", " << v4.w << std::endl;

    Tuple v5 = -v1;
    std::cout << v5.x << ", " << v5.y << ", " << v5.z << ", " << v5.w << std::endl;

    Tuple v6 = v1 * 2;
    std::cout << v6.x << ", " << v6.y << ", " << v6.z << ", " << v6.w << std::endl;

    Tuple v7 = v1 / 2;
    std::cout << v7.x << ", " << v7.y << ", " << v7.z << ", " << v7.w << std::endl;

    Tuple v8(1, 2, 3, 0);
    std::cout << v8.magnitude() << std::endl;

    std::cout << v8.normalize().magnitude() << std::endl;
    
    return 0;
}
