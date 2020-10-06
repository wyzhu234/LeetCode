#include "common.h"
#include <sstream>

string simplify_path(string path) {
    vector<string> vec;
    string res, temp;
    istringstream iss(path);
    while (getline(iss, temp, '/'))
    {
        if (temp.empty() || temp == ".") continue;
        if (temp == "..")
        {
            if (!vec.empty())
            {
                vec.pop_back();
            }
        }
        else
        {
            vec.push_back(temp);
        }
    }

    for (string s : vec)
    {
        res += "/" + s;
    }

    return res.empty() ? "/" : res;
}

void test_day71()
{
    string path = "/a/b/../";
    cout << simplify_path(path) << endl;
}