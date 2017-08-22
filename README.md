# STL-Iterators-and-Algorithms-in-C++

The project contains one file Assignment5.cpp which contains the following functions:-

 1. bool is_palindrome(const std::string & phrase)
    that receives a string as parameter and determines whether the received string is a palindrome using algorithm remove_copy_if,   
    transform and equal_to.
 
 2. template <class Iterator>
    std::pair<Iterator,bool> second_max(Iterator start, Iterator finish)
    - to find the second largest element in a container within a given range [ start , finish ), where start  and finish are iterators 
      that provide properties of forward iterator.
 
 3. void print_word_frequency(const std::string &filename)
    utilizes a map<string, int> class to model a word frequency list:  list of words (keys) together with their frequency
    of occurrence (values) within a given text.
    
 4. void print_word_frequency2(const std::string &filename)
    utilizes a map<string, int,MyCompare> class to model a word frequency list: a list of words (keys) together with their 
    frequency   of occurrence (values) within a given text in alphabetic order.
    
 5.void print_word_index(const std::string &filename)
   Use a map<string, set<int>, MyCompare> for storing the words and their associated line numbers(uses set).
   
   --Contains the main function and test functions to test the working of above mentioned functions.
