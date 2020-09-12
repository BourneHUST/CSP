CSP201909-4:

这道题中，首先要了解map自动排序的机制，特殊数据也可以自动排序，比如pair也是可以自动排的


//201909-4  learning
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;
int main()
{
    freopen("test.in", "r", stdin);
    int m, n, op;
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    unordered_map<int, int> G[51]; //存储编号到分数的映射,这个很重要
    unordered_map<int, int>::iterator itG;
    map<int, set<pair<int, int>>> F; //map<Score,set<pair<Type,Commodity> > >
    map<int, set<pair<int, int>>>::iterator itF;
    cin >> m >> n; //初始化商品
    for (int i = 0, id, score; i < n; ++i)
    {
        cin >> id >> score;
        for (int j = 0; j < m; ++j)
            F[score].insert(pair<int, int>(j, id)), G[j][id] = score;
    }
    cin >> op; //增删查操作
    for (int i = 0, k, kind, type, commodity, score, K[51]; i < op; ++i)
    {
        cin >> kind;
        switch (kind)
        {
        case 1: //增加
            cin >> type >> commodity >> score;
            G[type][commodity] = score;                       //在G中记录该Type类编号为Commodity商品成绩映射
            F[score].insert(pair<int, int>(type, commodity)); //在F中插入该商品
            break;
        case 2: //删除
            cin >> type >> commodity;
            if ((itG = G[type].find(commodity)) != G[type].end())
            {                                                       //如果该商品存在则开始删除
                itF = F.find(itG->second);                          //首先查找该商品在F中找到所有Score为itG->second的所有商品，也就是一个集合
                itF->second.erase(pair<int, int>(type, commodity)); //删除该商品
                if (itF->second.empty())                            //该分数集合为空
                    F.erase(itF);                                   //如果该分数的容器为空 删掉
                G[type].erase(itG);                                 //删掉Type类的Commodity到Score的映射
            }
            break;
        case 3:       //查询
            cin >> k; //查询总个数k
            for (int j = 0; j < m; ++j)
                cin >> K[j]; //输入每类不得超过的最大查询数

            vector<int> S[51]; //存储所有类查询到的商品编号

            for (auto it = F.rbegin(); it != F.rend() && k > 0; ++it) //rbegin()是倒数第一位 rend相应的是第一位
            {                                                         //按分数由大到小选择前k个物品
                set<pair<int, int>> &s = it->second;                  //该分数下所有商品的集合
                for (auto itS = s.begin(); itS != s.end() && k > 0; ++itS)
                {
                    const pair<int, int> &p = *itS;
                    if (K[p.first] > 0)
                        S[p.first].push_back(p.second), --K[p.first], --k; //若该物品不超过选择数量则选择该物品
                }
            }

            for (int j = 0; j < m; ++j)
            {                     //对所有类输出选择的物品
                if (S[j].empty()) //该类没有选中任何物品
                    cout << -1 << endl;
                else
                {
                    k = 0; //仅仅用于判断是否输出空格
                    for (auto it = S[j].begin(); it != S[j].end(); ++it, ++k)
                        cout << (k == 0 ? "" : " ") << *it;
                    cout << endl;
                }
            }
            break;
        }
    }
    return 0;
}
