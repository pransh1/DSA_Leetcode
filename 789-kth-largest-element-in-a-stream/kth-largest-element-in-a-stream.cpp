// class KthLargest {
// public:
//     vector<int> largest;
//     int k;
//     KthLargest(int k, vector<int>& nums) {
//         this->k = k; // the k-th number 
//         for(int num : nums) {
//             // first insert all numbers to the largest vector
//             largest.push_back(num);
//         }
//         // then sort it to maintain the sorting order for easy access to k-th largest element
//         sort(largest.begin(), largest.end());
//     }
    
//     int add(int val) {
//         // first find the index where to add the val
//         // we are doing this so that aour largest vector remains sorted
//         int index = bs(val);
//         // insert it at that index
//         largest.insert(largest.begin() + index, val); 
//         // return the k-th largest element
//         return largest[largest.size() - k];
//     }

//     private:
//         int bs(int val) {
//             int l = 0;
//             int r = largest.size() - 1;

//             while(l <= r) {
//                 int mid = l + (r - l) / 2;
//                 int large = largest[mid];

//                 if(large == val) {
//                     return mid;
//                 }
//                 if(large > val) {
//                     r = mid - 1;
//                 }
//                 else {
//                     l = mid + 1;
//                 }
//             }
//             return l;
//         }
// };


class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if(pq.size() < k || pq.top() < val) {
            pq.push(val);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }

};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */



// /**
//  * Your KthLargest object will be instantiated and called as such:
//  * KthLargest* obj = new KthLargest(k, nums);
//  * int param_1 = obj->add(val);
//  */