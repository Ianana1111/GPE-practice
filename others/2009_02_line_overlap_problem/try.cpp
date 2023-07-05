#include<bits/stdc++.h>
using namespace std;

struct LineSegment {
    int start;
    int end;
};

bool compare(LineSegment& a, LineSegment& b) {
    return a.start < b.start;
}

int calculateTotalOverlappingLength(vector<LineSegment>& segments) {
    int totalLength = 0;

    for (size_t i = 0; i < segments.size(); i++) {
        int currentEnd = segments[i].end;

        for (size_t j = i + 1; j < segments.size(); j++) {
            if (segments[j].start <= currentEnd) {
                // Found an overlapping segment
                totalLength += min(currentEnd, segments[j].end) - segments[j].start;
                currentEnd = max(currentEnd, segments[j].end);
            } else {
                // No more overlapping segments with current segment
                break;
            }
        }
    }

    return totalLength;
}

int main() {
    // Example usage
    vector<LineSegment> segments = {{1, 5}, {3, 7}, {2, 6}};
    sort(segments.begin(), segments.end(), compare);

    int totalOverlappingLength = calculateTotalOverlappingLength(segments);

    std::cout << "Total overlapping length: " << totalOverlappingLength << std::endl;

    return 0;
}
