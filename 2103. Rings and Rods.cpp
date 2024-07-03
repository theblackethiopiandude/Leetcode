int countPoints(string rings) {
        int count = 0;
        {
            unordered_map<int, unordered_set<char>> umap;
            for(int i = 1; i < rings.size(); i+=2)
                umap[rings[i]].insert(rings[i-1]);

            for(const auto& [_, roads] : umap)
                if(roads.size() == 3) count++;
        }
        return count;
    }
