#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

class FixImage 
{
	public:

		int h,w;
		int image[60][60];

		void show()
		{
			for(int i=0;i<h;i++)
			{
				for(int j=0;j<w;j++)
				{
					if(image[i][j]==3000)
						printf("N");
					else
						printf("%c",(image[i][j]!=-1)?char(image[i][j]+'a'):'.');
				}
				printf("\n");
			}
		}

		int color()
		{
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
					if(image[i][j]!=-1)
						image[i][j]=3000;
			int c=0;
			for(int sy=0;sy<h;sy++)
				for(int sx=0;sx<w;sx++)
					if(image[sy][sx]==3000)
					{
						queue<int> que;
						que.push(sy*60+sx);
						while(!que.empty())
						{
							int y=que.front()/60,x=que.front()%60;
							que.pop();
							if(image[y][x]==3000)
							{
								image[y][x]=c;
								if(y<h-1 && image[y+1][x]==3000)
									que.push((y+1)*60+x);
								if(0<y && image[y-1][x]==3000)
									que.push((y-1)*60+x);
								if(x<w-1 && image[y][x+1]==3000)
									que.push(y*60+x+1);
								if(0<w && image[y][x-1]==3000)
									que.push(y*60+x-1);
							}
						}
						c++;
					}

			//show();

			return c;
		}

		void fill(int c)
		{
			for(int y=0;y<h;y++)
			{
				int left,right;
				for(left=0;left<w;left++)
					if(image[y][left]==c)
						break;
				for(right=w-1;0<=right;right--)
					if(image[y][right]==c)
						break;
				for(int x=left;x<=right;x++)
					image[y][x]=c;
			}
			for(int x=0;x<w;x++)
			{
				int bottom,ceil;
				for(bottom=0;bottom<h;bottom++)
					if(image[bottom][x]==c)
						break;
				for(ceil=h-1;0<=ceil;ceil--)
					if(image[ceil][x]==c)
						break;
				for(int y=bottom;y<=ceil;y++)
					image[y][x]=c;
			}
		}

		vector <string> originalImage(vector <string> alteredImage) 
		{
			h=alteredImage.size(),w=alteredImage[0].size();
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
					image[i][j]=(alteredImage[i][j]=='.')?-1:3000;
			for(int time=0;time<50;time++)
			{
				int n=color();
				for(int i=0;i<=n;i++)
					fill(i);
			}
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
					alteredImage[i][j]=(image[i][j]==-1)?'.':'#';
			return alteredImage;
		}

		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
		void test_case_0() { string Arr0[] = {"##...#...#.##########################.##.#######..", "....####...##########################.###..#######", "#...####.############################..#...######.", "#...####.############################.......####.#", "#...###..##################################.###.#.", "##..###..###################################...#.#", "##..###.####################################.##.#.", ".#..###.####################################...###", "........######################################...#", ".##############################################..#", ".##############################################.#.", "################################################..", "#################################################.", "#################################################.", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", "##################################################", ".#################################################", "#.################################################", "#...##############################################"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"....", ".##.", ".##.", "...." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, originalImage(Arg0)); }
		void test_case_1() { string Arr0[] = {".....",
			".###.",
			".#.#.",
			".###.",
			"....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".....", ".###.", ".###.", ".###.", "....." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, originalImage(Arg0)); }
		void test_case_2() { string Arr0[] = {".......",
			".###...",
			".#..##.",
			".###.#.",
			".....#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".......", ".###...", ".#####.", ".#####.", ".....#." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, originalImage(Arg0)); }
		void test_case_3() { string Arr0[] =  {".................",
			"#####.#..#..#####",
			"..#...#..#....#..",
			"..#...#..###..#..",
			"................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".................", "#####.#..#..#####", "..#...#..#....#..", "..#...#..###..#..", "................." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, originalImage(Arg0)); }
		void test_case_4() { string Arr0[] =  {"###.####",
			"#.#.#..#",
			".#...#.#",
			".#####.#",
			"......#.",
			"########"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"########", "########", "########", "########", "########", "########" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, originalImage(Arg0)); }
		void test_case_5() { string Arr0[] = {"..###..",
			"..#.#..",
			"##...##",
			"#.....#",
			"#.....#",
			"#.....#",
			"##...##",
			"..#.#..",
			"..###.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..###..", "..###..", "##...##", "##...##", "##...##", "##...##", "##...##", "..###..", "..###.." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, originalImage(Arg0)); }

		// END CUT HERE


};

// BEGIN CUT HERE
int main() {
	FixImage ___test;
	___test.run_test(-1);
}
// END CUT HERE
