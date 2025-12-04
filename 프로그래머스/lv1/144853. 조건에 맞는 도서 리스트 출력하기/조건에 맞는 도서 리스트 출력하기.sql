-- 코드를 입력하세요
SELECT BOOK_ID, DATE_FORMAT(PUBLISHED_DATE, '%Y-%m-%d')
FROM book
WHERE YEAR(published_date) = 2021
    AND category = '인문'
ORDER BY published_date