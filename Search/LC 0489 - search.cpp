/************************************************
Problem: 		489. Robot Room Cleaner
Algorithm: 		Search, DFS, Backtracking, Graph, Iteractive, Random
Difficulty: 	***
Importance:		*****
Remark:			
*************************************************/

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

// Solution 1: Backtracking, DFS

class Solution {
public:
    
    void cleanRoom(Robot& robot) {
        unordered_map<int, int> graph;
        int move[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // up, right, around, left
        enum graph_type {visited, wall};
        
        function<int(int, int)> hash = [](int x, int y){
            return (y+200)*200 + (x+100);
            // not valid: (x+100) * 100 + (y+200) cuz the x range of 100 smaller than y range of 200 !
        };
        function<bool(int)>  operate = [&robot](int k){
            if(k == 0) ;
            else if(k == 1) robot.turnRight();
            else if(k == 2) {robot.turnRight(); robot.turnRight();}
            else robot.turnLeft();
            bool flag = robot.move(); //
            return flag;
        };
        function<void(int)>  deoperate = [&robot](int k){
            if(k == 0) ;
            else if(k == 1) robot.turnLeft();
            else if(k == 2) {robot.turnRight(); robot.turnRight();}
            else robot.turnRight();
        };
        function<void(int)>  demove = [&robot, &deoperate](int k){
            robot.turnRight();robot.turnRight();
            robot.move();
            robot.turnRight();robot.turnRight();
            deoperate(k);
        };
        function<void(int, int, int)> dfs = [&](int x, int y, int towards){
            for(int i=0 ; i<4 ; i++){
                int next_towards = (i+towards)%4;
                int next_x = x + move[next_towards][0];
                int next_y = y + move[next_towards][1];
                int next_hash = hash(next_x, next_y);
                if(graph.find(next_hash) == graph.end()){ // new grid found
                    if(!operate(i)) {
                        graph[next_hash] = wall;
                        deoperate(i);
                    }
                    else{
                        robot.clean();
                        graph[next_hash] = visited;
                        dfs(next_x, next_y, next_towards);
                        demove(i);
                    }
                }
            }
        };
        
        graph[hash(0, 0)] = visited;
        robot.clean();
        dfs(0, 0, 0);
    }
};

// Solution 2: much more elegant

class Solution {
public:
    
    void cleanRoom(Robot& robot) {
        unordered_set<int> graph;
        int move[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // up, right, around, left
        
        function<int(int, int)> hash = [](int x, int y){
            return (y+200)*200 + (x+100);
        };
        
        function<void(void)> demove = [&robot](){
            robot.turnRight(); robot.turnRight();
            robot.move();
            robot.turnRight(); robot.turnRight();
        };
        
        function<void(int, int, int)> dfs = [&](int x, int y, int towards){
            graph.insert(hash(x, y));
            robot.clean();
            for(int i=0 ; i<4 ; i++){
                int next_towards = (i+towards)%4;
                int next_x = x + move[next_towards][0];
                int next_y = y + move[next_towards][1];
                int next_hash = hash(next_x, next_y);
                if(graph.find(next_hash) == graph.end() && robot.move()){
                    dfs(next_x, next_y, next_towards);
                    demove();
                }
                robot.turnRight();
            }
        };
        
        dfs(0, 0, 0);
    }
};

// Solution 3: Random ..

class Solution {
public:
    void cleanRoom(Robot& robot) {
        int r, flag = true;
        for(int i=0 ; i<1000000 ; i++){
            robot.clean();
            if(!flag){
                r = rand() % 2;
                flag = true;
            }
            else r = rand() % 3;
            switch(r){
                case 0:
                    robot.turnLeft(); break;
                case 1:
                    robot.turnRight(); break;
                case 2:
                    break;
            }
            flag = robot.move();
        }
    }
};


