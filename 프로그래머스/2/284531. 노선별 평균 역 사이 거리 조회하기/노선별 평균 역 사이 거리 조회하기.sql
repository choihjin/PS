SELECT 
    ROUTE, 
    CONCAT(ROUND(SUM(d_between_dist), 2), 'km') AS TOTAL_DISTANCE, 
    CONCAT(ROUND(AVG(d_between_dist), 2), 'km') AS AVERAGE_DISTANCE
FROM subway_distance
GROUP BY route
ORDER BY SUM(d_between_dist) DESC