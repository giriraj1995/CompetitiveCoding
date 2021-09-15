int Solution::solve(vector<string> &A) {
    int n = A.size();
    int m = A[0].size();

    vector<set<int>>(m) red;
    vector<set<int>>(m) green;
    vector<set<int>>(m) blue;

    set<pair<int,int>> redall;
    set<pair<int,int>> greenall;
    set<pair<int,int>> blueall;

    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {

            if(A[i][j] == 'g'){
                green[j].insert(i);
                greenall.insert({i,j});
            }

            if(A[i][j] == 'r'){
                red[j].insert(i);
                redall.insert({i,j});
            }

            if(A[i][j] == 'b'){
                blue[j].insert(i);
                blueall.insert({i,j});
            }

        }
    }

    if(!(redall.size() > 0 && greenall.size() > 0 && blueall.size() > 0)) {
        return 0;
    }

    int ans = 0;

    for(int j = 0; j < m; j++) {
        if(green[j].size() > 0 && red[j].size() > 0) {
            int g1 = *(green[j].begin());
            int g2 = *(--(green[i].end()));
            int r1 = *(red[j].begin());
            int r2 = *(--(red[i].end()));

            for(int k = 0; k < m; k++) {
                if(blue[k].size() > 0 && k != j){
                    ans = max(ans, ceil(1/2.0 * (abs(g1-r2)+1) * (abs(k-j)+1)));
                    ans = max(ans, ceil(1/2.0 * (abs(g2-r1)+1) * (abs(k-j)+1)));
                }
            }
        }

        if(red[j].size() > 0 && blue[j].size() > 0) {
            int r1 = *(red[j].begin());
            int r2 = *(--(red[i].end()));
            int b1 = *(blue[j].begin());
            int b2 = *(--(blue[i].end()));

            for(int k = 0; k < m; k++) {
                if(green[k].size() > 0 && k != j){
                    ans = max(ans, ceil(1/2.0 * (abs(r1-b2)+1) * (abs(k-j)+1)));
                    ans = max(ans, ceil(1/2.0 * (abs(r2-b1)+1) * (abs(k-j)+1)));
                }
            }
        }

        if(blue[j].size() > 0 && green[j].size() > 0) {
            int b1 = *(green[j].begin());
            int b2 = *(--(green[i].end()));
            int g1 = *(red[j].begin());
            int g2 = *(--(red[i].end()));

            for(int k = 0; k < m; k++) {
                if(blue[k].size() > 0 && k != j){
                    ans = max(ans, ceil(1/2.0 * (abs(b1-g2)+1) * (abs(k-j)+1)));
                    ans = max(ans, ceil(1/2.0 * (abs(b2-g1)+1) * (abs(k-j)+1)));
                }
            }
        }
    }

    return ans;
}
