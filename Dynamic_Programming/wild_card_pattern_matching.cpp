class Solution {
  public:
  
    bool solve(string &txt , string &abc , int currTxt , int currAbc){
        if(currTxt==txt.size()&&currAbc==abc.size()) return true;
        if(currTxt==txt.size()&&currAbc!=abc.size()) return false;
        if(currTxt!=txt.size()&&currAbc==abc.size()) return false;
        
        if(txt[currTxt]!=abc[currAbc]&&abc[currAbc]!='?'&&abc[currAbc]!='*') return false;
        
        bool a=false;
        bool b = false;
        if(txt[currTxt]==abc[currAbc] || abc[currAbc]=='?'){
           a = solve(txt , abc , currTxt+1 , currAbc+1);
        }
        else{
            // if abc[i]='*';
            for(int i=currTxt+1;i<=txt.size();i++){
                b = solve(txt , abc , i , currAbc+1);
                if(b) return true;
            }
        }
        return a||b;
    }
    
    
    bool solveMem(string &txt , string &abc , int currTxt , int currAbc , vector<vector<int>>&dp){
        if(currTxt==txt.size()&&currAbc==abc.size()) return true;
        if(currTxt==txt.size()&&currAbc!=abc.size()) return false;
        if(currTxt!=txt.size()&&currAbc==abc.size()) return false;
        
        if(txt[currTxt]!=abc[currAbc]&&abc[currAbc]!='?'&&abc[currAbc]!='*') return false;
        
        if(dp[currTxt][currAbc]!=-1){
            return dp[currTxt][currAbc];
        }
        
        bool a=false;
        bool b = false;
        if(txt[currTxt]==abc[currAbc] || abc[currAbc]=='?'){
           a = solveMem(txt , abc , currTxt+1 , currAbc+1 , dp);
        }
        else{
            // if abc[i]='*';
            for(int i=currTxt+1;i<=txt.size();i++){
                b = solveMem(txt , abc , i , currAbc+1 , dp);
                if(b) return true;
            }
        }
        return dp[currTxt][currAbc] = a||b;
    }
    
    bool wildCard(string &txt, string &pat) {
        // code here
        
      //  return solve(txt ,pat,0 , 0);
      
      vector<vector<int>>dp(txt.size()+1 , vector<int>(pat.size()+1 , -1));
      return solveMem(txt ,pat,0 , 0 , dp);
    }
};

// open https://www.geeksforgeeks.org/problems/wildcard-pattern-matching/1?page=1&sprint=24daafa10fb2e984858c0a965d12b11c&sortBy=submissions