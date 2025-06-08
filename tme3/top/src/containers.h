#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

#include "GPL_2_text.h"

using namespace std;

namespace vector_bench { 

    void backInsert(){
        
        vector<string> vec;
        const char ** data = GPL_2_text;

        //insert data in vector
        while(*data != NULL)
        {
            vec.push_back(*data);
            data++;
        }

        //print nb of elmts
        cout << "vector contains " << vec.size() << " words" << endl;

        //sort vector
        sort(vec.begin(), vec.end());

        //print all elmts of vector
        size_t i;

        for(i = 0; i < vec.size() ; i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }

    /* this functions has to insert elements in the front
        but the vector class doesn't have push_front method
        
        However vector posseses an begin interator and we can use the insert method with it
        so we can insert an element at the front
    */
    void frontInsert(){

        const char ** data = GPL_2_text;
        vector<string> vec;

        //insert data
        while(*data !=  NULL){

            vec.insert(vec.begin(), *data);
            data++;
        }

        //print nb of elmts
        cout << "vector contains " << vec.size() << " words" << endl;

        //sort vector
        sort(vec.begin(), vec.end());

        //print all elmts of vector
        size_t i;

        for(i = 0; i < vec.size() ; i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;

    }


    void sortEachInsert(){

        vector<string> vec;
        const char ** data = GPL_2_text;

        //insert data in vector
        while(*data != NULL)
        {
            vec.push_back(*data);

            //sort vector after each insertion
            sort(vec.begin(), vec.end());
            
            data++;
        }

        //print nb of elmts
        cout << "vector contains " << vec.size() << " words" << endl;

        //print all elmts of vector
        size_t i;

        for(i = 0; i < vec.size() ; i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;

    }

}

namespace list_bench {

    void back_insert(){

    }

    void front_insert(){

    }

    void sortEachInsert(){
        
    }
}

namespace map_bench{

    void back_insert(){

    }

    void front_insert(){

    }

    void sortEachInsert(){
        
    }
}