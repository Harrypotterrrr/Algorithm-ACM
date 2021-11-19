/************************************************
Problem: 		489. Robot Room Cleaner
Algorithm: 		Search, DFS
Difficulty: 	**
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

// Solution 1: 



// Solution 2: Random ..

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