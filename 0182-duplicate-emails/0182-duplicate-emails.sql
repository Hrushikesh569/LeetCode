# Write your MySQL query statement below
select distinct email from (select email,row_number() over (partition by email order by email) as dp from Person ) temp where dp>1
