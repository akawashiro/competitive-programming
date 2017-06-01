class DiceRotation {
public:
	int theCount(int gx, int gy) {
		int res=0;

		if(gx>=2 && gy>=2) res+=2;
		if(gx==4) res+=gy+1;
		if(gy==4) res+=gx+1;
		return res;
	}
};

