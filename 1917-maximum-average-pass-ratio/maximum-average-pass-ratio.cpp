class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        std::priority_queue<std::tuple<double, int, int>, std::vector<std::tuple<double, int, int>>, std::greater<std::tuple<double, int, int>>> minHeap;
        double output = 0.0;
        for (const std::vector<int> &class_ : classes) {
            if (class_[0] == class_[1]) {
                output += 1;
                continue;
            }
            double first = static_cast<double>(class_[0]) / class_[1];
            double second = static_cast<double>(class_[0] + 1) / (class_[1] + 1) - first;
            minHeap.push(std::make_tuple(-second, class_[0], class_[1]));
        }
        while (extraStudents  && !minHeap.empty()) {
            std::tuple<double, int, int> cls = minHeap.top();
            minHeap.pop();
            int pass = std::get<1>(cls) + 1, total = std::get<2>(cls) + 1;
            double first = static_cast<double>(pass) / total;
            double second = static_cast<double>(pass + 1) / (total + 1) - first;
            minHeap.push(std::make_tuple(-second, pass, total));
            --extraStudents;
        }
        
        while (!minHeap.empty()) {
            output += static_cast<double>(std::get<1>(minHeap.top())) / std::get<2>(minHeap.top());
            minHeap.pop();
        }
        return output / classes.size();
    }
};