class DataStream {
private:
     int value=0;
     int k=0;
     int cnt=0;
public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        this->cnt = 0;
    }
    bool consec(int num) {
        
        if(num==value)
        {
            cnt++;
            if(cnt>=k)
            {
                
                return true;
            }
            else
            {
                
                return false;
            }
        }
        else
        {
           cnt =0;
            return false;
        }
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */