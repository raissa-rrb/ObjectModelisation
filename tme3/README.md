# STL containers and iterators  : list, map, vector

The aim of this lab is to compare the execution time of different operations
- back insertion + sorting + counting nb of elements + displaying all elements
- front insertion + sorting + counting nb of elements + displaying all elements
- back insert and sorting after each insertion + counting nb of elements + displaying all elements

Regarding front and back insertion the execution times are pretty much the same for the vector and the list, with the vector taking a little more time than the lists.
- on average
    - back insertion :
        - vector : 0.2
        - list : 0.15
      - front insertion :
          - vector : 0.4
          - list : 0.3
  The main difference is more noticeable with the insert + sort
- vector : around 2.5 secs
- list : around 1.5 sec

The map's execution time is always 0.1 sec (so it kinda win)

So what's happening: 

- Vectors are indexed arrays, inserting and deleting an object is in O(n) because then evrything has to be shifted, thus the slightly longer time but accessing data is in O(1)
- Lists are doubly inked list, accessing a value is in O(n) but the inserting and deleting is constant
- Maps are dictionnaries, the values are sorted when inserted, it's fast, but they take a lot of memeory
