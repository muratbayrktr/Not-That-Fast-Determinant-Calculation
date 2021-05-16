# fast-determinant-calculation  
Trying a new algorithm to calculate determinant in a fast way.  

It uses next_permutation algorithm the compute the next permutation in O(n).  

By doing so,  

detA = SUM[ +- a1x*a2y*a3z ... anbeta ],  

x , y , z ... beta  are the permutations of the 1,2 ... n  (which next permutation calculates at every iteration).   
