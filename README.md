Lem_in
======

This is a repository for our work on the lem_in project of the 42 school

Structure
=========
+ neighbour - struct
    + id - int
    + next - ptr

+ room - struct
    + name - str
    + ant_id - int
    + distance_to_end - int
    + neighbours_ids - chained list of neighbour (NULL terminated)

+ lem_in - struct
    + number_of_ants - int
    + start_id - int
    + end_id - int
    + rooms - struct of room (NULL terminated)

Authors
=======
+ mguerrea
+ mparigi
