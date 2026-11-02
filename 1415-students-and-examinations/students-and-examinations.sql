SELECT
s.student_id,
s.student_name,
t.subject_name,
COUNT(e.subject_name) AS attended_exams
FROM Students s
CROSS JOIN Subjects t
LEFT JOIN Examinations e
ON s.student_id = e.student_id
AND t.subject_name = e.subject_name
GROUP BY
s.student_id,
s.student_name,
t.subject_name
ORDER BY
s.student_id,
t.subject_name;
