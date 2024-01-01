**What is a transaction?**
- A collection of queries
- It is treated as one unit of work

**Transaction Lifespan**
- It begin with keyword **BEGIN**
- Basically these are part of implementation ion every database and each database handles them differently
- It ends with the word **COMMIT**
	- This is another part of database implementation
	- A commit means that work is done and we can write to the disk and now we have many options like we can either commit on every query or commit once for a transaction and different databases handle this part differently
	- Postgres optimizes this part and had lot of commits
- **ROLL BACK** - Do no persist all these changes

**Nature of Transactions**
- Usually transaction are used to change or modify data
- It can however be just a read only transaction

![[Pasted image 20240101201304.png]]


### Atomicity
- All the queries in a transaction must succeed
- If one query fails, all prior successful queries in the transaction should rollback
- If the database went down prior to a commit of a transaction all the successful queries in the transaction should rollback
- An atomic transaction is a transaction that will roll back all queries if one or more queries failed

### Isolation
- There is a chance that concurrency can happen and multiple transactions execute at once
- Can my inflight transaction see changes made by other transactions?
#### Read phenomena
- Dirty Reads
	- You read something that some other transaction has written but didn't really commit yet
	- So it may happen that this write may not be flushed (wrote to the disk)
- Non-repeatable reads
	- In database terms, a **non-repeatable read** happens when a transaction reads the same data twice, but the second time, the data has changed due to another transaction that committed in between.
- Phantom Reads
	- A Phantom read **occurs when one user is repeating a read operation on the same records, but has new records in the results set**
	- Phantom reads occur when one transaction reads a set of rows twice, but the set changes size between reads due to another committed transaction. It's like the attic suddenly rearranging itself, playing tricks on your memory.
- Lost Updates
	- **Lost update** is a concurrency problem that can occur in databases when multiple transactions attempt to modify the same data concurrently, and the isolation level in place doesn't prevent one transaction from overwriting the changes made by another.


**DIRTY READS**
**Here's how it happens:**
1. **Transaction 1 reads a value:** A transaction reads a value from a row in the database.
2. **Transaction 2 updates a value:** A transaction updates a value from a row in the database.
3. **Transaction 1 reads a wrong value**


**NON REPEATABLE READS**
**Here's how it happens:**
1. **Transaction A reads data:** (Orders the burger)
2. **Transaction B modifies the data:** (Steals the burger and replaces it with tofu)
3. **Transaction A reads data again:** (Takes a second bite, expecting the juicy burger)
4. **Surprise! Different data!** (Tofu, tofu, tofu!)

**LOST UPDATES**
**Here's how it happens:**

1. **Transaction 1 reads a value:** A transaction reads a value from a row in the database, intending to update it.
2. **Transaction 2 reads the same value:** Before Transaction 1 commits its update, another transaction (Transaction 2) reads the same value from the same row.
3. **Transaction 2 updates and commits:** Transaction 2 modifies the value and commits its changes to the database.
4. **Transaction 1 updates and commits:** Transaction 1, unaware of Transaction 2's changes, updates the value based on its original read and commits its changes.

### Isolation Levels

**Read Uncommitted** - No Isolation, any change from the outside is visible to the transaction, committed, ie you can read uncommitted values as a result get dirty reads.

**Read committed** - Each query in a transaction only sees committed changes by other transactions.

**Repeatable Read** - The transaction will make sure that when a query reads a row, that row will remain unchanged while its running. 

**Snapshot** - Each query in a transaction only sees changes that have been committed up to the start of the transaction. It's like a snapshot version of the database at that moment.  

**Serializable** - Transactions are run as if they serialized one after the other. No concurrency and the transactions are serialised

Each DBMS implements Isolation level differently.

![[Pasted image 20240101232628.png]]

**Database Implementation of Isolation**
- Each DBMS implements Isolation level differently 
- Pessimistic - Row level locks, table locks, page locks to avoid lost updates 
- Optimistic - No locks, just track if things changed and fail the transaction if so 
- Repeatable read “locks” the rows it reads but it could be expensive if you read a lot of rows, postgres implements RR as snapshot. That is why you don’t get phantom reads with postgres in repeatable read 
- Serializable are usually implemented with optimistic concurrency control, you can implement it pessimistically with SELECT FOR UPDATE

### Consistency
- Consistency in the data
	- Defined by the user
	- is the data following some rules
	- Referential integrity
	- Atomicity and isolation can also result in inconsistency in data/results
- Consistency in reads
	- This is in reference to multiple database instances, they can be out of sync 
	- Example let's say that there is a database with a main worked node and replicas and update was made in the main node and while it was syncing the replicas I read the replicas and now I am reading the wrong data.
	- Eventual consistency
	- Relational and NoSQL both suffer from this

### Durability
- Changes made by committed transactions must be persisted in a durable non-volatile storage.
- Durability Techniques
	- WAL - Write ahead log
		1. **Logging First, Writing Later:** Instead of directly updating the database files, any change you make (inserts, updates, deletes) is first recorded in a dedicated log file called the **WAL**. This log is like a running diary of all the database modifications.
		2. This is not stored on RAM but on disk
		3. Upon server restart, the database system reads the log and replays the recorded changes to bring the database to a consistent state. This way, any unfinished transactions are either completed or gracefully rolled back, ensuring **data integrity** is preserved
		4. You'll find WAL employed in various popular database systems, including PostgreSQL, MySQL, Oracle, and Cassandra.
		
		**OS CACHE**
		- Generally a write request in OS usually goes to the OS cache
			- As the OS cache bathes these request and executes these at once to minimize number of IO operations on the disk
		- But let's say the write goes to OS Cache, an OS crash happens and machine restart could lead to loss of data
		- Fsync OS command forces writes to always go to disk
		- Fsync can be expensive and slows down commits
	- 

	- Asynchronous Snapshot
		- We write in memory but asynchronously in background we write the whole snapshot to disk
		- Redis
	- AOF
		- Append only file
- 