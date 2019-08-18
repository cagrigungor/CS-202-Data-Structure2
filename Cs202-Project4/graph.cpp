/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Mustafa Çaðrý Güngör
* ID: 21602251
* Section : 2
* Assignment : 4
* Description : Cpp File of Graph class
*/

/** @file graph.cpp
 * An adjacency list representation of an undirected weighted graph.
*/
#include "graph.h"
/*Do not add new libraries or files*/

Graph::Graph()
{
}  // end constructor

void Graph::addAirport(const string& airportName)
{   /*YOUR IMPLEMENTATION*/
    if(adjList.find(airportName) == adjList.end())
    {
        list<node> list1;
        adjList.insert(make_pair(airportName,list1));
    }



}  // end addPerformer

void Graph::addConnection(const string& airport1, const string& airport2, int numOfPassengers)
{   /*YOUR IMPLEMENTATION*/
    map<string, list<node> >::iterator a1 = adjList.find(airport1);
    map<string, list<node> >::iterator a2 = adjList.find(airport2);

    if( a1 != adjList.end() &&  a2 != adjList.end())
    {

        node n1;
        n1.airportName = airport2;
        n1.numOfPassengers = numOfPassengers;
        node n2;
        n2.airportName = airport1;
        n2.numOfPassengers = numOfPassengers;
        list<node> list1 = a1->second;
        bool check = true;
        for(list<node>::iterator it=list1.begin(); it != list1.end(); ++it)
        {
            if( (*it).airportName == airport2 )
                check = false;
        }

        if(check)
        {
            a1->second.push_back(n1);
            a2->second.push_back(n2);
        }

    }


}  // end addConnection
list<string> Graph::getAdjacentAirports(const string& airportName)
{   /*YOUR IMPLEMENTATION*/
    list<string> result;
    map<string, list<node> >::iterator a1 = adjList.find(airportName);
    if(a1 != adjList.end())
    {
        list<node> airList = a1->second;

        for(list<node>::iterator it=airList.begin(); it != airList.end(); ++it)
        {
            result.push_back((*it).airportName);
        }
        return result;
    }
    else
        return result;

}  // end getAdjacentAirports

int Graph::getTotalPassengers(const string& airportName)
{   /*YOUR IMPLEMENTATION*/
    map<string, list<node> >::iterator a1 = adjList.find(airportName);
    int result = 0;
    if(a1 != adjList.end())
    {
        list<node> airList = a1->second;

        for(list<node>::iterator it=airList.begin(); it != airList.end(); ++it)
        {
            result += (*it).numOfPassengers;
        }
    }
    return result;

}  // end getTotalPassengers


list<string> Graph::findShortestPath(const string& airport1, const string& airport2)
{   /*YOUR IMPLEMENTATION*/
    map<string, list<node> >::iterator c1 = adjList.find(airport1);
    map<string, list<node> >::iterator c2 = adjList.find(airport2);
    map< string, list<string> > mapList;
    list<string> result;
    if(c1 != adjList.end() && c2 != adjList.end())
    {
        for(map< string, list<node> >::iterator it=adjList.begin(); it != adjList.end(); ++it)
        {
            if(mapList.find(it->first) == mapList.end())
            {
                list<string> list1;
                mapList.insert(make_pair(it->first,list1));
            }
        }

        int sizeL = adjList.size();

        bool visited[sizeL];
        for(int i = 0; i < sizeL; i++)
            visited[i] = false;
        queue<string> q;
        visited[distance(adjList.begin(),adjList.find(airport1))] = true;
        map<string, list<node> >::iterator a1 = adjList.find(airport1);
        string airName = a1->first;
        q.push(airName);
        while(!q.empty())
        {
            string taken = q.front();
            q.pop();
            map<string, list<node> >::iterator a1 = adjList.find(taken);
            list<node> airList = a1->second;

            for(list<node>::iterator it=airList.begin(); it != airList.end(); ++it)
            {
                map<string, list<string> >::iterator mapListIt = mapList.find((*it).airportName);
                list<string> mapList = mapListIt->second;
                mapListIt->second.push_back(taken);
                if( visited[distance(adjList.begin(),adjList.find((*it).airportName))] == false )
                {

                    q.push((*it).airportName);
                    visited[distance(adjList.begin(),adjList.find((*it).airportName))] = true;
                }

            }
        }
        map<string, list<string> >::iterator mapListIt2 = mapList.find(airport2);
        while(mapListIt2->first != airport1)
        {
            list<string> mapList2 = mapListIt2->second;
            result.push_front(mapList2.front());
            mapListIt2 = mapList.find(mapList2.front());
        }
        result.push_back(airport2);
    }
    return result;
}  // end findShortestPath

list< pair<string, string> > Graph::findMST()
{   /*YOUR IMPLEMENTATION*/
    priority_queue< pair<int,string>, vector <pair<int,string> > , greater<pair<int,string> > > minHeap;
    pair<string, list<node> > firstEntry = *adjList.begin();

    int sizeL = adjList.size();

    int key [sizeL];
    for(int i = 0; i < sizeL; i++)
        key[i] = /*INT_MAX*/2147483647;

    string parent[sizeL];
    for(int i = 0; i < sizeL; i++)
        parent[i] = "";

    bool visited[sizeL];
    for(int i = 0; i < sizeL; i++)
        visited[i] = false;

    minHeap.push(make_pair(0,firstEntry.first));
    key[distance(adjList.begin(),adjList.find(firstEntry.first))] = 0;

    while (!minHeap.empty())
    {
        string u = minHeap.top().second;
        minHeap.pop();
        visited[distance(adjList.begin(),adjList.find(u))] = true;

        map<string, list<node> >::iterator a1 = adjList.find(u);
        list<node> airList = a1->second;

        for(list<node>::iterator it=airList.begin(); it != airList.end(); ++it)
        {
            string v = (*it).airportName;
            int noOfPassenger = (*it).numOfPassengers;

            if (visited[distance(adjList.begin(),adjList.find(v))] == false && key[distance(adjList.begin(),adjList.find(v))] > noOfPassenger)
            {
                key[distance(adjList.begin(),adjList.find(v))] = noOfPassenger;
                minHeap.push(make_pair(key[distance(adjList.begin(),adjList.find(v))], v));
                parent[distance(adjList.begin(),adjList.find(v))] = u;
            }
        }
    }
    list< pair<string, string> > result;
    map<string, list<node> >::iterator beginL = adjList.begin();
    for (int i = 1; i < sizeL; ++i)
    {
        beginL++;
        result.push_back(make_pair(beginL->first,parent[i]));
    }

    return result;
}  // end findMST

void Graph::deleteAirport(const string& airportName)
{   /*YOUR IMPLEMENTATION*/
    map<string, list<node> >::iterator a1 = adjList.find(airportName);

    if(a1 != adjList.end())
    {
        list<node> airList = a1->second;
        for(list<node>::iterator it=airList.begin(); it != airList.end(); ++it)
        {
            map<string, list<node> >::iterator a2 = adjList.find((*it).airportName);
            list<node> airList2 = a2->second;

            for(list<node>::iterator it2=a2->second.begin(); it2 != a2->second.end(); ++it2)
            {

                if( (*it2).airportName == a1->first)
                {
                    (a2->second).erase(it2);
                    break;
                }

            }
        }
        adjList.erase(airportName);
    }
}  // end deleteAirport

