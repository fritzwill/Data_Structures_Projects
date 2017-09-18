Report.txt for mst.cpp

    From the user's perspective the program is supposed to accept info on a graph from stdin. After the user inputs the graph the program is mean to print the total weight of the minimum spanning tree and then print the edges of the minimum spannin tree such as AB in lexicographical order. So the user should be able to directly send info of a graph to the program and then the program produces the output as described above. THe user must input the data in thefollowing format:

    NVERTICES
    -1 -1 ...
    -1 -1 ...
    ...

Where each member of the distance matrix is separated by a space

    From the program's perspective only a mian function is used. Main begins with the program accepting from stdin, and filling a 2D matrix with the info given by the user. Since the user inputs the nEdges, this is used to create each dimension of the 2D matrix. This dist matrix is then filled in with the data offered by the user. An istringstream is used to get each number in the line that the user inputs (this works since the numbers are separated by a space). After this arrays are created for the MST, the min weight of each vertice, and a collection of the vertices not in the MST (which ones were visited).Then a for loop is used (with two other for loops inside) to find the minimum key of the vertex that hasn't been used. This is done making sure the vertices was not visted, and the key at specific location is less than the minimum vale (which starts essesntially at infinity). If thats the case, then the minimun value is changed and the index at that location is noted. Then the vetices is marked as visted by altering the visited array. Then that index is used to check every colum in the row of the minIndex. If any of these values is less than the key at the same column, then the mst array at the loaction of the column is given the value minIndex. Then the key is set to the value in the distance matrix at the location (minIndex, column). After this is done for every row, the total weigth of the MST is calculated. THis is done by using the following code: tot += dist[i][mst[i]] where i starts with 1 and is increadeed until i = nEdges. THis essentially adds the wieghts of the MST. then a list of char pairs is created called edges. The mst array is used to fill this list with the correct lettes. THen the letter paris are placed in ascending order. Finally, the edges list is sorted, and each pair is displayed. THen the program checks if there is another line. If there is it restarts by reading in the new graph and if there is not then the program ends.

The correctness of this was checked by using cout at speciifc locations to see if the program was performing the right calculations. Finally after debugging enough, make test was run to test the output, time, and memeory of the program  

