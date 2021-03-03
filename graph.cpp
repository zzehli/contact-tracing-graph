#include "graph.h"
using namespace std;

//Zach Li
//Table class supports building, traversing graph structures. There are 
//three ways of traversing and diplay the structure of the graph: display 
//adjacency list and connection of each vertices, DFS and BFS.The menu class handles the
//client program with simple display, functionality test, and continue function.
//All the functionalities can be accessed in the process() function.

//first prompt
void menu::intro()
{
   cout<<"==============Welcome!=============\n";
   cout<<"Welcome to the contract tracing manager!\n";
   cout<<"Start by entering the names you want to add. \n";
}

//adding vertices to the graph
void menu::establish(table & new_table)
{
   char option;
   char addName[SHORT];
   do
   {
      cout<<"Please enter the name you want to add: \n";
      cin.get(addName, SHORT, '\n');
      cin.ignore(100,'\n');
      if(new_table.insert_vertex(addName))
         cout<<"Contact added successfully!\n";
      cout<<"continue?\n";
      cin>>option;
      cin.ignore(100,'\n');
   }
   while(option!='n');
 
}

//display available options of the ADT
void menu::display()
{
   cout<<"===============MENU===============\n";
   cout<<"Please choose from the followin actions:\n";
   cout<<"1. Adding contacts among the existing list;\n";
   cout<<"2. Display each person and their contacts;\n";
   cout<<"3. Display every person using Depth First Search;\n";
   cout<<"4. Display every person with Breadth First Search;\n";
}


//record input choice from the user
void menu::choose()
{
   choice = 999;
   cin >> choice;
   cin.ignore(100,'\n');
}

//process available actions according to the order in the display menu
void menu::process(table & new_tree)
{
   switch(choice)
   {
      case 1: 
         insert_edges(new_tree);
         break;
      case 2:
         new_tree.display_list();
         break;
      case 3:
         new_tree.display_all(1);//need revision function
         break;
      case 4:
         new_tree.display_all(2);
         break;
      default:
         cout<<"Invalid!\n";
         break;
   }
}

//exit program only when the input is n
bool menu::cont()
{
   char option;
   cout<<"============================\n";
   cout<<"Do you want to continue(y/n) ?\n";
   cin>>option;
   cin.ignore(100,'\n');
   if(option == 'n')
      return false;
   else return true;
}
//prompt to take input for table
void menu::insert_edges(table & new_tree)
{         
   char anotherName[SHORT];
   char contactName[SHORT];
   char choice;
  do{
      cout<<"Please specify the person you are looking for\n";
      cin.get(anotherName,SHORT,'\n');
      cin.ignore(100,'\n');
      cout<<"Please specify the name person they are in contact with:\n";
      cin.get(contactName, SHORT, '\n');
      cin.ignore(100,'\n');
      int num = new_tree.insert_edge(contactName, anotherName);
      if(num >0)
         cout<<"Contact added successfully!\n";
      else if(num==0)
         cout<<"Contact already exist!\n";
      else
         cout<<"No matching entries!\n";
      cout<<"continue?\n";
      cin>>choice;
      cin.ignore(100,'\n');
   }while(choice!='n');
}
   
//constructor to initialize a table of designated size
table::table(int size)
{
   adjacency_list = new vertex[size];
   for(int i = 0; i < size; ++i)
   {
      adjacency_list[i].name = NULL;
      adjacency_list[i].head = NULL;
   }
   list_size = size;
   next_index = 0;
}

table::~table()
{
   if(adjacency_list)
   {
      for(int i = 0; i < list_size; ++i)//for each vertex 
      {
         if(adjacency_list[i].name)//check if the name of the vertex 
         {
            delete [] adjacency_list[i].name;
            if(adjacency_list[i].head)//delete the edge list
            {
               node * current = adjacency_list[i].head;
               while(current)
               {
                  node * temp = current->next;
                  delete current;
                  current = temp;
               }
            adjacency_list[i].head = NULL;
            }
         adjacency_list[i].name = NULL;//set the head to null
         }
      }
   delete [] adjacency_list;
   }
   adjacency_list = NULL;
}

//add a new person name to the adjacency list
int table::insert_vertex(char * new_name)
{
   if(next_index == list_size)
      return 0;//no more room
   adjacency_list[next_index].name = new char[strlen(new_name)+1];
   strcpy(adjacency_list[next_index].name, new_name);
   //cout<<"This is the copied name: "<<adjacency_list[next_index].name<<endl;
   ++next_index;
   return 1;
}

//wrapper function to calculate the necessary index in the array
int table::insert_edge(char * current, char * dest)
{
   int current_index = find_location(current);//index of current name
   int dest_index = find_location(dest);//find the index in the array to attach to
   if(dest_index < 0 || current_index < 0)//no match 
      return -1;
   return insert_edge(current, current_index, adjacency_list[dest_index].head);
}

//add an edge to a vertex, return 0 if edge already exits
int table::insert_edge(char * current, int current_index,node * & head)
{
   if(!head)
   {
      head = new node;
      head->adjacent =& adjacency_list[current_index];
      head->next = NULL;
      return 1;
   }
   if(head->adjacent ==& adjacency_list[current_index])//edge already exit;
      return 0;
   return insert_edge(current, current_index, head->next);
}

//take a name and return the index in the array
int table::find_location(char* index) const
{
   for(int i = 0; i < next_index; ++i)//search through existing array element
   {
      if(strcmp(index, adjacency_list[i].name)==0)
         return i;
   }
   return -1;
}

//wrapper function to display adjacency list
int table::display_list() const
{
    for(int i = 0; i < next_index; ++i)
    {
        cout<<"The contact list of "<<adjacency_list[i].name<<": \n";
        node * current = adjacency_list[i].head;
        display_list(current);
    }
    return 1;
}

//display the adjacent list and each edge list
void table::display_list(node * head) const
{
    if(!head)
        return;
    cout<<head->adjacent->name<<" "<<endl;
    display_list(head->next);
}

//wrapper function for traversal and display with dfs
int table::display_all(int option) const
{
   int array[next_index];//initialize the visit array to 0
   for(int i=0; i < next_index; ++i )
   {
      array[i] = 0;
   }

   int num =0;
   if(option == 1)
   {
      cout<<"+++DFS+++"<<endl;
      display_all(num, array);
   }
   else
   {
      cout<<"+++BFS+++"<<endl;
      display_bfs(num, array);
   }
   return 1;
}
//DFS for connected graph, index is the starting point of the search, visited[]
//is an array to keep track of vertices visited
void table::display_all(int & index, int visited[] ) const
{
   if(visited[index]==0)
   {
       cout<<adjacency_list[index].name<<endl;
       visited[index]=1;
       node * temp = adjacency_list[index].head;
       while(temp)
       {
            index = find_location(temp->adjacent->name);
            display_all(index, visited);
            temp = temp->next;
       }
   }
}

//BFS for connected graph, index is the starting point of the search, visited[]
//is an array to keep track of vertices visited
void table::display_bfs(int & index, int visited[]) const
{
    int indexEdge;
    if(visited[index]==2)//2 means the vertices is visited 
                        //1 means the vertices is displayed
                        //0 means it is neither
        return;
    if(visited[index]==0)//only for the first vertex
        cout<<adjacency_list[index].name<<endl;//display the name of the vertices 
    node * temp = adjacency_list[index].head;
    while(temp)//loop through the node adjacent to vertices
    {
        indexEdge = find_location(temp->adjacent->name);
        if(visited[indexEdge]==0)//only display if it is not displayed before
        {
            cout<<temp->adjacent->name<<" "<<endl;//display the name of the node
            visited[indexEdge]=1;
        }
        temp = temp->next;
    }
    temp = adjacency_list[index].head;//reset temp to the beginning of the list
    visited[index]=2;
    while(temp) //visit all the vertices in the previous loop
    {
        indexEdge = find_location(temp->adjacent->name);
        display_bfs(indexEdge,visited);//can I still access indexArray when I unwind?
        temp = temp->next;
    }
}
  
