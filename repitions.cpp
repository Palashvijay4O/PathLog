#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>	
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sys/types.h>
#include <dirent.h>


using namespace std;

#define scan(n) scanf("%d",&n)
#define print(n) printf("%d",n)
#define all(c) c.begin(),c.end()
#define MAX 1e9+10
const int mod = 1000000007;
#define ll long long
#define pb push_back

#define trace1(x)       cerr << #x << " : " << x << endl;
#define trace2(x, y)    cerr << #x << " : " << x << " | " << #y << " : " << y << endl;
#define trace3(x, y, z) cerr << #x << " : " << x << " | " << #y << " : " << y << " | " << #z << " : " << z << endl;
enum direction {
	north,
	south,
	east,
	west
};


pair<double, double> preprocess(string input) {
	int l = input.length();
	double x = std::stod(input.substr(0,input.find(" ")));
	//cout << x << " ";
	double y = std::stod(input.substr(input.find(" ") + 1, l));
	//cout << y << endl;
	//cout << x << " " << y << endl;
	return pair<double, double>(x, y);
}

 
vector<string> read_directory(const std::string& name)
{
	vector<string> v;
    DIR* dirp = opendir(name.c_str());
    struct dirent * dp;
    int count = 0;
    while ((dp = readdir(dirp)) != NULL) {
    	//if(count > 2) {
    		//cout << dp->d_name << endl;
    	string temp = dp->d_name;
    	if(temp != "." && temp != ".." && temp != ".DS_Store")
        	v.push_back(temp);
        	//cout << dp->d_name << endl;
        //}
        count++;
    }
    closedir(dirp);
    sort(all(v));
    return v;
}



int returnLaneNumber(pair<double, double> point) {
	if(point.first >= 950.0 && point.first <= 1050.0 && point.second >= 980.0 && point.second <= 1020.0) 
		return 13;
	if(point.first <= 1080.0 && point.first >= 1030.0 && point.second <= 1000.0 && point.second >= 850.0)
		return 10;
	if(point.first <= 1080.0 && point.first >= 1030.0 && point.second <= 1150.0 && point.second >= 1000.0)
		return 9;


	if(point.first <= 970.0 && point.first >= 920.0 && point.second <= 1000.0 && point.second >= 850.0)
		return 12;
	if(point.first <= 970.0 && point.first >= 920.0 && point.second <= 1150.0 && point.second >= 1000.0)
		return 11;


	if(point.first <= 1180.0 && point.first >= 1060.0 && point.second <= 870.0 && point.second >= 820.0)
		return 2;
	if(point.first <= 1060.0 && point.first >= 940.0 && point.second >= 820.0 && point.second <= 870.0)
		return 3;
	if(point.first >= 820.0 && point.first <= 940.0 && point.second >= 820.0 && point.second <= 870.0)
		return 4;


	if(point.first <= 1250.0 && point.first >= 1180.0 && point.second <= 1180.0 && point.second >= 820.0)
		return 1;
	if(point.first <= 820.0 && point.first >= 750.0 && point.second <= 1180.0 && point.second >= 820.0)
		return 5;
	

	if(point.first <= 1185.0 && point.first >= 1060.0 && point.second <= 1200.0 && point.second >= 1140.0)
		return 8;
	if(point.first <= 1060.0 && point.first >= 940.0 && point.second <= 1200.0 && point.second >= 1140.0)
		return 7;
	if(point.first >= 820.0 && point.first <= 940.0 && point.second <= 1200.0 && point.second >= 1140.0)
		return 6;
		
	else {
		//cout << point.first << " " << point.second << endl;
		return 12321323;
	}

}


direction getDirection(int prev, int next) {

// THREE POINT JUNCTIONS

	// Junction J-9
	if(prev == 13 && next == 9)
		return direction::west;
	if(prev == 13 && next == 10)
		return direction::east;
	if((prev == 9 && next == 13) || (prev == 10 && next == 13))
		return direction::south;
	if(prev == 9 && next == 10)
		return direction::east;
	if(prev == 10 && next == 9)
		return direction::west;

	// Junction J-10
	if(prev == 13 && next == 11)
		return direction::west;
	if(prev == 13 && next == 12)
		return direction::east;
	if((prev == 11 && next == 13) || (prev == 12 && next == 13))
		return direction::north;
	if(prev == 12 && next == 11)
		return direction::west;
	if(prev == 11 && next == 12)
		return direction::east;


	// Junction J-8
	if(prev == 9 && next == 8)
		return direction::north;
	if(prev == 9 && next == 7)
		return direction::south;
	if(prev == 7 && next == 8)
		return direction::north;
	if(prev == 8 && next == 7)
		return direction::south;
	if(prev == 8 && next == 9)
		return direction::east;
	if(prev == 7 && next == 9)
		return direction::east;


	// Junction J-7
	if(prev == 6 && next == 7)
		return direction::north;
	if(prev == 6 && next == 11)
		return direction::east;
	if(prev == 7 && next == 11)
		return direction::east;
	if(prev == 7 && next == 6)
		return direction::south;
	if(prev == 11 && next == 6)
		return direction::south;
	if(prev == 11 && next == 7)
		return direction::north;

	// Junction J-3
	if(prev == 2 && next == 3)
		return direction::south;
	if(prev == 3 && next == 2)
		return direction::north;
	if(prev == 2 && next == 10)
		return direction::west;
	if(prev == 3 && next == 10)
		return direction::west;
	if(prev == 10 && next == 3)
		return direction::south;
	if(prev == 10 && next == 2)
		return direction::north;

	// Junction J-4
	if(prev == 3 && next == 12)
		return direction::west;
	if(prev == 4 && next == 12)
		return direction::west;
	if(prev == 3 && next == 4)
		return direction::south;
	if(prev == 4 && next == 3)
		return direction::north;
	if(prev == 12 && next == 4)
		return direction::south;
	if(prev == 12 && next == 3)
		return direction::north;

// TWO POINT JUNCTIONS

	// Junction J-1
	if(prev == 8 && next == 1)
		return direction::east;
	if(prev == 1 && next == 8)
		return direction::south;

	// Junction J-2
	if(prev == 1 && next == 2)
		return direction::south;
	if(prev == 2 && next == 1)
		return direction:: west;

	// Junction J-5
	if(prev == 4 && next == 5)
		return direction::east;
	if(prev == 5 && next == 4)
		return direction::north;

	// Junction J-6
	if(prev == 5 && next == 6)
		return direction::north;
	if(prev == 6 && next == 5)
		return direction::east;



	return direction::left;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ifstream fp, fp2;
	
	
	string input;
	vector< pair<double, double> > all_points; 
	vector<int> onlane;
	


	vector<string> filenames = read_directory("GAMELOGS");
	for(auto x: filenames)
		cout << x << " ";
	cout << endl;
	for(auto d: filenames) {
		
		string y = "./GAMELOGS/" + d + "/Cleaned_PathLog.txt";
		cout << y << endl;
		fp2.open(y);
		input = "";
		map<pair<double, double>, int> hash;
		vector<int> halts_per_lane(13, 0);
		// Code for Dwelling at a point.
		while(getline(fp2,input)) {
			auto x = preprocess(input);
			int lane = returnLaneNumber(x);
			hash[x]++;
		}

		for(auto x: hash) {
			if(x.second >= 75) {

				//cout << x.first.first << " " << x.first.second << " : " << x.second/(double)100 << " on lane number : " << returnLaneNumber(x.first)  << endl;
				halts_per_lane[returnLaneNumber(x.first)-1]++;
			}
		}
		string name = d;
		std::transform(name.begin(), name.end(), name.begin(), ::toupper);
		cout << name << "\t";
	 	for(auto x: halts_per_lane)
	 		cout << x << "\t";
	 	cout << endl;

	 	fp2.close();

///////////////////////////////////////////////////////////////
	 	fp.open("./GAMELOGS/" + d + "/saaf.txt");
		input = "";
		vector< pair<double, double> > all_points; 
		vector<int> onlane;
		while(getline(fp, input)) {
			auto x = preprocess(input);
			all_points.push_back(x);
		}

		for(int i = 0; i < all_points.size(); i++) {
			onlane.push_back(returnLaneNumber(all_points[i]));
		}
	
		//for(auto x: onlane)
		//	cout << x << endl;
		//cout << all_points.size() << " " << onlane.size() << endl;
		int c = -1;
		vector<int> lane_map;
		map<int, int> no_of_times_visited;
		for(int i = 1; i <= 13; i++)
			no_of_times_visited[i] = 0;
		for(int i = 0; i < onlane.size(); i++) {
			c = onlane[i];
			int count = 0;
			lane_map.push_back(c);

			while(onlane[i] == c) {
				i++;
				count++;
			}
			if(count <= 8)
				continue;
			else {
				no_of_times_visited[c]++;
			}
		}

		//cout << endl;
		//cout << endl;
		cout << name << "\t";
		for(auto x: no_of_times_visited) {
			cout << x.second << "\t";
		}
		cout << endl;

		

		cout << name << "\t";
		int outer_halts = 0, inner_halts = 0;
		for(int i = 0; i < 8; i++) {
			outer_halts += halts_per_lane[i];
		}
		cout << outer_halts << "\t";
		for(int i = 8; i < 13; i++) {
			inner_halts += halts_per_lane[i];
		}
		cout << inner_halts << endl;

		cout << name << "\t";
		int outer_revisits = 0, inner_revisits = 0;
		for(int i = 1; i <= 8; i++) {
			outer_revisits += no_of_times_visited[i];
		}
		cout << outer_revisits << "\t";
		for(int i = 9; i <= 13; i++) {
			inner_revisits += no_of_times_visited[i];
		}
		cout << inner_revisits << endl;

		// Complete list of lane followed 
		for(auto x: lane_map) {
			cout << x << " -> ";
		}

		for(int i = 0; i < lane_map.size()-1; i++) {
			direction dir = getDirection(lane_map[i], lane_map[i+1]);
		}


		cout << endl;
		fp.close();

 	}
	// End Code for Dwelling here.

	
	return 0;
}