# Union Find

The Union Find program is a disjoint-set data structure that takes an undirected graph and checks whether it has a cycle or not. The program has three header files––all with unique constructors and functions––which help to construct the Union Find data structure.

## Organization

The code is organized into three files: SetUF.h, UnionFind.h, Graph.h, and demo.cpp. This program also includes a Makefile. Inside the SetUF.h header file, one can find the SetUF class with all header methods for the functions. In that same file, the function definitions are included. The main purpose of SetUF is to create the sets. Afterwards, in UnionFind.h one can find the UnionFind class with all the header methods for the functions, which create the Union Find data structure. Function definitions are also included in the file. Lastly, Graph.h includes the Graph class with all header methods for functions. The main purpose of this file is to graph and determine if there is a cycle or not.

## Compiling and running code

To compile the code:
- Open Terminal
- Navigate towards the location of the files / Makefile.
- Type "make" onto the terminal.

To run the code:
- After compiling, type "./demo"

## Author

* **Matt Thompson** - *Union Find*