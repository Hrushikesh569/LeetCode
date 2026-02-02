class RideSharingSystem {
public:
    queue<int>rider;
    queue<int>driver;
    int flag[1001]{};

    RideSharingSystem() {
        
    }
    void addRider(int riderId) {
        rider.push(riderId);
        flag[riderId] = 1;
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
     //   cout<<rider.front()<<" "<<driver.front();
     while(rider.size()>0 && flag[rider.front()]==0)
        rider.pop();
        if(!rider.empty()  && !driver.empty())
        {
          //  cout<<"asd"; 
          
            int x = rider.front();
            int y = driver.front();
             rider.pop();
            driver.pop();
            flag[x]  = 0 ; 
           return {y,x};
        }

        return {-1,-1};
    }
    
    void cancelRider(int riderId) {
        if(flag[riderId])
        {
            flag[riderId] = 0 ; 
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */