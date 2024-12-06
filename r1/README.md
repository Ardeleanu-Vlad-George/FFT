# Purpose
Learn the very basics of the FFT, by implementing in an unfussy language, with no third party libraries and code that is very modular and easy 
 to read and understand. The language of choice is ISO C99, the implementation is done for a vector read from a file hardcoded into 'main.c' 
 the output is written to another hardcoded file. No input checks need to be done, the input is coherent and FFT compatible.
Certain extra procedures like dividing the final result by a number or rearranging the vector to have the Nyquist in the centre weren't done
 to make the implementation that much easier.
Improving the project doesn't mean adding extra features, but making the code even easier to understand or read.
This is the branch in which you will attempt the above task.
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
(40.000000,0.000000)
(8.000000,-18.000000)
(-12.000000,-0.000000)
(8.000000,18.000000)
+++++++++++++++++++++++
```
Which is correct according to one source and to WolframAlpha, the sign difference can be explained away by the value of the first root of unity
 which is influenced by the way the 'SIGN' macro is defined (-1 for the first source, 1 for WolframAlpha).
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
