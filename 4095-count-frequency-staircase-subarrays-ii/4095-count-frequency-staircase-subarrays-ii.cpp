class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        vector<int> freq(100005, 0);
        vector<int> expected_freq(100005, 0);
        vector<int> touched;
        touched.reserve(400);
        for(int i = 0;i<n;i++){
            int valid_count = 0;
            int dis_count = 0;

            touched.clear();


            for(int j = i;j<n;j++){
                int val = nums[j];
                if(freq[val]==0){
                    dis_count++;
                    if (1LL * dis_count * (dis_count + 1) / 2 > (n - i)) {
                        break; 
                    }
                    expected_freq[val] = dis_count;
                    touched.push_back(val);
                }

                if(freq[val]==expected_freq[val]){
                    valid_count--;
                }
                
                freq[val]++;
                if(freq[val]==expected_freq[val]){
                    valid_count++;
                }
                else if(freq[val]>expected_freq[val]){
                    break;
                }

                if(valid_count==dis_count){
                    count++;
                }
            }
            for(int val : touched){
                freq[val] = 0;
                expected_freq[val] = 0;
            }
        }
        return count;
    }
};