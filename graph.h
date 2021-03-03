#include <iostream>
#include <cstring>
#include <cctype>

//Zach Li
//The bst class implements graph structure with adjacency list. User can
//interact with the comic library with functionalites provided in the bst ADT.
//The menu class handles the test program for the ADT. The display() function
//displays the functionalities of the ADT that can be executed in the process()
//function.

const int SHORT = 15;

//menu class to manipulate test program 
class menu //reference @Nrpickle
{
   public:
      void intro();
      void establish(class table & new_table);
      void display();
      void choose();
      void process(table & new_tree);
      bool cont();

   private:
      void insert_edges(table & new_tree);
      int choice;
};

//element of the edge list
struct vertex
{
   char * name;
   struct node * head;
};

//element of the adjacency list
struct node
{
   vertex * adjacent;
   node * next;
};

//graph ADT
class table
{
   public:
   table(int size);
   ~table();
   int insert_vertex(char * new_name);
   int insert_edge(char * current, char * dest);
   int display_list() const;
   int display_all(int option) const;
   int find_location(char * index) const;

   private:
   int insert_edge(char * current, int current_index, node * &head);
   void display_list(node * head) const;
   void display_all(int & index, int visited[] ) const;
   vertex * adjacency_list;
   void display_bfs(int & index, int visited[]) const;
   int list_size;
   int next_index;//the list might not be full, this keeps track
    //of the next position to be inserted in the adjacency list 
};


