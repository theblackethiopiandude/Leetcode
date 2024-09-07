bool checkStraightLine(vector<vector<int>>& coordinates) {
        bool vertical = false;
        float y = (coordinates[1][1] - coordinates[0][1]);
        float x = (coordinates[1][0] - coordinates[0][0]);

        if(x == 0){
            vertical = true;
            x = 1;
        }
        
        const float slope = y / x;

        for(int i = 2; i < coordinates.size(); i++){
            float xdiff = coordinates[i][0] - coordinates[i-1][0];
            float ydiff = coordinates[i][1] - coordinates[i-1][1];


            if(vertical && xdiff == 0)
                continue;

            if((xdiff == 0 && ! vertical) || ydiff/xdiff != slope)
                return false;
        }
        return true;
    }
