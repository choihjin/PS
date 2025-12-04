-- 코드를 작성해주세요
SELECT CONCAT(length, 'cm') AS MAX_LENGTH
FROM fish_info
ORDER BY length DESC
LIMIT 1;