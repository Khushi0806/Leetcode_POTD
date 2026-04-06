class Solution {
public:

    vector<int> move(int n,char dir,set<vector<int>>& st,int r,int c){
        int row=r;
        int col=c;
        int moves=0;
        if(dir=='N'){
            while(moves<n && st.find({col,row+1})==st.end()){
                moves++;
                row++;
            }
        }
        else if(dir=='E'){
            while(moves<n && st.find({col+1,row})==st.end()){
                moves++;
                col++;
            }
        }
        else if(dir=='S'){
            while(moves<n && st.find({col,row-1})==st.end()){
                moves++;
                row--;
            }
        }
        else{
            while(moves<n && st.find({col-1,row})==st.end()){
                moves++;
                col--;
            }
        }
        return{row,col};
    }

    char setdir(int x,char dir){
            if(x==-1){
                if(dir=='N')    return 'E';
                else if(dir=='E')    return 'S';
                else if(dir=='S')    return 'W';
                else return 'N';  
            }
            else{
                if(dir=='N')    return 'W';
                else if(dir=='E')    return 'N';
                else if(dir=='S')    return 'E';
                else return 'S'; 
            }
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int maxdist=0;
        set<vector<int>> st;
        for(auto t:obstacles){
            st.insert(t);
        }
        int r=0;
        int c=0;
        int start=0;
        char dir='N';
        for(int i=0;i<commands.size();i++){
            start=1;
            if(commands[i]==-1||commands[i]==-2){
                dir=setdir(commands[i],dir);
                continue;
            }
            vector<int> pos=move(commands[i],dir,st,r,c);
            r=pos[0];
            c=pos[1];
            maxdist=max(maxdist,r*r+c*c);
        }
        return maxdist;
    }
};
