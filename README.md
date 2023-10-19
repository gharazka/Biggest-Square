# Biggest-Square

## Description

The "Biggest Square" is a command-line program designed to find and visualize the largest square in a given map. The map consists of empty and obstacle characters. The program replaces the empty characters within the largest square with full characters and displays the modified map to help visualize the largest square. The biggest square is found using recursive backtracking algorithm.

## Features

Map Generation in Python:

    The project includes a Python script to generate maps. Users can easily create maps using the Python script using a random library, which provides flexibility in map creation.

Makefile for Easy Compilation:

    A Makefile is provided to simplify the compilation process. Users can build the C program by executing the 'make' command and run it with 'make out' command.

User Input for Map Creation:

    After executing the program, users are prompted to input the map's dimensions and specify the map by picking obstacle, empty and full characters.

Map Validation:

    The program checks for map errors, such as missing rows, inconsistent row lengths, or invalid characters, and provides feedback to the user if any errors are detected.

Largest Square Detection:

    The core functionality of the program is to find the largest square within the map that consists of empty characters. It uses a backtracking algorithm to identify the largest square and mark it with full characters.

Map Visualization:

    After identifying the largest square, the program replaces the empty characters within the square with full characters. The modified map is then displayed on the standard output for visualization.

## Tutorial:

    Run make to compile the C program.

    Execute make out to run the program.

    Follow the prompts to provide map dimensions and specify the map empty, full and obstacle characters.

    The program will validate the map and identify the largest square.

    The modified map with the largest square marked by full characters will be displayed.

## Example:
![obraz](https://github.com/gharazka/Biggest-Square/assets/148285170/d2b4ffcf-6c4b-4a99-9067-a1914e0f974c)
