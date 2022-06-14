class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
		//m= lenght of word1 string & n is also
        
		int dp[m+1][n+1];
		//created m and n size table
		
        for(int i=0;i<=m;i++)
            dp[i][0]=0;
		//first column is seted to zero	
		
          for(int i=0;i<=n;i++)
            dp[0][i]=0;
        //first row is seted to zero
		//because initially no common sequence
		
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
				//here i compared last elements of both string
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
					//if its same then we added +1 to last result
                else
                {
	
                    dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
		//here i found dp[m][n] which is common sequence and then i substracted it from both string length and we get result
        int sum = (m- dp[m][n])+(n-dp[m][n]);
                return sum;
    }
};