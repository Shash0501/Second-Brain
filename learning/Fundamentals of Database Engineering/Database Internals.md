
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