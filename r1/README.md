# Purpose
Learn the very basics of the FFT, by implementing in an unfussy language, with no third party libraries and code that is very modular and easy 
 to read and understand. The language of choice is ISO C99, the implementation is done for a vector read from a file hardcoded into 'main.c' 
 the output is written to another hardcoded file. No input checks need to be done, the input is coherent and FFT compatible.
<strikethrough>
Certain extra procedures like dividing the final result by a number or rearranging the vector to have the Nyquist in the centre weren't done
 to make the implementation that much easier.
Improving the project doesn't mean adding extra features, but making the code even easier to understand or read.
</strikethrough>
The last two ideas got scrapped in this branch, for it's purpose is to implement the post FFT operations that would be used in image 
 processing.
# Bonus
None
# MadeWith
- GCC; version 9.4.0
- GNU Make; version 4.2.1
- ISO C99
# ExampleOfUsage
For the input:
```
|data.in|
++++++++++
4
11 22 3 4
++++++++++

```
We get the following output:
```
|data.out|
+++++++++++++++++++++++
4
(176.127479,0.000000)
(208.062732,0.000000)
(255.000000,0.000000)
(208.062732,0.000000)
+++++++++++++++++++++++
```
# FurtherExplanations
## FFT algorithm
<!--
Not good enough, to delete or improve
Understanding the FFT algorithm is easier once concrete examples are considered and not abstract scenarios. As hypothetical, let's consider the following vector of four elements: (a, b, c,d). It's length already is a power of 2, so next step is to reorder it: (a, c, b, d).
First the vector is divided into a series of separate elements as such: ((a), (c), (b), (d)). For each consecutive non-overlapping pair of elements, the next BFS(ButterFly Schema) is applied:
```
    e0 = e0 + e1*pwr_4(4)
    e1 = e0 + e1*pwr_4(4)
```
Where:
- _e0_ is the first element of the constructed pair;
- _e1_ is the second element of the constructed pair;
- _pwr\_4_ is a shorthand notation that symbolizes the 
-->
