#include "Box.h"

Box testFunction( Box ab)
{
    std::cerr << " + testFunction() called." << std::endl;
    Box area ( "area", 0, 0, 15, 50);
    if (area.intersect(ab) ){
       std::cout << "intersection" << std::endl;
    } else
        std::cout << " No intersection" << std::endl;
    return ab;
}

int main()
{
    Box b0;
    Box b1 ("b1", 16, 16, 30, 20);
 
    
    testFunction(b1);

    b1.inflate(5,5,5,5);
    testFunction(b1);

    b1.inflate(-11);

    return 0;
}