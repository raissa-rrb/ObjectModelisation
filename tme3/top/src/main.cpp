#include "containers.h"
#include "timer.h"

using namespace vector_bench;

int main ( int argc, char* argv[] )
{
    Timer timer0;
    Timer timer1;
    Timer timer2;

    timer0.start();
    backInsert ();
    timer0.stop();
    std::cout << timer0 << endl;
    /* execution time is minimum 0.1 seconds  (around 10 execs)*/

    
/*     timer1.start();
    frontInsert ();
    timer1.stop();
    std::cout << timer1 << endl; */
    /* execution time is around 0.35 seconds  (around 10 execs)*/

/*     timer2.start();
    sortEachInsert();
    timer2.stop();
    std::cout << timer2 << endl; */
    /* execution time is minimum 2 seconds  (around 10 execs)*/

    return 0;
}