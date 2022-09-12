class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int start = 0, end = tokens.size() - 1;
        int score = 0;
        int maxScore = 0;
        sort(tokens.begin(), tokens.end());
        while(start <= end){
            if(power >= tokens[start])
            {
                score++;
                maxScore = max(maxScore, score);
                power -= tokens[start];
                start++;
            }
            else if(score)
            {
                power += tokens[end];
                end--;
                score--;
            }
            else
            {
                break;
            }
        }
        return maxScore;
    }
};