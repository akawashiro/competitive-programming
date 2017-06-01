#include <vector>
#include <string>
using namespace std;

class SequenceOfCommands{
	public:
		string whatHappens(vector <string> commands){
			string c;
			for(int i=0;i<commands.size();i++)
				c+=commands[i];
			string c4=c+c+c+c;

			int x=0,y=0;
			char degree='F';
			for(int i=0;i<c4.size();i++){
				if(c4[i]=='S'){
					if(degree=='F')	y++;
					else if(degree=='L')	x++;
					else if(degree=='B')	y--;
					else if(degree=='R')	x--;
				}
				else if(degree=='R'){
					if(degree=='F')				degree='L';
					else if(degree=='L')	degree='B';
					else if(degree=='B')	degree='R';
					else if(degree=='R')	degree='F';
				}
				else if(degree=='L'){
					if(degree=='F')				degree='R';
					else if(degree=='R')	degree='B';
					else if(degree=='B')	degree='L';
					else if(degree=='L')	degree='F';
				}
			}
			if(x==0 && y==0)
				return "bounded";
			else
				return	"unbounded";
		}
};
