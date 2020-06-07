#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

// void rearrangeKDist(char str[])
// {
//     int n = strlen(str);
//     unordered_map<char, int> table;
//     for (int i = 0; i < n; i++) {
//         unordered_map<char, int>::iterator it = table.find(str[i]);
//         if (it == table.end()) {
//             table.insert(make_pair(str[i], 1));
//         } else {
//             it->second = it->second + 1;
//         }
//     }
//     for (unordered_map<char, int>::iterator it = table.begin(); it != table.end(); it++)
//         cout << it->first << " " << it->second << endl;
//     sort(table.begin(), table.end(), comp);
//     for (unordered_map<char, int>::iterator it = table.begin(); it != table.end(); it++)
//         cout << it->first << " " << it->second << endl;
// }
class Frame {
public:
    Frame()
    {
    }

    void insertFrame()
    {
        // inserting values by using [] operator
        umap[1] = "Fram1";
        umap[2] = "Fram2";
        umap[0] = "Fram0";
        // inserting value by insert function
        umap.insert(make_pair(3, "Fram3"));
    }

    void traverseFrame()
    {
        // Traversing an unordered map
        for (auto& x : umap)
            cout << x.first << " " << x.second << endl;
    }

    void sortDecedent()
    {
        vector<pair<int, string>> vMap;
        for (auto& i : umap) {
            vMap.push_back(i);
        }
        // sort(umap.begin(), umap.end(), comp);
        sort(vMap.begin(), vMap.end(),
            [&](pair<int, string>& a, pair<int, string>& b) { return a.first >= b.first; });

        for (auto& x : vMap) {
            cout << x.first << " " << x.second << endl;
        }
    }

    void sortIncrease()
    {
        vector<pair<int, string>> vMap;
        for (auto& i : umap) {
            vMap.push_back(i);
        }
        // sort(umap.begin(), umap.end(), comp);
        // sort(vMap.begin(), vMap.end(),
        //     [&](pair<int, string>& a, pair<int, string>& b) { return a.first <= b.first; });

        sort(vMap.begin(), vMap.end(), comp);

        // for (auto x : vMap) {
        //     cout << x.first << " " << x.second << endl;
        // }

        for (auto& x : vMap) {
            // sortedmap.insert(make_pair(x.first, x.second));
            // sortedmap[x.first] = x.second;
            cout << x.first << " " << x.second << endl;
        }
    }

    static bool comp(pair<int, string> a, pair<int, string> b)
    {
        return a.first <= b.first;
    }

    // This is the easist way to sort a map
    void convert2OrderedMap()
    {
        cout << "-------- convert2OrderedMap ----------" << endl;
        std::map<int, string> ordered(umap.begin(), umap.end());
        for (auto it = ordered.begin(); it != ordered.end(); ++it)
            std::cout << it->first << it->second << endl;

        sortedmap = ordered;

        cout << "-------------sortedmap -----------" << endl;
        for (auto& x : sortedmap) {
            cout << x.first << " " << x.second << endl;
        }
    }

private:
    // Frame ID; Other information
    unordered_map<int, string> umap;
    map<int, string> sortedmap;
};

int main()
{
    Frame keyframe;
    cout << "----------Construct Frame---------------" << endl;
    keyframe.insertFrame();

    cout << "----------Before sort ---------------" << endl;
    keyframe.traverseFrame();

    cout << "----------Decedent sort ---------------" << endl;
    keyframe.sortDecedent();

    cout << "----------Increase sort ---------------" << endl;
    keyframe.sortIncrease();

    keyframe.convert2OrderedMap();

    return 0;

    // std::string str = "hello world!";
    // rearrangeKDist(str);
}
