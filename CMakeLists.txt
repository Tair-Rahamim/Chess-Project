cmake_minimum_required(VERSION 3.27)
project(Chess_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Chess_Project
        Bishop.cpp
        Bishop.h
        GameBoard.cpp
        GameBoard.h
        general.h
        King.cpp
        King.h
        Knight.cpp
        Knight.h
        main.cpp
        Pawn.cpp
        Pawn.h
        Piece.cpp
        Piece.h
        Pipe.h
        Queen.cpp
        Queen.h
        Rook.cpp
        Rook.h
        Source.cpp
        stdafx.cpp
        stdafx.h
        targetver.h)
