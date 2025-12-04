-- 코드를 입력하세요
SELECT COUNT(*) AS USERS
FROM user_info
WHERE YEAR(joined) = 2021
    AND AGE >= 20
    AND AGE <= 29