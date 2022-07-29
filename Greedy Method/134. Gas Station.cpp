class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumgas=0;
            int sumcost=0;
            
            for(int i = 0;i<gas.size();i++)
            {
                    sumgas+=gas[i];
                    sumcost+=cost[i];
            }
            if(sumgas < sumcost)
                    return -1;
            int start=0,cur=0;
            for(int i=0;i<gas.size();i++)
            {
                    cur  = cur + (gas[i]-cost[i]);
                    if(cur < 0)
                    {
                            start=i+1;
                            cur=0;
                    }   
                    
            }
            return start;
    }
};
