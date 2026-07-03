select w2.id as Id from weather w
join weather w2 
on datediff(w2.recordDate,w.recordDate)=1
where w2.temperature > w.temperature;