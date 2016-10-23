using namespace std;

class NotTwo{
	public:
		int f(int h,int w)
		{
			if(h*w%2==0)
				return h*w/2;
			else
				return h*w/2+1;
		}

		int maxStones(int width, int height)
		{
			int w1,w2,h1,h2;
			if(width%2==0)
				w1=width/2,w2=width/2;
			else
				w1=width/2,w2=width/2+1;
			if(height%2==0)
				h1=height/2,h2=height/2;
			else
				h1=height/2,h2=height/2+1;
			return f(h1,w1)+f(h1,w2)+f(h2,w1)+f(h2,w2);
		}
};
