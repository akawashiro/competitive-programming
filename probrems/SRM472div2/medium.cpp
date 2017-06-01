//this is copy
#include <string>

using namespace std;

class PotatoGame
{
public:
    string theWinner( int n );
};

string PotatoGame::theWinner( int n )
{
    return n%5==1 || n%5==3 || n%5==4 ? "Taro" : "Hanako";
}

