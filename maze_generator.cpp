  /********************************************************/
 /* Maze Generation using Randomized Kruskal's Algorithm */
/********************************************************/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <utility>
#include <vector>
#include <set>

using namespace std;


struct edge {

	pair<int,int> v1;
	pair<int,int> v2;
};


int nrows;
int ncols;
vector<edge> walls;


void init_walls() {

	//creating the column walls
	for(int i=0; i<nrows; i++) {
		for(int j=0; j<ncols-1; j++) {
			edge e = {pair<int,int>(i,j), pair<int,int>(i,j+1)};
			walls.push_back(e);
		}
	}

	//creating the row walls
	for(int j=0; j<ncols; j++) {
		for(int i=0; i<nrows-1; i++) {
			edge e = {pair<int,int>(i,j), pair<int,int>(i+1,j)};
			walls.push_back(e);
		}
	}
}


void generate_maze() {
	
	vector< set< pair<int,int> > > forest;
	for(int i=0; i<nrows; i++) {
		for(int j=0; j<ncols; j++) {
			set< pair<int,int> > tree;
			tree.insert(pair<int,int>(i,j));
			forest.push_back(tree);
		}
	}

	srand(time(NULL));
	while(forest.size()>1) {

		int w = rand()%walls.size();
		edge wall = walls[w];
		
		int t1, t2;
		for(t1=0; t1<forest.size() && forest[t1].find(wall.v1)==forest[t1].end(); t1++);
		if(forest[t1].find(wall.v2)!=forest[t1].end())
			continue;

		walls[w] = walls[walls.size()-1];
		walls.pop_back();

		for(t2=0; t2<forest.size() && forest[t2].find(wall.v2)==forest[t2].end(); t2++);
		forest[t1].insert(forest[t2].begin(),forest[t2].end());
		forest[t2] = forest[forest.size()-1];
		forest.pop_back();
	}

}


edge build_wall(edge e) {

	edge w;

	if(e.v1.first==e.v2.first) { //It will be a V-wall
		w.v1 = pair<int,int>(max(e.v1.second,e.v2.second),e.v1.first);
		w.v2 = pair<int,int>(max(e.v1.second,e.v2.second),e.v1.first+1);		
	}

	else { //It will be a H-wall
		w.v1 = pair<int,int>(e.v1.second,max(e.v1.first,e.v2.first));
		w.v2 = pair<int,int>(e.v1.second+1,max(e.v1.first,e.v2.first));		
	}

	return w;
}

float normalize(int x_coord) { return 25*(float)x_coord/(nrows+ncols); }

void draw_maze_latex(string file_name) {

	ofstream file;  
	file.open(file_name, ios::app);

	file << "\\documentclass{report}\n\n";
	file << "\\usepackage{tikz}\n";
	file << "\\colorlet{floor}{blue!25!green!60!white}\n";
	file << "\\colorlet{wall}{blue!25!green!90!black}\n\n";

	file << "\\begin{document}\n\n";
	file << "\\begin{tikzpicture}\n";

	file << "\\fill[floor] ";
	file << "(0,0) -- (0," << normalize(nrows) << ") -- (" <<  normalize(ncols) << "," <<  normalize(nrows) << ") -- (" <<  normalize(ncols) << ",0) -- (0,0);\n";

	for(int k=0; k<walls.size(); k++) {
		edge w = build_wall(walls[k]);
		file << "\\draw[wall,very thick] ";
		file << "(" << normalize(w.v1.first) << "," << normalize(w.v1.second) << ") -- (" << normalize(w.v2.first) << "," << normalize(w.v2.second) << ");\n";
	}

	file << "\\end{tikzpicture}\n\n";
	file << "\\end{document}\n";
}


int main(int nargs, char** argc) {

	nrows = atoi(argc[1]);
	ncols = atoi(argc[2]);

	init_walls();
	generate_maze();

	draw_maze_latex(argc[3]);
}