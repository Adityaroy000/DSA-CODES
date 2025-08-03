class KthLargest {
public:
    vector<int>temp;
    int pos,n;
    KthLargest(int k, vector<int>& nums) {
        temp = nums;
        pos = k;
        sort(temp.begin(),temp.end());
    }
    int add(int val) {
        auto it = lower_bound(temp.begin(),temp.end(),val);
        temp.insert(it,val);
        int n = temp.size();
        return temp[n-pos];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */