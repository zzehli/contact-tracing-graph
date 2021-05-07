# CLI program for contact tracing

This project is a class assignment that implements a graph structure with adjacency list. It is built from scrach, without using standard libraries. The program store contact information and connections among existing records. You can view your entire records or traverse them with BFS or DFS.

To run the program, compile with:
```
make
```

Then run with:
```
./graph
```

First, you need to specify the size of your graph, then the names you want to track. This will initialize the graph ADT:
```
Please enter the graph size:
3
==============Welcome!=============
Welcome to the contact tracing manager!
Start by entering the names you want to add.
Please enter the name you want to add:
Zach Long
Contact added successfully!
continue?
y
Please enter the name you want to add:
Roxy Deaton
Contact added successfully!
continue?
y
Please enter the name you want to add:
Raff
Contact added successfully!
continue?
n
```

Then, you should add contacts among the records in your graph. To do so, select `1` in the program menu and enter the contacts:
```
===============MENU===============
Please choose from the followin actions:
1. Adding contacts among the existing list;
2. Display each person and their contacts;
3. Display every person using Depth First Search;
4. Display every person with Breadth First Search;
1
Please specify the person you are looking for
Raff
Please specify the name of person they are in contact with:
Roxy Deaton
Contact added successfully!
continue?
y
Please specify the person you are looking for
2
Please specify the name of person they are in contact with:
2
No matching entries!
continue?
y
Please specify the person you are looking for
Roxy Deaton
Please specify the name of person they are in contact with:
Zach Long
Contact added successfully!
continue?
n
============================
Do you want to continue(y/n) ?
y
```

After you enter the contacts, you can either view your list or traverse your database with BFS or DFS:
```
===============MENU===============
Please choose from the followin actions:
1. Adding contacts among the existing list;
2. Display each person and their contacts;
3. Display every person using Depth First Search;
4. Display every person with Breadth First Search;
2
The contact list of Zach Long:
The contact list of Roxy Deaton:
Zach Long
The contact list of Raff:
Roxy Deaton
============================
Do you want to continue(y/n) ?
n
```
