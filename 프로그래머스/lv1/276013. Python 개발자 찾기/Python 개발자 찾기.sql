-- 코드를 작성해주세요
SELECT id, email, first_name, last_name
FROM developer_infos
WHERE skill_1 = 'Python'
OR skill_2 = 'Python'
OR skill_3 = 'Python'
ORDER BY id;