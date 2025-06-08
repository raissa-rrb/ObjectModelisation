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
