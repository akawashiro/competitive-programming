class LateProfessor
{
public:
double getProbability(int waitTime, int walkTime, int lateTime, int bestArrival, int worstArrival)
{
if(worstArrival==bestArrival){
	int a=0;
	a+=waitTime;
	if(bestArrival<=a)
		return 0;
	while(1){
		a+=walkTime-lateTime;
		if(bestArrival<=a)
			return 1;
		a+=waitTime+lateTime;
		if(bestArrival<=a)
			return 0;
	}
}
int ac=0,ng=0;
int time=0;
for(time;time<waitTime;time++)
	if(bestArrival<=time && time<worstArrival)
		ac++;
if(worstArrival<=time)
	return (double)ng/(double)(ac+ng);
while(1){
	int a=time;
	for(time;time<a+walkTime-lateTime;time++)
		if(bestArrival<=time && time<worstArrival)
			ng++;
	if(worstArrival<=time)
		return (double)ng/(double)(ac+ng);
	a=time;
	for(time;time<a+waitTime+lateTime;time++)
		if(bestArrival<=time && time<worstArrival)
			ac++;
	if(worstArrival<time)
		return (double)ng/(double)(ac+ng);
}
}
};
