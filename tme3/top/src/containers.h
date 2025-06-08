#include <vector>
#include <list>
#include <map>
#include <algorithm> //to sort the vector
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

    void backInsert(){

        const char ** data = GPL_2_text;
        list<string> list;

        //insert words in list
        while(*data != NULL)
        {
            list.push_back(*data);
            data++;
        }

        //print nb of elements in list
        cout << "list contains " << list.size() << endl;

        //sort list elmts
        list.sort();

        //print elmnts
        for(string s : list)
            cout << s << " ";
        cout << endl;
    }

    //list contains a push front method actually
    void frontInsert(){
        const char ** data = GPL_2_text;
        list<string> list;

        while(*data != NULL)
        {
            list.push_front(*data);
            data++;
        }

        //print nb of elements in list
        cout << "list contains " << list.size() << endl;

        //sort list elmts
        list.sort();

        //print elmnts
        for(string s : list)
            cout << s << " ";
        cout << endl;
    }

    void sortEachInsert(){

        const char ** data = GPL_2_text;
        list<string> list;

        while(*data != NULL)
        {
            list.push_back(*data);

            //sort after each insert
            list.sort();

            data++;
        }

        //print nb of elements in list
        cout << "list contains " << list.size() << endl;

        //print elmnts
        for(string s : list)
            cout << s << " ";
        cout << endl;

        
    }
}

namespace map_bench{
/* map will be used to count how many times a word appears
    here's the algorithm

        //check if word in map 
            //if yes
                //increment word counter
            //if not 
                //add word
        // print nb of elmts
        // calcultate total nb of words 

regarding the insertion, i coudl've checked with contains(key) if the word was in the map
but actually contains(key) does the same (checks if the word is there) and if it is it directly 
returns the iterator which will enable me to increment the key's counter.
*/
    void insertAndCount()
    {
        const char ** data = GPL_2_text;
        map<string, int> mymap;

        //insert
        while(*data != NULL)
        {       
            map<string, int>::iterator it_found = mymap.find(*data);
            if(it_found != mymap.end())
            {   
                it_found->second++;
            } else {
                mymap.insert({*data,1});
            }
            data++;
        }

        // print nb of elmts
        cout << "map contains " <<  mymap.size() << " words" << endl;

        // display all elmts count + words " "
        map<string,int>::iterator itCur = mymap.begin();

        for(; itCur != mymap.end() ; itCur++)
        {
            cout << itCur->first << " " << itCur->second << " ¦ " ;
        }
        cout << endl;

        // calcultate total nb of words 
        size_t sum = 0;
        for(itCur = mymap.begin(); itCur != mymap.end() ; itCur++)
        {
            sum += itCur->second  ;
        }

        cout << "total number of words is " << sum << endl;

    }
}