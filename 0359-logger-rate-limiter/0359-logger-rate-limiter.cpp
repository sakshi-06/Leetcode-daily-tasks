class Logger {
public:
    unordered_map<string, int> mp;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(mp.find(message)!=mp.end()){
            int t = mp[message];
            if(timestamp>=t+10) {
                mp[message]=timestamp;
                return true;
            } else{
                return false;
            }
        } else{
            mp[message] = timestamp;
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