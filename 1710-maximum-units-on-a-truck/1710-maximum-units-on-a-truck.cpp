class Solution {
public:
    static bool comparator(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comparator);
        int nbUnits = 0;
        int idx = 0;
        while(truckSize && idx < boxTypes.size()){
            if(boxTypes[idx][0] <= truckSize){
                nbUnits += boxTypes[idx][0] * boxTypes[idx][1];
                truckSize -= boxTypes[idx][0];
            }else{
                nbUnits += truckSize * boxTypes[idx][1];
                truckSize = 0;
            }
            idx++;
        }
        return nbUnits;
    }
};