# List of Contents:

- <a href = "#1">Session 1:</a><br>
  - <a href = "#1.1">Database</a>
  - <a href = "#1.2">Table</a>
  - <a href = "#1.3">Types of Databases</a>
    - <a href = "#1.3.1">Relational Databases</a>
    - <a href = "#1.3.2">NoSQL Databases</a>
  - <a href = "#1.4">SQL</a>
  - <a href = "#1.5">MySQL vs SQL</a>
  - <a href = "#1.6">Installation of MySQL</a>
    - <a href = "#1.6.1">Global Usage</a>

<h2 id = "1"> Session 1 </h2>

1. <h3 id = "1.1">Database</h3><br>
   Ans: A collection of data and holds this data in form of tables.<br><br>

2. <h3 id = "1.2">Table</h3><br>
   Ans: It holds the data in form of rows and columns, similar to a spreadsheet.<br>
   <h4>Why not use a spreadsheet then?</h4><br>
   Ans: The database provides us the capability to access and modify the data.<br><br>

3. <h3 id = "1.3">Different types of Databases</h3><br>
   Ans: 2 types of databases:<br>

- <h4 id = "1.3.1"> Relational Databases </h4>: Rows and Columns and also tables have relation between them. Example: `MySQL`, `SQL Server`, `PostgreSQL`, `SQLite`, `MariaDB`.<br>
- <h4 id = "1.3.2"> NoSQL Databases </h4>: Key Value, Document, Graphs. Doesn't have any specified structure and different structures are non-relational. Example: `Hbase`, `Mongodb`, `Cassandra`.<br><br>

4. <h3 id = "1.4">SQL</h3><br>
   Ans: Stands for Structured Query Language and is used to query a relational database.<br><br>

5. <h3 id = "1.5">MySQL vs SQL</h3> <br>
   Ans: MySQL is a relational database and SQL is the language used to interact with the databases, which includes, MySQL. SQL is a common language across all RDBs and the syntax also remains same for 99% code and the rest can be managed easily.<br><br>

6. <h3 id = "1.6"> Installation of MySQL </h3><br>
   Ans: There are 2 methods by which we can use MySQL, by using it globally or locally. Below are the 2 processes:<br><br>
   1. <h4 id = "1.6.1"> Global Usage: </h4><br>

   - Go to [https://ide.goorm.io/](Goorm ide site)
   - Click on _Get Started_ and _Sign up_ using an account. (Preferably Google).
   - Now, you will be re-directed to a dashboard.
   - Click _New Container_. It will be somewhere at the top-right of the page, considering this blog hasn't become too old!
   - Fill up the name (My Sql for this process, preferably), set-up the region to the nearest one and change the stack to **node.js**.
   - At the bottom, there will be a section of _Additional module/package_: Check the 1st 2 options, _Install MySQL_ and _Enable mysql-ctl command_.
   - We are all set and click _Create_. This will take some time to finish.
   - After finishing, click on launch container.
