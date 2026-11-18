select customer_number
from Orders
group by customer_number
having count(order_number) = (
    select max(cnt)
    from (
        select count(order_number) as cnt
        from Orders
        group by customer_number
    ) as temp
)