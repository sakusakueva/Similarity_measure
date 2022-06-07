# Similarity measure of template matching 
The similarity calculation of the template matching method is summarized.
We plan to add the latest methods in the future.

## What is the template matching ?
Template matching is a method that scans a template image with the input image, calculates the similarity at each position in the input image, and detects the position with the largest similarity (or above a threshold value).

## Implemented similarity measure
* Sum of Abusolute Difference (SAD)
* Sum of Squared Difference (SSD)
* Normalized Cross-Correlation (NCC)
* Zero-means Normalized Cross-Correlation (ZNCC)

## Requirement
* c++17
* OpenCV 3.4.3


## Repository clone 
Please clone the source code.<br>

~~~
$ git clone https://github.com/sakusakueva/Similarity_measure.git
$ cd Similarity_measure
~~~

## Compile and Run
~~~
$ make
$ ./similarity 
~~~

## Author
* Sakura Eba
* Chukyo University, Japan.
* Lab URL: http://asmi.sist.chukyo-u.ac.jp/m1/eba/
 
## License
"ImageToCo-occurrenceProbability" is under [MIT license](https://en.wikipedia.org/wiki/MIT_License).