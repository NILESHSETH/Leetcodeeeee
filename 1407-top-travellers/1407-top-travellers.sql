-- select u.name as name,(
-- if((select diatance from Rides count(diatance) group by user_id) = null, 0,distance) as travelled_diatance
-- from Users u
-- left join Rides r on u.id  = r.user_id
-- order by distance desc,name asc

SELECT u.name,
       IFNULL(SUM(r.distance), 0) AS travelled_distance
FROM Users u
LEFT JOIN Rides r
  ON u.id = r.user_id
GROUP BY u.id, u.name
ORDER BY travelled_distance DESC, u.name ASC;