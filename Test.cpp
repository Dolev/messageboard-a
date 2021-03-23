
#include "doctest.h"
#include "Board.hpp"
using namespace ariel;

#include <string>
using namespace std;


TEST_CASE("just a test") {
    Board board;
    CHECK_NOTHROW(board.post(100,200,Direction::Horizontal,"abcd"));
    CHECK_NOTHROW(board.post(99,202,Direction::Vertical,"xyz"));
    CHECK_NOTHROW(board.post(95,198,Direction::Vertical,"___"));
    CHECK_NOTHROW(board.post(70,170,Direction::Horizontal,"fdfh"));
    CHECK_NOTHROW(board.post(69,182,Direction::Vertical,"abc"));
    //5
    CHECK_NOTHROW(board.post(55,50,Direction::Vertical,"_____"));
    CHECK_NOTHROW(board.post(100,200,Direction::Horizontal,"abz"));// should return - abzd (overwrite the same)
    CHECK_NOTHROW(board.post(99,202,Direction::Vertical,"xyz"));
    CHECK_NOTHROW(board.post(95,198,Direction::Horizontal,"       "));
    CHECK_NOTHROW(board.post(10,198,Direction::Horizontal,"ewrfe"));
    //10
    CHECK_NOTHROW(board.post(30,40,Direction::Vertical," ")); //change to "_" -> " "
    CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"abc"));
    CHECK_NOTHROW(board.post(99,2,Direction::Vertical,"yu"));
    CHECK_NOTHROW(board.post(95,191,Direction::Horizontal,"xdsadsadas"));
    CHECK_NOTHROW(board.post(95,138,Direction::Vertical,"___"));
    //15 read tests
    CHECK_NOTHROW(board.read(99,201,Direction::Vertical,3));//prints "_b_"
    CHECK_NOTHROW(board.read(99, 2,Direction::Vertical,2));// should return - =="yu"
    CHECK_NOTHROW(board.read(100,200, Direction::Horizontal,4));// =="abzd"
    CHECK_NOTHROW(board.read(93,196,Direction::Vertical,3));// =="__ "
    CHECK_NOTHROW(board.read(99,202,Direction::Horizontal,3));// =="x__"
    
    //20
    /* Add more checks here */
}
