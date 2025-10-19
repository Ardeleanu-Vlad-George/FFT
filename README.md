# Purpose
Store the implementation of 3 Fast Fourier Transform (FFT) algorithms: 
1. one-dimensional: FFT applied to a vector read from a text file
2. two-dimensional: FFT applied to a matrix read from a text file
2. 1. practical use of the two-dimensional one: FFT applied to an image read from the disk
The 3 algorithms are stored in the './dimensions/' folder, with the third one being stored in './dimensions/2/prac/'.
The './common/' directory contains code that is used in all of the 3 programs. 
See the README of each directory for more details.
~~~~ 
Because the one-dimensional and practical example from the two-dimensional folder have errors compared to the previous
non-stiched versions of the same projects, the entire project is on a temporary pause, the README-s will be the final
addition, minimal work will be done on the code.
The errors most likely occur because of 'floating point rounding errors' even though you've used the 'long double' 
data type, and it should've helped you, but it wasn't good enough, so the most likely solution will be a custom data 
type for the real numbers.
~~~~ 
The above text was wrong, the error was thanks to your temporarily defined PI constant, adding more digits after the 
comma improved the precision for the one-dimensional case and it giving the same answer as the non-stiched project.
Checking on the two-dimensional case, the accuracy was maintained.
The image generated in the 'prac/' folder was looked more accurate, but on closer inspection, it had an error on the 
green component of the Nyquist pixel. Since said pixel is the most important for reconstruction trough the reverse FFT
it is of utmost importance to find the misstake.
Maybe you just need more digits for PI.
