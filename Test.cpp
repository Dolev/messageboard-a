#include "Board.hpp"
#include "doctest.h"
#include <string>

using namespace std;
using namespace ariel;
Board board;
//check empty words
TEST_CASE("Check Empty bulletin board")
{
    CHECK(board.read(50, 50, Direction::Horizontal, 4) == string("____"));
    CHECK(board.read(50, 50, Direction::Vertical, 5) == string("_____"));
    CHECK(board.read(50, 51, Direction::Horizontal, 1) == string("_"));
    CHECK(board.read(90, 28, Direction::Horizontal, 18) == string("__________________"));
    CHECK(board.read(20, 35, Direction::Horizontal, 6) == string("______"));
    CHECK(board.read(90, 28, Direction::Horizontal, 10) == string("__________"));
    CHECK(board.read(90, 28, Direction::Horizontal, 9) == string("_________"));
    CHECK(board.read(30, 40, Direction::Horizontal, 2) == string("__"));
    CHECK(board.read(50, 50, Direction::Horizontal, 0) == string(""));
    CHECK(board.read(50, 50, Direction::Vertical, 1) == string("_"));
    CHECK(board.read(50, 50, Direction::Horizontal, 2) == string("__"));
    CHECK(board.read(50, 50, Direction::Vertical, 3) == string("___"));
    
}
TEST_CASE("Check my board")
{


    /*
    My Board:
    __________________________________________________________
         0  1  2  3  4  5  6  7  8  9  10  11
     0   s  i  n  c  e
     1            o          
     2            h  m  n  d  y
     3            p  i     h
     4            u  l  d  o  l  e  v
     5            s  k  u  d  e  n  t
     6   n  a  m  e  y     e      
     7            r        e
     8                     D  o  n  e
     9            K  i  n  g
     10     
     _______________________________________________________
    */
    CHECK_NOTHROW(board.post(4, 5, Direction::Horizontal, "dolev"));
    CHECK_NOTHROW(board.post(2, 6, Direction::Vertical, "Shareef"));
    CHECK_NOTHROW(board.post(0, 0, Direction::Horizontal, "since"));
    CHECK_NOTHROW(board.post(0, 3, Direction::Vertical, "computer"));
    CHECK_NOTHROW(board.post(2, 3, Direction::Horizontal, "hindy"));
    CHECK_NOTHROW(board.post(5, 3, Direction::Horizontal, "student"));
    CHECK_NOTHROW(board.post(6, 0, Direction::Horizontal, "name"));
    CHECK_NOTHROW(board.post(2, 4, Direction::Vertical, "milky"));
    CHECK_NOTHROW(board.post(8, 6, Direction::Horizontal, "Done"));
    CHECK_NOTHROW(board.post(9, 3, Direction::Horizontal, "King"));
    CHECK_NOTHROW(board.post(4, 4, Direction::Horizontal, " "));
}
TEST_CASE("read after paste")
{
    CHECK(board.read(4, 5, Direction::Horizontal, 5) == string("dolev"));
    CHECK(board.read(2, 6, Direction::Vertical, 7) == string("Shareef"));
    CHECK(board.read(0, 0, Direction::Horizontal, 5) == string("since"));
    CHECK(board.read(0, 3, Direction::Vertical, 8) == string("computer"));
    CHECK(board.read(2, 3, Direction::Horizontal, 9) == string("hindy"));
    CHECK(board.read(5, 3, Direction::Horizontal, 4) == string("student"));
    CHECK(board.read(6, 0, Direction::Horizontal, 4) == string("name"));
    CHECK(board.read(5, 6, Direction::Vertical, 4) == string("reef"));
    CHECK(board.read(3, 3, Direction::Vertical, 4) == string("put"));
    CHECK(board.read(2, 5, Direction::Vertical, 4) == string("p_Ru"));
    CHECK(board.read(2, 5, Direction::Vertical, 5) == string("p_Ru_"));
    CHECK(board.read(2, 4, Direction::Vertical, 5) == string("milky"));
    CHECK(board.read(8, 6, Direction::Horizontal, 4) == string("Done"));
    CHECK(board.read(2, 8, Direction::Horizontal, 4) == string("test"));
    CHECK(board.read(9, 3, Direction::Horizontal, 4) == string("King"));
    CHECK(board.read(4, 4, Direction::Horizontal, 4) == string(" "));
}
