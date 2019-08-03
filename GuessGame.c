/*
1806
6801
2A2B
• 2linse of input having same size, 1 output.
-first line secret number
-second line commander guess.
• 2Arrow and 2 Bows. The Arrow is 8, the bows are 1 and 6.
• Our base array is 1806, comparing it with the second array, we see that two digits are at the same index, 8,0 so 2 Arrows.
• Though there are 2 more digits that are common between both arrays, their indices do not match so 2 Bows
1124
0111
1A1B
• The 1st 1 in commander's guess is arrow, the 2nd or 3rd 1 is a bow (same explanation as above)
*/

#include<stdio.h>
int function(int On,int Gn)
{
		int Ona[10]={0},Gna[10]={0},high=0;
		int i,j,count=0,bows=0,arrows=0;
		
		printf("%d  %d\n",On,Gn);
		for(i=3;i>=0&&On!=0;i--)
		{
		
			Ona[i]=On%10;
			On=On/10;
			
			count++;
			
		}
		high=count;
		count=0;
		for(i=3;i>=0&&Gn!=0;i--)
		{
			Gna[i]=Gn%10;
			Gn=Gn/10;
			count++;
		}
		if(high<count)
		{
			high=count;
		}
		for(i=0;i<4;i++)
		{
			printf("%d : %d  %d\n",i,Ona[i],Gna[i]);
		}
		for(i=0;i<10&&count>0;i++,count--)
		{
		if(Ona[i]==Gna[i])
		{
			arrows++;
		}
	    }
	    for(i=0;i<10&&count>0;i++,count--)
	    {
	    	for(j=0;j<4;j++)  
	    	{
	    		if(Ona[i]==Gna[j])
	    		{
	    			bows++;
				}
			}
		}
		if(arrows>0)
		{
			bows=bows-arrows;
		}
		printf("%dA%dB",arrows,bows);

	return 0;
}
void main()
{
    int ComGuess,CaesarGuess;

    	scanf("%d",&ComGuess);
    	scanf("%d",&CaesarGuess);
	
	function(ComGuess,CaesarGuess);
}
