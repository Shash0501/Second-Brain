
How tables and indexes are stored on disk?
How are they queried?

### Storage

Table - you know what it is
**Row_id**
- Most databases create there own column to work rather than the ones specified by the user
- This is called row_id
- In certain databases (mysql) it is the same as the primary key but other databases like postgres have a system column row_id (tuple_id)
- ![[Pasted image 20240102184751.png]]

**Pages**
  
In the context of databases, a page refers to a unit of data storage on disk. It's like a building block for your database's information, similar to how pages make up a book.

Pages have a fixed size, typically ranging from 4 kilobytes (KB) to 8 kilobytes (KB). This standardized format allows for efficient data access and management.
8KB in postgres and 16KB in Mysql
Basically a page is a memory location and it holds some rows

Each page consists of two main parts:
    - **Header:** This section contains metadata about the page, such as its number, type, free space available, and the object it belongs to.
    - **Data Area:** This section stores the actual data, like rows and columns from tables, indexes, or other database objects.


**Index**
- An index is another data structure separate from the heap that has 'pointers' to the heap
- It has part of the data and used to quickly search for something.
- You can index on one column or more



### Row - Column Based Databases  

##### Row oriented database
- Tables are stores as rows in disk
- A single block IO read to the table fetches multiple rows with all their columns 
- More IOs are required to find a particular row in a table scan but once you find the row you get all columns for that row.
- ![[Pasted image 20240109150944.png]]
- The above table would look like this in a row based database
- ![[Pasted image 20240109151009.png]]
- Each gray box takes on IO operations and all the data in that row is sent 

Executing queries in row oriented table

`select first_name from emp where ssn=666`
We pull each block one by one and then search through all the ssn and we do it till we reach the 3rd block.

### Column Oriented Databases
- Tables are stored as columns first in disk
- A single block io read to the table fetches multiple columns with all matching rows 
- Less IOs are required to get more values of a given column. But working with multiple column require more IO,s
- 
