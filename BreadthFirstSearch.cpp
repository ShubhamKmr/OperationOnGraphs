/*Program support only Undirected Graphs*/

#include<iostream>
#include<vector>
#include<string>

class Vertex
{
	public:
		std::string name;
		std::vector <Vertex *> neighbour;
		bool visited {0};
};

void add_vertex_in_graph(std::vector<Vertex *> &);
void BFS(std::vector<Vertex *> &);
void print_adjancy_list_format(const std::vector<Vertex *> &);
void toupper(std::string &);
unsigned char Vertex_present(const std::string & ,const std::vector<Vertex *> &);

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
				       add_vertex_in_graph(Graph);       
				       break;
			       }

			case 2:{
				       BFS(Graph);
				       break;
			       }

			case 3:{
				       print_adjancy_list_format(Graph);
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

void add_vertex_in_graph(std::vector<Vertex *> & Graph)
{
	char op;
	Vertex * temp = new Vertex;
	std::cout<<"\t Enter the name of vertex : "<<std::endl;
	std::cin>>temp->name;
	toupper(temp->name);
	do
	{
		Vertex * neighbor = new Vertex;
		std::cout<<"\n\t Enter the neighbours of: "<<temp->name<<std::endl;
		std::cin>>neighbor->name;
		toupper(neighbor->name);
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
}

void BFS(std::vector<Vertex *> & Graph)
{
	std::string start_vertex;
	unsigned char place {0};
	Vertex * queue ;
	std::cout<<"\n \t Enter the name of Vertex to traverse : ";
	std::cin>>start_vertex;
	toupper(start_vertex);
	place = Vertex_present(start_vertex,Graph);
	if (!place)
	{
		std::cout<<"\t Vertex not in Graph.. Please Retry.."<<std::endl;
	}
	else
	{
		Graph.at(place - 1 )->visited = 1;
		std::cout<<"\n \t "<<Graph.at(place - 1 )->name<<std::endl;
		for (auto n : Graph.at(place - 1)->neighbour )
		{
			if (n->visited == 0)
			{
				n->visited = 1;
				std::cout<<"->"<<n->name;
			}
		}
	}


}

void print_adjancy_list_format(const std::vector<Vertex *> & Graph)
{
	std::cout<<"\n\t Adjaceny list of the graph is following : - "<<std::endl;

	for(auto v : Graph)
	{
		std::cout<<"\t "<<v->name;
		for(auto n : v->neighbour)
		{
			std::cout<<"->"<<n->name;
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
}

void toupper(std::string & name)
{
	unsigned short i = 0;
	for(auto n : name)
	{
		name[i] = std::toupper(n);
		i++;
	}
}


unsigned char Vertex_present(const std::string & name,const std::vector<Vertex *> & Graph)
{
	unsigned char place {0};
	for(auto vertex : Graph)
	{
		place++;
		if (name == vertex->name)
		{
			return place;
		}
	}
	return place;
}
