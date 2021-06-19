- A:
    - don't use floating point arithmetic whenever possible
    - use constants for special srings denoting players, events, etc.
- B:
    - multiplication is often better than division
    - multiplication can cause overflow
    - simulation is sometimes quick enough to pass
    - binary search over the answer
    - math-based solutions are error-prone, use margins if you are not sure

- C:
    - if counting objects in some set seems hard, try counting objects in the complement of this set
    - frequency tables are the most basic yet the most oftenly used data structures
    - use long integers whenever you are not sure about the possible range of some value, \*unless you are running short on memory
    
- D:
    - `const int MAXA = 200200;` is often safer than `const int MAXA = 200000;`
    - whenever you write some code twice, make it a template and save it to yor library
    - disjoint set union is useful for graph connectivity problems

- E:
    - sometimes it makes sense to switch between problems if you don't get useful ideas for some time

- F:
    - if you are already familiar with basic algorithms and data structures, you may find it useful reading about [Sprague-Grundy game theory(https://cp-algorithms.com/game_theory/sprague-grundy-nim.html)
