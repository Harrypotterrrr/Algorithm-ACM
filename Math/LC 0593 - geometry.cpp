/************************************************
Problem: 		593. Valid Square
Algorithm: 		Math, Geometry
Difficulty: 	*
Importance:		*
Remark:			
*************************************************/

// Solution 1:

class Solution {
public:
    
    const double epsilon = 1e-9;

    double dist_square(vector<int>&p, vector<int>&q){
        return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
    }
    
    double double_eq(double &a, double &b){
        return fabs(a - b) <= epsilon;
    }
    
    double double_lt(double &a, double &b){
        return a - b > epsilon;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        double diag, side;
        
        vector<vector<int>>points = {p1, p2, p3, p4};
        for(int i=0 ; i<4 ; i++){
            auto test_p = points[i];
            auto other_1 = points[(i+1)%4];
            auto other_2 = points[(i+2)%4];
            auto other_3 = points[(i+3)%4];
            if(i == 0){
                double tmp1 = dist_square(test_p, other_1);
                double tmp2 = dist_square(test_p, other_2);
                double tmp3 = dist_square(test_p, other_3);
                if(double_lt(tmp1, tmp2)){
                    if(!double_eq(tmp2, tmp3)) return false; 
                    diag = tmp1;
                    side = tmp2;
                }
                else if(double_lt(tmp2, tmp3)){
                    if(!double_eq(tmp1, tmp3)) return false; 
                    diag = tmp2;
                    side = tmp1;
                }
                else{
                    if(!double_eq(tmp1, tmp2)) return false; 
                    diag = tmp3;
                    side = tmp1;
                }
                if(double_eq(diag, side)) return false;
            }
            else{
                double tmp1 = dist_square(test_p, other_1);
                double tmp2 = dist_square(test_p, other_2);
                double tmp3 = dist_square(test_p, other_3);
                if(double_lt(tmp1, tmp2)){
                    if(!double_eq(tmp2, tmp3)) return false;
                    if(!double_eq(tmp2, side)) return false;
                    if(!double_eq(tmp1, diag)) return false;
                }
                else if(double_lt(tmp2, tmp3)){
                    if(!double_eq(tmp1, tmp3)) return false;
                    if(!double_eq(tmp1, side)) return false;
                    if(!double_eq(tmp2, diag)) return false;
                }
                else{
                    if(!double_eq(tmp1, tmp2)) return false;
                    if(!double_eq(tmp1, side)) return false;
                    if(!double_eq(tmp3, diag)) return false;     
                }
            }
        }
        return true;
    }
};

// Solution 2: side number

class Solution {
public:
    
    const double epsilon = 1e-9;

    double dist_square(vector<int>&p, vector<int>&q){
        return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
    }
    
    double double_eq(double &a, double &b){
        return fabs(a - b) <= epsilon;
    }
    
    double double_lt(double &a, double &b){
        return a - b > epsilon;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        double diag, side;
        unordered_map<double, int> uM;
        vector<vector<int>>points = {p1, p2, p3, p4};
        
        for(int i=0 ; i<4 ; i++){
            for(int j=0 ; j<4 ; j++){
                if(i == j) continue;
                double dist = dist_square(points[i], points[j]);
                uM[dist]++;
            }
        }
        if(uM.size() != 2 || uM[0]) return false;
        bool side_num = false, diag_num = false;
        for(auto &[dist, num]: uM){
            if(num == 8) side_num = true;
            else if(num == 4) diag_num = true;
        }
        return side_num && diag_num;
    }
};