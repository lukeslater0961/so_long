#So_Long Project Readme
Overview
Welcome to the So_Long project! So_Long is a simple 2D game implemented in C using the MinilibX graphics library. The goal of the game is to navigate through a map, collect items, and reach the exit while avoiding obstacles. It's a great project for learning and practicing graphics programming in C.


Features
Basic game mechanics (player movement, item collection, and exit reaching).
Dynamic rendering with the MinilibX library.
Support for different maps and levels.
Minimalistic design for easy understanding.
How to Compile
To compile the So_Long project, follow these steps:

Clone the repository to your local machine:

bash
Copy code
git clone https://github.com/your-username/so_long.git
Navigate to the project directory:

bash
Copy code
cd so_long
Compile the project using the provided Makefile:

bash
Copy code
make
How to Run
Once the project is successfully compiled, you can run the game with the following command:

bash
Copy code
./so_long maps/your_map_file.ber
Replace your_map_file.ber with the name of the map file you want to play.

Map Format
So_Long uses a simple map format represented in a .ber file. Each character in the file represents a different element:

'1': Wall
'0': Empty space
'C': Collectible item
'E': Exit
'P': Player's starting position
Example map:

plaintext
Copy code
1111111
1000C01
1P000E1
1000C01
1111111
