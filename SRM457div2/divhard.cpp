class TheHexagonsDivTwo{
	public:

		long long calc(int color[7],int tempNums[9])
		{
			int nums[9];
			long long r=1;
			for(int i=0;i<9;i++)
				nums[i]=tempNums[i];
			for(int i=0;i<7;i++){
				r*=nums[color[i]];
				nums[color[i]]--;
			}
			return r;
		}


		long long count(int n, int k)
		{
			int color[7];
			long long ans=0;
			int nums[9];
			for(int i=0;i<9;i++)
				nums[i]=0;
			for(int i=1;i<=n;i++)
				nums[i%k]++;

			for(int n0=0;n0<k;n0++){
				for(int n1=0;n1<k;n1++){
					if(n1 == n0) 	continue;
					for(int n2=0;n2<k;n2++){
						if(n2 == n1) continue;
						for(int n3=0;n3<k;n3++){
							if(n3 == n2)	continue;
							for(int n4=0;n4<k;n4++){
								if(n4 == n3)	continue;
								for(int n5=0;n5<k;n5++){
									if(n5 == n4 || n5 == n0)	continue;
									for(int n6=0;n6<k;n6++){
										if(n6 == n0 || n6 == n1 || n6 == n2|| n6 == n3 || n6 == n4 || n6 == n5)	continue;
										color[0]=n0,color[1]=n1,color[2]=n2,color[3]=n3,color[4]=n4,color[5]=n5,color[6]=n6;
										ans+=calc(color,nums);
									}
								}
							}
						}
					}
				}
			}

			return ans/6;
		}
};
