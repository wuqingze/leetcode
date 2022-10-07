# Write your MySQL query statement below
#select customer_number from ( select customer_number, max(n) from (select #customer_number, count(*) as n from Orders group by customer_number ) as t2) as t1;

select customer_number from (select customer_number, count(*) as n from Orders group by customer_number order by n desc) as t1 limit 1;
