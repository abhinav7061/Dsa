//code for two number sum?
#include <iostream>
#include <vector>

int main()
{
    std::vector<int>nums = { 1,2,3,4,5 };
    int target =  7 ;

    for (std::size_t i = 0; i < nums.size()-1; i++)
    {
        for (std::size_t j = i + 1; j < nums.size(); j++)
        {
            if (nums[i]+nums[j]==target)
            {
                std::cout << " [ " << i << " ," << j << " ] ";
            }
        }
    }

    return 0;
}


//  [ 1 ,4 ]  [ 2 ,3 ] 


