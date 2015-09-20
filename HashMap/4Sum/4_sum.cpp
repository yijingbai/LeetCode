class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target)
    {
        vector<vector<int> > resultSet;
        sort(num.begin(), num.end());

        const int len = num.size();
        for (int id = 0; id < len - 3; ++id) // 1st loop
        {
            if (id > 0 && num[id] == num[id - 1]) // skip the duplication
                continue;

            vector<int> tmpNum(num.begin() + id + 1, num.end());
            vector<vector<int> > tmpResultSet = threeSum(tmpNum, target - num[id]);
            for(int j = 0; j < tmpResultSet.size(); ++j)
            {
                tmpResultSet[j].insert(tmpResultSet[j].begin(), num[id]);
                resultSet.push_back(tmpResultSet[j]);
            }
        }

        return resultSet;
    }

vector<vector<int> > threeSum(vector<int> &num, int target)
{
    vector<vector<int>> resultSet;
    // step01: quick sort
    sort(num.begin(), num.end());

    // step02:
    int len = num.size();
    for (int id = 0; id < len - 2; ++id) // id < len
    {
        // if (0 < id && id < len -1 && num[id] == num[id - 1] && num[id] == num[id + 1]) // 跳过重复元素
        if (id > 0 && num[id] == num[id - 1])
            continue;

        int low = id + 1;
        int high = len - 1;
        while(low < high)
        {
            int sum = num[id] + num[low] + num[high];
            if (sum > target)
            {
                // do{--high;} while(low < high && num[high] == num[high + 1]); //skip the duplication
                while(high > 0 && num[high] == num[high - 1])
                    --high;
                --high;
            }
            else if (sum < target)
            {
                // do{++low;} while(low < high && num[low] == num[low - 1]); //skip the duplication
                while(low < len && num[low] == num[low + 1])
                    ++low;
                ++low;
            }
            else
            {
                vector<int> result;
                result.push_back(num[id]);
                result.push_back(num[low]);
                result.push_back(num[high]);
                resultSet.push_back(result);
                //skip the duplication
                while(low < len && num[low] == num[low + 1])
                    ++low;
                while(high > 0 && num[high] == num[high - 1])
                    --high;
                ++low;
                --high;
            }
        }
    }

    return resultSet;
}
};
