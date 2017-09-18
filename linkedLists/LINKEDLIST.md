From the users perspective, the program should be able to take in any two positive integers and add them together. This output is then displayed to the user. An 'input' file is included so that this can be demonstrated for a few numbers. After using the command 'make', the user can then use the command: 'solution < input' to rest the demonstartion numbers. The file 'output' is included to show the correct output the program should show. 

From the programmer's perspective, linked lsts are used to store each digit of the inpt integers. The linked list is created by using templated structs. There is a struct for a Node (which has a value and a pointer next) and a struct for List which just has a pointer called head, which points to a struct type Node. This List struct is then used to take in command line arguments until end of file. Each digit of the integer is stored in a node. The sum function is a public function which takes in two lists and adds seach digit one by one together (accounting for remainders) and then storing the output sum into a new list called outp. Once this list is populated it is printed

The program was evaluated for correctness by running it by myself multpile times. I implemented some prints of the inputs for debugging purposes and I used inputs with different sizes (345 and 23).

A test can be ran to check output, time, and memory by running 'make text'
