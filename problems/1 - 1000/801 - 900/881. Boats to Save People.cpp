class Solution {
public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        int sz = people.size();
        std::sort(people.begin(), people.end());

        int l = 0, r = sz - 1, boats = 0;
        while(l <= r) {
            if(people[l] + people[r] <= limit) {
                ++l; --r; ++boats;
            }
            else {
                --r; ++boats;
            }
        }

        return boats;
    }
};
