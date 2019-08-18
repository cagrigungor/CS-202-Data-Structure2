/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Mustafa Çaðrý Güngör
* ID: 21602251
* Section : 2
* Assignment : 4
* Description : Main class to test graph class
*/

/**
 * CS 202 - HW 4
 * A main file
 * Please make sure that your code compiles and runs with this main file
 */
#include "graph.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
/*You can add additional libraries here to read and process the dataset*/

using namespace std;

int main() {
    /*YOUR IMPLEMENTATION*/
    Graph g;
    ifstream src("flightDataset.txt");
    char ch;
    string input = "";
    string a1 = "",a2 = "";
    bool check = true;
     bool check2 = false;
    while(!src.eof())
    {
        src.get(ch);
        if(ch == ';')
        {
            if(check)
            {

                a1 = input;
                g.addAirport(a1);
                check = false;
            }
            else
            {
                a2 = input;
                g.addAirport(a2);
                check = true;
            }

            input = "";
        }
        else if(isdigit(ch))
        {
            input += ch;
            check2 = true;
        }
        else
        {
            input += ch;
            if(check2)
            {
                int number;
                stringstream parseInt(input);
                parseInt>>number;
                g.addConnection(a1,a2,number);
                check2 = false;
                input = "";
            }


        }
    }

    list< pair<string, string> > result = g.findMST();
    for(list< pair<string, string> >::iterator it= result.begin(); it != result.end(); ++it)
    {
        cout<<it->first<<"--------"<<it->second<<endl;
    }
    cout<<endl;

    cout<<g.getTotalPassengers("BELFAST INTERNATIONAL")<<endl;
    cout<<endl;

    list<string> l = g.getAdjacentAirports("BRISTOL");
    for(list<string>::iterator it=l.begin(); it != l.end(); ++it)
    {
        cout<<*it<<" "<<endl;
    }
    cout<<endl;

    list<string> m = g.findShortestPath("BRISTOL", "MANCHESTER");
    for(list<string>::iterator it=m.begin(); it != m.end(); ++it)
    {
        cout<<*it<<" "<<endl;
    }
    cout<<endl;

    g.deleteAirport("BRISTOL");
    cout<<endl;

    list<string> k = g.getAdjacentAirports("BRISTOL");
    for(list<string>::iterator it=k.begin(); it != k.end(); ++it)
    {
        cout<<*it<<" "<<endl;
    }

    cout<<endl;

    cout<<g.getTotalPassengers("BELFAST INTERNATIONAL")<<endl;

    cout<<endl;

    list< pair<string, string> > result2 = g.findMST();
    for(list< pair<string, string> >::iterator it= result2.begin(); it != result2.end(); ++it)
    {
        cout<<it->first<<"--------"<<it->second<<endl;
    }
    cout<<endl;

	return 0;
}
// End of main file
