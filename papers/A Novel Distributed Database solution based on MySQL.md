

Problems with traditional RDBMS - expanding difficulties

The scale of data being generated by the applications has been growing exponentially

Enterprises or organization can use these methods to solve this problem.
- Hardware upgrade (Vertical scalability) - Not that good and possible after a point
- NoSQL
- Sharding 
	- Dividing very large databases into many more easily managed shards

This paper introduces and novel database solution based on MySQL. inspired by the idea of sharding, to meet the needs of horizontal scalability.

### System Architecture

![[Pasted image 20240120121733.png]]
##### MySQL Communication Protocol

\
The system uses MySQL communication protocol to communicate with other layers, including upper applications and underlying MySQL databases. 

##### Connection Pool
The database connection is a kind of limited expensive resources.

##### SQL Processor
This is the core function of the whole system , with responsibility for parsing, routing, executing the SQL statements and processing the results returned from MySQL databases.

**SQL Parser**
- Parse the SQL statement to get the abstract syntax tree
- Parse the AST to get the information such as table name, conditional expression, field list, value list for calculating the route.

**SQL Router**
- It is used to calculate the data node set corresponding to the SQL statement based on the configuration files

**SQL Executor**
- The processed SQL statements are sent to the corresponding data node set and then they are executed locally

**Results Processor**
- Merge the execution results from multiple data nodes and then further process the results according to requirements, such as sorting.


### Key Technologies

#### Input/ Output


#### Sharding Algorithms
They are used to distribute slices to data nodes which is the core business in distributed database. Some sharding algorithms
**Enumeration algorithm** 
- Determine the data node where data is stored by the value of designated table field. For example, the tuple is stored in data node 1 if the value of its field 'id' is '01'.

**Range partition algorithm**
- Determine the data node by the range of designated table field, similar to the enumeration algorithm. For example, the tuple is stored in data node 1 if the value of its field 'id' is between 1 and 100 thousand.

**Date partition algorithm**
- Determine the data node by the date value of designated table field, similar to range partition algorithm. Start date and time span are designated in the configure file.

#### Distributed Joins
This needs to be done when we will be distributing our tables column wise

So take a case where a join operation between table R and S is required on condition that attribute A is equal to attribute C
Direct-join strategy and semi-join strategy are the two basic strategies to transfer table data. The direct-join strategy works as follows: 
- Step 1: All tuples from R are shipped to the site 2 
- Step 2: After the tuples of R are received by the site 2, they would be stored in the local database firstly and then perform the join locally. 

Semi-join strategy consists of the following steps: 
- Step 1: Execute SQL statement (select distinct A from R) in site 1 and then obtain the result set T. 
- Step 2: Select one tuple from T (if not null), e.g. A=a, send it to site 2 and execute SQL statement (select * from S where C=’a’) in site 2 and then obtain the result set W. 
- Step 3: Send W (if not null) to site 1 and perform the join locally. If there are other tuples of T, return step 2.