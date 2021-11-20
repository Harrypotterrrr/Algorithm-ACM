/************************************************
Problem: 		853. Car Fleet
Algorithm: 		Array, Sorting
Difficulty: 	*
Importance:		****
Remark:			merge two array to sort
*************************************************/

// Solution 1: merge sorting

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> vec;
        for(int i=0 ; i<n ; i++)
            vec.push_back({position[i], speed[i]});
        sort(vec.begin(), vec.end(), [](pair<int, int>&a, pair<int, int>&b){
            // doesn't need to, but it is useful for future
            // return a.first<b.first || (a.first == b.first && a.second < b.second);
            return a.first<b.first;
        });

        double t, pre = double(target - vec[n-1].first) / vec[n-1].second;
        int ans = 1;
        for(int i=n-2 ; i>=0 ; i--){
            t = double(target - vec[i].first) / vec[i].second;
            if(t > pre){
                ans ++;
                pre = t;
            }
        }
        return ans;
    }
};

// Solution 2: a little bit more elegant

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> vec;
        for(int i=0 ; i<n ; i++)
            vec.push_back({position[i], speed[i]});
        sort(vec.begin(), vec.end(), [](pair<int, int>&a, pair<int, int>&b){
            return a.first<b.first;
        });

        double t, pre = -1.0;
        int ans = 0;
        const double epsilon = 1e-9;
        for(auto it = vec.rbegin() ; it != vec.rend() ; it++){
            t = double(target - it->first) / it->second;
            if(t > pre + epsilon){
                ans ++;
                pre = t;
            }
        }
        return ans;
    }
};

// Solution 3: construct new struct

class Solution {
public:
    
    struct Car{
        int position;
        int speed;
        Car(int _pos, int _spe) :position(_pos), speed(_spe){}
        bool operator < (const Car & car){
            return position < car.position || (position == car.position && speed < car.speed);
        }
    };
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<Car>vec;
        for(int i=0 ; i<n ; i++)
            vec.emplace_back(position[i], speed[i]);
            // vec.push_back(Car(position[i], speed[i]));
        sort(vec.begin(), vec.end());

        double t, pre = -1.0;
        int ans = 0;
        const double epsilon = 1e-9;
        for(auto it = vec.rbegin() ; it != vec.rend() ; it++){
            t = double(target - it->position) / it->speed;
            if(t > pre + epsilon){
                ans ++;
                pre = t;
            }
        }
        return ans;
    }
};