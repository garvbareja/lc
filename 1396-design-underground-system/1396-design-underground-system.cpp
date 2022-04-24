class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> checkedin;
    unordered_map<string,pair<long long,int>> avg;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkedin[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string station=checkedin[id].first+"-"+stationName;
        if(!avg.count(station)) avg[station]={0,0};
        avg[station].first+=(t-checkedin[id].second);
        avg[station].second+=1;
        checkedin.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string station=startStation+"-"+endStation;
        double tt=avg[station].first;
        double n=avg[station].second;
        return tt/n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */