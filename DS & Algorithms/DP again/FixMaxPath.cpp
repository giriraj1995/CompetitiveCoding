int find(int i, int j, vector<vector<int> > &A) {
    if(i == A.size()-1 && j == A[0].size()-1)
        return 1;
    
    int x = 0;
    int y = 0;
    
    if((i+1 < A.size() && A[i+1][j] > A[i][j]) && (j+1 < A[0].size() && A[i][j+1] > A[i][j])) {
        x = find(i+1, j, A);
        y = find(i, j+1, A);
        
        if(x == -1 && y == -1)
            return -1;
        
        if(x == -1)
            return 1+y;
        
        if(y == -1)
            return 1+x;
        
        return 1+max(x,y);
        
    }else if(i+1 < A.size() && A[i+1][j] > A[i][j]){
        x = find(i+1, j, A);
        
        if(x == -1)
            return -1;
            
        return x+1;
        
    }else if(j+1 < A[0].size() && A[i][j+1] > A[i][j]) {
        y = find(i, j+1, A);
        
        if(y == -1)
            return -1;
            
        return y+1;
            
    }else{
        return -1;
    }
    
}

int Solution::solve(vector<vector<int> > &A) {
    return find(0,0,A);
}
