#include <iostream>
#include <vector>
#include <algorithm>

struct Activity {
    int start;
    int end;
};

bool sortByEndTime(const Activity &a, const Activity &b) {
    return a.end < b.end;
}

void activitySelection(std::vector<Activity> &activities) {
    int n = activities.size();
    
    // Sort activities by end time
    std::sort(activities.begin(), activities.end(), sortByEndTime);
    
    std::vector<Activity> selectedActivities;
    selectedActivities.push_back(activities[0]);
    
    int prevEnd = activities[0].end;
    
    for (int i = 1; i < n; ++i) {
        if (activities[i].start >= prevEnd) {
            selectedActivities.push_back(activities[i]);
            prevEnd = activities[i].end;
        }
    }
    
    std::cout << "Selected activities:" << std::endl;
    for (const Activity &activity : selectedActivities) {
        std::cout << "Start: " << activity.start << " End: " << activity.end << std::endl;
    }
}

int main() {
    // Example activities data
    std::vector<Activity> activities = {
        {1, 3},
        {2, 4},
        {3, 5},
        {5, 7},
        {6, 8},
        {8, 10}
    };
    
    activitySelection(activities);
    
    return 0;
}
￼Enter
