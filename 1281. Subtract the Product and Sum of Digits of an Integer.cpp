int subtractProductAndSum(int n) {
        int sum = 0;
        int prod = 1;

        for(int d = n; d > 0; d /= 10){
            sum += (d % 10);
            prod *= (d % 10);
        }

        return prod - sum;
    }
