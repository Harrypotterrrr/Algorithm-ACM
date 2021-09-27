/*
359. Logger Rate Limiter
*/

class Logger {
public:
    unordered_map<string, int>uM;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(uM.find(message) == uM.end() || timestamp >= uM[message]){
            uM[message] = timestamp + 10;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */