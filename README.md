# fast-determinant-calculation  
Trying a new algorithm to calculate determinant in a fast way.  

It uses next_permutation algorithm the compute the next permutation in O(n). I added swap count   
in order to store the swaps so that we can infer whether the permutation is even or odd.    
With this way, I could implement the big formula for the determinant calculation.  


By doing so,  

detA = SUM[ +- a1x*a2y*a3z ... anbeta ],  

x , y , z ... beta  are the permutations of the 1,2 ... n  (which next permutation calculates at every iteration).  

```
$ ./determinantcalc < input.txt 
-83550
Program took 0.000227 seconds to execute
```

