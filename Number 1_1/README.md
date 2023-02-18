#  Pseudo-code

```
FUNCTION count_students_absent(sheet)
    count = 0
    FOR i = 1 to sheet.currentSize
        IF sheet.students[i].grade = 1 THEN
            count = count + 1
        END IF
    END FOR
    OUTPUT "Count absent students: " + count
END FUNCTION

```
