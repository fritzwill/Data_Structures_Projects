Will Fritz
4/26/2017

From the user's perspective, te program is supposed to accept input that describes one ore more graphs. Th input also describes potential paths within these graphs. The program is supposed to output whether these spcific paths exist within their respective graphs. The output looks like the following:
    In Graph 1 there is a path from A to B
    In Graph 2 there is no path from B to A
The prgram is essentially supposed to return whether paths exist in a certain graph given the graph and the potential paths.

From the programmer's perspective, a 'typedef map<string, vector<string>> Graph' is used to create a adjacency list representation of each graph. The main function begins by with a while(getline(cin, line)) statement. This is used to make sure that the program reads all of the input from stdin. Within this while loop, the contents of the input is parsed/ The first value is used to determine the number of edges of the current graph/ This number is used to start a for loop from 0 to that specific number. Within this for loop a istringstream object is used to access each specific word on the line. The first word from the stream is used as the source string, while the second is the destination string. This pair is inserted into the newGraph using newGraph[src].push_back(dest). This allows for source nodes to have multiple destination nodes (just like in a graph). After the for loop is complete and the graph is populated, the program continues to parse the input data by taking in the next line. This nex tline is used to determine the numer of paths that are to be checked. This is used to create a for loop from 0 to that number. This for loop is used to check whether the paths inserted exist. istringstream is used again to make sure that the words from each ine can be read into the variables source and destination. Within this loop, the helper function isPath is called. If this function returns ture then, the program outputs that there is a pth, if is false then the program outputs that there is not a specific path between the source and destination given. After this lopp completes, the program continues to read in graphs and paths until the eof is met (or ctrl-d is pressed). 

As stated earlier, a map was used to implement the Graphs using the adjacency list method. The function isPath is passed a Graph like this along with a string that is meant to be the source and second string that is meant to be the destination. This function utilizes an iterative depth-first search to find whether there is a path between the given source and destination. The psuedocode for that is:

DFS_Iter(src, dest, graph):
    frontier = []
    marked = {}
    frontier.push(src)
    while not frontier.empty():
        src = frontier.pop()
        if src in marked:
            continue
        if src == dest:
            return true
        marked.inser(src)
        for u in g[src]:
            frontier.push(u)

I evaluated the program by first using custom tests to make sure the output was exactly correct. Then, I used the provided Makefile and ran make test. This didn't produce any erros, so the program was took verified for its output, memory, and time. Overall, the program produces the correct results for the given inputs and for some custom inputs. 
