class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {

     sort(events.begin(),events.end());
     priority_queue<int,vector<int>,greater<int>> minHeap;
     int i=0;
     int count=0;
     int lastDay=0;
     for(auto i: events){
        lastDay=max(lastDay,i[1]);
     }

   for(int j=1;j<=lastDay;j++){

    while(i<events.size() && events[i][0]==j){
        minHeap.push(events[i][1]);
        i++;
    }
    while(!minHeap.empty() && minHeap.top()<j){
        minHeap.pop();
    }
    if(!minHeap.empty()){
        minHeap.pop();
        count++;
    }
    if(i==events.size()&& minHeap.empty()) break;
   }

return count;
    }
};