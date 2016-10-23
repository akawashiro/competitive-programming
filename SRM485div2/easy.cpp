class MicrowaveSelling{
		public:
				int mostAttractivePrice(int minPrice, int maxPrice);
};

int MicrowaveSelling::mostAttractivePrice(int minPrice, int maxPrice)
{
		int max9=0;
		int price=0;
		for(int i=minPrice;i<=maxPrice;i++){
				if(maxPrice<=9 && 9<=maxPrice){
						max9=1;
						price=9;
				}
				for(int j=10,k=1;j<i;j*=10,k++){
						if(i%j*10/j!=9)
								break;
						if(max9<=k){
								max9=k;
								price=i;
						}
				}
		}
		if(price==0)
				price=maxPrice;
		return price;
}

