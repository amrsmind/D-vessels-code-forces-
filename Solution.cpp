#include <iostream>
#include <iterator>
#include <functional>
#include <algorithm>
#include <utility>
#include <set>
#include <vector>
#include <stdio.h>

using namespace std;

vector<pair< long int, long int>> vessels;
set < long int>vesselsindex;
 long int negative=-1l,bigub,maxindecies;

long int findnextunfilled( long int bound){
    if(!vesselsindex.empty()){
    maxindecies = *(vesselsindex.rbegin());
    if ((bound-1l)<=maxindecies){
    auto itfirst = vesselsindex.begin();
    auto itlast = vesselsindex.end();
    auto ub = vesselsindex.lower_bound(bound-1l);
    bigub = *ub;
    return bigub;
    }
    else{ return negative;}}
    else {return negative;}

}

int main(){
     long int n,capacity,m,xliters,addcapacity,indexforadd;
    int onetwo;
       scanf("%d", &n);
     long int i = 0l,newindex,findvessel;
    while(n--)
        {
        scanf("%d", &capacity);
        vessels.push_back(make_pair(capacity,0l));
        vesselsindex.insert(i);
        i++;
        }


    scanf("%d", &m);
    while(m--){
        scanf("%d", &onetwo);
        if(onetwo == 1 ){
                scanf("%d %d", &indexforadd, &addcapacity);

                while(addcapacity>0l){
                    newindex = findnextunfilled(indexforadd);

                    if (newindex == -1l){addcapacity=0l;}

                    else if(addcapacity >= (vessels[newindex].first - vessels[newindex].second))
                        {
                        addcapacity = addcapacity - (vessels[newindex].first-vessels[newindex].second);
                        vessels[newindex].second = vessels[newindex].first;
                        vesselsindex.erase(vesselsindex.find(newindex));}

                    else if(addcapacity < (vessels[newindex].first - vessels[newindex].second)  ){

                        vessels[newindex].second +=  addcapacity;
                        addcapacity = 0l;

                        }
                            }
                           }
        else
            {
             scanf("%d", &findvessel);
             printf("%d\n",vessels[findvessel-1].second);


            }


            }

    return 0;
}
