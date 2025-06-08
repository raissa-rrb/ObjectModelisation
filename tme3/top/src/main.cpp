#include "containers.h"
#include "timer.h"


void test_vector(){

    Timer timer0;
    Timer timer1;
    Timer timer2;

    cout << "--back insert--" << endl;
    //vector
    timer0.start();
    vector_bench::backInsert ();
    timer0.stop();
    std::cout << timer0 << endl;
    /* execution time is around 0.2 seconds  (around 10 execs)*/
    cout << endl;

    cout << "--front insert--" << endl;
    timer1.start();
    vector_bench::frontInsert ();
    timer1.stop();
    std::cout << timer1 << endl;
    /* execution time is around 0.35 seconds  (around 10 execs)*/
    cout << endl;

    cout << "--sort insert--" << endl;
    timer2.start();
    vector_bench::sortEachInsert();
    timer2.stop();
    std::cout << timer2 << endl;
    /* execution time is minimum 2 seconds  (around 10 execs)*/
    cout << endl;
}


void test_list(){

    Timer timer0;
    Timer timer1;
    Timer timer2;


    //vector
    cout << "--back insert--" << endl;
    timer0.start();
    list_bench::backInsert ();
    timer0.stop();
    std::cout << timer0 << endl;
    /* execution time is around 0.2 seconds  (around 10 execs)*/
    cout << endl;

    cout << "--front insert--" << endl;
    timer1.start();
    list_bench::frontInsert ();
    timer1.stop();
    std::cout << timer1 << endl;
    /* execution time is around 0.3 seconds  (around 10 execs)*/
    cout << endl;
    
    cout << "--sort insert--" << endl;
    timer2.start();
    list_bench::sortEachInsert();
    timer2.stop();
    std::cout << timer2 << endl;
    /* execution time is around 1.4 seconds  (around 10 execs)*/
    cout << endl;
}

int main ( int argc, char* argv[] )
{

   /// cout << "-----------------Vector Test-----------------" << endl;
   /// test_vector();
   /// cout << "-----------------List Test-----------------" << endl;
   /// test_list();
   /// cout << "-----------------Map Test-----------------" << endl;

    Timer timer3;
    timer3.start();
    map_bench::insertAndCount();
    timer3.stop();
    std::cout << timer3 << endl;
    //execution time is aorund 0..1 sec



    return 0;
}