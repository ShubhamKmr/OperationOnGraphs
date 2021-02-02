/*Program support only Undirected Graphs*/

#include<iostream>
#include<vector>
#include<string>
class Vertex
{
	public:
		std::string name;
		std::vector <Vertex *> neighbour;
		bool visited = 0;
};

std::vector<Vertex *> & add_vertex_in_graph(std::vector<Vertex *> &);
void BFS(const std::vector<Vertex *> &);
void print_adjancy_list_format(const std::vector<Vertex *> &);
int main()
{

	std::vector<Vertex *> Graph;	
	do
	{
		std::cout<<"\t Press Option\n\t 1. Add a vertex to graph.\n \t 2.Traverse in BFS. \n \t 3.Adjacency-list of graph.\n \t 4.Quit"<<std::endl;
		unsigned short op;
		std::cin>>op;
		switch (op) 
		{
			case 1:{
				       Graph = add_vertex_in_graph(Graph);       
				       break;
			       }

			case 2:{
				       //BFS(Graph);
				       break;
			       }

			case 3:{
				       //print_adjancy_list_format(Graph);
				       break;
			       }

			case 4:{
				       exit(0);
				       break;
			       }

			default:{
					std::cout<<"Wrong Input\n \tTry Again"<<std::endl;
					break;
				}
		}			
	}while(1);
	return 0;
}

std::vector<Vertex *> & add_vertex_in_graph(std::vector<Vertex *> & Graph)
{
	char op;
	Vertex * temp = new Vertex;
	std::cout<<"\t Enter the name of vertex : "<<std::endl;
	//std::getline(std::cin,temp->name);
	std::cin>>temp->name;
	do
	{
		Vertex * neighbor = new Vertex;
		std::cout<<"\n\t Enter the neighbours of: "<<temp->name<<std::endl;
		//std::getline(std::cin,neighbor->name);
		std::cin>>neighbor->name;
		temp->neighbour.push_back(neighbor);
		std::cout<<"\n\t More Neighbours for "<<temp->name<<" ? Y/N "<<std::endl;
		std::cin>>op;
		if (std::toupper(op) == 'Y')
		{
		       continue;	
		}
		else if(std::toupper(op)=='N')
		{
			break;
		}
		else
		{
			std::cout<<"\n\t Wrong Key.. Try again.\n";
		}
	}while(1);
	Graph.push_back(temp);
	return Graph;
}

//void BFS(const std::vector<Vertex *> &)
//{

//}

//void print_adjancy_list_format(const std::vector<Vertex *> &)
//{

//}

