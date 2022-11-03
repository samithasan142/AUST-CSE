select taka from money
where id = (select id
from money
where name = 'A');


select id,name from money
union
select id,name from money1;

select S.name, B.taka
from money S inner join money1 B
on S.id = B.id;