string destCity(vector<vector<string>>& paths) {
        {
            unordered_map<string, string> umap;
            for(const auto& path : paths)
                umap[path[0]] = path[1];       
            
            for(const auto& [_, destination] : umap)
                if(umap.count(destination))
                    continue;
                else
                    return destination;
        }
        
        return "";
    }

string destCity(vector<vector<string>>& paths) {
        {
            unordered_set<string> cityA;
            for(const auto& path : paths)
                cityA.insert(path[0]);       
            
            for(const auto& path : paths)
                if(cityA.find(path[1]) == cityA.end())
                    return path[1];
        }

        return "";
    }
