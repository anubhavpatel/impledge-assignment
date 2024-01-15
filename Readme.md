## Word Composition Problem

### Execution Steps
1) Clone the repo into your local pc.
2) Open it into your visual studio editor.
3) Run the file WCP.cpp(c++ ompiler must be installed in your pc).
4) Input files must be in the same folder.
5) Output will print in the console.
6) Change input file name (input_01.txt or input_02.txt) as required in program in line 145.

### Approach
-> Sort all the words given through the standard input in ascending order in terms of their length (using a custom Comparator). <br />
-> Then,Remove the longest word from the sorted list of words.  <br />
-> Find the shortest prefix of this word that is a compound word.  <br />
-> If such one exists, find out if the remainder of the word is a compound word also. <br /> 
-> If so, then this word is the longest compound word, otherwise, repeat these steps. <br />
### Implementation
-> I have made a class "Result" which contains all the functions required by the program. <br />
-> Then I write the code to read from the file which contains the input. <br />
-> Now I store that input in a vector "result". <br />
-> Then I made a function "Longest_word_finder" which prints the longest and  second longest compounded word. <br />

### Overview 
-> I used Trie data structure its a special tree that stores strings.The complexity of creating a trie is O(W*L), where W is the number of words, and L is an average      length of the word: you need to perform L lookups on the average for each of the W words in the set and sorting time complexity is O(WlogW). <br />
-> Initially I called "Longest_word_finder" function through the Solution class and  the words in a trie and then sort the vector so that we have the longest words at    the starting and the smallest words at the end of the vector which will eventually help in finding our answer. In the Longest_word_finder function we made two          strings Longest and second longest compounded word. <br />
-> Now I iterate in the vector which stores all the input string so that I can access all the words. And then in loop I called a function "obj" which mark the flag as    false of the current word. <br />
-> After that I called a function "isformed", which will search whether the given word can be formed by using two or more words from all the given words. <br />
-> If the function "isformed" return true, then that word would be a possible answer. <br />
-> At last I call function "initialize" to mark the flag of the given word as true again.  <br />
-> Then I print both the strings. <br />








