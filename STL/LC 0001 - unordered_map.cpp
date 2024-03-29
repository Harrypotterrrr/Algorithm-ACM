/*
1. Two Sum
*/

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> M;
       
        for(int i=0 ; i < nums.size() ; i++){
            auto j = M.find(target - nums[i]);
            if(j != M.end())
                return {i, j->second};
            M[nums[i]] = i;
        }
        return {};
    }
};

// Solution 2: struct sort

class Solution {
public:

    struct Arr{
        int value;
        int id;
        Arr(int _value, int _id) : value(_value), id(_id){}
        static bool cmp(Arr &a, Arr &b){
            return a.value < b.value;
        }
    };
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<Arr>arr;
        for(int i=0 ; i<nums.size() ; i++){
            arr.emplace_back(nums[i], i);
        }
        
        sort(arr.begin(), arr.end(), Arr::cmp);
        
        int left = 0 , right = nums.size() - 1;
        while(left < right){
            if(arr[left].value + arr[right].value > target)
                right --;
            else if(arr[left].value + arr[right].value < target)
                left ++;
            else
                break;
        }
        return vector<int>({arr[left].id, arr[right].id});
    }
};


void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        vector<int> ret = Solution().twoSum(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}