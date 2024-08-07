string intToRoman(int num) {
        string ans = "";
        {
            string n = to_string(num);
            const int size = n.length();
            unordered_map<int, char> umap = {
                {1, 'I'},
                {5, 'V'},
                {10, 'X'},
                {50, 'L'},
                {100, 'C'},
                {500, 'D'},
                {1000, 'M'},
            };
            unordered_map<int, int> pow = {
                {1, 1},
                {2, 10},
                {3, 100},
                {4, 1000},
            };
            for(int i = 0; i < n.length(); i++){
                if(n[i] == '0')
                    continue;
                else if(n[i] < '5'){
                    if(n[i] == '4'){
                        ans += umap[pow[size - i]];
                        ans += umap[5 * pow[size - i]]; 
                    }else{
                        for(int j = '0'; j < n[i]; j++)
                            ans += umap[pow[size - i]];
                    }
                }else if(n[i] > '5'){
                    if(n[i] == '9'){
                        ans += umap[pow[size - i]];
                        ans += umap[10 * pow[size - i]]; 
                    }else{
                        ans += umap[5 * pow[size - i]];
                        for(int j = '5'; j < n[i]; j++)
                            ans += umap[pow[size - i]];
                    }
                }else{
                    ans += umap[5 * pow[size - i]];
                }
            }
        }
        return ans;
}

string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};

        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
}
