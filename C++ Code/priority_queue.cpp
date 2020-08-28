// Maximum heap
std::priority_queue<T> pq;

// Minimum heap
priority_queue<T, vector<T>, greater<T>> pq;

// Add
pq.push(a);

// Remove from front
pq.pop();

// Get front
T a = pq.top();


// Costomize comparator
class my_comparator {
public:
    bool operator() (T p1, T p2) {
        // Maximum heap (Default)
        return p1 < p2;

        // Minimum heap
        return p1 > p2;
    }
};

priority_queue<T, vector<T>, my_comparator> pq;