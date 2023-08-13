# SQL 50 Study Plan - Leetcode

<h3> 1757. Recyclable and Low Fat Products </h3>

[Problem Link](https://leetcode.com/problems/recyclable-and-low-fat-products/?envType=study-plan-v2&envId=top-sql-50)

> Rated: Easy

```sql
SELECT product_id
FROM Products
WHERE low_fats = 'Y' AND recyclable = 'Y';
```

<br>

<h3> 584. Find Customer Referee </h3>

[Problem Link](https://leetcode.com/problems/find-customer-referee/?envType=study-plan-v2&envId=top-sql-50)

> Rated: Easy

```sql
SELECT name
FROM Customer
WHERE referee_id IS NULL OR referee_id != 2;
```

<br>

<h3> 595. Big Countries </h3>

[Problem Link](https://leetcode.com/problems/big-countries/?envType=study-plan-v2&envId=top-sql-50)

> Rated: Easy

```sql
SELECT name, population, area
FROM World
WHERE area >= 3000000 OR population >= 25000000;
```

<br>

<h3> 1148. Article Views I </h3>

> Rated: Easy

[Problem Link](https://leetcode.com/problems/article-views-i/?envType=study-plan-v2&envId=top-sql-50)

```sql
SELECT author_id AS id
FROM Views
WHERE  author_id = viewer_id
GROUP bY author_id
ORDER BY author_id;
```

<br>

<h3> 1683. Invalid Tweets </h3>

> Rated: Easy

[Problem Link](https://leetcode.com/problems/invalid-tweets/description/?envType=study-plan-v2&envId=top-sql-50)

```sql
SELECT tweet_id
FROM Tweets
WHERE CHAR_LENGTH(content) > 15;
```

<br>

<h3> 1378. Replace Employee ID With The Unique Identifier </h3>

> Rated: Easy

[Problem Link](https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/?envType=study-plan-v2&envId=top-sql-50)

```sql
SELECT unique_id, name
FROM Employees E
LEFT JOIN EmployeeUNI EU
ON E.id = EU.id;
```

<br>

<h3> 1068. Product Sales Analysis I </h3>

> Rated: Easy

[Problem Link](https://leetcode.com/problems/product-sales-analysis-i/description/?envType=study-plan-v2&envId=top-sql-50)

```sql
SELECT product_name, year, price
FROM Sales S
INNER JOIN Product P
ON S.product_id = P.product_id;
```

<br>
