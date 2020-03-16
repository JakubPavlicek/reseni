#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main()
{
    std::vector<int> values;

    std::string x;
    bool q = false;

    while(!q)
    {
        std::string nums;
        std::cin >> x;
        if(x == "q")
            q = true;
        else
        {
            for(int i = 0; i < x.size(); i++)
            {
                if(x[i] >= 48 && x[i] <= 57)
                    nums += x[i];    
            }
        int ans = std::stoi(nums);
        values.push_back(ans);    
        }
    }
    for(int value : values)
        std::cout << value << std::endl;
}