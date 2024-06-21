int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        const int n=customers.size();
        int satisfied=0, nosat=0;
        for(int i=0; i<minutes; i++){
            satisfied+=(1-grumpy[i])*customers[i];
            nosat+=grumpy[i]*customers[i];
        }
        // Sliding window to find max_add for max nosat
        int max_add=nosat;
        for (int i = minutes; i < n; i++) { 
            satisfied += (1-grumpy[i])*customers[i];
            nosat+=grumpy[i]*customers[i]-grumpy[i-minutes]*customers[i-minutes];
            max_add = max(max_add, nosat);
        }
        return satisfied+max_add;
    }
