class Solution {
public:
    double calc(pair<int, int> a, pair<int, int> b){
        return ((double)(a.first - b.first) / (double)(a.second - b.second));
    }
    bool areInline(pair<int, int> a, pair<int, int> b, pair<int, int> c){
        return (calc(a, b) == calc(b, c));
    }
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() < 2){
            return points.size();
        }
        int maxPoints = 0;
        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                int nbPoints = 2;
                if(points[i][0] == points[j][0]){
                    for(int k = j + 1; k < points.size(); k++){
                        if(points[k][0] == points[i][0]){
                            nbPoints++;
                        }
                    }
                }else if(points[i][1] == points[j][1]){
                    for(int k = j + 1; k < points.size(); k++){
                        if(points[k][1] == points[i][1]){
                            nbPoints++;
                        }
                    }
                }else{
                    for(int k = j + 1; k < points.size(); k++){
                        if(areInline({points[i][0], points[i][1]}, 
                                     {points[j][0], points[j][1]}, 
                                     {points[k][0], points[k][1]})){
                            nbPoints++;
                        }
                    }
                }
                maxPoints = max(maxPoints, nbPoints);
            }
        }
        return maxPoints;
    }
};