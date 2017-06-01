#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>

using namespace std;
int mv[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

class PiecesMover 
{
	public:

		int nP;

		bool check(vector<int> pos)
		{
			vector<string> board(5,string(5,'.'));
			for(int i=0;i<nP;i++)
				board[pos[i]/5][pos[i]%5]='*';

			int connected=0;
			queue<int> que;
			que.push((pos[0]/5)*5+pos[0]%5);
			while(!que.empty())
			{
				int y=que.front()/5,x=que.front()%5;
				que.pop();
				if(board[y][x]!='*')
					continue;
				connected++;
				board[y][x]='#';
				for(int i=0;i<4;i++)
				{
					int yy=y+mv[i][0],xx=x+mv[i][1];
					if(yy<0 || 4<yy || xx<0 || 4<xx)
						continue;
					que.push(yy*5+xx);
				}
			}

			return (connected==nP);
		}

		int getMinimumMoves(vector <string> board) 
		{
			nP=0;
			vector<int> first;
			for(int i=0;i<5;i++)
				for(int j=0;j<5;j++)
					if(board[i][j]=='*')
						first.push_back(i*5+j),nP++;

			map<vector<int>,int> used;
			queue<pair<vector<int>,int> > que;
			que.push(make_pair(first,0));

			while(!que.empty())
			{
				vector<int> v=que.front().first;
				int d=que.front().second;
				que.pop();

				if(used.find(v)!=used.end())
					continue;
				else if(check(v))
					return d;
				else
				{
					used[v]=d;
					for(int i=0;i<nP;i++)
						for(int j=0;j<4;j++)
						{
							vector<int> vv=v;
							int y=vv[i]/5+mv[j][0],x=vv[i]%5+mv[j][1];
							if(y<0 || 4<y || x<0 || 4<x)
								continue;
							vv[i]=y*5+x;
							int k;
							for(k=0;k<nP;k++)
								if(k!=i && vv[i]==vv[k])
									break;
							if(k==nP)
								que.push(make_pair(vv,d+1));
						}
				}
			}

			return -1;
		}


		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { string Arr0[] = {".....",
			"..**.",
			".....",
			"...*.",
			"....."}
			; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, getMinimumMoves(Arg0)); }
			void test_case_1() { string Arr0[] = {".....",
				".....",
				".**..",
				".*...",
				"**..."}
				; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getMinimumMoves(Arg0)); }
				void test_case_2() { string Arr0[] = {"*...*",
					".....",
					".....",
					".....",
					"*...*"}
					; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(2, Arg1, getMinimumMoves(Arg0)); }

					// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	PiecesMover ___test;
	___test.run_test(-1);
}
// END CUT HERE
