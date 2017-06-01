#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;
int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int dist[(1<<15)][10][10];

class TurningMaze 
{
	public:

		bool can(char c,char d)
		{
			if(c=='B' || d=='B')
				return false;
			else if(c==d)
				return true;
			else if(c=='A' || d=='A')
				return true;
			else
				return false;
		}

		int minTime(vector <string> maze) 
		{
			printf("\n");
			fflush(stdout);

			int h=maze.size(),w=maze[0].size();
			for(int i=0;i<(1<<15);i++)
				for(int j=0;j<10;j++)
					for(int k=0;k<10;k++)
						dist[i][j][k]=(1<<28);
			queue<pair<pair<int,int>,int> > que;
			que.push(make_pair(make_pair(0,0),0));

			while(!que.empty())
			{
				int m=que.front().first.first;
				int y=que.front().first.second/w;
				int x=que.front().first.second%w;
				int d=que.front().second;
				que.pop();

				//printf("m=%d y=%d x=%d d=%d\n",m,y,x,d);
				//fflush(stdout);

				if(0<=y && y<h && 0<=x && x<w && d<dist[m][y][x])
				{
					//printf("d<dist[m][y][x]\n");
					//fflush(stdout);

					if(y==h-1 && x==w-1)
						return d;
					dist[m][y][x]=d;

					vector<string> vs=maze;
					for(int i=0;i<h;i++)
						if(m&(1<<i))
							for(int j=0;j<w;j++)
							{
								char c=vs[i][j];
								if(c=='C')
									vs[i][j]='D';
								if(c=='D')
									vs[i][j]='C';
							}
					for(int i=0;i<w;i++)
						if(m&(1<<i+h))
							for(int j=0;j<h;j++)
							{
								char c=vs[j][i];
								if(c=='C')
									vs[j][i]='D';
								if(c=='D')
									vs[j][i]='C';
							}
					
					//printf("convert\n");
					//fflush(stdout);

					for(int i=0;i<4;i++)
					{
						int yy=y+mv[i][0],xx=x+mv[i][1];
						if(i<2 && 0<=yy && yy<h && (vs[y][x]=='C' || vs[y][x]=='A')
							 	&& (vs[yy][xx]=='C' || vs[yy][xx]=='A'))
							que.push(make_pair(make_pair(m,yy*w+xx),d+1));
						if(1<i && 0<=xx && xx<w && (vs[y][x]=='D' || vs[y][x]=='A') && (vs[yy][xx]=='D' || vs[yy][xx]=='A'))
							que.push(make_pair(make_pair(m,yy*w+xx),d+1));
					}
					int mm=m;
					mm=(mm^(1<<y));
					mm=(mm^(1<<(x+h)));
					que.push(make_pair(make_pair(mm,y*w+x),d+1));
				}
			}

			return -1;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { string Arr0[] = {"AA", "AA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minTime(Arg0)); }
		void test_case_1() { string Arr0[] = {"AAA", "BBA", "AAA", "ABB", "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(1, Arg1, minTime(Arg0)); }
		void test_case_2() { string Arr0[] = {"AAACAAA", "BBBBBBA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(2, Arg1, minTime(Arg0)); }
		void test_case_3() { string Arr0[] = {"ACDCDCA", "BBBBBBA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(3, Arg1, minTime(Arg0)); }
		void test_case_4() { string Arr0[] = {"CA", "BA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, minTime(Arg0)); }
void test_case_5() { string Arr0[] = {"CAA", "DAA", "ACA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(5, Arg1, minTime(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	TurningMaze ___test;
	___test.run_test(-1);
}
// END CUT HERE
