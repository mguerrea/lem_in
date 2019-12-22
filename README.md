Lem_in
======

This is a repository for our work on the lem_in project of the 42 school

Structure
=========
+ neighbour - struct
    + id   - int
    + nxt  - ptr

+ room - struct
    + name - char *
    + x    - int
    + y    - int
    + ant  - int
    + dist - int
    + adjs - chained list of neighbour (NULL terminated)

+ lem_in - struct
    + ant_nbr - int
    + strt    - int
    + end     - int
    + rooms   - struct of room (NULL terminated)


Authors
=======
+ mguerrea
+ mparigi
