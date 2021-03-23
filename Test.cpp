
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
    CHECK_NOTHROW(board.post(100,200,Direction::Horizontal,"abc"));// should return - abcd (overwrite the same)
    CHECK_NOTHROW(board.post(99,202,Direction::Vertical,"xyz"));
    CHECK_NOTHROW(board.post(95,198,Direction::Vertical,"___"));
    CHECK_NOTHROW(board.post(95,198,Direction::Horizontal,"___"));
    //10
    CHECK_NOTHROW(board.post(30,40,Direction::Vertical," ")); //change to "_" -> " "
    CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"abc"));// should return - abcd (overwrite the same)
    CHECK_NOTHROW(board.post(99,2,Direction::Vertical,"yu"));
    CHECK_NOTHROW(board.post(95,191,Direction::Horizontal," "));
    CHECK_NOTHROW(board.post(95,138,Direction::Vertical,"___"));
    //15
    CHECK_NOTHROW(board.post(300,0,Direction::Vertical,"sd_dfgd"));
    CHECK_NOTHROW(board.post(100,200,Direction::Horizontal,"abc"));// should return - abcd (overwrite the same)
    CHECK_NOTHROW(board.post(2,0,Direction::Vertical,"xdsadsadas"));
    CHECK_NOTHROW(board.post(85,57,Direction::Horizontal,"ewewt"));
    CHECK_NOTHROW(board.post(0,300,Direction::Vertical,"saddas"));
    //20
    /* Add more checks here */
}
